/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** ECSManager
*/

#include "raylib.h"
#include "ECSManager.hpp"
#include "../Components/Loadable/Loadable.hpp"
#include "../../Engine/Engine.hpp"
#include <iostream>
#include "../Components/Clickable/Clickable.hpp"

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


IComponent *ECSManager::getComponent(Entity *entity, COMPONENT_TYPES type)
{
    for (auto &component : entity->getComponents())
        if (component->getType() == type)
            return (component);
    return nullptr;
}

ECSManager *ECSManager::applySystems()
{
    int i = 0;
    std::vector<IComponent *> components; // Let's create a vector that will store all the needed components by the system

    BeginDrawing();
    ClearBackground(BLACK);
    for (auto &system : this->_systems)
        for (auto &entity : this->_entities)
            for (auto &component : entity.get()->getComponents()) {
                components.clear();
                if (system->getType() == GRAVITY && component->getType() == PLACABLE) {
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
                    Clickable *click = static_cast<Clickable *>(component);
                    ECSManager *ecs = click->getEcs();
                    if (ecs != nullptr)
                        return ecs;
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
                else if (system->getType() == ANIMATION && component->getType() == ANIMABLE) {
                    components.push_back(component);
                    components.push_back(entity->getComponentsByType(DRAWABLE));
                    system->apply(components);
                }
                else if (system->getType() == LOADING && component->getType() == LOADABLE) {
                    components.push_back(component);
                    components.push_back(entity->getComponentsByType(PLACABLE));
                    system->apply(components);
                    Loadable *load = static_cast<Loadable *>(component);
                    if (load->isLoaded())
                        return load->getEcs();
                }
                if (!loop_status)
                    return nullptr;
            }

    this->applyDraw();

    return (nullptr);
}


void ECSManager::applyDraw()
{
    int current_plan = 0;
    bool found = true;
    ISystem *system = this->getSystemByType(DRAW);
    std::vector<IComponent *> components;
    Drawable *draw;
    Placable *place;
    IComponent *camera;

    for (; found == true; current_plan++) {
        found = false;

        for (auto &entity : this->_entities) {
            components.clear();
            draw = static_cast<Drawable *>(entity->getComponentsByType(DRAWABLE));
            if (draw != nullptr && (draw->getPlan() == current_plan ||
            draw->getComponentType() == DRAWABLE_TYPE_CUBE || draw->getComponentType() == DRAWABLE_TYPE_TEXTURE_CUBE )) {
                place = static_cast<Placable *>(entity->getComponentsByType(PLACABLE));
                if (!(draw->getComponentType() == DRAWABLE_TYPE_CUBE || draw->getComponentType() == DRAWABLE_TYPE_TEXTURE_CUBE))
                    found = true;
                components.push_back(place);
                components.push_back(draw);
                camera = this->getCamera();
                if (camera != nullptr)
                    components.push_back(camera);
                system->apply(components);
            }
        }
    }
    EndDrawing();
}

ISystem *ECSManager::getSystemByType(SYSTEM_TYPES type)
{
    std::vector<IComponent *> components;
    for (auto &system : this->_systems)
        if (system->getType() == type)
            return(system.get());
    return nullptr;
}

IComponent *ECSManager::getCamera()
{
    for (auto &entity : this->_entities)
        for (auto &component : entity->getComponents())
            if (component->getType() == CAMERA)
                return (component);
    return nullptr;
}

void ECSManager::setScene(void *scene)
{
    this->_scene = scene;
}

void ECSManager::deleteScene()
{
    delete static_cast<Scene *>(this->_scene);
}

void *ECSManager::getScene()
{
    return (this->_scene);
}