//
// Created by Administrator on 10/10/2020.
//

#ifndef DRAGONSLAYER_RESOURCE_H
#define DRAGONSLAYER_RESOURCE_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Resource {
private:
    sf::Texture* texture;
    std::string resourcePath;
    std::string usageDescription;
    std::string stateName;
protected:

public:
    Resource(std::string resourcePath, std::string usageDescription,std::string stateName, sf::Texture* texture);
    virtual ~Resource();

    std::string toString();
};


#endif //DRAGONSLAYER_RESOURCE_H
