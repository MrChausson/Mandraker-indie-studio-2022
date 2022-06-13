/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Timer.cpp
*/


#include "Timer.hpp"
#include "raylib.hpp"
#include "../../Components/Timable/Timable.hpp"
#include "../../Components/Playable/Playable.hpp"
#include "../../Components/Breakable/Breakable.hpp"
#include "../../Components/Animable/Animable.hpp"


Timer::Timer(ECSManager *ecsManager, std::vector<Entity *> *mapEntities, std::vector<Entity *> *playerEntities)

{
    Raylib::Raylib_encap Raylib_encp;
    this->_ecsManager = ecsManager;
    this->_mapEntities = mapEntities;
    this->_playerEntities = playerEntities;
}

Timer::~Timer()
{
}

void Timer::apply(std::vector<IComponent *> component)
{
    // Components [0] Timable [1] DrawableText [2] Placable [3] Animable [4] Soundable
    Timable *time = static_cast<Timable *>(component[0]);
    Placable *place = static_cast<Placable *>(component[2]);
    Animable *anim = static_cast<Animable *>(component[3]);
    Soundable *sound;
    DrawableText *text;
    TIMABLE_TYPE time_type = time->getTimeType();
    Playable *playable;

    if (time_type == GAME_CLOCK) {
        text = static_cast<DrawableText *>(component[1]);
        text->setText(std::to_string(time->getTimeLeft()) + "s");
    } else if (time_type == GAME_MANDRAKE) {
        if (time->isTimeOut()) {
            time->setTimer(0.2);
            time->RestartClock();
            time->setTimeType(GAME_MANDRAKE_SECOND);
            anim->setAnimationType(ANIMATION_TYPE::RUN);
        }
    } else if  (time_type == GAME_MANDRAKE_SECOND) {
        if (time->isTimeOut()) {
            sound = static_cast<Soundable *>(component[4]);
            if (sound != nullptr)
                sound->stopSound();
            time->setFinished(true);
            playable = static_cast<Playable *>(time->getPlayable());
            playable->setNbMandrake(playable->getNbMandrake() - 1);
            this->updatePlayer(place->getPosition(), time->getPlayable());
            this->deleteGnome(place->getPosition(), time->getPlayable());
            this->_ecsManager->deleteEntity(time->getIdEntity());
        }
    } else if (time_type == GAME_GNOME) {
        if (time->isTimeOut()) {
            time->setFinished(true);
            this->deleteGnome(place->getPosition(), time->getPlayable());
        }
    } else if (time_type == GAME_PLAYER_FALL) {
        if (time->isTimeOut()) {
            time->setFinished(true);
            this->deletePlayer(place->getPosition(), time->getPlayable());
        }
    }
}


SYSTEM_TYPES Timer::getType()
{
    return (TIMER);
}

void Timer::deleteGnome(Vector3 position, void *play)
{
    Vector3 pos;
    Playable *playable = static_cast<Playable *>(play);
    Placable *place;
    Breakable *breakable;
    float range = playable->getRange();
    for (auto &entity : *this->_mapEntities) {
        if (entity->getComponents().size() != 0 && static_cast<Breakable *>(entity->getComponentsByType(BREAKABLE)) != nullptr) {
            place = static_cast<Placable *>(entity->getComponentsByType(PLACABLE));
            pos = place->getPosition();
            if (pos.x - position.x < range && pos.x - position.x > - range && pos.z - position.z < range && pos.z - position.z > - range) {
                this->_ecsManager->getEntity(entity->getId())->clearComponent();
            }
        }
    }
}

void Timer::updateGnome(Vector3 position, void *play)
{
    Vector3 pos;
    Playable *playable = static_cast<Playable *>(play);
    Placable *place;
    Breakable *breakable;
    float range = playable->getRange();
    for (auto &entity : *this->_mapEntities) {
        if (entity->getComponents().size() != 0 && static_cast<Breakable *>(entity->getComponentsByType(BREAKABLE)) != nullptr) {
            place = static_cast<Placable *>(entity->getComponentsByType(PLACABLE));
            pos = place->getPosition();
            if (pos.x - position.x < range && pos.x - position.x > - range && pos.z - position.z < range && pos.z - position.z > - range) {
                this->_ecsManager->addComponent(entity->getId(), std::make_unique<Animable>("assets/models/gnome/gnome.iqm", ANIMATION_TYPE::RUN, 40));
                this->_ecsManager->addComponent(entity->getId(),std::make_unique<Timable>(0.3, GAME_GNOME, -1, playable));
                this->_ecsManager->addComponent(entity->getId(), std::make_unique<Playable>(3));
                this->_ecsManager->addComponent(entity->getId(), std::make_unique<Movable>());
            }
        }
    }
}

void Timer::updatePlayer(Vector3 position, void *play)
{
    Vector3 pos;
    Playable *playable = static_cast<Playable *>(play);
    Placable *place;
    Breakable *breakable;
    float range = playable->getRange();
    for (auto &entity : *this->_playerEntities) {
        if (entity->getComponents().size() != 0 && static_cast<Breakable *>(entity->getComponentsByType(BREAKABLE)) != nullptr) {
            place = static_cast<Placable *>(entity->getComponentsByType(PLACABLE));
            pos = place->getPosition();
            if (pos.x - position.x < range && pos.x - position.x > - range && pos.z - position.z < range && pos.z - position.z > - range) {
                static_cast<Animable *>(entity->getComponentsByType(ANIMABLE))->setAnimationType(ANIMATION_TYPE::FALL);
                entity->addComponent(std::make_unique<Timable>(2, GAME_PLAYER_FALL, -1, playable));
            }
        }
    }
}

void Timer::deletePlayer(Vector3 position, void *play)
{
    Vector3 pos;
    Playable *playable = static_cast<Playable *>(play);
    Placable *place;
    Breakable *breakable;
    float range = playable->getRange();
    for (auto &entity : *this->_playerEntities) {
        if (entity->getComponents().size() != 0 && static_cast<Breakable *>(entity->getComponentsByType(BREAKABLE)) != nullptr) {
            place = static_cast<Placable *>(entity->getComponentsByType(PLACABLE));
            pos = place->getPosition();
            if (pos.x - position.x < range && pos.x - position.x > - range && pos.z - position.z < range && pos.z - position.z > - range) {
                this->_ecsManager->getEntity(entity->getId())->clearComponent();
            }
        }
    }
}


