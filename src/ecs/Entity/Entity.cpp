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
    std::cout << "Entity created with id " << this->_id << std::endl;
}

Entity::~Entity()
{
    std::cout << "Entity deleted with id " << this->_id << std::endl;
}

std::vector<std::unique_ptr<IComponent>> *Entity::getComponents()
{
    return &this->_components;
}

int Entity::getId()
{
    return this->_id;
}

void Entity::addComponent(std::unique_ptr<IComponent> component)
{
    this->_components.push_back(std::move(component)); 
}