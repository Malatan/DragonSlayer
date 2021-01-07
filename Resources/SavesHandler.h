//
// Created by Zheng on 26/12/2020.
//

#ifndef DRAGONSLAYER_SAVESHANDLER_H
#define DRAGONSLAYER_SAVESHANDLER_H

#include "../Game/Save.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <../includers/CerealHeaders.h>

class Save;

class SavesHandler {
public:
    SavesHandler();
    virtual ~SavesHandler();

    Save* getSave(const std::string& key);
    std::map<std::string, Save>& getLoadedSaves();

    void clear();
    bool write(Save& save) const;
    bool read(const std::string& saveName);

    std::string saveFileExtension;
    std::string savePath;
    int maxSaves;
private:
    std::map<std::string, Save> loadedSaves;
};

#endif //DRAGONSLAYER_SAVESHANDLER_H
