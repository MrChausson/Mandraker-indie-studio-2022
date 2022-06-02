/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Movable
*/

#include "Movable.hpp"

Movable::Movable(float speed)
{
    this->_speed = speed;
}

Movable::~Movable()
{
}

float Movable::getSpeed()
{
    return _speed;
}

void Movable::setSpeed(float speed)
{
    this->_speed = speed;
}
