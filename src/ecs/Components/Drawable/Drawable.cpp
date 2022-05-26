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

Drawable::Drawable(int plan, int x, int y)
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

void Drawable::setX(int x)
{
    this->_x = x;
}

int Drawable::getX()
{
    return this->_x;
}

void Drawable::setY(int y)
{
    this->_y = y;
}

int Drawable::getY()
{
    return this->_y;
}