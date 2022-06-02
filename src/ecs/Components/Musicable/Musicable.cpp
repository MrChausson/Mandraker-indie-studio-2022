/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Musicable
*/

#include "Musicable.hpp"

Musicable::Musicable(Music music)
{
    _music = music;
    _pause = false;
}

Musicable::~Musicable()
{
    
}

COMPONENT_TYPES Musicable::getType()
{
    return (MUSICABLE);
}

void Musicable::updatePause()
{
    this->_pause = !this->_pause;

    if (this->_pause)
        PauseMusicStream(this->_music);
    else
        ResumeMusicStream(this->_music);
}

bool Musicable::isPaused()
{
    return (this->_pause);
}

Music Musicable::getMusic()
{
    return (this->_music);
}