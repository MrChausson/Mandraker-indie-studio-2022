/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Loading
*/

#include "Loading.hpp"
#include <chrono>

Loading::Loading()
{
    this->_clock = std::chrono::system_clock::now();
}

Loading::~Loading()
{
}

void Loading::apply(std::vector<IComponent *> component)
{
    Loadable *loadable = static_cast<Loadable *>(component[0]);
    Placable *placable = static_cast<Placable *>(component[1]);
    Vector2 position = {placable->getX(), placable->getY()};
    std::chrono::duration<double> elapsed_seconds = std::chrono::system_clock::now() - this->_clock;

    DrawTexture(loadable->getTextureBack(), 0, 0, WHITE);
    DrawTextureEx(loadable->getTexture(), position, loadable->getRotation(), 1, WHITE);
    loadable->setRotation(loadable->getRotation() + 1.0f);
    if (elapsed_seconds.count() > loadable->getTime())
        loadable->setLoaded(true);
}

SYSTEM_TYPES Loading::getType()
{
    return LOADING;
}
