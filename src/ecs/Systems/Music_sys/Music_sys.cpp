/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Music_sys
*/

#include "Music_sys.hpp"
#include <iostream>

Music_sys::Music_sys()
{
}

Music_sys::~Music_sys()
{
}

void Music_sys::apply(std::vector<IComponent *> component)
{
    Musicable *musicable = static_cast<Musicable *>(component[0]);

    UpdateMusicStream(musicable->getMusic());
    if (IsKeyPressed(KEY_P))
        musicable->updatePause();
    else if (musicable->isPaused())
        return;
    
}

SYSTEM_TYPES Music_sys::getType()
{
    return (MUSIC);
}