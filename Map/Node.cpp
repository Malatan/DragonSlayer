//
// Created by Zheng on 12/01/2021.
//


#include "Node.h"
//constructors/destructor
Node::Node(bool _walkable, int pos_x, int pos_y) : walkable(_walkable), posX(pos_x), posY(pos_y){

}

Node::~Node() {
    delete parent;
}

//functions
int Node::getPosX() const {
    return posX;
}

int Node::getPosY() const {
    return posY;
}

int Node::fCost() const {
    return gCost + hCost;
}

bool Node::operator!=(const Node &obj) const {
    return !(obj.posX == posX && obj.posY == posY);
}

bool Node::operator==(const Node &obj) const {
    return (obj.posX == posX && obj.posY == posY);
}

std::string Node::toString() const {
    std::stringstream ss;
    ss << "GridX: " << posX << " GridY: " << posY << std::endl;
    return ss.str();
}

void Node::setWalkable(bool _walkable) {
    Node::walkable = _walkable;
}

bool Node::isWalkable() const {
    return walkable;
}


