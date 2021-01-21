//
// Created by Zheng on 08/12/2020.
//

#include "LootBag.h"

//initializzers
void LootBag::initLootContainer(sf::Vector2f window_size) {
    background.setSize(window_size);
    background.setFillColor(sf::Color(20, 20, 20, 100));

    container.setSize(sf::Vector2f(290.f,570.f));
    container.setFillColor(sf::Color(20, 20, 20, 200));
    container.setPosition(sf::Vector2f(
            window_size.x/2.f - container.getGlobalBounds().width/2.f,
            window_size.y/2.f - container.getGlobalBounds().height/2.f
    ));
    container.setOutlineThickness(5.f);
    container.setOutlineColor(sf::Color(10, 10, 10));

    containerTitleLbl.setFont(*font);
    containerTitleLbl.setFillColor(sf::Color(255, 255, 255, 200));
    containerTitleLbl.setCharacterSize(40);
    containerTitleLbl.setString(to_string(id));
    containerTitleLbl.setPosition(
            container.getPosition().x + (container.getGlobalBounds().width/2.f) -
            (containerTitleLbl.getGlobalBounds().width/2.f),
            container.getPosition().y + 10.f);

    cancelBtn = std::make_unique<gui::Button>(container.getPosition().x,
                            container.getPosition().y + container.getGlobalBounds().height - 80.f,
                            container.getGlobalBounds().width, 80.f, font, "Cancel<Esc>", 25);
    cancelBtn->setIdleTextColor(sf::Color::Black);

    lootAllBtn = std::make_unique<gui::Button>(cancelBtn->getPosition().x,
                             cancelBtn->getPosition().y - 85.f,
                             cancelBtn->getGlobalBounds().width, 80.f, font, "Loot All<R>", 25);
    lootAllBtn->setIdleTextColor(sf::Color::Black);
}

void LootBag::initLootSlots() {
    if(!lootSlots.empty())
        lootSlots.clear();

    int max_per_row = 4;
    float modifierX = 70.f;
    float modifierY = 90.f;
    float yMultiplier = 0;
    for(int i = 0 ; i < loots.size() ; i++){
        if((i % max_per_row) == 0 && i != 0){
            yMultiplier ++;
        }
        lootSlots.push_back(std::make_unique<gui::LootSlot>(60.f, 60.f,
                container.getPosition().x + 10.f + (modifierX * (float)(i % max_per_row)),
                container.getPosition().y + 70.f + (modifierY * yMultiplier),
                font, loots[i], textures["ITEMS_SHEET"]
        ));
    }
}

//constructors/destructor
LootBag::LootBag(const std::shared_ptr<sf::RenderWindow>& window, sf::Vector2f position,
                 std::map<std::string, sf::Texture> textures, std::shared_ptr<Player> player, State* state,
                 std::vector<shared_ptr<Item>> loots, sf::Font* font, int life_time_s, unsigned int id)
                    : textures(std::move(textures)), loots(std::move(loots)), font(font), id(id), player(std::move(player)){
    gState = dynamic_cast<GameState*>(state);
    lifeTime.first = life_time_s/60;
    lifeTime.second = life_time_s - lifeTime.first * 60;
    expired = false;
    sprite.setScale(sf::Vector2f(0.16f, 0.16f));
    sprite.setTexture(this->textures["LOOTBAG_SPRITE"]);
    LootBag::setPosition(position.x, position.y);
    createHitboxComponent(sprite, 0.f, 0.f, 40.f, 40.f);
    createCollisionBoxComponent(sprite, 20.f, 38.f, 10.f);
    collisionBoxComponent->update();

    mergeRange.setSize(sf::Vector2f(this->player->getHitboxComponent()->getGlobalBounds().width * 2.f + 40.f,
                                    this->player->getHitboxComponent()->getGlobalBounds().height * 2.f + 40.f));
    mergeRange.setSize(mergeRange.getSize() * 1.2f);
    mergeRange.setPosition(hitboxComponent->getCenter().x - mergeRange.getGlobalBounds().width/2.f,
                           hitboxComponent->getCenter().y - mergeRange.getGlobalBounds().height/2.f);

    sf::Vector2f center_up_pos = {hitboxComponent->getPosition().x + hitboxComponent->getGlobalBounds().width / 2.f,
                               hitboxComponent->getPosition().y};

    textLbl.setFont(*this->font);
    textLbl.setCharacterSize(15);
    textLbl.setString("Disappears in");
    textLbl.setFillColor(sf::Color(196, 116, 29));
    textLbl.setPosition(center_up_pos.x - textLbl.getGlobalBounds().width / 2.f,
                            center_up_pos.y - 40.f);

    lifeTimeLbl.setFont(*this->font);
    lifeTimeLbl.setCharacterSize(15);
    lifeTimeLbl.setFillColor(sf::Color(196, 116, 29));
    stringstream ss;
    ss << lifeTime.first << " : " << lifeTime.second;
    lifeTimeLbl.setString(ss.str());
    lifeTimeLbl.setPosition(center_up_pos.x - lifeTimeLbl.getGlobalBounds().width / 2.f,
                            textLbl.getPosition().y + lifeTimeLbl.getGlobalBounds().height + 5.f);

    interactIcon.setSize(sf::Vector2f(20.f, 20.f));
    interactIcon.setTexture(&this->textures["CHATTABLE_ICON"]);
    interactIcon.setPosition(center_up_pos.x - interactIcon.getGlobalBounds().width / 2.f,
                             textLbl.getPosition().y - interactIcon.getGlobalBounds().height);
    initLootContainer(sf::Vector2f(window->getSize().x, window->getSize().y));
    sortByItemType();
    initLootSlots();
}

