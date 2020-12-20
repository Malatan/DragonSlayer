//
// Created by Zheng on 23/10/2020.
//

#include "SpellTab.h"

void SpellTab::initSpellSlots() {
    //init spellslots
    if(!spellSlots.empty()){
        spellSlots.clear();
    }

    int max_per_row = 3;
    float modifierX = 375.f;
    float modifierY = 170.f;
    float yMultiplier = 0;
    int count = 0;
    for(const auto& i : spellComponent->getPlayerSpells()){
        if(i->isLearned()){
            if((count % max_per_row) == 0 && count != 0){
                yMultiplier ++;
            }
            spellSlots.push_back(std::make_shared<gui::SpellSlot>(350.f, 150.f,
                    container.getPosition().x + 35.f + (modifierX * (float)(count % max_per_row)),
                    container.getPosition().y + 80.f + (modifierY * yMultiplier) ,
                    i, &textures["ITEMS_SHEET"], 34.f, font, 18
            ));
            count++;
        }
    }
}

SpellTab::SpellTab(const std::shared_ptr<sf::RenderWindow>& window, sf::Font* font, std::shared_ptr<Player> player, State *state,
                   std::shared_ptr<ResourcesHandler> rsHandler, std::map<std::string, sf::Texture> textures) : window(window),
                   font(font), player(std::move(player)), rsHandler(std::move(rsHandler)), textures(std::move(std::move(textures))){
    gState = dynamic_cast<GameState*>(state);
    spellComponent = gState->getSpellComponent();

    //init background
    background.setSize(sf::Vector2f(
            static_cast<float>(window->getSize().x),
            static_cast<float>(window->getSize().y)));
    background.setFillColor(sf::Color(20, 20, 20, 100));

    //init container
    container.setSize(sf::Vector2f(1170.f,820.f));
    container.setFillColor(sf::Color(20, 20, 20, 200));

    container.setPosition(sf::Vector2f(
            static_cast<float>(window->getSize().x) / 2.f - container.getSize().x / 2.f,
            40.f));

    //init text
    containerTitle.setFont(*this->font);
    containerTitle.setFillColor(sf::Color(255, 255, 255, 200));
    containerTitle.setCharacterSize(40);
    containerTitle.setString("Spells");
    containerTitle.setPosition(
            container.getPosition().x + (container.getGlobalBounds().width/2.f) - (containerTitle.getGlobalBounds().width/2.f),
            container.getPosition().y + 10.f);

    infoLbl.setFont(*this->font);
    infoLbl.setCharacterSize(20);
    infoLbl.setPosition(
            container.getPosition().x + 35.f,
            container.getPosition().y + 35.f);
    //inits
    initSpellSlots();
    updateSpellsInfoLbl();
}

SpellTab::~SpellTab() = default;

bool SpellTab::closeTabByClicking(const sf::Vector2f& mousePos, gui::Button* spellTab_Btn) {
    return sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
           background.getGlobalBounds().contains(mousePos)
           && !container.getGlobalBounds().contains(mousePos) && !spellTab_Btn->contains(mousePos);
}

void SpellTab::updateInputs() {
    if((sf::Keyboard::isKeyPressed(sf::Keyboard::P) || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) &&
            gState->getKeyTime()){
        gState->changeStato(NO_TAB);
    }
}

void SpellTab::updateSpellsInfoLbl() {
    std::stringstream ss;
    ss << std::fixed << std::setprecision(1) << player->getPlayerStats()->getSpellDmgMultiplier();
    dmgMultiplier = ss.str();
    infoLbl.clear();
    infoLbl << "Spell damage x " << dmgMultiplier << " (Wisdom/10)";

    for(const auto& i : spellSlots){
        switch(i->getSpell()->getTypeEnum()){
            case HOLY:
                (i->getSpellInfoLbl())->clear();
                *(i->getSpellInfoLbl()) << sf::Text::Bold << i->getSpell()->getName() << "(Lv." << to_string(i->getSpell()->getLevel()) << ")\n"
                << sf::Text::Regular << "Effect: ";
                if(i->getSpell()->getName() == "Cleanse"){
                    *(i->getSpellInfoLbl()) << sf::Color::White << "Remove all debuffs";
                } else if(i->getSpell()->getName() == "Heal"){
                    *(i->getSpellInfoLbl()) << sf::Color::Red << to_string(i->getSpell()->getFinalDamage())
                    << " x "<< dmgMultiplier << " = "
                    << to_string((int)((float)i->getSpell()->getFinalDamage()*player->getPlayerStats()->getSpellDmgMultiplier()))
                    << " hp";
                } else if(i->getSpell()->getName() == "Meditation"){
                    *(i->getSpellInfoLbl()) << sf::Color::Blue << to_string(i->getSpell()->getFinalDamage())
                    << " x "<< dmgMultiplier << " = "
                    << to_string((int)((float)i->getSpell()->getFinalDamage()*player->getPlayerStats()->getSpellDmgMultiplier()))
                    << " mp";
                }
                *(i->getSpellInfoLbl())<< "\n" << sf::Color::White
                << "Cost: " << sf::Color::Blue << to_string(i->getSpell()->getFinalCost()) << " mp" << sf::Color::White
                << "\nCooldown: " << to_string(i->getSpell()->getCooldown()) << " turn/s";
                break;
            default:
                (i->getSpellInfoLbl())->clear();
                *(i->getSpellInfoLbl()) << sf::Text::Bold << i->getSpell()->getName() << "(Lv." << to_string(i->getSpell()->getLevel()) << ")\n"
                << sf::Text::Regular << "Damage: " << sf::Color(255, 60, 31) << to_string(i->getSpell()->getFinalDamage())
                << " x "<< dmgMultiplier << " = " << to_string((int)((float)i->getSpell()->getFinalDamage()*player->getPlayerStats()->getSpellDmgMultiplier()))
                << "\n" << sf::Color::White
                << "Cost: " << sf::Color::Blue << to_string(i->getSpell()->getFinalCost()) << " mp" << sf::Color::White
                << "\nCooldown: " << to_string(i->getSpell()->getCooldown()) << " turn/s"
                << "\nAoe: " << to_string(i->getSpell()->getAoe()) << " target/s";
                break;
        }

    }
}

void SpellTab::update(const sf::Vector2f &mousePos) {
    updateInputs();
}

void SpellTab::render(sf::RenderTarget &target) {
    target.draw(background);
    target.draw(container);
    target.draw(containerTitle);
    target.draw(infoLbl);
    for(const auto& i : spellSlots){
        i->render(target);
    }
}






