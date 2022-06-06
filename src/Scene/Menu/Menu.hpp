/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Menu
*/

#ifndef MENU_HPP_
#define MENU_HPP_
    #include "../Scene.hpp"
    #include "../../Engine/Engine.hpp"

class Menu : public Scene {
    public:
        Menu(Engine *engine = nullptr);
        ~Menu();

    protected:
    private:
        Texture2D _background_texture;
        Texture2D _textures[3];
        Texture2D _title_texture;
        Font _btn_font;
        Font _title_font;
        Music _music;
        Scene *_scene;
};

#endif /* !MENU_HPP_ */
