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
    this->_fps = fps;
}

Engine::~Engine()
{
    std::cout << "Engine destroyed" << std::endl;
}

void Engine::game_loop()
{
    this->_chrono.init();
    int i = 0;
    InitWindow(800, 450, "Mandraker");
    this->setFps(this->_fps);
    Image icon = LoadImage("./assets/icon.png");
    SetWindowIcon(icon);
    while (this->_loop) {
        this->_chrono.startLoop();
        BeginDrawing();
        ClearBackground(BLACK);
        DrawText("Congrats! You have finished the game!", 190, 200, 20 + i++, LIGHTGRAY);
        EndDrawing();
        this->_chrono.sleepEndLoop();
    }
    // Start the clock
}

void Engine::setFps(int fps)
{
    this->_chrono.setFps(fps);
    SetTargetFPS(fps);
}