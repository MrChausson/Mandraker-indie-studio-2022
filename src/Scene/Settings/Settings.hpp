/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Settings
*/

#ifndef SETTINGS_HPP_
#define SETTINGS_HPP_
    #include "../Scene.hpp"
    #include "../../Engine/Engine.hpp"

class Settings : public Scene {
    public:
        Settings(Engine *engine = nullptr);
        ~Settings();

    protected:
    private:
        Texture2D _background_texture;
        Texture2D _textures[3];
        Texture2D _title_texture;
        Font _btn_font;
        Font _title_font;
        Music _music;
};

#endif /* !SETTINGS_HPP_ */
