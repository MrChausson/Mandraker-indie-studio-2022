/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Menu
*/

#include "raylib.h"
#include "Menu.hpp"
#include "../Game/Game.hpp"
#include "../../ecs/Components/Clickable/Clickable.hpp"
#include "../../Tools/Button.hpp"
#include <string>


Menu::Menu(Engine *engine)
{
    std::cout << "Menu creating" << std::endl;
    this->_ecsManager = std::make_unique<ECSManager>(engine);
    //Create entities
    int bg_id = this->_ecsManager->createEntity();
    int title_id = this->_ecsManager->createEntity();
    int title_text = this->_ecsManager->createEntity();
    int settings_id = this->_ecsManager->createEntity();
    int settings_text = this->_ecsManager->createEntity();
    int quit_id = this->_ecsManager->createEntity();
    int quit_text = this->_ecsManager->createEntity();
    int player = this->_ecsManager->createEntity();
    int music_id = this->_ecsManager->createEntity();

    this->_music = LoadMusicStream("assets/sounds/menu_bg.mp3");
    this->_type = MENU;
    this->_background_texture = LoadTexture("assets/materials/main_menu.png");
    this->_title_texture = LoadTexture("assets/materials/title_bar.png");
    this->_btn_font = LoadFontEx("assets/fonts/wizarding.ttf", 100, 0, 0);
    this->_textures[0] = LoadTexture("assets/materials/buttons/btn_hover.png");
    this->_textures[1] = LoadTexture("assets/materials/buttons/btn_inactive.png");
    this->_textures[2] = LoadTexture("assets/materials/buttons/btn_clicked.png");

    // Adjust
    PlayMusicStream(this->_music);

    // add components
    // this->_ecsManager->addComponent(player, std::make_unique<Placable>(0, 0, 0));

    this->_ecsManager->addComponent(player, std::make_unique<Movable>(1));

    this->_ecsManager->addComponent(title_id, std::make_unique<Placable>(1000, 100));
    this->_ecsManager->addComponent(title_id, std::make_unique<DrawableSprite>(this->_title_texture, 1));

    this->_ecsManager->addComponent(title_text, std::make_unique<Placable>(1200, 150));
    this->_ecsManager->addComponent(title_text, std::make_unique<DrawableText>(2,"Mandraker", Color{255, 255, 255, 255}, this->_btn_font));

    this->_ecsManager->addComponent(bg_id, std::make_unique<Placable>(0, 0));
    this->_ecsManager->addComponent(bg_id, std::make_unique<DrawableSprite>(this->_background_texture, 0));

    Button(this->_ecsManager.get(), "play", 100, 300, this->_btn_font, this->_textures, "game", CLICKABLE_ACTION_CHANGE_ECS);
    Button(this->_ecsManager.get(), "settings", 100, 500, this->_btn_font, this->_textures, "settings", CLICKABLE_ACTION_CHANGE_ECS);
    Button(this->_ecsManager.get(), "quit", 100, 700, this->_btn_font, this->_textures, "none", CLICKABLE_ACTION_QUIT_GAME);

    this->_ecsManager->addComponent(music_id, std::make_unique<Musicable>(this->_music));

    // add systems
    // this->_ecsManager->addSystem(std::make_unique<Move>(Move()));
    this->_ecsManager->addSystem(std::make_unique<Draw>(Draw()));
    this->_ecsManager->addSystem(std::make_unique<MouseClick>(MouseClick()));
    this->_ecsManager->addSystem(std::make_unique<MouseHover>(MouseHover()));
    this->_ecsManager->addSystem(std::make_unique<Music_sys>(Music_sys()));
}

Menu::~Menu()
{
    UnloadTexture(this->_background_texture);
    UnloadTexture(this->_textures[0]);
    UnloadTexture(this->_textures[1]);
    UnloadTexture(this->_textures[2]);
    UnloadTexture(this->_title_texture);
    UnloadFont(this->_btn_font);
    UnloadFont(this->_title_font);
    UnloadMusicStream(this->_music);
    delete(this->_scene);
    std::cout << "Menu destroyed" << std::endl;
}