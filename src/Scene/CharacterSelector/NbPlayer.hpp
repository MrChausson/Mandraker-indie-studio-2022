/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** NbPlayer
*/

#ifndef NBPLAYER_HPP_
#define NBPLAYER_HPP_
    #include "../Scene.hpp"

class NbPlayer : public Scene {
    public:
        NbPlayer();
        ~NbPlayer();
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
        Font _btn_font;
        Music _music;
        Sound _click;
};

#endif /* !NBPLAYER_HPP_ */
