//
// Created by Zheng on 12/01/2021.
//

#ifndef DRAGONSLAYER_PATHFINDER_H
#define DRAGONSLAYER_PATHFINDER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Node.h"
#include "Map.h"

class Map;

class PathFinder {
public:
    //constructors/destructor
    PathFinder();
    ~PathFinder();

    //functions
    void generateNodes(Map* _map);
    void updateNodes(Map* _map, sf::Vector2i current_grid_pos);
    void updateWalkableNodes(Map* _map);
    bool FindPath(sf::Vector2f start_pos, sf::Vector2f target_pos, int max_cost);
    std::vector<Node*> getNearNodes(int grid_x, int grid_y);
    static int GetDistance(Node* node_a, Node* node_b);
    void RetracePath(Node* start_node, Node* end_node);
    void updateTimer(const float& dt);

    std::vector<Node*> path;
    std::vector<std::vector<Node*>> nodes;
    int widthN{};
    int heightN{};
    int nodesN{};
    int nodeMultiplier{1};

    float timer{};
    int counts{};
};


#endif //DRAGONSLAYER_PATHFINDER_H
