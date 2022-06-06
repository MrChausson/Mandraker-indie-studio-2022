/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Engine
*/

#ifndef ENGINE_HPP_
    #define ENGINE_HPP_
    #include <iostream>
    #include <chrono>
    #include "../ecs/ECSManager/ECSManager.hpp"
    #include "raylib.h"
    #include "../ecs/Components/Drawable/DrawableText.hpp"
    #include "Chrono/Chrono.hpp"

class Engine {
    public:
        Engine(int fps = 60);
        ~Engine();
        void game_loop();
        void setFps(int fps);
        bool _loop = true;

    protected:
    private:
        Chrono _chrono;
        ECSManager *_currentEcs;
        int _fps;
};

#endif /* !ENGINE_HPP_ */
