//
// Created by Zheng on 12/01/2021.
//

#include "PathFinder.h"

//constructors/destructor
PathFinder::PathFinder() = default;

PathFinder::~PathFinder() {
    for(const auto& i : nodes){
        for(auto j : i){
            delete j;
        }
    }
}

//functions
void PathFinder::generateNodes(Map* _map) {
    nodes.clear();
    for(auto i: nodes){
        i.clear();
    }
    const auto& tiles = _map->getTiles();
    nodeMultiplier = 8;
    heightN = _map->getHeight() * nodeMultiplier;
    widthN = _map->getWidth() * nodeMultiplier;
    nodesN = 0;
    nodes.resize(heightN);
    for(auto y = 0 ; y < heightN ; y += nodeMultiplier){
        nodes[y].resize(widthN);
        for(auto yy = 1 ; yy < nodeMultiplier ; yy++)
            nodes[y + yy].resize(widthN);
        for(auto x = 0 ; x < widthN ; x += nodeMultiplier){
            bool is_walkable = tiles[y/nodeMultiplier][x/nodeMultiplier]->isTraversable();
            for(auto y1 = 0 ; y1 < nodeMultiplier ; y1 ++){
                for(auto x1 = 0 ; x1 < nodeMultiplier ; x1 ++){
                    nodes[y + y1][x + x1] = new Node(is_walkable, x + x1, y + y1);
                    nodesN++;
                }
            }
        }
    }
    emptyNodes = (heightN * widthN) - nodesN;
    updateWalkableNodes(_map);
}

void PathFinder::updateNodes(Map *_map, sf::Vector2i current_grid_pos) {
    const auto& tiles = _map->getTiles();
    int map_width = _map->getWidth();
    int map_height = _map->getHeight();

    int from_x = current_grid_pos.x - 1;
    if (from_x < 0)
        from_x = 0;
    else if (from_x > map_width)
        from_x = map_width;

    int to_x = current_grid_pos.x + 2;
    if (to_x < 0)
        to_x = 0;
    else if (to_x > map_width)
        to_x = map_width;

    int from_y = current_grid_pos.y - 1;
    if (from_y < 0)
        from_y = 0;
    else if (from_y > map_height)
        from_y = map_height;

    int to_y = current_grid_pos.y + 2;
    if (to_y < 0)
        to_y = 0;
    else if (to_y >= map_height)
        to_y = map_height;

    from_x *= nodeMultiplier;
    to_x *= nodeMultiplier;
    from_y *= nodeMultiplier;
    to_y *= nodeMultiplier;

    for(auto y = from_y ; y < to_y ; y += nodeMultiplier){
        for(auto x = from_x ; x < to_x ; x += nodeMultiplier){
            types tile_type = tiles[y/nodeMultiplier][x/nodeMultiplier]->GetType();
            if(tile_type == OPENDOOR){
                bool is_walkable = tiles[y/nodeMultiplier][x/nodeMultiplier]->isTraversable();
                for(auto y1 = 0 ; y1 < nodeMultiplier ; y1 ++){
                    for(auto x1 = 0 ; x1 < nodeMultiplier ; x1 ++){
                        nodes[y + y1][x + x1]->setWalkable(is_walkable);
                    }
                }
            }
        }
    }
}

void PathFinder::updateWalkableNodes(Map* _map) {
    const auto& tiles = _map->getTiles();
    for(auto y = 0 ; y < heightN ; y += nodeMultiplier){
        for(auto x = 0 ; x < widthN ; x += nodeMultiplier){
            bool walkable_tile = tiles[y/nodeMultiplier][x/nodeMultiplier]->isTraversable();
            types tile_type = tiles[y/nodeMultiplier][x/nodeMultiplier]->GetType();
            if(!walkable_tile && tile_type != VOID && tile_type != CLOSEDOOR){
                for(auto y1 = -1 ; y1 < nodeMultiplier + 1 ; y1 ++){
                    for(auto x1 = -1 ; x1 < nodeMultiplier + 1; x1 ++){
                        int new_x = x + x1;
                        int new_y = y + y1;
                        if(new_x > 0 && new_y > 0 && new_x < widthN && new_y < heightN){
                            if(nodes[new_y][new_x]){
                                nodes[new_y][new_x]->setWalkable(false);
                            }
                        }
                    }
                }
            }
        }
    }
}

