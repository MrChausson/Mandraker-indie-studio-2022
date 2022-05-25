/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Engine
*/

#include "Engine.hpp"

Engine::Engine()
{
    this->_ecsManager = std::make_unique<ECSManager>();
    std::cout << "Engine created" << std::endl;
    this->_chrono = Chrono(1);
}

Engine::~Engine()
{
    std::cout << "Engine destroyed" << std::endl;
}

void Engine::game_loop()
{
    this->_chrono.init();
    while (this->_loop) {
        this->_chrono.startLoop();
        std::this_thread::sleep_for(std::chrono::milliseconds(15));
        std::cout << "Here is one frame" << std::endl;
        this->_chrono.sleepEndLoop();
    }
    // Start the clock
}