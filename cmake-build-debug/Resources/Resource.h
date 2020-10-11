//
// Created by Administrator on 10/10/2020.
//

#ifndef DRAGONSLAYER_RESOURCE_H
#define DRAGONSLAYER_RESOURCE_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Resource {
private:
    sf::Image image;
    std::string resourcePath;
    std::string key;
    std::string stateName;
protected:

public:
    Resource(std::string resourcePath, std::string key,std::string stateName);
    virtual ~Resource();

    std::string getKey();
    const sf::Image getImage() const;
    std::string toString();
};


#endif //DRAGONSLAYER_RESOURCE_H
