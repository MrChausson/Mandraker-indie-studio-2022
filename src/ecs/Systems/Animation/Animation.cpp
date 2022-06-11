/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Animation
*/

#include "Animation.hpp"
#include "raylib.hpp"
#include <iostream>

Animation::Animation()
{
    this->_clock = std::chrono::system_clock::now();
}

Animation::~Animation()
{
}


SYSTEM_TYPES Animation::getType()
{
    return ANIMATION;
}

void Animation::apply(std::vector<IComponent *> component)
{
    Raylib::Raylib_encap Raylib_encp;
    Animable *animable = static_cast<Animable *>(component[0]);
    DrawableModel *model = static_cast<DrawableModel *>(component[1]);
    std::chrono::duration<double> elapsedSecond = std::chrono::system_clock::now() - this->_clock;
    std::cout << "elaps  " << elapsedSecond.count() << std::endl;
    if (elapsedSecond.count() > 0.0003) {
        animable->setAnimFrameCounter(animable->getAnimFrameCounter() + 1);
        this->_clock = std::chrono::system_clock::now();
    }
    Raylib_encp.UpdtModelAnimation(model->getModel(), animable->getAnims()[animable->getAnimationType()], animable->getAnimFrameCounter());
    if (animable->getAnimFrameCounter() >= animable->getAnims()[animable->getAnimationType()].frameCount)
        animable->setAnimFrameCounter(0);
}
