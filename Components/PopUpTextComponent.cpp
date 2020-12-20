//
// Created by Zheng on 17/10/2020.
//

#include "PopUpTextComponent.h"

void PopUpTextComponent::initTagTemplates() {
    popUpTextTemplates[DEFAULT_TAG] = std::make_shared<PopUpText>(font, "", 100.f, 100.f, 0.f, -1.f,
            sf::Color::White, 25, 5000.f, true, 100.f, 80.f, 1);

    popUpTextTemplates[NEGATIVE_TAG] = std::make_shared<PopUpText>(font, "", 100.f, 100.f, 0.f, -1.f,
            sf::Color::Red, 25, 2000.f, true, 200.f, 80.f, 1);

    popUpTextTemplates[EXPERIENCE_TAG] = std::make_shared<PopUpText>(font, "", 100.f, 100.f, 0.f, -1.f,
            sf::Color::Green, 30, 2000.f, true, 200.f, 80.f, 2);

    popUpTextTemplates[GOLD_TAG] = std::make_shared<PopUpText>(font, "", 100.f, 100.f, 0.f, -1.f,
            sf::Color::Yellow, 30, 2000.f, true, 200.f, 80.f, 2);

    popUpTextTemplates[HEAL_TAG] = std::make_shared<PopUpText>(font, "", 100.f, 100.f, 0.f, -1.f,
            sf::Color::Red, 30, 2000.f, true, 200.f, 80.f, 2);

    popUpTextTemplates[MANA_RESTORE_TAG] = std::make_shared<PopUpText>(font, "", 100.f, 100.f, 0.f, -1.f,
            sf::Color::Blue, 30, 2000.f, true, 200.f, 80.f, 2);

}

//Constructor / Destructor
PopUpTextComponent::PopUpTextComponent(const sf::Font& font, const std::shared_ptr<sf::RenderWindow>& window) {
    this->font = font;
    this->window = window;

    windowCenter.x = window->getSize().x / 2.f;
    windowCenter.y = window->getSize().y / 2.f;

    initTagTemplates();
}

PopUpTextComponent::~PopUpTextComponent() = default;

//Functions
void PopUpTextComponent::addPopUpText(const unsigned tag_type, const float pos_x, const float pos_y,
        const std::string& str, const std::string& prefix, const std::string& postfix) {
    std::stringstream ss;
    ss << prefix << " " << str << " " << postfix;
    popUpTexts.push_back(std::make_shared<PopUpText>(popUpTextTemplates[tag_type], pos_x, pos_y, ss.str()));
}

void PopUpTextComponent::addPopUpText(const unsigned tag_type, const float pos_x, const float pos_y,
        const int i, const std::string& prefix, const std::string& postfix) {
    std::stringstream ss;
    ss << prefix << " " << i << " " << postfix;
    popUpTexts.push_back(std::make_shared<PopUpText>(popUpTextTemplates[tag_type], pos_x, pos_y, ss.str()));
}

void PopUpTextComponent::addPopUpTextCenter(const unsigned tag_type,
        const std::string& str, const std::string& prefix = "", const std::string& postfix = "") {
    std::stringstream ss;
    ss << prefix << " " << str << " " << postfix;
    popUpTexts.push_back(std::make_shared<PopUpText>(popUpTextTemplates[tag_type],
            windowCenter.x,
            windowCenter.y,
            ss.str()));
}

void PopUpTextComponent::addPopUpTextCenter(const unsigned tag_type,
        const int i, const std::string& prefix = "", const std::string& postfix = "") {
    std::stringstream ss;
    ss << prefix << " " << i << " " << postfix;
    popUpTexts.push_back(std::make_shared<PopUpText>(
            popUpTextTemplates[tag_type],
            windowCenter.x,
            windowCenter.y,
            ss.str()));
}

void PopUpTextComponent::addPopUpTextCenterYShifted(unsigned int tag_type, const std::string &str, const std::string &prefix,
                                                    const std::string &postfix, float y_shift) {
    std::stringstream ss;
    ss << prefix << " " << str << " " << postfix;
    popUpTexts.push_back(std::make_shared<PopUpText>(popUpTextTemplates[tag_type],
                                                     windowCenter.x,
                                                     windowCenter.y + y_shift,
                                                     ss.str()));
}

void PopUpTextComponent::addPopUpTextCenterYShifted(unsigned int tag_type, const int i, const std::string &prefix,
                                                    const std::string &postfix, float y_shift) {
    std::stringstream ss;
    ss << prefix << " " << i << " " << postfix;
    popUpTexts.push_back(std::make_shared<PopUpText>(popUpTextTemplates[tag_type],
                                                     windowCenter.x,
                                                     windowCenter.y + y_shift,
                                                     ss.str()));
}

void PopUpTextComponent::update(const float & dt) {
    for (size_t i = 0; i < popUpTexts.size(); ++i) {
        popUpTexts[i]->update(dt);

        if (popUpTexts[i]->isExpired()) {
            popUpTexts.erase(popUpTexts.begin() + i);
        }
    }
}

void PopUpTextComponent::render(sf::RenderTarget & target) {
    for (const auto& i : popUpTexts) {
        i->render(target);
    }
}


