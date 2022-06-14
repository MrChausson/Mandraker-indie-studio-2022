/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** GameOver
*/

#include "raylib.hpp"
#include "GameOver.hpp"
#include "../../ecs/Components/Clickable/Clickable.hpp"
#include "../../Tools/Button.hpp"
#include <string>
#include "raymath.h"
#include "../../ecs/Components/CameraComponent/CameraComponent.hpp"
#include "../../ecs/Components/Animable/Animable.hpp"
#include "../../ecs/Systems/Animation/Animation.hpp"
#include "../../ecs/Systems/Sound/SoundSystem.hpp"


GameOver::GameOver()
{
    Raylib::Raylib_encap Raylib_encp;
    Vector3 position = { 0.0f, 10.0f, 180.0f };
    Vector3 target = { 32.0f, 25.0f, 0.0f }; //  Gauche-Droite|Haut-bas|??
    Vector3 up = { 0.0f, 1.0f, 0.0f };
    Vector3 scale = { 0.5, 0.5, 0.5 };
    Vector3 rotationAxis = {2.0f, 0.0f, 0.0f};

    std::cout << "End the game" << std::endl;
    this->_ecsManager = std::make_unique<ECSManager>();

    int bg_id = this->_ecsManager->createEntity();
    int title_id = this->_ecsManager->createEntity();
    int title_text = this->_ecsManager->createEntity();
    int title_text_bis = this->_ecsManager->createEntity();
    int music_id = this->_ecsManager->createEntity();
    int character_salle = this->_ecsManager->createEntity();


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
    this->_ecsManager->addComponent(title_text, std::make_unique<DrawableText>(2,"winner :", Color{255, 255, 255, 255}, this->_btn_font));
    this->_ecsManager->addComponent(bg_id, std::make_unique<Placable>(0, 0));
    this->_ecsManager->addComponent(bg_id, std::make_unique<DrawableSprite>(this->_background_texture, 0));
    Button(this->_ecsManager.get(), "quit", 1400, 900, this->_btn_font, this->_btn_textures, SCENE_NONE, CLICKABLE_ACTION_QUIT_GAME, this, &this->_click);
    Button(this->_ecsManager.get(), "replay", 1400, 700, this->_btn_font, this->_btn_textures, SCENE_PLAYERS_SELECTOR, CLICKABLE_ACTION_CHANGE_ECS, this, &this->_click);

    this->_ecsManager->addComponent(music_id, std::make_unique<Musicable>(this->_music));

    // Adding systems
    this->_ecsManager->addSystem(std::make_unique<Draw>(Draw()));
    this->_ecsManager->addSystem(std::make_unique<MouseClick>(MouseClick()));
    this->_ecsManager->addSystem(std::make_unique<MouseHover>(MouseHover()));
    this->_ecsManager->addSystem(std::make_unique<Music_sys>(Music_sys()));

       this->_textures_salle = {
       Raylib_encp.LTexture("assets/models/greathall/BannerHA_v2@4x.png"),
       Raylib_encp.LTexture("assets/models/greathall/ceiling_A_wood_v3@4x.png"),
       Raylib_encp.LTexture("assets/models/greathall/ceiling_M_wood_v25@4x.png"),
       Raylib_encp.LTexture("assets/models/greathall/CheatSheet_white_v141@4x.png"),
       Raylib_encp.LTexture("assets/models/greathall/CheatSheet_white_v146@4x.png"),
       Raylib_encp.LTexture("assets/models/greathall/CheatSheet_white_v156@4x.png"),
       Raylib_encp.LTexture("assets/models/greathall/Env_HP_Ground_COLOR_v89@4x.png"),
       Raylib_encp.LTexture("assets/models/greathall/Env_HP_Ground_COLOR_v91@4x.png"),
       Raylib_encp.LTexture("assets/models/greathall/env_M_WoodPanels_color_v108@4x.png"),
       Raylib_encp.LTexture("assets/models/greathall/env_texture_GreatHallConcrete_01_v15@4x.png"),
       Raylib_encp.LTexture("assets/models/greathall/env_texture_GreatHall_M_Concrete_01_v77@4x.png"),
       Raylib_encp.LTexture("assets/models/greathall/env_texture_GreatHall_M_Concrete_B_v24@4x.png"),
       Raylib_encp.LTexture("assets/models/greathall/GH__BackWall_SD_LM_v3@4x.png"),
       Raylib_encp.LTexture("assets/models/greathall/GH_BigWindowFrames_SD_LM_v3@4x.png"),
       Raylib_encp.LTexture("assets/models/greathall/GH_BigWindow_SD_LM_v3@4x.png"),
       Raylib_encp.LTexture("assets/models/greathall/GH_ceeling_SD_Lm_v3@4x.png"),
       Raylib_encp.LTexture("assets/models/greathall/env_texture_GreatHall_M_Walls_01_v77@4x.png"),
       Raylib_encp.LTexture("assets/models/greathall/env_WoodPanels_color_v30@4x.png"),
       Raylib_encp.LTexture("assets/models/greathall/FireplaceCrest_M_01_v27@4x.png"),
       Raylib_encp.LTexture("assets/models/greathall/Furniture_LM_v54@4x.png"),
       Raylib_encp.LTexture("assets/models/greathall/GH_Fireholder_DT_LM_v12@4x.png"),
       Raylib_encp.LTexture("assets/models/greathall/GH_Fireplace_SD_LM_v3@4x.png"),
       Raylib_encp.LTexture("assets/models/greathall/GH_Floor_SD_LM_v3@4x.png"),
       Raylib_encp.LTexture("assets/models/greathall/GH_Frontdoor_SD_LM_v3@4x.png"),
       Raylib_encp.LTexture("assets/models/greathall/GH_FrontWall_SD_LM_v3@4x.png"),
       Raylib_encp.LTexture("assets/models/greathall/GH_Gargoyles_SD_LM_v3@4x.png"),
       Raylib_encp.LTexture("assets/models/greathall/GH_Leftwall_SD_LM_v3@4x.png"),
       Raylib_encp.LTexture("assets/models/greathall/GH_Rightwall_SD_LM_v3@4x.png"),
       Raylib_encp.LTexture("assets/models/greathall/GH_SupportBeams_SD_LM_v3@4x.png"),
       Raylib_encp.LTexture("assets/models/greathall/GH_TopBackWall_SD_LM_v3@4x.png"),
       Raylib_encp.LTexture("assets/models/greathall/GH_WALL_SD_Lm_v3@4x.png"),
       Raylib_encp.LTexture("assets/models/greathall/GH_WindColFraming_SD_LM_v3@4x.png"),
       Raylib_encp.LTexture("assets/models/greathall/GH_WoodWalls_SD_LM_v3@4x.png"),
       Raylib_encp.LTexture("assets/models/greathall/GreatHal_CentralWindowWall_DM_v21@4x.png"),
       Raylib_encp.LTexture("assets/models/greathall/GreatHall_BigWindowFrame_LM_v21@4x.png"),
       Raylib_encp.LTexture("assets/models/greathall/GreatHall_CentralArch_DM_v21@4x.png"),
       Raylib_encp.LTexture("assets/models/greathall/GreatHall_FirePlace_LM_v28@4x.png"),
       Raylib_encp.LTexture("assets/models/greathall/GreatHall_M_door_01_v34@4x.png"),
       Raylib_encp.LTexture("assets/models/greathall/GreatHall_sideWall_DM_B_v21@4x.png"),
       Raylib_encp.LTexture("assets/models/greathall/GreatHall_sideWall_DM_C_v20@4x.png"),
       Raylib_encp.LTexture("assets/models/greathall/hufflepuff_v21@4x.png"),
       Raylib_encp.LTexture("assets/models/greathall/MoldingsEntrance_M_01_v22@4x.png"),
       Raylib_encp.LTexture("assets/models/greathall/p_FireHolder_Diffuse_v22@4x.png"),
       Raylib_encp.LTexture("assets/models/greathall/p_GryffindorStatue_Diffuse_v22@4x.png"),
       Raylib_encp.LTexture("assets/models/greathall/p_GryffindorStatue_Spec_v22@4x.png"),
       Raylib_encp.LTexture("assets/models/greathall/p_HufflepuffFireplace_Grate_Diffuse_v31@4x.png"),
       Raylib_encp.LTexture("assets/models/greathall/p_HufflepuffFireplace_Grate_Diffuse_v35@4x.png"),
       Raylib_encp.LTexture("assets/models/greathall/p_HufflepuffStokers_diffuse_v27@4x.png"),
       Raylib_encp.LTexture("assets/models/greathall/p_HufflepuffStokers_diffuse_v31@4x.png"),
       Raylib_encp.LTexture("assets/models/greathall/p_HufflepuffStokers_spec_v33@4x.png"),
       Raylib_encp.LTexture("assets/models/greathall/p_HufflepuffStokers_spec_v37@4x.png"),
       Raylib_encp.LTexture("assets/models/greathall/Ravenclaw_v21@4x.png"),
       Raylib_encp.LTexture("assets/models/greathall/slythering_gargoyle_v21@4x.png"),
       Raylib_encp.LTexture("assets/models/greathall/windows_columsConcrete_M1_color_v3@4x.png"),
       Raylib_encp.LTexture("assets/models/greathall/windows_columsConcrete_M_color_v63@4x.png"),
       Raylib_encp.LTexture("assets/models/greathall/windows_Decal_DM_v21@4x.png"),
       Raylib_encp.LTexture("assets/models/greathall/windows_Decal_LM_v12@4x.png"),
    };
    std::vector<int> meshOrder_salle = {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57
    };

    this->_ecsManager->addComponent(character_salle, std::make_unique<Placable>(0.0f, -2.0f, 0.0f, rotationAxis, -90.0f, scale));
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