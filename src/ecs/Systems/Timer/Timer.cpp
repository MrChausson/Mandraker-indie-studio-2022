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


Timer::Timer(ECSManager *ecsManager)
{
    Raylib::Raylib_encap Raylib_encp;
    this->_ecsManager = ecsManager;
}

Timer::~Timer()
{
}

void Timer::apply(std::vector<IComponent *> component)
{
    // Components [0] Timable [1] DrawableText
    Timable *time = static_cast<Timable *>(component[0]);
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
            this->_ecsManager->deleteEntity(time->getIdEntity());
        }
    }
}


SYSTEM_TYPES Timer::getType()
{
    return (TIMER);
}