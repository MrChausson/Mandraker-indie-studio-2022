/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Loading
*/

#include "Loading.hpp"
#include "raylib.hpp"
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
    Raylib::Raylib_encap Raylib_encp;
    Loadable *loadable = static_cast<Loadable *>(component[0]);
    Placable *placable = static_cast<Placable *>(component[1]);
    std::chrono::duration<double> elapsed_seconds = std::chrono::system_clock::now() - this->_clock;
    Rectangle src = {0, 0, static_cast<float>(loadable->getTexture().width) , static_cast<float>(loadable->getTexture().height)};
    Rectangle dest = {placable->getX(), placable->getY(), static_cast<float>(loadable->getTexture().width) , static_cast<float>(loadable->getTexture().height)};
    Vector2 origin = {static_cast<float>(loadable->getTexture().width)/2 , static_cast<float>(loadable->getTexture().height)/2 + 10};

    Raylib_encp.DwTexture(loadable->getTextureBack(), 0, 0, WHITE);
    Raylib_encp.DwTexturePro(loadable->getTexture(), src, dest, origin, loadable->getRotation(), WHITE);
    loadable->setRotation(loadable->getRotation() + 1.0f);
    if (elapsed_seconds.count() > loadable->getTime())
        loadable->setLoaded(true);
}

SYSTEM_TYPES Loading::getType()
{
    return LOADING;
}
