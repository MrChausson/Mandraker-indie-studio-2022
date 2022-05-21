/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** ECSManager
*/

#include "ECSManager.hpp"
#include <iostream>

ECSManager::ECSManager()
{
}

ECSManager::~ECSManager()
{
}

int ECSManager::createEntity()
{
    // Entity *entity = new Entity(this->_entities.size());
    this->_entities.emplace_back(new Entity(this->_entities.size()));
    return (this->_entities[this->_entities.size() - 1].get()->getId());
}

std::unique_ptr<Entity> ECSManager::getEntity(int id)
{
    for (auto &entity : this->_entities) {
        if (entity.get()->getId() == id)
            return (std::move(entity));
    }
    return nullptr;
}

void ECSManager::addComponent(int entityId, std::unique_ptr<IComponent> component)
{
    for (auto &entity : this->_entities) {
        if (entity.get()->getId() == entityId) {
            entity.get()->addComponent(std::move(component));
            return;
        }
    }
}