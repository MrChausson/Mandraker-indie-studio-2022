/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Placable
*/

#include "Placable.hpp"

Placable::Placable(float x, float y, float z)
{
    this->_x = x;
    this->_y = y;
    this->_z = z;
}

Placable::~Placable()
{
}

void Placable::setX(float x)
{
    this->_x = x;
}

void Placable::setY(float y)
{
    this->_y = y;
}

void Placable::setZ(float z)
{
    this->_z = z;
}

float Placable::getX()
{
    return this->_x;
}

float Placable::getY()
{
    return this->_y;
}

float Placable::getZ()
{
    return this->_z;
}

COMPONENT_TYPES Placable::getType()
{
    return this->_type;
}

Vector3 Placable::getPosition()
{
    return {this->_x, this->_y, this->_z};
}