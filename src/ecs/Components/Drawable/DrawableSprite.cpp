/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** DrawableSprite
*/

#include "DrawableSprite.hpp"

DrawableSprite::DrawableSprite(Texture2D texture, int plan , int x, int y)
{
    this->_x = x;
    this->_y = y;
    this->_texture = texture;
    this->_type = DRAWABLE_TYPE_SPRITE;
    this->_bounds = {(float)x, (float)y, (float)texture.width, (float)texture.height};
}

DrawableSprite::~DrawableSprite()
{

}

void DrawableSprite::setTexture(Texture2D texture)
{
    this->_texture = texture;
}

Texture2D DrawableSprite::getTexture()
{
    return this->_texture;
}

Rectangle DrawableSprite::getBounds()
{
    return this->_bounds;
}
