/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Timable
*/

#ifndef TIMABLE_HPP_
#define TIMABLE_HPP_

#include "../../IComponent/IComponent.hpp"
#include <chrono>

enum TIMABLE_TYPE {
    GAME_CLOCK
};

class Timable : public IComponent {
    public:
        Timable(float timer, TIMABLE_TYPE time_type);
        ~Timable();
        COMPONENT_TYPES getType() override { return TIMABLE; };
        std::chrono::duration<double> getElapsedSeconds();
        void RestartClock();
        bool isTimeOut();
        int getTimeLeft();
        TIMABLE_TYPE getTimeType();

    protected:
    private:
        std::chrono::time_point<std::chrono::system_clock> _clock;
        float _timer;
        TIMABLE_TYPE _time_type;
};

#endif /* !TIMABLE_HPP_ */
