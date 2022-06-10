/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Movable
*/

#include "Movable.hpp"

Movable::Movable(float speed, MOVABLE_TYPE type)
{
    this->_speed = speed;
    this->_type = type;
    this->_clock = std::chrono::system_clock::now();
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

MOVABLE_TYPE Movable::getMovableType()
{
    return _type;
}

std::chrono::duration<double> Movable::getElapsedSeconds()
{
    return (std::chrono::system_clock::now() - this->_clock);
}

void Movable::RestartClock()
{
    this->_clock = std::chrono::system_clock::now();;
}