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
    #include "Chrono/Chrono.hpp"

class Engine {
    public:
        Engine();
        ~Engine();
        void game_loop();
        void getManager(ECSManager *manager);

    protected:
    private:
        bool _loop = true;
        Chrono _chrono;
        std::unique_ptr<ECSManager> _ecsManager;
};

#endif /* !ENGINE_HPP_ */
