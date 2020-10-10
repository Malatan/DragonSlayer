//
// Created by Administrator on 10/10/2020.
//

#include "Resource.h"

Resource::Resource(std::string resourcePath, std::string usageDescription,std::string stateName, sf::Texture* texture)  :
resourcePath(resourcePath), usageDescription(usageDescription), stateName(stateName), texture(texture){
    if(!this->texture->loadFromFile(resourcePath)){
        throw("Resource load error: " + stateName + "-" + usageDescription + " path:" + resourcePath);
    }
}

Resource::~Resource() {

}

std::string Resource::toString() {
    std::string app = "";
    app += "State: " + this->stateName;
    app += " Description: " + this->usageDescription;
    app += " Path: " + this->resourcePath;
    return app;
}
