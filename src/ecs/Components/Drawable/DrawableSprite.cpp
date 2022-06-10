/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** DrawableSprite
*/

#include "DrawableSprite.hpp"

DrawableSprite::DrawableSprite(Texture2D texture, int plan)
{
    this->_texture = texture;
    this->_type = DRAWABLE_TYPE_SPRITE;
    this->_plan = plan;
    this->_bounds = {0, 0, (float)texture.width, (float)texture.height};
    this->_selected = false;
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

bool DrawableSprite::isSelected()
{
    return this->_selected;
}

void DrawableSprite::setSelected(bool selected)
{
    this->_selected = selected;
}
