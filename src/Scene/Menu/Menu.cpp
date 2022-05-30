/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Menu
*/

#include "raylib.h"
#include "Menu.hpp"


Menu::Menu()
{
    this->_type = MENU;
    this->_ecsManager = std::make_unique<ECSManager>();
}

Menu::~Menu()
{
}

void Menu::init()
{
    int bg_id = this->_ecsManager->createEntity();
    int text_id = this->_ecsManager->createEntity();
    int button_id = this->_ecsManager->createEntity();
    int second_text = this->_ecsManager->createEntity();
    std::unique_ptr <Texture2D> texture = std::make_unique<Texture2D> (LoadTexture("assets/materials/buttons/btn_inactive.png"));
    std::unique_ptr <Texture2D> bg_img = std::make_unique<Texture2D> (LoadTexture("assets/materials/main_menu.png"));
    
    this->_ecsManager->addComponent(text_id, std::make_unique<DrawableText>(0, 190, 200 ,"Hello World", 30, Color{255, 255, 255, 255}));
    this->_ecsManager->addComponent(second_text, std::make_unique<DrawableText>(0, 190, 400 ,"Hello World Second", 10, Color{255, 255, 255, 255}));
    this->_ecsManager->addComponent(bg_id, std::make_unique<DrawableSprite>(0, 100, 200, bg_img.get()));
    this->_ecsManager->addComponent(button_id, std::make_unique<DrawableSprite>(1, 0, 0, texture.get()));
    
    this->_ecsManager->addSystem(std::make_unique<Draw>(Draw()));
}