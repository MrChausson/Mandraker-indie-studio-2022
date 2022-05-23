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

int Entity::getId()
{
    return this->_id;
}

void Entity::addComponent(std::unique_ptr<IComponent> component)
{
    this->_components.push_back(std::move(component)); 
}

std::vector<IComponent *> Entity::getComponents()
{
    std::vector<IComponent *> components;
    for (auto &component : this->_components)
        components.push_back(component.get());
    return components;
}


template <class T>
T Entity::getComponentsByType(COMPONENT_TYPES type)
{
    std::vector<T> components;
    for (auto &component : this->_components)
        if (component->getType() == type)
            return(static_cast<T>(component.get()));
    return nullptr;
}