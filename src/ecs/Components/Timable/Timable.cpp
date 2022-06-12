/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Timable
*/

#include "Timable.hpp"


Timable::Timable(float timer, TIMABLE_TYPE time_type, int id_entiy, void *playable)
{
    this->_timer = timer;
    this->_clock = std::chrono::system_clock::now();
    this->_time_type = time_type;
    this->_id_entity = id_entiy;
    this->_playable = playable;
}

Timable::~Timable()
{
}

int Timable::getTimeLeft()
{
    return (this->_timer - this->getElapsedSeconds().count());
}

std::chrono::duration<double> Timable::getElapsedSeconds()
{
    return (std::chrono::system_clock::now() - this->_clock);
}

void Timable::RestartClock()
{
    this->_clock = std::chrono::system_clock::now();;
}

bool Timable::isTimeOut()
{
    return (this->getElapsedSeconds().count() >= this->_timer);
}

TIMABLE_TYPE Timable::getTimeType()
{
    return (this->_time_type);
}

int Timable::getIdEntity()
{
    return (this->_id_entity);
}

void Timable::setFinished(bool finished)
{
    this->_finished = finished;
}

bool Timable::isFinished()
{
    return (this->_finished);
}

void *Timable::getPlayable()
{
    return (this->_playable);
}

void Timable::setTimer(float timer)
{
    this->_timer = timer;
}

float Timable::getTimer()
{
    return (this->_timer);
}

void Timable::setTimeType(TIMABLE_TYPE time_type)
{
    this->_time_type = time_type;
}