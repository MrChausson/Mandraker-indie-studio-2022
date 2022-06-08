/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Settings
*/

#include "Settings.hpp"
#include "raylib.h"
#include "../../ecs/Components/Clickable/Clickable.hpp"
#include "../../Tools/Button.hpp"
#include <string>

Settings::Settings()
{
    std::cout << "Options creating" << std::endl;
    this->_ecsManager = std::make_unique<ECSManager>();
    this->_ecsManager->setScene(this);
    int bg_id = this->_ecsManager->createEntity();
    int title_id = this->_ecsManager->createEntity();
    int title_text = this->_ecsManager->createEntity();
    int music_id = this->_ecsManager->createEntity();

    this->_music = LoadMusicStream("assets/sounds/menu_bg.mp3");
    this->_type = SCENE_SETTINGS;
    this->_background_texture = LoadTexture("assets/materials/main_menu.png");
    this->_title_texture = LoadTexture("assets/materials/title_bar.png");
    this->_btn_font = LoadFontEx("assets/fonts/wizarding.ttf", 100, 0, 0);
    this->_btn_textures[0] = LoadTexture("assets/materials/buttons/btn_hover.png");
    this->_btn_textures[1] = LoadTexture("assets/materials/buttons/btn_inactive.png");
    this->_btn_textures[2] = LoadTexture("assets/materials/buttons/btn_clicked.png");
    PlayMusicStream(this->_music);

    this->_ecsManager->addComponent(title_id, std::make_unique<Placable>(1000, 100));
    this->_ecsManager->addComponent(title_id, std::make_unique<DrawableSprite>(this->_title_texture, 1));

    this->_ecsManager->addComponent(title_text, std::make_unique<Placable>(1200, 150));
    this->_ecsManager->addComponent(title_text, std::make_unique<DrawableText>(2,"settings", Color{255, 255, 255, 255}, this->_btn_font));

    this->_ecsManager->addComponent(bg_id, std::make_unique<Placable>(0, 0));
    this->_ecsManager->addComponent(bg_id, std::make_unique<DrawableSprite>(this->_background_texture, 0));

    Button(this->_ecsManager.get(), "menu", 724, 900, this->_btn_font, this->_btn_textures, SCENE_MENU, CLICKABLE_ACTION_CHANGE_ECS);

    this->_ecsManager->addComponent(music_id, std::make_unique<Musicable>(this->_music));

    this->_ecsManager->addSystem(std::make_unique<Draw>(Draw()));
    this->_ecsManager->addSystem(std::make_unique<MouseClick>(MouseClick()));
    this->_ecsManager->addSystem(std::make_unique<MouseHover>(MouseHover()));
    this->_ecsManager->addSystem(std::make_unique<Music_sys>(Music_sys()));
}

Settings::~Settings()
{
}
