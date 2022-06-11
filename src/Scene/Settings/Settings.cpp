/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Settings
*/

#include "raylib.hpp"
#include "Settings.hpp"
#include "../../ecs/Components/Clickable/Clickable.hpp"
#include "../../Tools/Button.hpp"
#include "../../Engine/Engine.hpp"
#include <string>
#include <math.h>

Settings::Settings()
{
    Raylib::Raylib_encap Raylib_encp;
    int mvolume = round(musicVolume * 100);
    int svolume = round(soundVolume * 100);
    std::cout << "Options creating" << std::endl;
    this->_ecsManager = std::make_unique<ECSManager>();
    int bg_id = this->_ecsManager->createEntity();
    int title_id = this->_ecsManager->createEntity();
    int title_text = this->_ecsManager->createEntity();
    int music_id = this->_ecsManager->createEntity();
    int mtitle_id = this->_ecsManager->createEntity();
    int mtitle_text = this->_ecsManager->createEntity();
    int mvolume_id = this->_ecsManager->createEntity();
    int mvolume_text = this->_ecsManager->createEntity();
    int stitle_id = this->_ecsManager->createEntity();
    int stitle_text = this->_ecsManager->createEntity();
    int svolume_id = this->_ecsManager->createEntity();
    int svolume_text = this->_ecsManager->createEntity();
    int fps_id = this->_ecsManager->createEntity();
    int fps_text = this->_ecsManager->createEntity();
    int vfps_id = this->_ecsManager->createEntity();
    int vfps_text = this->_ecsManager->createEntity();

    this->_music = Raylib_encp.LoadMStream("assets/sounds/menu_bg.mp3");
    this->_click = Raylib_encp.LSound("assets/sounds/menu/click.wav");
    this->_type = SCENE_SETTINGS;
    this->_background_texture = Raylib_encp.LTexture("assets/materials/selection/background.png");
    this->_title_texture = Raylib_encp.LTexture("assets/materials/selection/title_bar.png");
    this->_btn_font = Raylib_encp.LFontEx("assets/fonts/wizarding.ttf", 90, 0, 0);
    this->_text_font = Raylib_encp.LFontEx("assets/fonts/wizarding.ttf", 70, 0, 0);
    this->_value_font = Raylib_encp.LFontEx("assets/fonts/wizarding.ttf", 50, 0, 0);
    this->_btn_textures[0] = Raylib_encp.LTexture("assets/materials/buttons/btn_hovered.png");
    this->_btn_textures[1] = Raylib_encp.LTexture("assets/materials/buttons/btn_inactive.png");
    this->_btn_textures[2] = Raylib_encp.LTexture("assets/materials/buttons/btn_clicked.png");
    this->_stitle_texture = Raylib_encp.LTexture("assets/materials/settings/content.png");
    this->_state_texture = Raylib_encp.LTexture("assets/materials/settings/state.png");
    this->_minus_textures[0] = Raylib_encp.LTexture("assets/materials/settings/left.png");
    this->_minus_textures[1] = Raylib_encp.LTexture("assets/materials/settings/left.png");
    this->_minus_textures[2] = Raylib_encp.LTexture("assets/materials/settings/left_clicked.png");
    this->_plus_textures[0] = Raylib_encp.LTexture("assets/materials/settings/right.png");
    this->_plus_textures[1] = Raylib_encp.LTexture("assets/materials/settings/right.png");
    this->_plus_textures[2] = Raylib_encp.LTexture("assets/materials/settings/right_clicked.png");
    Raylib_encp.PlayMStream(this->_music);

    // Title image
    this->_ecsManager->addComponent(title_id, std::make_unique<Placable>(347.5, 0));
    this->_ecsManager->addComponent(title_id, std::make_unique<DrawableSprite>(this->_title_texture, 1));

    // Title Text
    this->_ecsManager->addComponent(title_text, std::make_unique<Placable>(800, 85));
    this->_ecsManager->addComponent(title_text, std::make_unique<DrawableText>(2,"settings", Color{255, 255, 255, 255}, this->_btn_font));

    this->_ecsManager->addComponent(bg_id, std::make_unique<Placable>(0, 0));
    this->_ecsManager->addComponent(bg_id, std::make_unique<DrawableSprite>(this->_background_texture, 0));

    this->_ecsManager->addComponent(mtitle_id, std::make_unique<Placable>(180, 400));
    this->_ecsManager->addComponent(mtitle_id, std::make_unique<DrawableSprite>(this->_stitle_texture, 0));
    this->_ecsManager->addComponent(mtitle_text, std::make_unique<Placable>(260, 412));
    this->_ecsManager->addComponent(mtitle_text, std::make_unique<DrawableText>(2,"music", Color{255, 255, 255, 255}, this->_text_font));
    Button(this->_ecsManager.get(), 190, 500, this->_minus_textures, CLICKABLE_ACTION_MINUS_MUSIC, this, &this->_click);
    this->_ecsManager->addComponent(mvolume_id, std::make_unique<Placable>(305, 500));
    this->_ecsManager->addComponent(mvolume_id, std::make_unique<DrawableSprite>(this->_state_texture, 0));
    this->_ecsManager->addComponent(mvolume_text, std::make_unique<Placable>(325, 525));
    this->_ecsManager->addComponent(mvolume_text, std::make_unique<DrawableText>(2, std::to_string(mvolume), Color{255, 255, 255, 255}, this->_value_font));
    Button(this->_ecsManager.get(), 420, 500, this->_plus_textures, CLICKABLE_ACTION_PLUS_MUSIC, this, &this->_click);

    this->_ecsManager->addComponent(stitle_id, std::make_unique<Placable>(800, 400));
    this->_ecsManager->addComponent(stitle_id, std::make_unique<DrawableSprite>(this->_stitle_texture, 0));
    this->_ecsManager->addComponent(stitle_text, std::make_unique<Placable>(880, 412));
    this->_ecsManager->addComponent(stitle_text, std::make_unique<DrawableText>(2,"sound", Color{255, 255, 255, 255}, this->_text_font));
    Button(this->_ecsManager.get(), 810, 500, this->_minus_textures, CLICKABLE_ACTION_MINUS_SOUND, this, &this->_click);
    this->_ecsManager->addComponent(svolume_id, std::make_unique<Placable>(925, 500));
    this->_ecsManager->addComponent(svolume_id, std::make_unique<DrawableSprite>(this->_state_texture, 0));
    this->_ecsManager->addComponent(svolume_text, std::make_unique<Placable>(940, 525));
    this->_ecsManager->addComponent(svolume_text, std::make_unique<DrawableText>(2, std::to_string(svolume), Color{255, 255, 255, 255}, this->_value_font));
    Button(this->_ecsManager.get(), 1040, 500, this->_plus_textures, CLICKABLE_ACTION_PLUS_SOUND, this, &this->_click);

    
    this->_ecsManager->addComponent(fps_id, std::make_unique<Placable>(1400, 400));
    this->_ecsManager->addComponent(fps_id, std::make_unique<DrawableSprite>(this->_stitle_texture, 0));
    this->_ecsManager->addComponent(fps_text, std::make_unique<Placable>(1520, 412));
    this->_ecsManager->addComponent(fps_text, std::make_unique<DrawableText>(2,"fps", Color{255, 255, 255, 255}, this->_text_font));
    Button(this->_ecsManager.get(), 1410, 500, this->_minus_textures, CLICKABLE_ACTION_MINUS_FPS, this, &this->_click);
    this->_ecsManager->addComponent(vfps_id, std::make_unique<Placable>(1525, 500));
    this->_ecsManager->addComponent(vfps_id, std::make_unique<DrawableSprite>(this->_state_texture, 0));
    this->_ecsManager->addComponent(vfps_text, std::make_unique<Placable>(1540, 525));
    this->_ecsManager->addComponent(vfps_text, std::make_unique<DrawableText>(2, std::to_string(max_fps), Color{255, 255, 255, 255}, this->_value_font));
    Button(this->_ecsManager.get(), 1640, 500, this->_plus_textures, CLICKABLE_ACTION_PLUS_FPS, this, &this->_click);

    Button(this->_ecsManager.get(), "apply", 724, 900, this->_btn_font, this->_btn_textures, SCENE_MENU, CLICKABLE_ACTION_CHANGE_ECS);

    this->_ecsManager->addComponent(music_id, std::make_unique<Musicable>(this->_music));

    this->_ecsManager->addSystem(std::make_unique<Draw>(Draw()));
    this->_ecsManager->addSystem(std::make_unique<MouseClick>(MouseClick()));
    this->_ecsManager->addSystem(std::make_unique<MouseHover>(MouseHover()));
    this->_ecsManager->addSystem(std::make_unique<Music_sys>(Music_sys()));
}

Settings::~Settings()
{
}


void Settings::Unload()
{
    Raylib::Raylib_encap Raylib_encp;

    Raylib_encp.UnloadMStream(this->_music);
    Raylib_encp.UnlSound(this->_click);
    Raylib_encp.UnlTexture(this->_background_texture);
    Raylib_encp.UnlTexture(this->_title_texture);
    Raylib_encp.UnlTexture(this->_state_texture);
    Raylib_encp.UnlTexture(this->_stitle_texture);
    Raylib_encp.UnlFont(this->_btn_font);
    Raylib_encp.UnlFont(this->_text_font);
    Raylib_encp.UnlFont(this->_value_font);
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

float Settings::getMusicTimePlayed()
{
    Raylib::Raylib_encap Raylib_encp;
    return Raylib_encp.GetMSTimePlayed(this->_music);
}

void Settings::SetMusicTimePlayed(float dur)
{
    Raylib::Raylib_encap Raylib_encp;
    Raylib_encp.SeekMStream(this->_music, dur);
}