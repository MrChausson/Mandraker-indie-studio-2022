/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** GameSettings
*/

#ifndef GameSettings_HPP_
#define GameSettings_HPP_
    #include "../Scene.hpp"

class GameSettings : public Scene {
    public:
        GameSettings(ECSManager *_ecsToReturn);
        ~GameSettings();
        void Unload() override;
        float getMusicTimePlayed();
        void SetMusicTimePlayed(float dur);
        ECSManager *_previousEcs;

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

#endif /* !GameSettings_HPP_ */
