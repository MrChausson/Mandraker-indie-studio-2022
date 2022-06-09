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

bool Collisionable::isColliding(float x, float y)
{

    //bool CheckCollisionSpheres(Vector3 center1, float radius1, Vector3 center2, float radius2); 
    Vector3 center1 = {x, 0.0, y};
    float radius1 = 0.4;
    Vector3 center2 = {0, 0.0, 0.5};
    float radius2 = 0.25;
    for (auto &entity : *this->_entities) {
        auto placeMap = static_cast<Placable *> (entity->getComponentsByType(COMPONENT_TYPES::PLACABLE));
        center2.x = placeMap->getX();
        center2.z = placeMap->getZ();
        if (CheckCollisionSpheres(center1, radius1, center2, radius2))
            return true;
    }
    return (false);
}

void Collisionable::setEntities(std::vector<Entity *> *entities)
{
    this->_entities = entities;
}