#include "Dungeon.h"

//constructors/destructor
Dungeon::Dungeon(int width, int height)
        : _width(width), _height(height), _tiles(width * height, Unused), _rooms(), _exits() {
}

//setters/getters
char Dungeon::getTile(int x, int y) const {
    if (x < 0 || y < 0 || x >= _width || y >= _height)
        return Unused;

    return _tiles[x + y * _width];
}

void Dungeon::setTile(int x, int y, char tile) {
    _tiles[x + y * _width] = tile;
}

void Dungeon::print() const {
    for (int y = 0; y < _height; ++y) {
        for (int x = 0; x < _width; ++x)
            std::cout << getTile(x, y);

        std::cout << std::endl;
    }
}

std::string Dungeon::getGenerationLog() const {
    return generationLog;
}

//functions
void Dungeon::generate(int maxFeatures) {
    // place the first room in the center
    if (!makeRoom(_width / 2, _height / 2, static_cast<Direction>(utils::generateRandomNumber(0,3), true))) {
        generationLog += "Unable to place the first room.\n";
        return;
    }

    // we already placed 1 feature (the first room)
    for (int i = 1; i < maxFeatures; ++i) {
        if (!createFeature()) {
            generationLog += "Unable to place more features (placed " + to_string(i) + ").\n";
            break;
        }
    }

    if (!placeObject(UpStairs)) {
        generationLog += "Unable to place up stairs.\n";
        return;
    }

    if (!placeObject(DownStairs)) {
        generationLog += "Unable to place down stairs.\n";
        return;
    }

    for (char &tile : _tiles) {
        if (tile == Unused)
            tile = '.';
        else if (tile == Floor || tile == Corridor)
            tile = ' ';
    }
}

void Dungeon::writeOnFile(const std::string& path) const {
    std::ofstream myfile;
    myfile.open(path);
    for (int y = 0; y < _height; ++y) {
        for (int x = 0; x < _width; ++x)
            myfile << getTile(x, y);

        myfile << std::endl;
    }
    myfile.close();
}

bool Dungeon::createFeature() {
    for (int i = 0; i < 1000; ++i) {
        if (_exits.empty())
            break;

        // choose a random side of a random room or corridor
        int r = utils::generateRandomNumber(0, (int)_exits.size() - 1);
        int x = utils::generateRandomNumber(_exits[r].x, _exits[r].x + _exits[r].width - 1);
        int y = utils::generateRandomNumber(_exits[r].y, _exits[r].y + _exits[r].height - 1);

        // north, south, west, east
        for (int j = 0; j < DirectionCount; ++j) {
            if (createFeature(x, y, static_cast<Direction>(j))) {
                _exits.erase(_exits.begin() + r);
                return true;
            }
        }
    }

    return false;
}

bool Dungeon::createFeature(int x, int y, Direction dir) {
    static const int roomChance = 20; // corridorChance = 100 - roomChance

    int dx = 0;
    int dy = 0;

    if (dir == North)
        dy = 1;
    else if (dir == South)
        dy = -1;
    else if (dir == West)
        dx = 1;
    else if (dir == East)
        dx = -1;

    if (getTile(x + dx, y + dy) != Floor && getTile(x + dx, y + dy) != Corridor)
        return false;

    if (utils::generateRandomNumber(0, 100) < roomChance) {
        if (makeRoom(x, y, dir)) {
            setTile(x, y, ClosedDoor);

            return true;
        }
    } else {
        if (makeCorridor(x, y, dir)) {
            if (getTile(x + dx, y + dy) == Floor)
                setTile(x, y, ClosedDoor);
            else // don't place a door between corridors
                setTile(x, y, Corridor);

            return true;
        }
    }

    return false;
}

bool Dungeon::makeRoom(int x, int y, Direction dir, bool firstRoom) {
    static const int minRoomSize = 3;
    static const int maxRoomSize = 6;

    Rect room{};
    room.width = utils::generateRandomNumber(minRoomSize, maxRoomSize);
    room.height = utils::generateRandomNumber(minRoomSize, maxRoomSize);

    if (dir == North) {
        room.x = x - room.width / 2;
        room.y = y - room.height;
    } else if (dir == South) {
        room.x = x - room.width / 2;
        room.y = y + 1;
    } else if (dir == West) {
        room.x = x - room.width;
        room.y = y - room.height / 2;
    } else if (dir == East) {
        room.x = x + 1;
        room.y = y - room.height / 2;
    }

    if (placeRect(room, Floor)) {
        _rooms.emplace_back(room);

        if (dir != South || firstRoom) // north side
            _exits.emplace_back(Rect{room.x, room.y - 1, room.width, 1});
        if (dir != North || firstRoom) // south side
            _exits.emplace_back(Rect{room.x, room.y + room.height, room.width, 1});
        if (dir != East || firstRoom) // west side
            _exits.emplace_back(Rect{room.x - 1, room.y, 1, room.height});
        if (dir != West || firstRoom) // east side
            _exits.emplace_back(Rect{room.x + room.width, room.y, 1, room.height});

        return true;
    }

    return false;
}

