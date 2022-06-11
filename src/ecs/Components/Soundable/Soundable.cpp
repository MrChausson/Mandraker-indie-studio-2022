/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Soundable
*/

#include "Soundable.hpp"
#include "raylib.hpp"

float soundVolume = 1.0f;

Soundable::Soundable(Sound sound)
{
    Raylib::Raylib_encap Raylib_encp;
    Raylib_encp.SetSVolume(sound, soundVolume);
    this->_sound = sound;
}

Soundable::~Soundable()
{
}

void Soundable::playSound()
{
    Raylib::Raylib_encap r;
    if (_playing && !IsSoundPlaying(_sound))
        r.PlayS(this->_sound);
    _playing = false;
}

void Soundable::setSoundPlaying(bool playing)
{
    this->_playing = playing;
}


COMPONENT_TYPES Soundable::getType()
{
    return SOUNDABLE;
}
