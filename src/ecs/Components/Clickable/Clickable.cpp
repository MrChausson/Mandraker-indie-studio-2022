/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Clickable
*/

#include "Clickable.hpp"

Clickable::Clickable(Entity *entity, Texture2D texture, ECSManager *ecsToChangeTo)
{
    Drawable *test = static_cast<Drawable *>(entity->getComponentsByType(DRAWABLE));
    this->_type = CLICKABLE;
    this->_isClicked = false;
    this->_bounds = {static_cast<float>(test->getX()), static_cast<float>(test->getY()), static_cast<float>(texture.width), static_cast<float>(texture.height)};
    this->_textureClick = texture;
    this->_tmpEcs = ecsToChangeTo;
}

Clickable::~Clickable()
{
}

void Clickable::setBound(float x, float y)
{
    this->_bounds = {x, y,this->_bounds.width, this->_bounds.height};
}

bool Clickable::isClicked(Vector2 mouse, bool pressed)
{
    bool res = CheckCollisionPointRec(mouse, this->_bounds);
    if (res && pressed)
        return (true);
    else
        return (false);
}

bool Clickable::changedState(Vector2 mouse, bool pressed)
{
    bool res = this->_isClicked;

    if (this->isClicked(mouse, pressed))
        this->_isClicked = true;
    else
        this->_isClicked = false;
    return (res != this->_isClicked);
}

Rectangle Clickable::getBound()
{
    return this->_bounds;
}

Texture2D Clickable::getTexture()
{
    return this->_textureClick;
}

void Clickable::setTexture(Texture2D texture)
{
    this->_textureClick = texture;
}

COMPONENT_TYPES Clickable::getType()
{
    return (CLICKABLE);
}

ECSManager *Clickable::getEcs()
{
    return (this->_ecsToChangeTo);
}

void Clickable::setEcs(ECSManager *ecs)
{
    this->_ecsToChangeTo = ecs;
}
