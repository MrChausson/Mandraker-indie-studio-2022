/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Engine
*/

#include "Engine.hpp"

Engine::Engine(int fps)
{
    this->_ecsManager = std::make_unique<ECSManager>();
    std::cout << "Engine created" << std::endl;
    this->_chrono = Chrono(fps);
}

Engine::~Engine()
{
    std::cout << "Engine destroyed" << std::endl;
}

void Engine::game_loop()
{
    this->_chrono.init();
    int i = 0;
    while (this->_loop) {
        this->_chrono.startLoop();
        std::cout << i++ << std::endl;
        this->_chrono.sleepEndLoop();
    }
    // Start the clock
}