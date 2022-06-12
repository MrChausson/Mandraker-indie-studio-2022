/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Animable
*/

#ifndef ANIMABLE_HPP_
#define ANIMABLE_HPP_

#include "raylib.h"
#include "../../IComponent/IComponent.hpp"
#include <string>

enum ANIMATION_TYPE {
    IDLE,
    RUN,
    FALL,
    LOST,
    WON
};

class Animable : public IComponent {
    public:
        Animable(std::string pathToFile, ANIMATION_TYPE animationType);
        ~Animable();
        COMPONENT_TYPES getType() override { return ANIMABLE; };
        void setAnimFrame(int frame);
        int getAnimFrame();
        void setAnimFrameCounter(int frame);
        int getAnimFrameCounter();
        ModelAnimation *getAnims();
        void setAnimationType(ANIMATION_TYPE animationType);
        int getAnimationType();
        std::string getPathToFile();

    protected:
    private:
        std::string _pathToFile;
        ModelAnimation *_anims;
        int _animFrameCounter = 0;
        unsigned int _animsCount = 0;
        ANIMATION_TYPE _animationType;
};

#endif /* !ANIMABLE_HPP_ */
