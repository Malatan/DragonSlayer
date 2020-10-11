//
// Created by Administrator on 10/10/2020.
//

#include "Resource.h"

Resource::Resource(std::string resourcePath, std::string key,std::string stateName)  :
        resourcePath(resourcePath), key(key), stateName(stateName){

    if(!this->image.loadFromFile(resourcePath)){
        throw("Resource load error: " + stateName + "-" + key + " path:" + resourcePath);
    }
}

Resource::~Resource() {
}

std::string Resource::getKey() {
    return this->key;
}

const sf::Image Resource::getImage() const{
    return this->image;
}

std::string Resource::toString() {
    std::string app = "";
    app += "State: " + this->stateName;
    app += " Key: " + this->key;
    app += " Path: " + this->resourcePath;
    return app;
}




