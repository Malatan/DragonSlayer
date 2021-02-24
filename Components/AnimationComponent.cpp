//
// Created by Zheng on 07/10/2020.
//

#include "AnimationComponent.h"
#include <iostream>
AnimationComponent::AnimationComponent(sf::Sprite &sprite, sf::Texture &texture_sheet)
        : sprite(sprite), textureSheet(texture_sheet){
}

AnimationComponent::~AnimationComponent() = default;

//functions
void AnimationComponent::addAnimation(const std::string& key,float animation_timer,
                                      int start_frame_x, int start_frame_y,
                                      int frames_x, int frames_y,
                                      int width, int height) {
    animations[key] = std::make_shared<Animation>(
            sprite, textureSheet,
            animation_timer,
            start_frame_x, start_frame_y, frames_x ,frames_y,
            width, height);
}

const bool& AnimationComponent::play(const std::string& key, const float &dt, bool resetStartRect) {
    animations[key]->play(dt, resetStartRect);
    return animations[key]->isDone();
}

float AnimationComponent::getWalkWidth(){
    return (float)animations.at("WALK")->width;
}