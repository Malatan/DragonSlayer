//
// Created by Administrator on 10/10/2020.
//

#include "Resource.h"

Resource::Resource(std::string resourcePath, std::string key,std::string stateName)  :
        resourcePath(resourcePath), key(key), stateName(stateName){

    if(!image.loadFromFile(resourcePath)){
        throw("Resource load error: " + stateName + "-" + key + " path:" + resourcePath);
    }
}

Resource::~Resource() {
}

std::string Resource::getKey() {
    return key;
}

const sf::Image Resource::getImage() const{
    return image;
}

std::string Resource::toString() {
    std::string app = "";
    app += "State: " + stateName;
    app += " Key: " + key;
    app += " Path: " + resourcePath;
    return app;
}




