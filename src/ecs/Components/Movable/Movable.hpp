/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Movable
*/

#ifndef MOVABLE_HPP_
#define MOVABLE_HPP_

#include "../../IComponent/IComponent.hpp"

class Movable : public IComponent {
    public:
        Movable(float speed = 1);
        ~Movable();
        COMPONENT_TYPES getType() override { return MOVABLE; }
        void setSpeed(float speed);
        float getSpeed();

    protected:
    private:
        float _speed = 1;
};

#endif /* !MOVABLE_HPP_ */
