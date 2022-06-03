/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Hoverable
*/

#include "Hoverable.hpp"

Hoverable::Hoverable(Texture2D texture)
{
    this->_type = HOVERABLE;
    this->_isHovered = false;
    this->_bounds = {0, 0, static_cast<float>(texture.width), static_cast<float>(texture.height)};
    this->_textureHover = texture;
}

Hoverable::~Hoverable()
{
}

void Hoverable::setBound(float x, float y)
{
    this->_bounds = {x, y,this->_bounds.width, this->_bounds.height};
}

bool Hoverable::isHovered(Vector2 mouse)
{
    bool res = CheckCollisionPointRec(mouse, this->_bounds);
    return (res);
}

bool Hoverable::changedState(Vector2 mouse)
{
    bool res = this->_isHovered;

    if (this->isHovered(mouse))
        this->_isHovered = true;
    else
        this->_isHovered = false;
    return (res != this->_isHovered);
}

Rectangle Hoverable::getBound()
{
    return this->_bounds;
}

Texture2D Hoverable::getTexture()
{
    return this->_textureHover;
}

void Hoverable::setTexture(Texture2D texture)
{
    this->_textureHover = texture;
}

COMPONENT_TYPES Hoverable::getType()
{
    return (HOVERABLE);
}
