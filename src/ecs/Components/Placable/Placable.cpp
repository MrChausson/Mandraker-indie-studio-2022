/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Placable
*/

#include "Placable.hpp"

Placable::Placable(TYPE type)
{
    this->_type = type;
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
