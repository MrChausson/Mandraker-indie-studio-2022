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


GameOver::GameOver(ModelType modelType)
{
   Raylib::Raylib_encap Raylib_encp;
    Vector3 position = { 0.0f, 10.0f, 180.0f };
    Vector3 target = { 32.0f, 25.0f, 0.0f };
    Vector3 up = { 0.0f, 1.0f, 0.0f };
    Vector3 scale = { 0.5, 0.5, 0.5 };

    this->_ecsManager = std::make_unique<ECSManager>();
    int bg_id = this->_ecsManager->createEntity();
    int title_id = this->_ecsManager->createEntity();
    int title_text = this->_ecsManager->createEntity();
    int music_id = this->_ecsManager->createEntity();
    int character_mcg = this->_ecsManager->createEntity();
    int mcg_bg = this->_ecsManager->createEntity();
    int character_sprout = this->_ecsManager->createEntity();
    int sprout_bg = this->_ecsManager->createEntity();
    int character_trelawney = this->_ecsManager->createEntity();
    int trelawney_bg = this->_ecsManager->createEntity();
    int character_snape = this->_ecsManager->createEntity();
    int snape_bg = this->_ecsManager->createEntity();
    int camera = this->_ecsManager->createEntity();
    int x = 0;
    std::string winner = "time ! no one won";
    if (modelType == ModelType::MCG) {
        winner = "McGonagall won !";
        x = 600;
    } else if (modelType == ModelType::SPROUT) {
        winner = "Sprout won !";
        x = 720;
    } else if (modelType == ModelType::TRELAWNEY) {
        winner = "Trelawney won !";
        x = 650;
    } else if (modelType == ModelType::SNAPE) {
        winner = "Snape won !";
        x = 720;
    }

    int total = 420 * 4;
    int start_pos = (1920/2 - total/2);

    this->_music = Raylib_encp.LoadMStream("assets/sounds/char_select_bg.mp3");
    this->_type = SCENE_GAME_OVER;
    this->_title_texture = Raylib_encp.LTexture("assets/materials/selection/title_bar.png");
    this->_btn_font = Raylib_encp.LFontEx("assets/fonts/wizarding.ttf", 90, 0, 0);
    this->_btn_textures[0] = Raylib_encp.LTexture("assets/materials/buttons/btn_hovered.png");
    this->_btn_textures[1] = Raylib_encp.LTexture("assets/materials/buttons/btn_inactive.png");
    this->_btn_textures[2] = Raylib_encp.LTexture("assets/materials/buttons/btn_clicked.png");
    this->_background_texture = Raylib_encp.LTexture("assets/materials/selection/background.png");

    //this->_box Textures
    this->_looser = Raylib_encp.LTexture("assets/materials/selection/btn_hovered.png");
    this->_victory = Raylib_encp.LTexture("assets/materials/selection/btn_clicked.png");

    // Creating vector texture and the mesh order for mcg
    this->_textures_mcg = {
        Raylib_encp.LTexture("assets/models/mcg/c_McGonagall_Body_Diffuse_v1@4x.png"),
        Raylib_encp.LTexture("assets/models/mcg/c_McGonagall_eyes_Diffuse_v1@4x.png"),
        Raylib_encp.LTexture("assets/models/mcg/c_McGonagall_hands_Diffuse_v1@4x.png"),
        Raylib_encp.LTexture("assets/models/mcg/c_McGonagall_Hat_Diffuse_v1@4x.png"),
        Raylib_encp.LTexture("assets/models/mcg/c_McGonagall_Head_Diffuse_v1@4x.png"),
        Raylib_encp.LTexture("assets/models/mcg/glass.png")
    };
    std::vector<int> meshOrder_mcg = {
        1, 2, 3, 5, 0, 4
    };
    Vector3 rotationAxis = {2.0f, 0.0f, 0.0f};

    //sprout
        this->_textures_sprout = {
        Raylib_encp.LTexture("assets/models/sprout/Sprout_body_diffuse_v1@4x.png"),
        Raylib_encp.LTexture("assets/models/sprout/Sprout_cloak_diffuse_v1@4x.png"),
        Raylib_encp.LTexture("assets/models/sprout/Sprout_eyes_diffuse_v1@4x.png"),
        Raylib_encp.LTexture("assets/models/sprout/Sprout_face_diffuse_v1@4x.png"),
        Raylib_encp.LTexture("assets/models/sprout/Sprout_hair_diffuse_v1@4x.png"),
        Raylib_encp.LTexture("assets/models/sprout/Sprout_hand_diffuse_v1@4x.png"),
        Raylib_encp.LTexture("assets/models/sprout/Sprout_hat_diffuse_v1@4x.png")
    };
    std::vector<int> meshOrder_sprout = {
        1, 5, 4, 0, 6, 3, 2
    };

        // Creating Model , vector texture and the mesh order for Trelawney
    this->_texturesTre = {
        Raylib_encp.LTexture("assets/models/trelawney/ProfTrelawney_accessory_diffuse_v1@4x.png"),
        Raylib_encp.LTexture("assets/models/trelawney/ProfTrelawney_body_diffuse_v1@4x.png"),
        Raylib_encp.LTexture("assets/models/trelawney/Trelawney_face_diffuse_v1@4x.png"),
        Raylib_encp.LTexture("assets/models/trelawney/Trelawney_hair_diffuse_v1@4x.png"),
        Raylib_encp.LTexture("assets/models/trelawney/Trelawney_hands_diffuse_v1@4x.png"),
        Raylib_encp.LTexture("assets/models/trelawney/Trelawney_eyes_diffuse_v1@4x.png")
    };
    std::vector<int> meshOrderTrelawney = {
        2, 1, 0, 6, 3, 4
    };

    // Creating Model , vector texture and the mesh order for Snape
    this->_textures_snape = {
        Raylib_encp.LTexture("assets/models/snape/c_Snape_Hair_diffuse_v3@4x.png"),
        Raylib_encp.LTexture("assets/models/snape/c_Snape_Hands_diffuse_v8@4x.png"),
        Raylib_encp.LTexture("assets/models/snape/c_Snape_Head_diffuse_v3@4x.png"),
        Raylib_encp.LTexture("assets/models/snape/c_Snape_Outfit_diffuse_v3@4x.png"),
        Raylib_encp.LTexture("assets/models/snape/EyesBW_v169@4x.png")
    };
    std::vector<int> meshOrderSnape = {
       4, 3, 0, 2, 1
    };

    Raylib_encp.PlayMStream(this->_music);

    // Title
    this->_ecsManager->addComponent(title_id, std::make_unique<Placable>(960 - _title_texture.width / 2, 0));
    this->_ecsManager->addComponent(title_id, std::make_unique<DrawableSprite>(this->_title_texture, 1));

    // Text
    this->_ecsManager->addComponent(title_text, std::make_unique<Placable>(x, 60));
    this->_ecsManager->addComponent(title_text, std::make_unique<DrawableText>(2, winner, Color{255, 255, 255, 255}, this->_btn_font));
    // Background texture
    this->_ecsManager->addComponent(bg_id, std::make_unique<Placable>(0, 0));
    this->_ecsManager->addComponent(bg_id, std::make_unique<DrawableSprite>(this->_background_texture, 0));

    if (modelType == ModelType::MCG) {
        this->_SoundMcg = {
            Raylib_encp.LSound("assets/sounds/mcg/selection/mcg_won_01.wav"),
            Raylib_encp.LSound("assets/sounds/mcg/selection/mcg_won_02.wav"),
            Raylib_encp.LSound("assets/sounds/mcg/selection/mcg_won_03.wav"),
        };
    } else {
        this->_SoundMcg = {
            Raylib_encp.LSound("assets/sounds/mcg/selection/mcg_lost_01.wav"),
            Raylib_encp.LSound("assets/sounds/mcg/selection/mcg_lost_02.wav"),
            Raylib_encp.LSound("assets/sounds/mcg/selection/mcg_lost_03.wav"),
        };
    }
    if (modelType == ModelType::SPROUT) {
        this->_SoundSprout = {
            Raylib_encp.LSound("assets/sounds/sprout/selection/sprout_won_01.wav"),
            Raylib_encp.LSound("assets/sounds/sprout/selection/sprout_won_02.wav"),
            Raylib_encp.LSound("assets/sounds/sprout/selection/sprout_won_03.wav"),
        };
    } else {
        this->_SoundSprout = {
            Raylib_encp.LSound("assets/sounds/sprout/selection/sprout_lost_01.wav"),
            Raylib_encp.LSound("assets/sounds/sprout/selection/sprout_lost_02.wav"),
            Raylib_encp.LSound("assets/sounds/sprout/selection/sprout_lost_03.wav"),
        };
    }
    if (modelType == ModelType::TRELAWNEY) {
        this->_SoundTrelawney = {
            Raylib_encp.LSound("assets/sounds/trelawney/selection/trelawney_won_01.wav"),
            Raylib_encp.LSound("assets/sounds/trelawney/selection/trelawney_won_02.wav"),
            Raylib_encp.LSound("assets/sounds/trelawney/selection/trelawney_won_03.wav"),
        };
    } else {
        this->_SoundTrelawney = {
            Raylib_encp.LSound("assets/sounds/trelawney/selection/trelawney_lost_01.wav"),
            Raylib_encp.LSound("assets/sounds/trelawney/selection/trelawney_lost_02.wav"),
            Raylib_encp.LSound("assets/sounds/trelawney/selection/trelawney_lost_03.wav"),
        };
    }
    if (modelType == ModelType::SNAPE) {
        this->_SoundSnape = {
            Raylib_encp.LSound("assets/sounds/snape/selection/snape_won_01.wav"),
            Raylib_encp.LSound("assets/sounds/snape/selection/snape_won_02.wav"),
            Raylib_encp.LSound("assets/sounds/snape/selection/snape_won_03.wav"),
        };
    } else {
        this->_SoundSnape = {
            Raylib_encp.LSound("assets/sounds/snape/selection/snape_lost_01.wav"),
            Raylib_encp.LSound("assets/sounds/snape/selection/snape_lost_02.wav"),
            Raylib_encp.LSound("assets/sounds/snape/selection/snape_lost_03.wav"),
        };
    }

    // Box for the characters selection
    
    this->_ecsManager->addComponent(camera, std::make_unique<CameraComponent>(position, target, up, 45.0f, CAMERA_PERSPECTIVE));

    //mcg

    this->_ecsManager->addComponent(character_mcg, std::make_unique<Placable>(-52.0f, -2.0f, 0.0f, rotationAxis, -90.0f, scale));
    Model mgmModel = Raylib_encp.LModel("assets/models/mcg/mcg.iqm");
    mgmModel.transform = Raylib_encp.MatrixRotZ(-0.1);
    this->_ecsManager->addComponent(character_mcg, std::make_unique<DrawableModel>(_textures_mcg, mgmModel, meshOrder_mcg, 2));
    if (modelType == ModelType::MCG)
        this->_ecsManager->addComponent(character_mcg, std::make_unique<Animable>("assets/models/mcg/mcg.iqm", ANIMATION_TYPE::WON));
    else
        this->_ecsManager->addComponent(character_mcg, std::make_unique<Animable>("assets/models/mcg/mcg.iqm", ANIMATION_TYPE::LOST));

    //sprout
    this->_ecsManager->addComponent(character_sprout, std::make_unique<Placable>(0.0f, -2.0f, 0.0f, rotationAxis, -90.0f, scale));
    Model sproutModel = Raylib_encp.LModel("assets/models/sprout/sprout.iqm");
    this->_ecsManager->addComponent(character_sprout, std::make_unique<DrawableModel>(_textures_sprout, sproutModel, meshOrder_sprout, 2));
    if (modelType == ModelType::SPROUT)
        this->_ecsManager->addComponent(character_sprout, std::make_unique<Animable>("assets/models/sprout/sprout.iqm", ANIMATION_TYPE::WON));
    else
        this->_ecsManager->addComponent(character_sprout, std::make_unique<Animable>("assets/models/sprout/sprout.iqm", ANIMATION_TYPE::LOST));

    //Trelawney
    this->_ecsManager->addComponent(character_trelawney, std::make_unique<Placable>(59.0f, -2.0f, 0.0f, rotationAxis, -90.0f, scale));
    Model trelawneyModel = Raylib_encp.LModel("assets/models/trelawney/trelawney.iqm");
    trelawneyModel.transform = Raylib_encp.MatrixRotZ(0.2);
    this->_ecsManager->addComponent(character_trelawney, std::make_unique<DrawableModel>(_texturesTre, trelawneyModel, meshOrderTrelawney, 2));
    if (modelType == ModelType::TRELAWNEY)
        this->_ecsManager->addComponent(character_trelawney, std::make_unique<Animable>("assets/models/trelawney/trelawney.iqm", ANIMATION_TYPE::WON));
    else
        this->_ecsManager->addComponent(character_trelawney, std::make_unique<Animable>("assets/models/trelawney/trelawney.iqm", ANIMATION_TYPE::LOST));

    //Snape
    this->_ecsManager->addComponent(character_snape, std::make_unique<Placable>(126.0f, -2.0f, 0.0f, rotationAxis, -90.0f, scale));
    Model snapeModel = Raylib_encp.LModel("assets/models/snape/snape.iqm");
    snapeModel.transform = Raylib_encp.MatrixRotZ(0.6);
    this->_ecsManager->addComponent(character_snape, std::make_unique<DrawableModel>(_textures_snape, snapeModel, meshOrderSnape, 2));
    if (modelType == ModelType::SNAPE)
        this->_ecsManager->addComponent(character_snape, std::make_unique<Animable>("assets/models/snape/snape.iqm", ANIMATION_TYPE::WON));
    else
        this->_ecsManager->addComponent(character_snape, std::make_unique<Animable>("assets/models/snape/snape.iqm", ANIMATION_TYPE::LOST));

    //button play
    Button(this->_ecsManager.get(), "menu", 724, 900, this->_btn_font, this->_btn_textures, SCENE_MENU, CLICKABLE_ACTION_CHANGE_ECS, this);

    this->_ecsManager->addComponent(music_id, std::make_unique<Musicable>(this->_music));
    // System to add
    this->_ecsManager->addSystem(std::make_unique<Draw>(Draw()));
    this->_ecsManager->addSystem(std::make_unique<MouseClick>(MouseClick()));
    this->_ecsManager->addSystem(std::make_unique<MouseHover>(MouseHover()));
    this->_ecsManager->addSystem(std::make_unique<Music_sys>(Music_sys()));
    this->_ecsManager->addSystem(std::make_unique<Animation>());
    this->_ecsManager->addSystem(std::make_unique<SoundSystem>(SoundSystem()));
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