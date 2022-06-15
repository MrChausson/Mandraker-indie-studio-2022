/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** GameOver.hpp
*/

#ifndef GAMEOVER_HPP_
#define GAMEOVER_HPP_
    #include "../Scene.hpp"

class GameOver : public Scene {
    public:
        GameOver(ModelType modelType);
        ~GameOver();
        void Unload() override;
        float getMusicTimePlayed();
        void SetMusicTimePlayed(float dur);

    protected:
    private:
        Texture2D _background_texture;
        Texture2D _btn_textures[3];
        Texture2D _looser;
        Texture2D _victory;
        Texture2D _title_texture;
        Font _btn_font;
        Font _title_font;
        Music _music;
        Sound _click;
        std::vector<Texture2D> _textures_mcg;
        std::vector<Texture2D> _textures_sprout;
        std::vector<Texture2D> _texturesTre;
        std::vector<Texture2D> _textures_snape;
        std::vector<Sound> _SoundMcg;
        std::vector<Sound> _SoundSprout;
        std::vector<Sound> _SoundTrelawney;
        std::vector<Sound> _SoundSnape;
};

#endif /* !GAMEOVER_HPP_ */
