//
// Created by Zheng on 26/12/2020.
//

#include "SavesHandler.h"

SavesHandler::SavesHandler() {
    savePath = "../Saves";
    maxSaves = 5;
}

SavesHandler::~SavesHandler() = default;

Save* SavesHandler::getSave(const std::string& key) {
    return &(loadedSaves[key]);
}

std::map<std::string, Save>& SavesHandler::getLoadedSaves() {
    return loadedSaves;
}

void SavesHandler::clear() {
    if(!loadedSaves.empty())
        loadedSaves.clear();
}

bool SavesHandler::write(Save& save) {
    if (mkdir("../Saves") != -1)
        std::cout << "Saves Directory created" << std::endl;
    std::stringstream ss;
    ss << savePath << "/" << save.getName() << ".dat";
    std::ofstream ofs(ss.str());
    boost::archive::text_oarchive oa(ofs);
    oa << save;
    ofs.clear();
    return true;
}

bool SavesHandler::read(const std::string& saveName) {
    std::stringstream ss;
    ss << savePath << "/" << saveName << ".dat";
    std::ifstream ifs(ss.str());
    Save loaded_save;
    if(ifs.is_open()){
        boost::archive::text_iarchive ia(ifs);
        ia >> loaded_save;
        ifs.close();
        loadedSaves.insert(std::pair<std::string, Save>(saveName, loaded_save));
        return true;
    }
    return false;
}


