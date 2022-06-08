/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Settings
*/

#ifndef CHARACTERSELECTOR_HPP_
#define CHARACTERSELECTOR_HPP_
    #include "../Scene.hpp"
    #include "../../Engine/Engine.hpp"

class CharacterSelector : public Scene {
    public:
        CharacterSelector(Engine *engine = nullptr);
        ~CharacterSelector();

    protected:
    private:
        Texture2D _background_texture;
        Texture2D _textures[3];
        Texture2D _title_texture;
        Texture2D _texture_menuperso;
        Font _btn_font;
        Font _title_font;
        Music _music;
};

#endif /* !CHARACTERSELECTOR_HPP_ */
