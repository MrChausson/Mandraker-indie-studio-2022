/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Menu
*/

#ifndef MENU_HPP_
#define MENU_HPP_
    #include "../Scene.hpp"

class Menu : public Scene {
    public:
        Menu();
        ~Menu();
        void Unload() override;
        float getMusicTimePlayed();
        void SetMusicTimePlayed(float dur);

    protected:
    private:
        Texture2D _background_texture;
        Texture2D _btn_textures[3];
        Texture2D _title_texture;
        Font _btn_font;
        Font _title_font;
        Music _music;
        Sound _click;
};

#endif /* !MENU_HPP_ */