bool Dungeon::makeCorridor(int x, int y, Direction dir) {
    static const int minCorridorLength = 3;
    static const int maxCorridorLength = 6;

    Rect corridor{};
    corridor.x = x;
    corridor.y = y;

    if (utils::trueFalse(0.5)) // horizontal corridor
    {
        corridor.width = utils::generateRandomNumber(minCorridorLength, maxCorridorLength);
        corridor.height = 1;

        if (dir == North) {
            corridor.y = y - 1;

            if (utils::trueFalse(0.5)) // west
                corridor.x = x - corridor.width + 1;
        } else if (dir == South) {
            corridor.y = y + 1;

            if (utils::trueFalse(0.5)) // west
                corridor.x = x - corridor.width + 1;
        } else if (dir == West)
            corridor.x = x - corridor.width;

        else if (dir == East)
            corridor.x = x + 1;
    } else // vertical corridor
    {
        corridor.width = 1;
        corridor.height = utils::generateRandomNumber(minCorridorLength, maxCorridorLength);

        if (dir == North)
            corridor.y = y - corridor.height;

        else if (dir == South)
            corridor.y = y + 1;

        else if (dir == West) {
            corridor.x = x - 1;

            if (utils::trueFalse(0.5)) // north
                corridor.y = y - corridor.height + 1;
        } else if (dir == East) {
            corridor.x = x + 1;

            if (utils::trueFalse(0.5)) // north
                corridor.y = y - corridor.height + 1;
        }
    }

    if (placeRect(corridor, Corridor)) {
        if (dir != South && corridor.width != 1) // north side
            _exits.emplace_back(Rect{corridor.x, corridor.y - 1, corridor.width, 1});
        if (dir != North && corridor.width != 1) // south side
            _exits.emplace_back(Rect{corridor.x, corridor.y + corridor.height, corridor.width, 1});
        if (dir != East && corridor.height != 1) // west side
            _exits.emplace_back(Rect{corridor.x - 1, corridor.y, 1, corridor.height});
        if (dir != West && corridor.height != 1) // east side
            _exits.emplace_back(Rect{corridor.x + corridor.width, corridor.y, 1, corridor.height});

        return true;
    }

    return false;
}

bool Dungeon::placeRect(const Rect &rect, char tile) {
    if (rect.x < 1 || rect.y < 1 || rect.x + rect.width > _width - 1 ||
        rect.y + rect.height > _height - 1) //controllo bordo dungeon
        return false;

    for (int y = rect.y; y < rect.y + rect.height; ++y)
        for (int x = rect.x; x < rect.x + rect.width; ++x) {
            if (getTile(x, y) != Unused)
                return false; // area già usata
        }

    for (int y = rect.y - 1; y < rect.y + rect.height + 1; ++y)
        for (int x = rect.x - 1; x < rect.x + rect.width + 1; ++x) {
            if (x == rect.x - 1 || y == rect.y - 1 || x == rect.x + rect.width ||
                y == rect.y + rect.height) //controllo bordo stanza
                setTile(x, y, Wall);
            else
                setTile(x, y, tile); //applico il tile
        }

    return true;
}

bool Dungeon::placeObject(char tile) {
    if (_rooms.empty())
        return false;

    int r = utils::generateRandomNumber(0, (int)_rooms.size()-1); // choose a random room
    int x = utils::generateRandomNumber(_rooms[r].x + 1, _rooms[r].x + _rooms[r].width - 2);
    int y = utils::generateRandomNumber(_rooms[r].y + 1, _rooms[r].y + _rooms[r].height - 2);

    if (getTile(x, y) == Floor) {
        setTile(x, y, tile);

        // place one object in one room (optional)
        _rooms.erase(_rooms.begin() + r);

        return true;
    }

    return false;
}

