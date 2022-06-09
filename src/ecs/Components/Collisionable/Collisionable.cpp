/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Collisionable
*/

#include "Collisionable.hpp"

Collisionable::Collisionable(std::vector<Entity *> *entities)
{
    this->_entities = entities;
}

Collisionable::~Collisionable()
{
}

COMPONENT_TYPES Collisionable::getType()
{
    return COLLISIONABLE;
}

bool Collisionable::isColliding(Model model)
{
    for (auto &entity : *this->_entities) {
        auto model_map = static_cast<DrawableModel *> (entity->getComponentsByType(COMPONENT_TYPES::DRAWABLE));
        if (CheckCollisionBoxes(GetModelBoundingBox(model), GetModelBoundingBox(model_map->getModel())))
            return true;
    }
    return (false);
}

void Collisionable::setEntities(std::vector<Entity *> *entities)
{
    this->_entities = entities;
}