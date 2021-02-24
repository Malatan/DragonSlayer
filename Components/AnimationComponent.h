//
// Created by Zheng on 07/10/2020.
//

#ifndef DRAGONSLAYER_ANIMATIONCOMPONENT_H
#define DRAGONSLAYER_ANIMATIONCOMPONENT_H

#include <SFML/Graphics.hpp>
#include <memory>

class AnimationComponent {
public:
    AnimationComponent(sf::Sprite& sprite, sf::Texture& texture_sheet);
    ~AnimationComponent();

    //accessors
    float getWalkWidth();

    //functions
    void addAnimation(const std::string& key,
                      float animation_timer, int start_frame_x,
                      int start_frame_y, int frames_x, int frames_y,
                      int width, int height);

    const bool& play(const std::string& key, const float &dt, bool resetStartRect = true);

private:
    class Animation{
    private:

    public:
        //variables
        sf::Sprite& sprite;
        sf::Texture& textureSheet;
        float animationTimer;
        float timer;
        bool done;
        int width;
        int height;
        sf::IntRect startRect;
        sf::IntRect currentRect;
        sf::IntRect endRect;

        Animation(sf::Sprite& sprite, sf::Texture& texture_sheet,
                  float animation_timer, int start_frame_x, int start_frame_y, int frames_x, int frames_y, int width, int height)
                : sprite(sprite), textureSheet(texture_sheet), animationTimer(animation_timer), timer(0.f), done(false), width(width), height(height){
            startRect = sf::IntRect(start_frame_x * width, start_frame_y * height, width, height);
            currentRect = startRect;
            endRect = sf::IntRect(frames_x * width, frames_y * height, width, height);

            this->sprite.setTexture(this->textureSheet, true);
            this->sprite.setTextureRect(startRect);
        }
        //accessor
        const bool& isDone() const{
            return done;
        }


        //functions
        const bool& play(const float &dt, const bool resetStartRect){
            //update timer
            done = false;
            timer += 100.f * dt;
            if(timer >= animationTimer){
                //reset timer
                timer = 0.f;
                //animate
                if(currentRect != endRect){
                    currentRect.left += width;
                    if(!resetStartRect)
                        sprite.setTextureRect(currentRect);
                } else{  //reset
                    currentRect.left = startRect.left;
                    done = true;
                }
                if(resetStartRect)
                    sprite.setTextureRect(currentRect);
            }

            return done;
        }

        bool play(const float &dt, float mod_percent){ // mod_percent serve a modificare la velocita dell'animazione
            //update timer                                   // esempio: camminata lenta a camminata con max velocita(corsa)
            done = false;
            if(mod_percent < 0.5f){
                mod_percent = 0.5f;
            }
            timer += mod_percent * 100.f * dt;
            if(timer >= animationTimer){
                //reset timer
                timer = 0.f;
                //animate
                if(currentRect != endRect){
                    currentRect.left += width;
                } else{  //reset
                    currentRect.left = startRect.left;
                    done = true;
                }
                sprite.setTextureRect(currentRect);
            }
            return done;
        }

        void reset(){
            timer = animationTimer;
            currentRect = startRect;
        }

    };

    sf::Sprite& sprite;
    sf::Texture& textureSheet;
    std::map<std::string, std::shared_ptr<Animation>> animations;

};

#endif //DRAGONSLAYER_ANIMATIONCOMPONENT_H
