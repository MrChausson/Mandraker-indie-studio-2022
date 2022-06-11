/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Engine
*/

#include "Engine.hpp"
#include "raylib.hpp"
#include "../Scene/Scene.hpp"
#include "../Scene/Menu/Menu.hpp"
#include "../Scene/SplashScreen/SplashScreen.hpp"

bool loop_status = 1;
int max_fps = 60;

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
    Raylib::Raylib_encap Raylib_encp;

    Raylib_encp.SetConfFlags(FLAG_FULLSCREEN_MODE);
    Raylib_encp.InitWind(1920, 1080, "Mandraker");
    Raylib_encp.InitAudioDev();
    this->setFps(this->_fps);
    Engine *engine = this;
    Scene *scene = new SplashScreen();
    this->_currentEcs = scene->getECS();
    ECSManager *tmp;
    std::thread thread_music;

    while (loop_status) {
        tmp = this->_currentEcs->applySystems();
        if (tmp != nullptr)
            {
                this->_currentEcs = tmp;
            }
        if (Raylib_encp.WindowShouldEnd() && !Raylib_encp.IsKDown(KEY_ESCAPE))
            loop_status = false;
    }
    Raylib_encp.CloseAudioDev();
    Raylib_encp.CloseWind();
    // delete(static_cast<Menu *>(scene));
}

void Engine::setFps(int fps)
{
    Raylib::Raylib_encap Raylib_encp;

    this->_chrono.setFps(fps);
    Raylib_encp.SetTargFPS(fps);
}
