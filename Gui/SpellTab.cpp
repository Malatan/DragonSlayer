//
// Created by Zheng on 23/10/2020.
//

#include "SpellTab.h"

void SpellTab::initSpellSlots() {
    //init spellslots
    if(this->spellSlots.size() != 0){
        this->spellSlots.clear();
    }

    int max_per_row = 3;
    float modifierX = 375.f;
    float modifierY = 170.f;
    float yMultiplier = 0;
    int count = 0;
    for(auto i : this->spellComponent->getPlayerSpells()){
        if(i->isLearned()){
            if((count % max_per_row) == 0 && count != 0){
                yMultiplier ++;
            }
            this->spellSlots.push_back(new gui::SpellSlot(350.f, 150.f,
                    this->container.getPosition().x + 35.f + (modifierX * (count % max_per_row)),
                    this->container.getPosition().y + 80.f + (modifierY * yMultiplier) ,
                    i, &this->textures["ITEMS_SHEET"], 34.f, this->font, 18
            ));
            count++;
        }
    }
}

SpellTab::SpellTab(std::shared_ptr<sf::RenderWindow> window, sf::Font* font, std::shared_ptr<Player> player, State *state,
                   std::shared_ptr<ResourcesHandler> rsHandler, std::map<std::string, sf::Texture> textures) : window(window),
                   font(font), player(player), rsHandler(rsHandler), textures(textures){
    gState = dynamic_cast<GameState*>(state);
    spellComponent = this->gState->getSpellComponent();

    //init background
    this->background.setSize(sf::Vector2f(
            static_cast<float>(window->getSize().x),
            static_cast<float>(window->getSize().y)));
    this->background.setFillColor(sf::Color(20, 20, 20, 100));

    //init container
    this->container.setSize(sf::Vector2f(1170.f,820.f));
    this->container.setFillColor(sf::Color(20, 20, 20, 200));

    this->container.setPosition(sf::Vector2f(
            static_cast<float>(window->getSize().x) / 2.f - this->container.getSize().x / 2.f,
            40.f));

    //init text
    this->containerTitle.setFont(*this->font);
    this->containerTitle.setFillColor(sf::Color(255, 255, 255, 200));
    this->containerTitle.setCharacterSize(40);
    this->containerTitle.setString("Spells");
    this->containerTitle.setPosition(
            this->container.getPosition().x + (this->container.getGlobalBounds().width/2.f) - (this->containerTitle.getGlobalBounds().width/2.f),
            this->container.getPosition().y + 10.f);

    this->infoLbl.setFont(*this->font);
    this->infoLbl.setCharacterSize(20);
    this->infoLbl.setPosition(
            this->container.getPosition().x + 35.f,
            this->container.getPosition().y + 35.f);
    //inits
    this->initSpellSlots();
    this->updateSpellsInfoLbl();
}

SpellTab::~SpellTab() {
    for(auto i : this->spellSlots){
        delete i;
    }
}

bool SpellTab::closeTabByClicking(const sf::Vector2f& mousePos, gui::Button* spellTab_Btn) {
    return sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
           this->background.getGlobalBounds().contains(mousePos)
           && !this->container.getGlobalBounds().contains(mousePos) && !spellTab_Btn->contains(mousePos);
}

void SpellTab::updateSpellsInfoLbl() {
    std::stringstream ss;
    ss << std::fixed << std::setprecision(1) << this->player->getPlayerStats()->getSpellDmgMultiplier();
    this->dmgMultiplier = ss.str();
    this->infoLbl.clear();
    this->infoLbl << "Spell damage x " << dmgMultiplier << " (Wisdom/10)";

    for(auto i : this->spellSlots){
        switch(i->getSpell()->getTypeEnum()){
            case HOLY:
                (i->getSpellInfoLbl())->clear();
                *(i->getSpellInfoLbl()) << sf::Text::Bold << i->getSpell()->getName() << "(Lv." << to_string(i->getSpell()->getLevel()) << ")\n"
                << sf::Text::Regular << "Effect: " << sf::Color(255, 60, 31) << to_string(i->getSpell()->getFinalDamage())
                << " x "<< this->dmgMultiplier << " = " << to_string((int)(i->getSpell()->getFinalDamage()*this->player->getPlayerStats()->getSpellDmgMultiplier()))
                << "\n" << sf::Color::White
                << "Cost: " << sf::Color::Blue << to_string(i->getSpell()->getFinalCost()) << " mp" << sf::Color::White
                << "\nCooldown: " << to_string(i->getSpell()->getCooldown()) << " turn/s";
                break;
            default:
                (i->getSpellInfoLbl())->clear();
                *(i->getSpellInfoLbl()) << sf::Text::Bold << i->getSpell()->getName() << "(Lv." << to_string(i->getSpell()->getLevel()) << ")\n"
                << sf::Text::Regular << "Damage: " << sf::Color(255, 60, 31) << to_string(i->getSpell()->getFinalDamage())
                << " x "<< this->dmgMultiplier << " = " << to_string((int)(i->getSpell()->getFinalDamage()*this->player->getPlayerStats()->getSpellDmgMultiplier()))
                << "\n" << sf::Color::White
                << "Cost: " << sf::Color::Blue << to_string(i->getSpell()->getFinalCost()) << " mp" << sf::Color::White
                << "\nCooldown: " << to_string(i->getSpell()->getCooldown()) << " turn/s"
                << "\nAoe: " << to_string(i->getSpell()->getAoe()) << " target/s";;
                break;
        }

    }
}

void SpellTab::update(const sf::Vector2f &mousePos) {
}

void SpellTab::render(sf::RenderTarget &target) {
    target.draw(this->background);
    target.draw(this->container);
    target.draw(this->containerTitle);
    target.draw(this->infoLbl);
    for(auto i : this->spellSlots){
        i->render(target);
    }
}




