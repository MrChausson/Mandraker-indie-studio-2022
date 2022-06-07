/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** SplashScreen
*/

#include "SplashScreen.hpp"
#include "../../Engine/Engine.hpp"
#include "../../ecs/Components/Drawable/DrawableSprite.hpp"
#include "../../ecs/Components/Loadable/Loadable.hpp"
#include "../../ecs/Systems/Loading/Loading.hpp"
#include "../Menu/Menu.hpp"
#include "../../ecs/ECSManager/ECSManager.hpp"

SplashScreen::SplashScreen(Engine *engine)
{
    this->_ecsManager = std::make_unique<ECSManager>();
    Menu *menu = new Menu();
    
    int bg = this->_ecsManager->createEntity();
    int load_bar = this->_ecsManager->createEntity();

    Texture2D back = LoadTexture("assets/materials/loading_bg.png");
    Texture2D load = LoadTexture("assets/materials/loading.png");
    
    this->_ecsManager->addComponent(load_bar, std::make_unique<Placable>(back.width/2, (back.height/20) * 12));
    this->_ecsManager->addComponent(load_bar, std::make_unique<Loadable>(load, back, 0.0f, menu->getECS(), 5));

    this->_ecsManager->addSystem(std::make_unique<Loading>());
}

SplashScreen::~SplashScreen()
{
}
