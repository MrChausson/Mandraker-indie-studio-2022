/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** DrawablePlane
*/

#include "DrawablePlane.hpp"

DrawablePlane::DrawablePlane(Vector2 size, Color color)
{
    this->_size = size;
    this->_color = color;
    this->_type = DRAWABLE_TYPE_PLANE;
}

DrawablePlane::~DrawablePlane()
{
}

Color DrawablePlane::getColor()
{
    return this->_color;
}

Vector2 DrawablePlane::getSize()
{
    return this->_size;
}
