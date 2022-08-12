/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Hoverable
*/

#include "Hoverable.hpp"
#include "raylib.hpp"
#include "../Placable/Placable.hpp"

Hoverable::Hoverable(Entity *entity, Texture2D texture)
{
    Placable *test = static_cast<Placable *>(entity->getComponentsByType(PLACABLE));
    this->_type = HOVERABLE;
    this->_isHovered = false;
    this->_bounds = {static_cast<float>(test->getX()), static_cast<float>(test->getY()), static_cast<float>(texture.width), static_cast<float>(texture.height)};
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
    Raylib::Raylib_encap Raylib_encp;
    bool res = Raylib_encp.checkCollPointRec(mouse, this->_bounds);

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
