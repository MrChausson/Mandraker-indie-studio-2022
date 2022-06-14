/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Finish.cpp
*/

#include "Finish.hpp"
#include "../../../Scene/Menu/Menu.hpp"
#include "../../../Scene/GameOver/GameOver.hpp"


Finish::Finish(std::vector<Entity *> *playerEntities)
{
    this->_playerEntities = playerEntities;
}

Finish::~Finish()
{
}

void Finish::apply(std::vector<IComponent *> component)
{
}


SYSTEM_TYPES Finish::getType()
{
    return (FINISH);
}

ECSManager *Finish::getEcsManager()
{
    return (this->_ecsManager);
}

bool Finish::isFinished()
{
    int i = 0;
    std::vector<IComponent *> components;
    for (auto &entity : *_playerEntities) {
        components = entity->getComponents();
        if (components.size() == 0)
            i++;
    }
    if (i >= 0) {
        this->_ecsManager = (new GameOver())->getECS();
        return (true);
    } else
        return (false);
}