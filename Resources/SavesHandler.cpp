//
// Created by Zheng on 26/12/2020.
//

#include "SavesHandler.h"

SavesHandler::SavesHandler() {
    saveFileExtension = ".cereal";
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

bool SavesHandler::write(Save& save) const {
    if (mkdir("../Saves") != -1)
        std::cout << "Saves Directory created" << std::endl;
    std::stringstream ss;
    ss << savePath << "/" << save.getName() << ".png";
    save.getSaveImage().saveToFile(ss.str());
    save.setImagePath(ss.str());
    ss.str("");
    ss << savePath << "/" << save.getName() << saveFileExtension;
    std::ofstream ofs(ss.str(), std::ios::binary);
    cereal::BinaryOutputArchive archive(ofs);
    archive(save);
    ofs.clear();
    return true;
}

bool SavesHandler::read(const std::string& saveName) {
    std::stringstream ss;
    ss << savePath << "/" << saveName << saveFileExtension;
    std::ifstream ifs(ss.str(), std::ios::binary);
    Save loaded_save;
    if(ifs.is_open()){
        cereal::BinaryInputArchive archive(ifs);
        archive >> loaded_save;
        ifs.close();
        loaded_save.loadSaveImage();
        loadedSaves.insert(std::pair<std::string, Save>(saveName, loaded_save));
        return true;
    }
    return false;
}


