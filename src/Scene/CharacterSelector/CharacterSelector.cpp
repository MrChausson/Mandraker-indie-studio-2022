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

CharacterSelector::CharacterSelector(Engine *engine)
{
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


    int total = 350 * 4;
    int start_pos = (1920/2 - total/2);
    int btotal = 350 * 2;
    int bstart_pos = (1920/2 - total/2);

    this->_music = LoadMusicStream("assets/sounds/menu_bg.mp3");
    this->_type = SCENE_CHARACTER_SELECTOR;
    this->_background_texture = LoadTexture("assets/materials/main_menu.png");
    this->_title_texture = LoadTexture("assets/materials/title_bar.png");
    this->_btn_font = LoadFontEx("assets/fonts/wizarding.ttf", 100, 0, 0);
    this->_textures[0] = LoadTexture("assets/materials/buttons/btn_hover.png");
    this->_textures[1] = LoadTexture("assets/materials/buttons/btn_inactive.png");
    this->_textures[2] = LoadTexture("assets/materials/buttons/btn_clicked.png");
    this->_texture_menuperso = LoadTexture("assets/materials/menuperso.png");

    PlayMusicStream(this->_music);

    this->_ecsManager->addComponent(title_id, std::make_unique<Placable>(550, 50));
    this->_ecsManager->addComponent(title_id, std::make_unique<DrawableSprite>(this->_title_texture, 1));

    this->_ecsManager->addComponent(title_text, std::make_unique<Placable>(700, 100));
    this->_ecsManager->addComponent(title_text, std::make_unique<DrawableText>(2,"SELECTION DE PERSONNAGE", Color{255, 255, 255, 255}, this->_btn_font));

    this->_ecsManager->addComponent(bg_id, std::make_unique<Placable>(0, 0));
    this->_ecsManager->addComponent(bg_id, std::make_unique<DrawableSprite>(this->_background_texture, 0));



    this ->_ecsManager->addComponent(bg_perso1, std::make_unique<Placable>(start_pos, 200));
    this->_ecsManager->addComponent(bg_perso1, std::make_unique<DrawableSprite>(this->_texture_menuperso, 1));

    this ->_ecsManager->addComponent(bg_perso2, std::make_unique<Placable>(start_pos + (350*1), 200));
    this->_ecsManager->addComponent(bg_perso2, std::make_unique<DrawableSprite>(this->_texture_menuperso, 1));
    
    this ->_ecsManager->addComponent(bg_perso3, std::make_unique<Placable>(start_pos + (350*2), 200));
    this->_ecsManager->addComponent(bg_perso3, std::make_unique<DrawableSprite>(this->_texture_menuperso, 1));
    
    this ->_ecsManager->addComponent(bg_perso4, std::make_unique<Placable>(start_pos + (350*3), 200));
    this->_ecsManager->addComponent(bg_perso4, std::make_unique<DrawableSprite>(this->_texture_menuperso, 1));



    Button(this->_ecsManager.get(), "Play", 724, 900, this->_btn_font, this->_textures, SCENE_GAME, CLICKABLE_ACTION_CHANGE_ECS);

    this->_ecsManager->addComponent(music_id, std::make_unique<Musicable>(this->_music));

    this->_ecsManager->addSystem(std::make_unique<Draw>(Draw()));
    this->_ecsManager->addSystem(std::make_unique<MouseClick>(MouseClick()));
    this->_ecsManager->addSystem(std::make_unique<MouseHover>(MouseHover()));
    this->_ecsManager->addSystem(std::make_unique<Music_sys>(Music_sys()));
}

CharacterSelector::~CharacterSelector()
{
}
