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
    this->_ecsManager = std::make_unique<ECSManager>();
    int bg_id = this->_ecsManager->createEntity();
    int text_id = this->_ecsManager->createEntity();
    int button_id = this->_ecsManager->createEntity();
    int second_text = this->_ecsManager->createEntity();

    this->_type = MENU;
    this->_background_texture = LoadTexture("assets/materials/main_menu.png");
    this->_btn_active_texture = LoadTexture("assets/materials/buttons/btn_hover.png");
    this->_btn_inactive_texture = LoadTexture("assets/materials/buttons/btn_inactive.png");
    std::unique_ptr <Texture2D> texture = std::make_unique<Texture2D> (LoadTexture("assets/materials/buttons/btn_inactive.png"));
    std::unique_ptr <Texture2D> bg_img = std::make_unique<Texture2D> (LoadTexture("assets/materials/main_menu.png"));
    this->_ecsManager->addComponent(text_id, std::make_unique<DrawableText>(0, 190, 200 ,"Hello World", 30, Color{255, 255, 255, 255}));
    this->_ecsManager->addComponent(second_text, std::make_unique<DrawableText>(0, 190, 400 ,"Hello World Second", 10, Color{255, 255, 255, 255}));
    this->_ecsManager->addComponent(bg_id, std::make_unique<DrawableSprite>(this->_background_texture, 0, 0, 0));
    this->_ecsManager->addComponent(button_id, std::make_unique<DrawableSprite>(this->_btn_inactive_texture, 1, 0, 0));
    //float x, float y, float width, float height, Texture2D texture
    this->_ecsManager->addComponent(button_id, std::make_unique<Hoverable>(0, 0, 100, 100, this->_btn_active_texture));

    this->_ecsManager->addSystem(std::make_unique<Draw>(Draw()));
    this->_ecsManager->addSystem(std::make_unique<MouseHover>(MouseHover()));
}

Menu::~Menu()
{
    UnloadTexture(this->_background_texture);
    UnloadTexture(this->_btn_active_texture);
    UnloadTexture(this->_btn_inactive_texture);
}