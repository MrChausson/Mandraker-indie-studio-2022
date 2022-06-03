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


Menu::Menu()
{
    std::cout << "Menu creating" << std::endl;
    this->_ecsManager = std::make_unique<ECSManager>();
    //Create entities
    int bg_id = this->_ecsManager->createEntity();
    int title_id = this->_ecsManager->createEntity();
    int play_id = this->_ecsManager->createEntity();
    int player = this->_ecsManager->createEntity();
    int music_id = this->_ecsManager->createEntity();
    this->_scene = new Game();

    this->_music = LoadMusicStream("assets/sounds/menu_bg.mp3");
    this->_type = MENU;
    this->_background_texture = LoadTexture("assets/materials/main_menu.png");
    this->_btn_active_texture = LoadTexture("assets/materials/buttons/btn_hover.png");
    this->_btn_inactive_texture = LoadTexture("assets/materials/buttons/btn_inactive.png");
    this->_btn_clicked_texture = LoadTexture("assets/materials/buttons/btn_clicked.png");
    this->_title_texture = LoadTexture("assets/materials/title_bar.png");
    this->_btn_font = LoadFontEx("assets/fonts/wizarding.ttf", 100, 0, 0);
    this->_title_font = LoadFontEx("assets/fonts/wizarding.ttf", 200, 0, 0);

    // Adjust
    PlayMusicStream(this->_music);
    Vector2 playVector = {static_cast<float>(100 + (this->_btn_inactive_texture.width / 2 - this->_btn_font.baseSize)),static_cast<float>(300 + (this->_btn_inactive_texture.height / 2 - this->_btn_font.baseSize / 2)) };

    // add components
    // this->_ecsManager->addComponent(player, std::make_unique<Placable>(0, 0, 0));
    this->_ecsManager->addComponent(player, std::make_unique<Movable>(1));
    this->_ecsManager->addComponent(title_id, std::make_unique<DrawableSprite>(this->_title_texture, 1, 800, 100));
    this->_ecsManager->addComponent(title_id, std::make_unique<DrawableText>(0, 1000, 150 ,"Mandraker", Color{255, 255, 255, 255}, this->_btn_font));
    this->_ecsManager->addComponent(bg_id, std::make_unique<DrawableSprite>(this->_background_texture, 0, 0, 0));
    this->_ecsManager->addComponent(play_id, std::make_unique<DrawableSprite>(this->_btn_inactive_texture, 1, 100, 300));
    this->_ecsManager->addComponent(play_id, std::make_unique<Clickable>(100, 300, this->_btn_clicked_texture, this->_scene->getECS()));
    this->_ecsManager->addComponent(play_id, std::make_unique<Hoverable>(100, 300, this->_btn_active_texture));
    this->_ecsManager->addComponent(play_id, std::make_unique<DrawableText>(0, playVector.x, playVector.y ,"play", Color{255, 255, 255, 255}, this->_btn_font));
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
    UnloadTexture(this->_btn_active_texture);
    UnloadTexture(this->_btn_inactive_texture);
    UnloadTexture(this->_btn_clicked_texture);
    UnloadTexture(this->_title_texture);
    UnloadFont(this->_btn_font);
    UnloadFont(this->_title_font);
    UnloadMusicStream(this->_music);
    delete(this->_scene);
    std::cout << "Menu destroyed" << std::endl;
}