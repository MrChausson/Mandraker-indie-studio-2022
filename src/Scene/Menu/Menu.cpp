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


Menu::Menu(Engine *engine)
{
    std::cout << "Menu creating" << std::endl;
    this->_ecsManager = std::make_unique<ECSManager>(engine);
    //Create entities
    int bg_id = this->_ecsManager->createEntity();
    int title_id = this->_ecsManager->createEntity();
    int title_text = this->_ecsManager->createEntity();
    int play_id = this->_ecsManager->createEntity();
    int play_text = this->_ecsManager->createEntity();
    int settings_id = this->_ecsManager->createEntity();
    int settings_text = this->_ecsManager->createEntity();
    int quit_id = this->_ecsManager->createEntity();
    int quit_text = this->_ecsManager->createEntity();
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

    // add components
    // this->_ecsManager->addComponent(player, std::make_unique<Placable>(0, 0, 0));

    this->_ecsManager->addComponent(player, std::make_unique<Movable>(1));

    this->_ecsManager->addComponent(title_id, std::make_unique<Placable>(800, 100));
    this->_ecsManager->addComponent(title_id, std::make_unique<DrawableSprite>(this->_title_texture, 1));

    this->_ecsManager->addComponent(title_text, std::make_unique<Placable>(1000, 150));
    this->_ecsManager->addComponent(title_text, std::make_unique<DrawableText>(2,"Mandraker", Color{255, 255, 255, 255}, this->_btn_font));

    this->_ecsManager->addComponent(bg_id, std::make_unique<Placable>(0, 0));
    this->_ecsManager->addComponent(bg_id, std::make_unique<DrawableSprite>(this->_background_texture, 0));

    this->_ecsManager->addComponent(play_id, std::make_unique<Placable>(100, 300));
    this->_ecsManager->addComponent(play_id, std::make_unique<DrawableSprite>(this->_btn_inactive_texture, 1));
    this->_ecsManager->addComponent(play_id, std::make_unique<Clickable>(this->_ecsManager->getEntity(play_id) ,this->_btn_clicked_texture, this->_scene->getECS(), CLICKABLE_ACTION_CHANGE_ECS));
    this->_ecsManager->addComponent(play_id, std::make_unique<Hoverable>(this->_ecsManager->getEntity(play_id), this->_btn_active_texture));
    this->_ecsManager->addComponent(play_text, std::make_unique<Placable>(static_cast<float>(100 + (this->_btn_inactive_texture.width / 2 - this->_btn_font.baseSize)),static_cast<float>(300 + (this->_btn_inactive_texture.height / 2 - this->_btn_font.baseSize / 2))));
    this->_ecsManager->addComponent(play_text, std::make_unique<DrawableText>(2 ,"play", Color{255, 255, 255, 255}, this->_btn_font));

    this->_ecsManager->addComponent(settings_id, std::make_unique<Placable>(100, 500));
    this->_ecsManager->addComponent(settings_id, std::make_unique<DrawableSprite>(this->_btn_inactive_texture, 1));
    this->_ecsManager->addComponent(settings_id, std::make_unique<Clickable>(this->_ecsManager->getEntity(settings_id) ,this->_btn_clicked_texture, this->getECS(), CLICKABLE_ACTION_OPEN_OPTIONS));
    this->_ecsManager->addComponent(settings_id, std::make_unique<Hoverable>(this->_ecsManager->getEntity(settings_id), this->_btn_active_texture));
    this->_ecsManager->addComponent(settings_text, std::make_unique<Placable>(static_cast<float>((this->_btn_inactive_texture.width / 2 - this->_btn_font.baseSize)),static_cast<float>(500 + (this->_btn_inactive_texture.height / 2 - this->_btn_font.baseSize / 2))));
    this->_ecsManager->addComponent(settings_text, std::make_unique<DrawableText>(2 ,"settings", Color{255, 255, 255, 255}, this->_btn_font));

    this->_ecsManager->addComponent(quit_id, std::make_unique<Placable>(100, 700));
    this->_ecsManager->addComponent(quit_id, std::make_unique<DrawableSprite>(this->_btn_inactive_texture, 1));
    this->_ecsManager->addComponent(quit_id, std::make_unique<Clickable>(this->_ecsManager->getEntity(quit_id) ,this->_btn_clicked_texture, this->_ecsManager.get(), CLICKABLE_ACTION_QUIT_GAME));
    this->_ecsManager->addComponent(quit_id, std::make_unique<Hoverable>(this->_ecsManager->getEntity(quit_id), this->_btn_active_texture));
    this->_ecsManager->addComponent(quit_text, std::make_unique<Placable>(static_cast<float>(100 + (this->_btn_inactive_texture.width / 2 - this->_btn_font.baseSize)),static_cast<float>(700 + (this->_btn_inactive_texture.height / 2 - this->_btn_font.baseSize / 2))));
    this->_ecsManager->addComponent(quit_text, std::make_unique<DrawableText>(2 ,"quit", Color{255, 255, 255, 255}, this->_btn_font));

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