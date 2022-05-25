/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Drawable
*/

#include "Drawable.hpp"

Drawable::Drawable()
{
    this->_plan = 0;
}

Drawable::Drawable(int plan)
{
    _plan = plan;
}

Drawable::~Drawable()
{
}

int Drawable::getPlan()
{
    return _plan;
}

void Drawable::setPlan(int plan)
{
    _plan = plan;
}