LootBag::~LootBag() = default;

//functions
bool LootBag::canBeRendered(float distance, sf::Vector2f from) {
    sf::Vector2f v_diff = {getPosition().x - from.x, getPosition().y - from.y};
    auto vec_length = (float)sqrt(pow(v_diff.x, 2) + pow(v_diff.y, 2));
    return vec_length <= distance;
}

bool LootBag::lootItem(const std::shared_ptr<Item>& loot_item) {
    if(!player->getInventory()->isFull() ||
       (player->getInventory()->hasItemByName(loot_item->getName()) && loot_item->getUsageType() == CONSUMABLE_USAGE)){
        gState->addItem(loot_item);
        if(loot_item->getUsageType() == CONSUMABLE_USAGE || loot_item->getUsageType() == MATERIAL_USAGE){
            stringstream ss;
            ss << "You got x" << loot_item->getQuantity() << " [" << loot_item->getName() << "]";
            gState->getPopUpTextComponent()->addPopUpTextCenter(
                    DEFAULT_TAG, ss.str(), "", "");
        }else{
            gState->getPopUpTextComponent()->addPopUpTextCenter(
                    DEFAULT_TAG, loot_item->getName(), "You got [", "]");
        }
        return true;
    } else{
        gState->getPopUpTextComponent()->addPopUpTextCenter(
                DEFAULT_TAG, "Your inventory is full!", "", "");
    }
    return false;
}

void LootBag::lootAllItem() {
    if(player->getInventory()->getAvailableSpace() >= loots.size()){
        stringstream ss;
        for(const auto& i : loots){
            gState->addItem(i);
            if(i->getUsageType() == CONSUMABLE_USAGE || i->getUsageType() == MATERIAL_USAGE){
                ss << "You got x" << i->getQuantity() << " [" << i->getName() << "]" << std::endl;
            }else{
                ss << "You got [" << i->getName() << "]" << std::endl;
            }
        }
        loots.clear();
        lootSlots.clear();
        expired = true;
        gState->getPopUpTextComponent()->addPopUpTextCenter(
                DEFAULT_TAG, ss.str(), "", "");
    }else{
        gState->getPopUpTextComponent()->addPopUpTextCenter(
                DEFAULT_TAG, "You don't have enough space for them!", "", "");
    }
}

void LootBag::updateLifeTime(const float &dt) {
    msCounter += dt;
    if(msCounter >= 1.f){
        msCounter = msCounter - 1.f;
        if(lifeTime.second == 0){
            if(lifeTime.first == 0){
                expired = true;
            }else{
                lifeTime.second = 60;
                lifeTime.first--;
            }
        }
        lifeTime.second --;
        updateLifeTimeLbl();
    }
}

void LootBag::updateLifeTimeLbl() {
    stringstream ss;
    ss << lifeTime.first << " : " << lifeTime.second;
    lifeTimeLbl.setString(ss.str());
}