bool PathFinder::FindPath(sf::Vector2f start_pos, sf::Vector2f target_pos, int max_cost) {
    int start_grid_x = (int)(start_pos.x / (Tile::TILE_SIZE / (float)nodeMultiplier));
    int start_grid_y = (int)(start_pos.y / (Tile::TILE_SIZE / (float)nodeMultiplier));
    int target_grid_x = (int)(target_pos.x / (Tile::TILE_SIZE / (float)nodeMultiplier));
    int target_grid_y = (int)(target_pos.y / (Tile::TILE_SIZE / (float)nodeMultiplier));
    Node* start_node = nodes[start_grid_y][start_grid_x];
    Node* target_node = nodes[target_grid_y][target_grid_x];
    std::vector<Node*> openSet;
    std::vector<Node*> closedSet;
    openSet.push_back(start_node);

    while (!openSet.empty()) {
        Node* node = openSet[0];
        int index = 0;
        for (int i = 1; i < openSet.size(); i ++) {
            if (openSet[i]->fCost() < node->fCost() || openSet[i]->fCost() == node->fCost()) {
                if (openSet[i]->hCost < node->hCost){
                    node = openSet[i];
                    index = i;
                }
            }
        }
        openSet.erase(openSet.begin() + index);
        closedSet.push_back(node);

        if (node == target_node) {
            RetracePath(start_node, target_node);
            for(auto i : openSet){
                i->hCost = 0;
                i->gCost = 0;
            }
            for(auto i : closedSet){
                i->hCost = 0;
                i->gCost = 0;
            }
            return true;
        }

        for(auto& i : getNearNodes(node->posX, node->posY)){
            if (!i->walkable || std::find(closedSet.begin(), closedSet.end(), i) != closedSet.end()){
                continue;
            }
            int newCostToNeighbour = node->gCost + GetDistance(node, i);
            if(newCostToNeighbour > max_cost){
                return false;
            }
            if (newCostToNeighbour < i->gCost || std::find(openSet.begin(), openSet.end(), i) == openSet.end()) {
                i->gCost = newCostToNeighbour;
                i->hCost = GetDistance(i, target_node);
                i->parent = node;
                if (std::find(openSet.begin(), openSet.end(), i) == openSet.end())
                    openSet.push_back(i);
            }
        }
    }

    return false;
}

std::vector<Node *> PathFinder::getNearNodes(int grid_x, int grid_y) {
    std::vector<Node*> res;
    int fromx = grid_x - 1;
    int tox = grid_x + 2;
    int fromy = grid_y - 1;
    int toy = grid_y + 2;
    for (int y = fromy; y < toy; y++) {
        for (int x = fromx; x < tox; x++) {
            if(x > 0 && x < widthN && y > 0 && y < heightN){
                res.push_back(nodes[y][x]);
            }
        }
    }
    return res;
}

int PathFinder::GetDistance(Node* node_a, Node* node_b) {
    int dst_x = std::abs(node_a->posX - node_b->posX);
    int dst_y = std::abs(node_a->posY - node_b->posY);
    if (dst_x > dst_y)
        return 14 * dst_y + 10 * (dst_x - dst_y);
    return 14 * dst_x + 10 * (dst_y - dst_x);
}

void PathFinder::RetracePath(Node* start_node, Node* end_node) {
    path.clear();
    Node* current_node = end_node;
    while (current_node != start_node) {
        path.push_back(current_node);
        current_node = current_node->parent;
    }
    std::reverse(path.begin(), path.end());
}
