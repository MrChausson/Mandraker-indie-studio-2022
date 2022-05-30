/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Boundable
*/

#include "Boundable.hpp"

Boundable::Boundable(float x, float y, float width, float height)
{
    this->_bounds = {x, y, width, height};
    this->_type = BOUNDABLE;
}

Boundable::~Boundable()
{
}


Rectangle Boundable::getBounds()
{
    return this->_bounds;
}

void Boundable::setBounds(float x, float y, float width, float height)
{
    this->_bounds = {x, y, width, height};
}
