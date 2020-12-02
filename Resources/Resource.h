//
// Created by Administrator on 10/10/2020.
//

#ifndef DRAGONSLAYER_RESOURCE_H
#define DRAGONSLAYER_RESOURCE_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Resource {
public:
    Resource(const std::string& resourcePath, const std::string& key,const std::string& stateName);
    virtual ~Resource();

    std::string getKey();
    sf::Image getImage() const;
    std::string toString();

private:
    sf::Image image;
    std::string resourcePath;
    std::string key;
    std::string stateName;
};


#endif //DRAGONSLAYER_RESOURCE_H
