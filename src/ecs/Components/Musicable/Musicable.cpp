/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Musicable
*/

#include "Musicable.hpp"
#include "raylib.hpp"

float musicVolume = 0.5f;

Musicable::Musicable(Music music)
{
    Raylib::Raylib_encap Raylib_encp;
    Raylib_encp.SetMVolume(music, musicVolume);
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
    Raylib::Raylib_encap Raylib_encp;
    this->_pause = !this->_pause;

    if (this->_pause)
        Raylib_encp.PauseMStream(this->_music);
    else
        Raylib_encp.ResumeMStream(this->_music);
}

bool Musicable::isPaused()
{
    return (this->_pause);
}

Music Musicable::getMusic()
{
    return (this->_music);
}