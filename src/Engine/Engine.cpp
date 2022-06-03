/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Engine
*/

#include "Engine.hpp"

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


//Engine std::vector<Scene> scenes;

// Parent class "Scene" absctract or interface
// .getECS() = gives ecs so Engine can applysystem
// enum scene_type = Scene type
// Child scene:
// Menu, Game
// .init() = add components, add systems and store an ECSManager
// .


void Engine::game_loop()
{
    this->_chrono.init();
    int i = 0;
    InitWindow(1920, 1080, "Mandraker");
    InitAudioDevice();
    ToggleFullscreen();
    this->setFps(this->_fps);
    Scene *scene = new Menu();
    this->_currentEcs = scene->getECS();
    ECSManager *tmp;

    while (this->_loop) {
        this->_chrono.startLoop();
        tmp = this->_currentEcs->applySystems();
        if (tmp != nullptr)
            {
                delete (this->_currentEcs);
                this->_currentEcs = tmp;
            }
        if (WindowShouldClose() && !IsKeyDown(KEY_ESCAPE))
            this->_loop = false;
        this->_chrono.sleepEndLoop();
    }
    CloseAudioDevice();
    CloseWindow();
    delete(scene);
}

void Engine::setFps(int fps)
{
    this->_chrono.setFps(fps);
    SetTargetFPS(fps);
}
