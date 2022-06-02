/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** ECSManager
*/

#include "raylib.h"
#include "ECSManager.hpp"
#include <iostream>

ECSManager::ECSManager()
{
}

ECSManager::~ECSManager()
{
}

void ECSManager::deleteEntity(int id)
{
    bool found = false;
    this->_deletedEntityIds.push_back(id); // adds id to the list of deleted entities
    if (this->_entities[this->_entities.size() - 1].get()->getId() == id)
        this->_entities.pop_back();
    else {
        for (unsigned int i = 0; i < this->_entities.size(); i++)
            if (this->_entities[i].get()->getId() == id) {
                this->_entities.erase(this->_entities.begin() + i);
                found = true;
                break;
            }
        if (!found)
            throw(std::runtime_error("Cannot delete entity with id (not found): " + std::to_string(id)));
    }
}

int ECSManager::createEntity()
{
    int id;
    
    if (this->_deletedEntityIds.size() != 0) {
        id = this->_deletedEntityIds.back();
        this->_deletedEntityIds.pop_back();
    } else 
        id = this->current_id++;
    this->_entities.push_back(std::make_unique<Entity>(id));
    return (id);
}

Entity *ECSManager::getEntity(int id)
{
    for (auto &entity : this->_entities) {
        if (entity.get()->getId() == id)
            return (entity.get());
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

void ECSManager::addSystem(std::unique_ptr<ISystem> system)
{
    this->_systems.push_back(std::move(system));
}


bool ECSManager::entityHasComponent(Entity entity, COMPONENT_TYPES type)
{
    for (auto &component : entity.getComponents())
        if (component->getType() == type)
            return true;
    return false;
}


IComponent *ECSManager::getComponent(std::unique_ptr<Entity> &entity, COMPONENT_TYPES type)
{
    for (auto &component : entity.get()->getComponents())
        if (component->getType() == type)
            return (component);
    return nullptr;
}

void ECSManager::applySystems()
{
    int i = 0;
    BeginDrawing();
    ClearBackground(BLACK);
    std::vector<IComponent *> components; // Let's create a vector that will store all the needed components by the system
    for (auto &system : this->_systems)
        for (auto &entity : this->_entities)
            for (auto &component : entity.get()->getComponents()) {
                components.clear();
                if (system->getType() == GRAVITY && component->getType() == PLACABLE) {
                    components.push_back(component);
                    system->apply(components);
                }
                else if (system->getType() == DRAW && component->getType() == DRAWABLE) {
                    components.push_back(component);
                    system->apply(components);
                }
                else if (system->getType() == MOUSE_HOVER && component->getType() == HOVERABLE) {
                    components.push_back(entity->getComponentsByType(DRAWABLE));
                    components.push_back(component);
                    system->apply(components);
                }
                else if (system->getType() == MOUSE_CLICK && component->getType() == CLICKABLE) {
                    components.push_back(entity->getComponentsByType(DRAWABLE));
                    components.push_back(component);
                    system->apply(components);
                }
                else if (system->getType() == MOVE && component->getType() == MOVABLE) {
                    components.push_back(entity->getComponentsByType(PLACABLE));
                    components.push_back(component);
                    system->apply(components);
                }
                else if (system->getType() == MUSIC && component->getType() == MUSICABLE) {
                    components.push_back(component);
                    system->apply(components);
                }
            }
    EndDrawing();
}
