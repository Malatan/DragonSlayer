//
// Created by Zheng on 26/12/2020.
//

#include "SavesHandler.h"

SavesHandler::SavesHandler() {

}

SavesHandler::~SavesHandler() {

}

bool SavesHandler::write(Save& save) {
    if (mkdir("../Saves") != -1)
        std::cout << "Saves Directory created" << std::endl;
    std::ofstream ofs("../Saves/save001.dat");
    boost::archive::text_oarchive oa(ofs);
    oa << save;
    ofs.clear();
    return true;
}

Save SavesHandler::read() {
    Save read_save;
    std::ifstream ifs("../Saves/save001.dat");
    boost::archive::text_iarchive ia(ifs);
    // Load the data
    ia >> read_save;
    ifs.close();
    return read_save;
}


