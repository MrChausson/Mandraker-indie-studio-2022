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

enum class IA_ACTION{
    IA_MOVE,
    IA_STAY,
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
        void setstartIAclock();
        void setEndIAclock();
        void setTimedurationIAclock();
        void restartTimedurationIAclock();
        std::chrono::time_point<std::chrono::system_clock> getStartIA();
        std::chrono::time_point<std::chrono::system_clock> getEndIA();
        std::chrono::duration<double> getTimedurationIA();
        void setIAActionType(IA_ACTION action);
        IA_ACTION getIAActionType();

    protected:
    private:
        float _speed = 1;
        MOVABLE_TYPE _type;
        IA_ACTION _action_type;
        std::chrono::time_point<std::chrono::system_clock> _clock;
        std::chrono::time_point<std::chrono::system_clock> _start;
        std::chrono::time_point<std::chrono::system_clock>  _end;
        std::chrono::duration<double> timeduration;
};

#endif /* !MOVABLE_HPP_ */
