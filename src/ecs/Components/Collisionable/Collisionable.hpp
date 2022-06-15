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
#include "../Placable/Placable.hpp"
#include <vector>

class Collisionable : public IComponent {
    public:
        Collisionable();
        ~Collisionable();
        COMPONENT_TYPES getType() override;
        bool isColliding(float x, float y, float z, std::vector<Entity *> *mapEntities);

    protected:
    private:
};

#endif /* !COLLISIONABLE_HPP_ */
