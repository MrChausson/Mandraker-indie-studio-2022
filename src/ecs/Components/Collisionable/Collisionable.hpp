/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Collisionable
*/

#ifndef COLLISIONABLE_HPP_
#define COLLISIONABLE_HPP_

#include "../../IComponent/IComponent.hpp"
#include "../../Entity/Entity.hpp"
#include "../Drawable/DrawableModel.hpp"
#include <vector>

class Collisionable : public IComponent {
    public:
        Collisionable(std::vector<Entity *> *entities = nullptr);
        ~Collisionable();
        COMPONENT_TYPES getType() override;
        bool isColliding(Model model);
        void setEntities(std::vector<Entity *> *entities);

    protected:
    private:
        std::vector<Entity *> *_entities;
};

#endif /* !COLLISIONABLE_HPP_ */
