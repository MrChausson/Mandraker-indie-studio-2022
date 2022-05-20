/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Entity
*/

#include "Entity.hpp"

Entity::Entity(int id)
{
    this->_id = id;
}

Entity::~Entity()
{
}

std::vector<std::unique_ptr<IComponent>> *Entity::getComponents()
{
    return &this->_components;
}

int Entity::getId()
{
    return this->_id;
}
