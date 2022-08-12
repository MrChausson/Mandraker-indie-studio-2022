/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Settings
*/

#ifndef SETTINGS_HPP_
#define SETTINGS_HPP_
    #include "../Scene.hpp"

class Settings : public Scene {
    public:
        Settings();
        ~Settings();
        void Unload() override;
        float getMusicTimePlayed();
        void SetMusicTimePlayed(float dur);

    protected:
    private:
        Texture2D _background_texture;
        Texture2D _btn_textures[3];
        Texture2D _minus_textures[3];
        Texture2D _plus_textures[3];
        Texture2D _title_texture;
        Texture2D _state_texture;
        Texture2D _stitle_texture;
        Font _btn_font;
        Font _text_font;
        Font _value_font;
        Music _music;
        Sound _click;
};

#endif /* !SETTINGS_HPP_ */
