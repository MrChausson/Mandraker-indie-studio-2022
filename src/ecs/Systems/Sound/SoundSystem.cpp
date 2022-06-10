/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Sound
*/

#include "SoundSystem.hpp"
#include "../../Components/Soundable/Soundable.hpp"

SoundSystem::SoundSystem()
{  
}

SoundSystem::~SoundSystem()
{
}

void SoundSystem::apply(std::vector<IComponent *> component)
{
    for (auto &component : component) {
        if (component->getType() == SOUNDABLE) {
            Soundable *soundable = static_cast<Soundable *>(component);
            soundable->playSound();
        }
    }
}

SYSTEM_TYPES SoundSystem::getType()
{
    return SOUND;
}