/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Bomber.cpp
*/

#include "Bomber.hpp"

Bomber::Bomber()
{
    this->_toWait = std::chrono::system_clock::now();
}

Bomber::~Bomber()
{
}

void Bomber::apply(std::vector<IComponent *> component)
{
}


SYSTEM_TYPES Bomber::getType()
{
    return (BOMBER);
}