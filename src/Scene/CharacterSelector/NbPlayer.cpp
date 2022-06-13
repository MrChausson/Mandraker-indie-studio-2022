/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** NbPlayer
*/

#include "raylib.hpp"
#include "NbPlayer.hpp"
#include "../../ecs/Components/Clickable/Clickable.hpp"
#include "../../Tools/Button.hpp"
#include "../../Engine/Engine.hpp"
#include <string>
#include <math.h>

NbPlayer::NbPlayer()
{
    Raylib::Raylib_encap Raylib_encp;

    this->_ecsManager = std::make_unique<ECSManager>();
    int bg_id = this->_ecsManager->createEntity();
    int title_id = this->_ecsManager->createEntity();
    int title_text = this->_ecsManager->createEntity();
    int music_id = this->_ecsManager->createEntity();
    int player_id = this->_ecsManager->createEntity();
    int player_text = this->_ecsManager->createEntity();

    this->_music = Raylib_encp.LoadMStream("assets/sounds/menu_bg.mp3");
    this->_click = Raylib_encp.LSound("assets/sounds/menu/click.wav");
    this->_type = SCENE_PLAYERS_SELECTOR;
    this->_background_texture = Raylib_encp.LTexture("assets/materials/selection/background.png");
    this->_title_texture = Raylib_encp.LTexture("assets/materials/selection/title_bar.png");
    this->_btn_font = Raylib_encp.LFontEx("assets/fonts/wizarding.ttf", 90, 0, 0);
    this->_btn_textures[0] = Raylib_encp.LTexture("assets/materials/buttons/btn_hovered.png");
    this->_btn_textures[1] = Raylib_encp.LTexture("assets/materials/buttons/btn_inactive.png");
    this->_btn_textures[2] = Raylib_encp.LTexture("assets/materials/buttons/btn_clicked.png");
    this->_state_texture = Raylib_encp.LTexture("assets/materials/selection/value.png");
    this->_minus_textures[0] = Raylib_encp.LTexture("assets/materials/selection/left.png");
    this->_minus_textures[1] = Raylib_encp.LTexture("assets/materials/selection/left.png");
    this->_minus_textures[2] = Raylib_encp.LTexture("assets/materials/selection/left.png");
    this->_plus_textures[0] = Raylib_encp.LTexture("assets/materials/selection/right.png");
    this->_plus_textures[1] = Raylib_encp.LTexture("assets/materials/selection/right.png");
    this->_plus_textures[2] = Raylib_encp.LTexture("assets/materials/selection/right.png");
    Raylib_encp.PlayMStream(this->_music);

    // Title image
    this->_ecsManager->addComponent(title_id, std::make_unique<Placable>(960 - _title_texture.width / 2, 0));
    this->_ecsManager->addComponent(title_id, std::make_unique<DrawableSprite>(this->_title_texture, 1));

    // Title Text
    this->_ecsManager->addComponent(title_text, std::make_unique<Placable>(500, 60));
    this->_ecsManager->addComponent(title_text, std::make_unique<DrawableText>(2,"how many players?", Color{255, 255, 255, 255}, this->_btn_font));

    this->_ecsManager->addComponent(bg_id, std::make_unique<Placable>(0, 0));
    this->_ecsManager->addComponent(bg_id, std::make_unique<DrawableSprite>(this->_background_texture, 0));

    Button(this->_ecsManager.get(), 721, 545, this->_minus_textures, CLICKABLE_ACTION_MINUS_PLAYER, this, &this->_click);
    this->_ecsManager->addComponent(player_id, std::make_unique<Placable>(851, 476));
    this->_ecsManager->addComponent(player_id, std::make_unique<DrawableSprite>(this->_state_texture, 0));
    this->_ecsManager->addComponent(player_text, std::make_unique<Placable>(945, 545));
    this->_ecsManager->addComponent(player_text, std::make_unique<DrawableText>(2, "1", Color{255, 255, 255, 255}, this->_btn_font));
    Button(this->_ecsManager.get(), 1120, 545, this->_plus_textures, CLICKABLE_ACTION_PLUS_PLAYER, this, &this->_click);

    Button(this->_ecsManager.get(), "confirm", 724, 900, this->_btn_font, this->_btn_textures, SCENE_CHARACTER_SELECTOR, CLICKABLE_ACTION_CHANGE_ECS, this, &this->_click);

    this->_ecsManager->addComponent(music_id, std::make_unique<Musicable>(this->_music));

    this->_ecsManager->addSystem(std::make_unique<Draw>(Draw()));
    this->_ecsManager->addSystem(std::make_unique<MouseClick>(MouseClick()));
    this->_ecsManager->addSystem(std::make_unique<MouseHover>(MouseHover()));
    this->_ecsManager->addSystem(std::make_unique<Music_sys>(Music_sys()));
}

NbPlayer::~NbPlayer()
{
}


void NbPlayer::Unload()
{
    Raylib::Raylib_encap Raylib_encp;

    Raylib_encp.UnloadMStream(this->_music);
    Raylib_encp.UnlSound(this->_click);
    Raylib_encp.UnlTexture(this->_background_texture);
    Raylib_encp.UnlTexture(this->_title_texture);
    Raylib_encp.UnlTexture(this->_state_texture);
    Raylib_encp.UnlFont(this->_btn_font);
    Raylib_encp.UnlTexture(this->_btn_textures[0]);
    Raylib_encp.UnlTexture(this->_btn_textures[1]);
    Raylib_encp.UnlTexture(this->_btn_textures[2]);
    Raylib_encp.UnlTexture(this->_minus_textures[0]);
    Raylib_encp.UnlTexture(this->_minus_textures[1]);
    Raylib_encp.UnlTexture(this->_minus_textures[2]);
    Raylib_encp.UnlTexture(this->_plus_textures[0]);
    Raylib_encp.UnlTexture(this->_plus_textures[1]);
    Raylib_encp.UnlTexture(this->_plus_textures[2]);
}

float NbPlayer::getMusicTimePlayed()
{
    Raylib::Raylib_encap Raylib_encp;
    return Raylib_encp.GetMTimePlayed(this->_music);
}

void NbPlayer::SetMusicTimePlayed(float dur)
{
    Raylib::Raylib_encap Raylib_encp;
    Raylib_encp.SeekMStream(this->_music, dur);
}