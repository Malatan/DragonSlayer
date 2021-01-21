//
// Created by Zheng on 12/01/2021.
//

#ifndef DRAGONSLAYER_NODE_H
#define DRAGONSLAYER_NODE_H

#include <memory>
#include <sstream>

class Node {
public:
    //constructors/destructor
    Node(bool _walkable, int pos_x, int pos_y);
    virtual ~Node();

    //functions
    int fCost() const;
    int getPosX() const;
    int getPosY() const;
    void setWalkable(bool _walkable);
    bool isWalkable() const;
    void resetCosts();
    bool operator!=(const Node& obj) const;
    bool operator==(const Node& obj) const;
    std::string toString() const;

private:
    friend class PathFinder;
    bool walkable{};
    int posX{};
    int posY{};

    int gCost{};
    int hCost{};
    Node* parent{};
};


#endif //DRAGONSLAYER_NODE_H
