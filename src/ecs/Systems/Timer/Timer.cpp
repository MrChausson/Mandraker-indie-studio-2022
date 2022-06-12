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


Timer::Timer(ECSManager *ecsManager, std::vector<Entity *> *mapEntities)
{
    Raylib::Raylib_encap Raylib_encp;
    this->_ecsManager = ecsManager;
    this->_mapEntities = mapEntities;
}

Timer::~Timer()
{
}

void Timer::apply(std::vector<IComponent *> component)
{
    // Components [0] Timable [1] DrawableText [2] Placable
    Timable *time = static_cast<Timable *>(component[0]);
    Placable *place = static_cast<Placable *>(component[2]);
    DrawableText *text;
    TIMABLE_TYPE time_type = time->getTimeType();
    Playable *playable;

    if (time_type == GAME_CLOCK) {
        text = static_cast<DrawableText *>(component[1]);
        text->setText(std::to_string(time->getTimeLeft()) + "s");
    } else if (time_type == GAME_MANDRAKE) {
        if (time->isTimeOut()) {
            time->setFinished(true);
            playable = static_cast<Playable *>(time->getPlayable());
            playable->setNbMandrake(playable->getNbMandrake() - 1);
            // this->deleteGnome(place->getPosition(), time->getPlayable());
            this->_ecsManager->deleteEntity(time->getIdEntity());
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
    for (auto &entity : *this->_mapEntities) {
        Placable *place = static_cast<Placable *>(entity->getComponentsByType(PLACABLE));
        Breakable *breakable = static_cast<Breakable *>(entity->getComponentsByType(BREAKABLE));
        pos = place->getPosition();
        if (breakable != nullptr && (pos.x - position.x < playable->getRange()/100  || pos.x - position.x > - playable->getRange()/100)) {
            this->_ecsManager->deleteEntity(entity->getId());
            break;
        }
    }
}