/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** ECSManager
*/

#include "ECSManager.hpp"

ECSManager::ECSManager()
{
}

ECSManager::~ECSManager()
{
}

int ECSManager::createEntity()
{
    std::unique_ptr<Entity> entity(new Entity(this->_entities.size()));
    this->_entities.push_back(entity);
    return (entity.get()->getId());
}