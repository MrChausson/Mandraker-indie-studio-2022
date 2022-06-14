/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** GameOver
*/

#include "raylib.hpp"
#include "GameOver.hpp"
#include <string>
#include "raymath.h"
#include "../../ecs/Components/Clickable/Clickable.hpp"
#include "../../ecs/Components/CameraComponent/CameraComponent.hpp"
#include "../../ecs/Components/Animable/Animable.hpp"
#include "../../ecs/Systems/Animation/Animation.hpp"
#include "../../ecs/Systems/Sound/SoundSystem.hpp"
#include "../../Tools/Button.hpp"


GameOver::GameOver()
{
    Raylib::Raylib_encap Raylib_encp;

    std::cout << "End the game" << std::endl;
    this->_ecsManager = std::make_unique<ECSManager>();

    int bg_id = this->_ecsManager->createEntity();
    int title_id = this->_ecsManager->createEntity();
    int title_text = this->_ecsManager->createEntity();
    int title_text_bis = this->_ecsManager->createEntity();
    int music_id = this->_ecsManager->createEntity();
    int character_salle = this->_ecsManager->createEntity();
    int cameraover = this->_ecsManager->createEntity();


    // Loading Assets for the menu
    this->_music = Raylib_encp.LoadMStream("assets/sounds/menu_bg.mp3");
    this->_click = Raylib_encp.LSound("assets/sounds/menu/click.wav");
    this->_type = SCENE_MENU;
    //this->_background_texture = Raylib_encp.LTexture("assets/materials/selection/background.png");
    this->_title_texture = Raylib_encp.LTexture("assets/materials/menu/title_bar.png");
    this->_btn_font = Raylib_encp.LFontEx("assets/fonts/wizarding.ttf", 100, 0, 0);
    this->_btn_textures[0] = Raylib_encp.LTexture("assets/materials/buttons/btn_hovered.png");
    this->_btn_textures[1] = Raylib_encp.LTexture("assets/materials/buttons/btn_inactive.png");
    this->_btn_textures[2] = Raylib_encp.LTexture("assets/materials/buttons/btn_clicked.png");
    // Play Music
    Raylib_encp.PlayMStream(this->_music);
    // Adding components
    this->_ecsManager->addComponent(title_id, std::make_unique<Placable>(1200, 100));
    this->_ecsManager->addComponent(title_id, std::make_unique<DrawableSprite>(this->_title_texture, 1));
    this->_ecsManager->addComponent(title_text, std::make_unique<Placable>(1400, 150));
    this->_ecsManager->addComponent(title_text, std::make_unique<DrawableText>(3,"winner :", Color{255, 255, 255, 255}, this->_btn_font));
    this->_ecsManager->addComponent(bg_id, std::make_unique<Placable>(0, 0));
    this->_ecsManager->addComponent(bg_id, std::make_unique<DrawableSprite>(this->_background_texture, 0));

    Button(this->_ecsManager.get(), "quit", 1400, 900, this->_btn_font, this->_btn_textures, SCENE_NONE, CLICKABLE_ACTION_QUIT_GAME, this, &this->_click, 2);
    Button(this->_ecsManager.get(), "replay", 1400, 700, this->_btn_font, this->_btn_textures, SCENE_PLAYERS_SELECTOR, CLICKABLE_ACTION_CHANGE_ECS, this, &this->_click, 2);

    this->_ecsManager->addComponent(music_id, std::make_unique<Musicable>(this->_music));

    // Adding systems
    this->_ecsManager->addSystem(std::make_unique<Draw>(Draw()));
    this->_ecsManager->addSystem(std::make_unique<MouseClick>(MouseClick()));
    this->_ecsManager->addSystem(std::make_unique<MouseHover>(MouseHover()));
    this->_ecsManager->addSystem(std::make_unique<Music_sys>(Music_sys()));

       this->_textures_salle = {
       Raylib_encp.LTexture("assets/models/greathall/MoldingsEntrance_M_01_v22@4x.png"),
       Raylib_encp.LTexture("assets/models/greathall/windows_columsConcrete_M_color_v63@4x.png"),
       Raylib_encp.LTexture("assets/models/greathall/windows_columsConcrete_M_color_v63@4x.png"),
       Raylib_encp.LTexture("assets/models/greathall/env_texture_GreatHallConcrete_01_v15@4x.png"),
       Raylib_encp.LTexture("assets/models/greathall/env_texture_GreatHallConcrete_01_v15@4x.png"),
       Raylib_encp.LTexture("assets/models/greathall/env_texture_GreatHall_M_Walls_01_v77@4x.png"),
       Raylib_encp.LTexture("assets/models/greathall/GreatHall_M_door_01_v34@4x.png"),
       Raylib_encp.LTexture("assets/models/greathall/ceiling_M_wood_v25@4x.png"),
       Raylib_encp.LTexture("assets/models/greathall/env_M_WoodPanels_color_v108@4x.png"),
    };
    std::vector<int> meshOrder_salle = {
        0, 1, 2, 3, 4, 5, 6, 7, 8
    };

    Vector3 position = { -108.0f, 600.0f, 90.0f };
    Vector3 target = { 70.0f, 300.0f, 0.0f };
    Vector3 up = { 0.0f, 1.0f, 0.0f };
    Vector3 scale = { 1.5, 1.5, 1.5 };
    Vector3 rotationAxis = { 1.5f, 1.3f, 1.0f };

    
    this->_ecsManager->addComponent(cameraover, std::make_unique<CameraComponent>(position, target, up, 45.0f, CAMERA_PERSPECTIVE));
    this->_ecsManager->addComponent(character_salle, std::make_unique<Placable>(0.0f, 0.0f, 0.0f, rotationAxis, -90.0f, scale));
    Model salleModel = Raylib_encp.LModel("assets/models/greathall/greathall.obj");
    this->_ecsManager->addComponent(character_salle, std::make_unique<DrawableModel>(_textures_salle, salleModel, meshOrder_salle, 2));
}

GameOver::~GameOver()
{
}

void GameOver::Unload()
{
    Raylib::Raylib_encap Raylib_encp;

    Raylib_encp.UnlTexture(this->_background_texture);
    Raylib_encp.UnlTexture(this->_btn_textures[0]);
    Raylib_encp.UnlTexture(this->_btn_textures[1]);
    Raylib_encp.UnlTexture(this->_btn_textures[2]);
    Raylib_encp.UnlTexture(this->_title_texture);
    Raylib_encp.UnlFont(this->_btn_font);
    Raylib_encp.UnloadMStream(this->_music);
    std::cout << "Menu destroyed" << std::endl;
}

float GameOver::getMusicTimePlayed()
{
    Raylib::Raylib_encap Raylib_encp;
    return Raylib_encp.GetMTimePlayed(this->_music);
}

void GameOver::SetMusicTimePlayed(float dur)
{
    Raylib::Raylib_encap Raylib_encp;
    Raylib_encp.SeekMStream(this->_music, dur);
}