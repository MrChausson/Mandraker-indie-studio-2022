/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** ISystem
*/

#ifndef ISYSTEM_HPP_
#define ISYSTEM_HPP_

#include <vector> 
#include "raylib.h"
#include "../IComponent/IComponent.hpp"
#include "../Components/Hoverable/Hoverable.hpp"
#include "../Components/Drawable/DrawableSprite.hpp"

enum SYSTEM_TYPES {
    GRAVITY,
    DRAW,
    BOUND,
    MOUSE_HOVER,
    MOUSE_CLICK,
    MOVE,
    MUSIC,
    ANIMATION,
    LOADING,
    BOMBER,
    PLAYER,
    SOUND,
    TIMER,
    SAVE,
    FINISH
};

enum GAMEPAD_BUTTON {
    BUTTON_ZERO,
    BUTTON_UP,
    BUTTON_RIGHT,
    BUTTON_DOWN,
    BUTTON_LEFT,
    BUTTON_Y,
    BUTTON_B,
    BUTTON_A,
    BUTTON_X,
    BUTTON_LB,
    BUTTON_RB,
    BUTTON_SELECT,
    BUTTON_NONE,
    BUTTON_START,
    BUTTON_L3,
    BUTTON_R3
};

class ISystem {
    public:
        ISystem() = default;
        ~ISystem() = default;
        virtual void apply(std::vector<IComponent *> component) = 0;
        virtual SYSTEM_TYPES getType() = 0;
};

#endif /* !ISYSTEM_HPP_ */
