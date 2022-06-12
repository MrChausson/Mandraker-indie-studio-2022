/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Animable
*/

#include "Animable.hpp"
#include "raylib.hpp"

Animable::Animable(std::string pathToFile, ANIMATION_TYPE animationType)
{
    Raylib::Raylib_encap Raylib_encp;
    this->_anims = Raylib_encp.LoadMAnimations(pathToFile, &this->_animsCount);
    this->_animationType = animationType;
    this->_pathToFile = pathToFile;
}

Animable::~Animable()
{
}

void Animable::setAnimFrame(int frame)
{
    this->_animsCount = frame;
}
int Animable::getAnimFrame()
{
    return this->_animsCount;
}

void Animable::setAnimFrameCounter(int frame)
{
    this->_animFrameCounter = frame;
}
int Animable::getAnimFrameCounter()
{
    return this->_animFrameCounter;
}

ModelAnimation *Animable::getAnims()
{
    return this->_anims;
}

void Animable::setAnimationType(ANIMATION_TYPE animationType)
{
    this->_animationType = animationType;
}

int Animable::getAnimationType()
{
    return this->_animationType;
}

std::string Animable::getPathToFile()
{
    return this->_pathToFile;
}
