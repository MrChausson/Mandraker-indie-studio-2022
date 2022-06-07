/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Loadable
*/

#include "Loadable.hpp"

Loadable::Loadable(Texture2D texture,Texture2D textureBack,  float rotation, ECSManager *ecs, float second)
{
    this->_texture = texture;
    this->_rotation = rotation;
    this->_textureBack = textureBack;
    this->_ecs = ecs;
    this->_second = second;
}

Loadable::~Loadable()
{
}

COMPONENT_TYPES Loadable::getType()
{
    return LOADABLE;
}

Texture2D Loadable::getTexture()
{
    return this->_texture;
}

Texture2D Loadable::getTextureBack()
{
    return this->_textureBack;
}

void Loadable::setRotation(float rotation)
{
    this->_rotation = rotation;
}


float Loadable::getRotation()
{
    return this->_rotation;
}

bool Loadable::isLoaded()
{
    return this->_isLoaded;
}

void Loadable::setLoaded(bool loaded)
{
    this->_isLoaded = loaded;
}

ECSManager *Loadable::getEcs()
{
    return this->_ecs;
}

float Loadable::getTime()
{
    return this->_second;
}