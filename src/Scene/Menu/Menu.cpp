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
    //Create entities
    int bg_id = this->_ecsManager->createEntity();
    int text_id = this->_ecsManager->createEntity();
    int button_id = this->_ecsManager->createEntity();
    int second_text = this->_ecsManager->createEntity();
    int player = this->_ecsManager->createEntity();

    this->_type = MENU;
    this->_background_texture = LoadTexture("assets/materials/main_menu.png");
    this->_btn_active_texture = LoadTexture("assets/materials/buttons/btn_hover.png");
    this->_btn_inactive_texture = LoadTexture("assets/materials/buttons/btn_inactive.png");
    this->_btn_clicked_texture = LoadTexture("assets/materials/buttons/btn_clicked.png");
    Font font = LoadFontEx("assets/fonts/wizarding.ttf", 100, 0, 0);
    Vector2 playVector = {static_cast<float>(this->_btn_inactive_texture.width / 2 - font.baseSize),static_cast<float>(this->_btn_inactive_texture.height / 2 - font.baseSize / 2) };

    // add components
    // this->_ecsManager->addComponent(player, std::make_unique<Placable>(0, 0, 0));
    this->_ecsManager->addComponent(player, std::make_unique<Movable>(1));
    this->_ecsManager->addComponent(text_id, std::make_unique<DrawableText>(0, 190, 200 ,"Hello World", Color{255, 255, 255, 255}));
    this->_ecsManager->addComponent(bg_id, std::make_unique<DrawableSprite>(this->_background_texture, 0, 0, 0));
    this->_ecsManager->addComponent(button_id, std::make_unique<DrawableSprite>(this->_btn_inactive_texture, 1, 0, 0));
    this->_ecsManager->addComponent(button_id, std::make_unique<Clickable>(0, 0, this->_btn_clicked_texture));
    this->_ecsManager->addComponent(button_id, std::make_unique<Hoverable>(0, 0, this->_btn_active_texture));
    this->_ecsManager->addComponent(second_text, std::make_unique<DrawableText>(0, playVector.x, playVector.y ,"play", Color{255, 255, 255, 255}, font));

    // add systems
    // this->_ecsManager->addSystem(std::make_unique<Move>(Move()));
    this->_ecsManager->addSystem(std::make_unique<Draw>(Draw()));
    this->_ecsManager->addSystem(std::make_unique<MouseClick>(MouseClick()));
    this->_ecsManager->addSystem(std::make_unique<MouseHover>(MouseHover()));
}

Menu::~Menu()
{
    UnloadTexture(this->_background_texture);
    UnloadTexture(this->_btn_active_texture);
    UnloadTexture(this->_btn_inactive_texture);
}