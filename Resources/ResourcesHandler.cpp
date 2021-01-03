//
// Created by Administrator on 10/10/2020.
//

#include "ResourcesHandler.h"

ResourcesHandler::ResourcesHandler(){
    IdCounter = 1000;
    gameVersion = "1.0.0";
}

ResourcesHandler::~ResourcesHandler() = default;

bool ResourcesHandler::addResource(const std::string& path, const std::string& key, const std::string& state_name) {
    for(const auto& i : resources){
        if(i->getKey() == key){
            return false;
        }
    }
    if(unitTesting){
        std::string new_path = "../" + path;
        resources.push_back(std::make_shared<Resource>(new_path, key, state_name));
    }else{
        resources.push_back(std::make_shared<Resource>(path, key, state_name));
    }
    return true;
}

std::shared_ptr<Resource> ResourcesHandler::getResourceByKey(const std::string& key) {
    for(auto i : resources){
        if(i->getKey() == key)
            return i;
    }

    return nullptr;
}

std::string ResourcesHandler::toString() {
    std::string app;
    for(const auto& i : resources){
        app += i->toString() + "\n";
    }
    return app;
}

void ResourcesHandler::loadPlayerStatsTxt(const std::shared_ptr<Stats>& playerStats) const {
    std::string path;
    if(unitTesting){
        path = "../../Data/Stats.txt";
    }else{
        path = "../Data/Stats.txt";
    }
    std::ifstream file;
    file.open(path);
    if (!file.is_open()){
        std::cerr << "Resource load error: Could not load " << path << std::endl;
    } else{
        float appf;
        int appi;
        file >> appi;
        playerStats->setLevel(appi);
        file >> appi;
        playerStats->setExp(0);
        playerStats->setMaxExp(appi);
        file >> appi;
        playerStats->setMaxHp(appi);
        playerStats->setHp(appi);
        file >> appi;
        playerStats->setMaxMp(appi);
        playerStats->setMp(appi);
        file >> appi;
        playerStats->setArmor(appi);
        file >> appi;
        playerStats->setDamage(appi);
        file >> appf;
        playerStats->setCritChance(appf);
        file >> appf;
        playerStats->setEvadeChance(appf);
        file >> appi;
        playerStats->addAttribute(STRENGTH, appi);
        file >> appi;
        playerStats->addAttribute(WISDOM, appi);
        file >> appi;
        playerStats->addAttribute(AGILITY, appi);
        file >> appi;
        playerStats->setFreePoints(appi);
        file.close();
    }
}

void ResourcesHandler::loadPlayerInventoryTxt(const std::shared_ptr<Inventory>& playerInventory) {
    std::string path;
    if(unitTesting){
        path = "../../Data/Inventory.txt";
    }else{
        path = "../Data/Inventory.txt";
    }
    std::shared_ptr<Item> item;
    std::ifstream file;
    file.open(path);
    if (!file.is_open()){
        std::cout << "Resource load error: Could not load " << path << std::endl;
    } else{
        std::string app;
        while(file.peek() != EOF){
            item = std::make_shared<Item>();
            file >> app;
            item->setItemType(app);
            file >> app;
            std::replace(app.begin(), app.end(), '_', ' ');
            item->setName(app);
            file >> app;
            std::replace(app.begin(), app.end(), '_', ' ');
            item->setDescription(app);
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
            item->setId(generateId());
            playerInventory->addItem(item);
        }

        if(playerInventory->getItemsSize() > 1){
            playerInventory->sortByItemType();
        }
        file.close();
    }
}

