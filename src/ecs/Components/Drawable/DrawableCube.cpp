/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** DrawableCube
*/

#include "DrawableCube.hpp"

DrawableCube::DrawableCube(Color color, float width, float height, float length)
{
    this->_color = color;
    this->_type = DRAWABLE_TYPE_CUBE;
}

DrawableCube::~DrawableCube()
{
}

void DrawableCube::setColor(Color color)
{
    this->_color = color;
}

Color DrawableCube::getColor()
{
    return this->_color;
}

void DrawableCube::setWidth(float width)
{
    this->_width = width;
}

void DrawableCube::setHeight(float height)
{
    this->_height = height;
}

void DrawableCube::setLength(float length)
{
    this->_length = length;
}

float DrawableCube::getWidth()
{
    return this->_width;
}

float DrawableCube::getHeight()
{
    return this->_height;
}

float DrawableCube::getLength()
{
    return this->_length;
}
