/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Playable
*/

#include "Playable.hpp"

Playable::Playable(int nbMaxMandrake)
{
    this->_nbMandrakeMax = 1;
    this->_nbMandrake = 0;
    this->_range = 2;
}

Playable::~Playable()
{
}

COMPONENT_TYPES Playable::getType()
{
    return (COMPONENT_TYPES::PLAYABLE);
}

int Playable::getNbMandrake()
{
    return (this->_nbMandrake);
}

int Playable::getNbMaxMandrake()
{
    return (this->_nbMandrakeMax);
}

void Playable::setNbMandrake(int nbMandrake)
{
    this->_nbMandrake = nbMandrake;
}

void Playable::setNbMaxMandrake(int nbMaxMandrake)
{
    this->_nbMandrakeMax = nbMaxMandrake;
}

void Playable::setRange(int range)
{
    this->_range = range;
}

int Playable::getRange()
{
    return (this->_range);
}
