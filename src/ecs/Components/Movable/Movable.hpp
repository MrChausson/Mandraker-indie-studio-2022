/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Movable
*/

#ifndef MOVABLE_HPP_
#define MOVABLE_HPP_

#include "../../IComponent/IComponent.hpp"
#include <chrono>

enum MOVABLE_TYPE {
    MOVABLE_PLAYER,
    MOVABLE_PLAYER_2,
    MOVABLE_AI
};

class Movable : public IComponent {
    public:
        Movable(float speed = 1, MOVABLE_TYPE type = MOVABLE_AI);
        ~Movable();
        COMPONENT_TYPES getType() override { return MOVABLE; }
        void setSpeed(float speed);
        float getSpeed();
        MOVABLE_TYPE getMovableType();
        std::chrono::duration<double> getElapsedSeconds();
        void RestartClock();

    protected:
    private:
        float _speed = 1;
        MOVABLE_TYPE _type;
        std::chrono::time_point<std::chrono::system_clock> _clock;
};

#endif /* !MOVABLE_HPP_ */
