/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Placable
*/

#include "Placable.hpp"

Placable::Placable(float x, float y, float z, Vector3 rotationAxis, float rotationAngle, Vector3 scale)
{
    this->_x = x;
    this->_y = y;
    this->_z = z;
    this->_rotationAxis = rotationAxis;
    this->_rotationAngle = rotationAngle;
    this->_scale = scale;
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
    Vector3 position = {this->_x, this->_y, this->_z};
    return {position};
}

void Placable::setRotationAxis(Vector3 rotationAxis)
{
    this->_rotationAxis = rotationAxis;
}

Vector3 Placable::getRotationAxis()
{
    return this->_rotationAxis;
}

void Placable::setRotationAngle(float rotationAngle)
{
    this->_rotationAngle = rotationAngle;
}

float Placable::getRotationAngle()
{
    return this->_rotationAngle;
}

void Placable::setScale(Vector3 scale)
{
    this->_scale = scale;
}

Vector3 Placable::getScale()
{
    return this->_scale;
}
