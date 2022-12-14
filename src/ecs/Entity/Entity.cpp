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
    if (this->_components.size() < 20)
        for (auto &component : this->_components)
            components.push_back(component.get());
    return components;
}


IComponent *Entity::getComponentsByType(COMPONENT_TYPES type)
{
    std::vector<IComponent *> components;
    if (this->_components.size() < 20)
        for (auto &component : this->_components)
            if (component != nullptr && component->getType() == type)
                return(component.get());
    return nullptr;
}

void Entity::clearComponent()
{
    this->_components.clear();
}
