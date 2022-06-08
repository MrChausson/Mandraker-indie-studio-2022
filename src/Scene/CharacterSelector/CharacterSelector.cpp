/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Settings
*/

#include "CharacterSelector.hpp"
#include "raylib.h"
#include "../../ecs/Components/Clickable/Clickable.hpp"
#include "../../Tools/Button.hpp"
#include <string>
#include "../../ecs/Components/CameraComponent/CameraComponent.hpp"
#include "../../ecs/Components/Animable/Animable.hpp"
#include "../../ecs/Systems/Animation/Animation.hpp"

CharacterSelector::CharacterSelector(Engine *engine)
{
    Vector3 position = { 90.0f, 1.0f, 0.0f };
    Vector3 target = { 0.0f, 0.0f, 0.0f }; //  Gauche-Droite|Haut-bas|??
    Vector3 up = { 0.0f, 1.0f, 0.0f };
    Vector3 scale = { 0.5, 0.5, 0.5 };

    std::cout << "Options creating" << std::endl;
    this->_ecsManager = std::make_unique<ECSManager>();
    int bg_id = this->_ecsManager->createEntity();
    int title_id = this->_ecsManager->createEntity();
    int title_text = this->_ecsManager->createEntity();
    int music_id = this->_ecsManager->createEntity();
    int bg_perso1 = this->_ecsManager->createEntity(); 
    int bg_perso2 = this->_ecsManager->createEntity(); 
    int bg_perso3 = this->_ecsManager->createEntity(); 
    int bg_perso4 = this->_ecsManager->createEntity(); 
    int character_mcg = this->_ecsManager->createEntity();
    int camera = this->_ecsManager->createEntity();

    int total = 420 * 4;
    int start_pos = (1920/2 - total/2);

    this->_music = LoadMusicStream("assets/sounds/char_select_bg.mp3");
    this->_type = SCENE_CHARACTER_SELECTOR;
    this->_background_texture = LoadTexture("assets/materials/selection/background.png");
    this->_title_texture = LoadTexture("assets/materials/selection/title_bar.png");
    this->_btn_font = LoadFontEx("assets/fonts/wizarding.ttf", 90, 0, 0);
    this->_btn_textures[0] = LoadTexture("assets/materials/buttons/btn_hovered.png");
    this->_btn_textures[1] = LoadTexture("assets/materials/buttons/btn_inactive.png");
    this->_btn_textures[2] = LoadTexture("assets/materials/buttons/btn_clicked.png");
    this->_box_texture = LoadTexture("assets/materials/selection/btn_inactive.png");

    // Creating vector texture and the mesh order for mcg 
    std::vector<Texture2D> textures_mcg = {
        LoadTexture("assets/models/mcg/c_McGonagall_Body_Diffuse_v1@4x.png"),
        LoadTexture("assets/models/mcg/c_McGonagall_eyes_Diffuse_v1@4x.png"),
        LoadTexture("assets/models/mcg/c_McGonagall_hands_Diffuse_v1@4x.png"),
        LoadTexture("assets/models/mcg/c_McGonagall_Hat_Diffuse_v1@4x.png"),
        LoadTexture("assets/models/mcg/c_McGonagall_Head_Diffuse_v1@4x.png"),
        LoadTexture("assets/models/mcg/glass.png")
    };
    std::vector<int> meshOrder_mcg = {
        1, 2, 3, 5, 0, 4
    };
    Vector3 rotationAxis = {2.0f, 0.0f, 0.0f};

    PlayMusicStream(this->_music);

    this->_ecsManager->addComponent(title_id, std::make_unique<Placable>(347.5, 0));
    this->_ecsManager->addComponent(title_id, std::make_unique<DrawableSprite>(this->_title_texture, 1));

    this->_ecsManager->addComponent(title_text, std::make_unique<Placable>(430, 85));
    this->_ecsManager->addComponent(title_text, std::make_unique<DrawableText>(2,"choose your character", Color{255, 255, 255, 255}, this->_btn_font));

    this->_ecsManager->addComponent(bg_id, std::make_unique<Placable>(0, 0));
    this->_ecsManager->addComponent(bg_id, std::make_unique<DrawableSprite>(this->_background_texture, 0));


    this ->_ecsManager->addComponent(bg_perso1, std::make_unique<Placable>(start_pos, 260));
    this->_ecsManager->addComponent(bg_perso1, std::make_unique<DrawableSprite>(this->_box_texture, 1));

    this ->_ecsManager->addComponent(bg_perso2, std::make_unique<Placable>(start_pos + (420*1), 260));
    this->_ecsManager->addComponent(bg_perso2, std::make_unique<DrawableSprite>(this->_box_texture, 1));
    
    this ->_ecsManager->addComponent(bg_perso3, std::make_unique<Placable>(start_pos + (420*2), 260));
    this->_ecsManager->addComponent(bg_perso3, std::make_unique<DrawableSprite>(this->_box_texture, 1));
    
    this ->_ecsManager->addComponent(bg_perso4, std::make_unique<Placable>(start_pos + (420*3), 260));
    this->_ecsManager->addComponent(bg_perso4, std::make_unique<DrawableSprite>(this->_box_texture, 1));

    Button(this->_ecsManager.get(), "confirm", 724, 900, this->_btn_font, this->_btn_textures, SCENE_GAME, CLICKABLE_ACTION_CHANGE_ECS);

    this->_ecsManager->addComponent(music_id, std::make_unique<Musicable>(this->_music));

    this->_ecsManager->addSystem(std::make_unique<Draw>(Draw()));
    this->_ecsManager->addSystem(std::make_unique<MouseClick>(MouseClick()));
    this->_ecsManager->addSystem(std::make_unique<MouseHover>(MouseHover()));
    this->_ecsManager->addSystem(std::make_unique<Music_sys>(Music_sys()));
}

CharacterSelector::~CharacterSelector()
{
}
