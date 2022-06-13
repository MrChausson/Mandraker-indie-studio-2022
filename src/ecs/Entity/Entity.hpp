/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Entity
*/

#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include <vector>
#include <memory>
#include <iostream>
#include "../IComponent/IComponent.hpp"
#include "../../Error.hpp"

class Entity {
    public:
        Entity(int id);
        ~Entity();
        int getId();
        std::vector<IComponent *> getComponents();
        IComponent  *getComponentsByType(COMPONENT_TYPES type);
        void addComponent(std::unique_ptr<IComponent> component);
        void clearComponent();

    protected:
    private:
        std::vector<std::unique_ptr<IComponent>> _components;
        int _id;
};

#endif /* !ENTITY_HPP_ */
