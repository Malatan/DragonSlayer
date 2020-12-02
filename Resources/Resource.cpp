//
// Created by Administrator on 10/10/2020.
//

#include "Resource.h"

Resource::Resource(const std::string& resourcePath, const std::string& key,const std::string& stateName)  :
        resourcePath(resourcePath), key(key), stateName(stateName){

    if(!image.loadFromFile(resourcePath)){
        std::cout<<"Resource load error: " << stateName << "-" << key << " path:" << resourcePath;
    }
}

Resource::~Resource() = default;

std::string Resource::getKey() {
    return key;
}

sf::Image Resource::getImage() const{
    return image;
}

std::string Resource::toString() {
    std::string app;
    app += "State: " + stateName;
    app += " Key: " + key;
    app += " Path: " + resourcePath;
    return app;
}