void LootBag::updateButtons() {
    if(cancelBtn->isPressed() && gState->getStateKeyTime()){
        gState->changeStato(NO_TAB);
    }else if(lootAllBtn->isPressed() && gState->getStateKeyTime()){
        lootAllItem();
    }
}

void LootBag::updateInputs() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) && gState->getKeyTime()) {
        lootAllItem();
    } else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || sf::Keyboard::isKeyPressed(sf::Keyboard::E))
                    && gState->getKeyTime()) {
        gState->changeStato(NO_TAB);
    }
}

void LootBag::update(const float &dt) {
    updateLifeTime(dt);
}

void LootBag::render(sf::RenderTarget &target, sf::Shader *shader, sf::Vector2f light_position) {
    collisionBoxComponent->render(target);
    if(shader){
        shader->setUniform("hasTexture", true);
        shader->setUniform("lightPos", light_position);

        target.draw(sprite, shader);
    } else{
        target.draw(sprite);
    }
    target.draw(textLbl);
    target.draw(lifeTimeLbl);
    if(interact)
        target.draw(interactIcon);
}

void LootBag::updatePage(const sf::Vector2f& mousePos) {
    cancelBtn->update(mousePos);
    lootAllBtn->update(mousePos);
    updateButtons();
    updateInputs();
    for(auto &i : lootSlots){
        i->update(mousePos);
        if(i->isPressed() && gState->getStateKeyTime()){
            if(lootItem(i->getItem())){
                //se viene aggiunto nell'inventario allora
                for(size_t j = 0 ; j < loots.size() ; j++){
                    //elimina il loot dalla lista
                    if(loots[j]->getId() == i->getId()){
                        loots.erase(loots.begin() + j);
                        break;
                    }
                }
                if(loots.empty()){
                    expired = true;
                }else{
                    initLootSlots();
                }
                break;
            }
        }
    }
}

void LootBag::renderPage(sf::RenderTarget &target) {
    target.draw(background);
    target.draw(container);
    target.draw(containerTitleLbl);
    cancelBtn->render(target);
    lootAllBtn->render(target);
    for(auto &i : lootSlots){
        i->render(target);
    }
    for(auto &i : lootSlots){
        i->renderInfoContainer(target);
    }
}

//getters
unsigned int LootBag::getId() const {
    return id;
}

void LootBag::canInteract(bool b) {
    interact = b;
}

void LootBag::setPosition(float x, float y) {
    if(hitboxComponent)
        hitboxComponent->setPosition(x, y);
    else
        sprite.setPosition(x, y);
}

bool LootBag::isExpired() const {
    return expired;
}

void LootBag::sortByItemType() {
    sort(loots.begin(),loots.end(),
         [](const std::shared_ptr<Item>& lhs , const std::shared_ptr<Item>& rhs)
         {
             return lhs->sortKeyWord() < rhs->sortKeyWord();
         });
}

bool LootBag::canMerge(sf::FloatRect other_lootbag) {
    return mergeRange.getGlobalBounds().intersects(other_lootbag);
}

void LootBag::mergeLoots(const std::vector<shared_ptr<Item>>& more_loots) {
    if(!more_loots.empty()){
        for(const auto& i : more_loots){
            loots.push_back(i);
        }
        sortByItemType();
        initLootSlots();
    }
}

void LootBag::setLifeTime(int life_time) {
    lifeTime.first = life_time/60;
    lifeTime.second = life_time - lifeTime.first * 60;
}

lifeTimePair LootBag::getLifeTimep() const {
    return lifeTime;
}

void LootBag::setLifeTimep(lifeTimePair ltp) {
    lifeTime = ltp;
}

float LootBag::getMsCounter() const {
    return msCounter;
}

std::vector<shared_ptr<Item>> &LootBag::getLoots() {
    return loots;
}

void LootBag::setMsCounter(float f) {
    msCounter = f;
}

std::string LootBag::toString() const {
    std::stringstream ss;
    ss << "--------------------LootBag " << id << "--------------------" << std::endl;
    ss << "Expired: [" << expired << "]"
            << " LifeTime: [" << lifeTime.first << "]" << "[" << lifeTime.second << "]"
            << " Loots: [" << loots.size() << "]" << std::endl;
    ss << "------------------End-LootBag " << id << "-End------------------" << std::endl;
    return ss.str();
}










