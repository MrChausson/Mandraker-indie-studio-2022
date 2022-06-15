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

void Movable::setstartIAclock()
{
    this->_start = std::chrono::system_clock::now();
}

void Movable::setEndIAclock()
{
    this->_end = std::chrono::system_clock::now();
}

void Movable::setTimedurationIAclock()
{
    this->timeduration += this->_end - this->_start;
}

std::chrono::time_point<std::chrono::system_clock> Movable::getStartIA()
{
    return this->_start;
}

std::chrono::time_point<std::chrono::system_clock> Movable::getEndIA()
{
    return this->_end;
}

std::chrono::duration<double> Movable::getTimedurationIA()
{
    return this->timeduration;
}

void Movable::restartTimedurationIAclock()
{
    this->timeduration = std::chrono::duration<double> (0);
}

void Movable::setIAActionType(IA_ACTION action)
{
    this->_action_type = action;
}

IA_ACTION Movable::getIAActionType()
{
    return this->_action_type;
}
