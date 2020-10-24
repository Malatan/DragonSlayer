//
// Created by Administrator on 10/10/2020.
//

#include "ResourcesHandler.h"


ResourcesHandler::ResourcesHandler() {

}

ResourcesHandler::~ResourcesHandler() {
    for(auto i : this->resources){
        delete i;
    }
}

bool ResourcesHandler::checkIfKeyExist(std::string key) {
    for(auto i : this->resources){
        if(i->getKey().compare(key) == 0){
            return true;
        }
    }
    return false;
}

bool ResourcesHandler::addResouce(std::string path, std::string key, std::string state_name) {
    for(auto i : this->resources){
        if(i->getKey().compare(key) == 0){
            return false;
        }
    }
    this->resources.push_back(new Resource(path, key, state_name));
    return true;
}

Resource *ResourcesHandler::getResouceByKey(std::string key) {
    for(auto i : this->resources){
        if(i->getKey().compare(key) == 0)
            return i;
    }

    return nullptr;
}

std::string ResourcesHandler::toString() {
    std::string app = "";
    for(auto i : this->resources){
        app += i->toString() + "\n";
    }
    return app;
}

bool ResourcesHandler::loadPlayerStatsTxt(Stats* playerStats) {
    ifstream file;
    file.open("../Data/Stats.txt");
    if (!file.is_open()){
        cout<<"Resource load error: Could not load Stats.txt";
    } else{
        float app;
        file >> app;
        playerStats->setLevel(app);
        file >> app;
        playerStats->setExp(0);
        playerStats->setMaxExp(app);
        file >> app;
        playerStats->setMaxHp(app);
        playerStats->setHp(app);
        file >> app;
        playerStats->setMaxMp(app);
        playerStats->setMp(app);
        file >> app;
        playerStats->setArmor(app);
        file >> app;
        playerStats->setDamage(app);
        file >> app;
        playerStats->setCritChance(app);
        file >> app;
        playerStats->setEvadeChance(app);
        file >> app;
        playerStats->setStrength(app);
        file >> app;
        playerStats->setWisdom(app);
        file >> app;
        playerStats->setAgility(app);
        file >> app;
        playerStats->setFreePoints(app);
    }

    file.close();
    return true;
}

bool ResourcesHandler::loadPlayerInventoryTxt(Inventory *playerInventory) {
    Item* item;
    ifstream file;
    file.open("../Data/Inventory.txt");
    if (!file.is_open()){
        cout<<"Resource load error: Could not load Inventory.txt";
    } else{
        std::string app;
        int count;
        file >> count;
        while(count != 0){
            item = new Item();
            file >> app;
            item->setItemType(app);
            file >> app;
            item->setName(app);
      //      file >> app;
      //      item->setDescription(app);

            file >> app;
            if(app == "'"){
                std::stringstream ss;
                file >> app;
                while(app != "'"){
                    ss << app << " ";
                    file >> app;
                }
                item->setDescription(ss.str());
            }


            file >> app;
            item->setValue(std::stoi(app));
            file >> app;
            item->setRarity(app);

            if(item->getItemType().at(0) != 'C'){
                file >> app;
                item->setHp(std::stoi(app));
                file >> app;
                item->setMp(std::stoi(app));
                file >> app;
                item->setDamage(std::stoi(app));
                file >> app;
                item->setArmor(std::stoi(app));
                file >> app;
                item->setCritChance(std::stof(app));
                file >> app;
                item->setEvadeChance(std::stof(app));

                item->setQuantity(1);
            } else{ // consumable
                file >> app;
                item->setQuantity(std::stoi(app));
            }

            file >> app;
            item->setIconRectX(std::stoi(app));
            file >> app;
            item->setIconRectY(std::stoi(app));

            item->setIsNew(true);
            item->updateUsageType();
            playerInventory->addItem(item);
            count --;
        }

        if(playerInventory->getItemsSize() > 1){
            playerInventory->sortByItemType();
        }
    }
    return true;
}

bool ResourcesHandler::loadSpellList(SpellComponent *spellComponent) {
    Spell* spell;
    ifstream file;
    file.open("../Data/Spells.txt");
    if (!file.is_open()){
        cout<<"Resource load error: Could not load Spells.txt";
    } else{
        std::string app;
        int count;
        file >> count;
        while(count != 0){
            spell = new Spell();
            file >> app;
            std::replace(app.begin(), app.end(), '_', ' '); // replace all '_' to ' '
            spell->setName(app);
            file >> app;
            spell->setType(app);
            file >> app;
            std::replace(app.begin(), app.end(), '_', ' '); // replace all '_' to ' '
            spell->setDescription(app);

            file >> app;
            spell->setCost(std::stoi(app));
            file >> app;
            spell->setCooldown(std::stoi(app));
            file >> app;
            spell->setDamage(std::stoi(app));
            file >> app;
            spell->setAoe(std::stoi(app));

            file >> app;
            spell->setLearned(std::stoi(app));
            file >> app;
            spell->setIntRectX(std::stoi(app));
            file >> app;
            spell->setIntRectY(std::stoi(app));
            spell->setLevel(1);
            spellComponent->addSpell(spell);
            if(spell->isLearned())
                spellComponent->addPlayerSpell(spell);
            count--;
        }
    }
    return false;
}

void ResourcesHandler::setEquipSlotsTextureIntRect(int equip_slot, sf::IntRect intRect) {
    if(equip_slot < 6 && equip_slot >= 0){
        this->equipSlotsTextureIntRects[equip_slot] = intRect;
    }

}

sf::IntRect ResourcesHandler::getEquipSlotTextureRect(int equip_slot) {
    if(equip_slot < 6 && equip_slot >= 0){
        return this->equipSlotsTextureIntRects[equip_slot];
    }
    return sf::IntRect(0, 0, 0, 0);
}






