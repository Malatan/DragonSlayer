//
// Created by Zheng on 26/12/2020.
//

#ifndef DRAGONSLAYER_SAVESHANDLER_H
#define DRAGONSLAYER_SAVESHANDLER_H

#include <sys/stat.h>
#include <sys/types.h>
#include "../Game/Save.h"

class Save;

class SavesHandler {
public:
    SavesHandler();
    virtual ~SavesHandler();

    bool write(Save& save);
    Save read();
};

namespace boost {
    namespace serialization {
        template<class Archive>
        void serialize(Archive & ar, sf::Vector2f& v, const unsigned int version){
            ar & v.x;
            ar & v.y;
        }

    } // namespace serialization
} // namespace boost


#endif //DRAGONSLAYER_SAVESHANDLER_H
