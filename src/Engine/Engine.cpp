/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Engine
*/

#include "Engine.hpp"
#include "../Scene/Scene.hpp"
#include "../Scene/Menu/Menu.hpp"


bool loop_status = 1;

Engine::Engine(int fps)
{
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

    SetConfigFlags(FLAG_FULLSCREEN_MODE);
    InitWindow(1920, 1080, "Mandraker");
    InitAudioDevice();
    this->setFps(this->_fps);
    Engine *engine = this;
    Scene *scene = new Menu(engine);
    this->_currentEcs = scene->getECS();
    ECSManager *tmp;

    while (loop_status) {
        this->_chrono.startLoop();
        tmp = this->_currentEcs->applySystems();
        if (tmp != nullptr)
            {
                delete (this->_currentEcs);
                this->_currentEcs = tmp;
            }
        if (WindowShouldClose() && !IsKeyDown(KEY_ESCAPE))
            loop_status = false;
        this->_chrono.sleepEndLoop();
    }
    CloseAudioDevice();
    CloseWindow();
    // delete(static_cast<Menu *>(scene));
}

void Engine::setFps(int fps)
{
    this->_chrono.setFps(fps);
    SetTargetFPS(fps);
}
