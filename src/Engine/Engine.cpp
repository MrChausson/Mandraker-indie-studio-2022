/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Engine
*/

#include "Engine.hpp"
#include "../ecs/Components/Drawable/DrawableText.hpp"
#include "../ecs/Systems/Draw/Draw.hpp"

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

    int text_id = this->_ecsManager->createEntity();
    this->_ecsManager->addComponent(text_id, std::make_unique<DrawableText>(0, 190, 200 ,"Hello World", 30, Color{255, 255, 255, 255}));
    int second_text = this->_ecsManager->createEntity();
    this->_ecsManager->addComponent(text_id, std::make_unique<DrawableText>(0, 190, 400 ,"Hello World Second", 10, Color{255, 255, 255, 255}));
    
    this->_ecsManager->addSystem(std::make_unique<Draw>(Draw()));

    while (this->_loop) {
        this->_chrono.startLoop();
        BeginDrawing();
        ClearBackground(BLACK);
        this->_ecsManager.get()->applySystems();
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
