/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Collisionable
*/

#include "Collisionable.hpp"
#include "raylib.hpp"

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

bool Collisionable::isColliding(float x, float y, float z)
{

    //bool CheckCollisionSpheres(Vector3 center1, float radius1, Vector3 center2, float radius2); 
    Vector3 min = {x - 0.3f, y, z- 0.2f};
    Vector3 max = {x + 0.2f, y + 1.5f, z + 0.1f  };
    Vector3 min_map;
    Vector3 max_map;
    BoundingBox box = {min, max};
    BoundingBox box_map = {min, max};
    Raylib::Raylib_encap Raylib_encp;

    for (auto &entity : *this->_entities) {
        auto placeMap = static_cast<Placable *> (entity->getComponentsByType(COMPONENT_TYPES::PLACABLE));
        min_map.x = placeMap->getX() - 0.4;
        min_map.y = placeMap->getY();
        min_map.z = placeMap->getZ() - 0.4;
        max_map.x = placeMap->getX() + 0.4;
        max_map.y = placeMap->getY() + 1.5;
        max_map.z = placeMap->getZ() + 0.4;
        box_map = {min_map, max_map};
        if (Raylib_encp.CheckCollBoxes(box, box_map))
            return true;
    }
    return (false);
}

void Collisionable::setEntities(std::vector<Entity *> *entities)
{
    this->_entities = entities;
}