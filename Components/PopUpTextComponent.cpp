//
// Created by Zheng on 17/10/2020.
//

#include "PopUpTextComponent.h"

void PopUpTextComponent::initTagTemplates() {
    this->popUpTextTemplates[DEFAULT_TAG] = new PopUpText(this->font, "", 100.f, 100.f, 0.f, -1.f,
            sf::Color::White, 25, 2000.f, true, 200.f, 200.f, 2);

    this->popUpTextTemplates[NEGATIVE_TAG] = new PopUpText(this->font, "", 100.f, 100.f, 0.f, 1.f,
            sf::Color::Red, 25, 2000.f, true, 200.f, 200.f, 1);

    this->popUpTextTemplates[EXPERIENCE_TAG] = new PopUpText(this->font, "", 100.f, 100.f, 0.f, -1.f,
            sf::Color::Green, 30, 2000.f, true, 200.f, 200.f, 2);

    this->popUpTextTemplates[GOLD_TAG] = new PopUpText(this->font, "", 100.f, 100.f, 0.f, -1.f,
            sf::Color::Yellow, 30, 2000.f, true, 200.f, 200.f, 2);

    this->popUpTextTemplates[HEAL_TAG] = new PopUpText(this->font, "", 100.f, 100.f, 0.f, -1.f,
            sf::Color::Red, 30, 2000.f, true, 200.f, 200.f, 2);

    this->popUpTextTemplates[MANA_RESTORE_TAG] = new PopUpText(this->font, "", 100.f, 100.f, 0.f, -1.f,
            sf::Color::Blue, 30, 2000.f, true, 200.f, 200.f, 2);

}

//Constructor / Destructor
PopUpTextComponent::PopUpTextComponent(sf::Font font, sf::Window* window) {
    this->font = font;
    this->window = window;

    this->windowCenter.x =  this->window->getSize().x / 2.f;
    this->windowCenter.y = this->window->getSize().y / 2.f;

    this->initTagTemplates();
}

PopUpTextComponent::~PopUpTextComponent() {
    for (auto i : this->popUpTexts){
        delete i;
    }
    for (auto i : this->popUpTextTemplates){
        delete i.second;
    }
}

//Functions
void PopUpTextComponent::addPopUpText(const unsigned tag_type, const float pos_x, const float pos_y,
        const std::string str, const std::string prefix = "", const std::string postfix = "") {
    std::stringstream ss;
    ss << prefix << " " << str << " " << postfix;
    this->popUpTexts.push_back(new PopUpText(this->popUpTextTemplates[tag_type], pos_x, pos_y, ss.str()));
}

void PopUpTextComponent::addPopUpText(const unsigned tag_type, const float pos_x, const float pos_y,
        const int i, const std::string prefix = "", const std::string postfix = "") {
    std::stringstream ss;
    ss << prefix << " " << i << " " << postfix;
    this->popUpTexts.push_back(new PopUpText(this->popUpTextTemplates[tag_type], pos_x, pos_y, ss.str()));
}

void PopUpTextComponent::addPopUpTextCenter(const unsigned tag_type,
        const std::string str, const std::string prefix = "", const std::string postfix = "") {
    std::stringstream ss;
    ss << prefix << " " << str << " " << postfix;
    this->popUpTexts.push_back(new PopUpText(this->popUpTextTemplates[tag_type],
            this->windowCenter.x, this->windowCenter.y, ss.str()));
}

void PopUpTextComponent::addPopUpTextCenter(const unsigned tag_type,
        const int i, const std::string prefix = "", const std::string postfix = "") {
    std::stringstream ss;
    ss << prefix << " " << i << " " << postfix;
    this->popUpTexts.push_back(new PopUpText(this->popUpTextTemplates[tag_type],
            this->windowCenter.x, this->windowCenter.y, ss.str()));
}

void PopUpTextComponent::update(const float & dt) {
    for (size_t i = 0; i < this->popUpTexts.size(); ++i) {
        this->popUpTexts[i]->update(dt);

        if (this->popUpTexts[i]->isExpired()) {
            delete this->popUpTexts[i];
            this->popUpTexts.erase(this->popUpTexts.begin() + i);
        }
    }
}

void PopUpTextComponent::render(sf::RenderTarget & target) {
    for (auto i : this->popUpTexts) {
        i->render(target);
    }
}