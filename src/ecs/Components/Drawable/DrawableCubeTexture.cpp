/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** DrawableCubeTexture
*/

#include "DrawableCubeTexture.hpp"

DrawableCubeTexture::DrawableCubeTexture(Texture2D texture, float width, float height, float length, Color color)
{
    this->_color = color;
    this->_type = DRAWABLE_TYPE_TEXTURE_CUBE;
    this->_width = width;
    this->_height = height;
    this->_length = length;
    this->_texture = texture;
}

DrawableCubeTexture::~DrawableCubeTexture()
{
}

void DrawableCubeTexture::setColor(Color color)
{
    this->_color = color;
}

Color DrawableCubeTexture::getColor()
{
    return this->_color;
}

void DrawableCubeTexture::setWidth(float width)
{
    this->_width = width;
}

void DrawableCubeTexture::setHeight(float height)
{
    this->_height = height;
}

void DrawableCubeTexture::setLength(float length)
{
    this->_length = length;
}

float DrawableCubeTexture::getWidth()
{
    return this->_width;
}

float DrawableCubeTexture::getHeight()
{
    return this->_height;
}

float DrawableCubeTexture::getLength()
{
    return this->_length;
}

Texture2D DrawableCubeTexture::getTexture()
{
    return this->_texture;
}