void ResourcesHandler::loadSpellList(const std::shared_ptr<SpellComponent>& spellComponent) const {
    std::string path;
    if(unitTesting){
        path = "../../Data/Spells.txt";
    }else{
        path = "../Data/Spells.txt";
    }
    Spell spell;
    ifstream file;
    file.open(path);
    if (!file.is_open()){
        cout<<"Resource load error: Could not load " << path << endl;
    } else{
        std::string app;
        while(file.peek() != EOF){
            spell = Spell();
            file >> app;
            std::replace(app.begin(), app.end(), '_', ' ');
            spell.setName(app);
            file >> app;
            spell.setType(static_cast<spell_type>(std::stoi(app)));
            file >> app;
            std::replace(app.begin(), app.end(), '_', ' ');
            spell.setDescription(app);

            file >> app;
            spell.setCost(std::stoi(app));
            file >> app;
            spell.setCooldown(std::stoi(app));
            file >> app;
            spell.setDamage(std::stoi(app));
            file >> app;
            spell.setAoe(std::stoi(app));

            file >> app;
            spell.setLearned(std::stoi(app));
            file >> app;
            spell.setMaxLevel(std::stoi(app));
            file >> app;
            spell.setLearnCost(std::stoi(app));
            file >> app;
            spell.setIntRectX(std::stoi(app));
            file >> app;
            spell.setIntRectY(std::stoi(app));
            spell.setLevel(1);
            spellComponent->addSpell(spell);
            spellComponent->addPlayerSpell(spell);
        }
        file.close();
    }
}

void ResourcesHandler::loadMaterialsTxt(std::vector<std::unique_ptr<Item>> &material_list) {
    std::unique_ptr<Item> material;
    std::string path;
    if(unitTesting){
        path = "../../Data/Materials.txt";
    }else{
        path = "../Data/Materials.txt";
    }
    ifstream file;
    file.open(path);
    if (!file.is_open()){
        cout<<"Resource load error: Could not load " << path << endl;
    } else {
        std::string app;
        while (file.peek() != EOF) {
            material = std::make_unique<Item>();
            file >> app;
            material->setItemType(app);
            file >> app;
            std::replace(app.begin(), app.end(), '_', ' ');
            material->setName(app);
            file >> app;
            std::replace(app.begin(), app.end(), '_', ' ');
            material->setDescription(app);
            file >> app;
            material->setValue(std::stoi(app));
            file >> app;
            material->setIconRectX(std::stoi(app));
            file >> app;
            material->setIconRectY(std::stoi(app));

            material->setQuantity(1);
            material->setIsNew(true);
            material->updateUsageType();
            material->setId(generateId());
            material_list.push_back(std::move(material));
        }
        file.close();
    }
}

void ResourcesHandler::loadAchievementsTxt(std::vector<std::shared_ptr<Achievement>> &achievement_list) const {
    std::shared_ptr<Achievement> achievement;
    std::string path;
    if(unitTesting){
        path = "../../Data/Achievements.txt";
    }else{
        path = "../Data/Achievements.txt";
    }
    ifstream file;
    file.open(path);
    if (!file.is_open()){
        cout<<"Resource load error: Could not load " << path << endl;
    } else {
        std::string app;
        while (file.peek() != EOF) {
            achievement = std::make_shared<Achievement>();
            file >> app;
            achievement->setAchievementEventType(std::stoi(app));
            file >> app;
            achievement->setSeriesPos(std::stoi(app));
            file >> app;
            std::replace(app.begin(), app.end(), '_', ' ');
            achievement->setName(app);
            file >> app;
            std::replace(app.begin(), app.end(), '_', ' ');
            achievement->setDescription(app);
            file >> app;
            achievement->setGoal(std::stoi(app));

            achievement_list.push_back(std::move(achievement));
        }
        file.close();
    }
}

void ResourcesHandler::setEquipSlotsTextureIntRect(int equip_slot, sf::IntRect intRect) {
    if(equip_slot < 6 && equip_slot >= 0){
        equipSlotsTextureIntRects[equip_slot] = intRect;
    }

}

sf::IntRect ResourcesHandler::getEquipSlotTextureRect(int equip_slot) {
    if(equip_slot < 6 && equip_slot >= 0){
        return equipSlotsTextureIntRects[equip_slot];
    }
    return {0, 0, 0, 0};
}

unsigned int ResourcesHandler::generateId() {
    IdCounter++;
    return IdCounter-1;
}

unsigned int ResourcesHandler::getIdCunter() const {
    return IdCounter;
}

void ResourcesHandler::setIdCounter(unsigned int value) {
    IdCounter = value;
}

std::string ResourcesHandler::getGameVersion() const {
    return gameVersion;
}

void ResourcesHandler::setUnitTesting(bool b) {
    unitTesting = b;
}

bool ResourcesHandler::isUnitTesting() const {
    return unitTesting;
}






