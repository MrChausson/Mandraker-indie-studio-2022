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
        CharacterSelector(int nb_characters,  std::vector<CHARACTER_CHOOSEN> *characterChoosen = nullptr);
        ~CharacterSelector();
        std::vector<Model> getModels();
        void Unload() override;
        void resetBoxClicked();
        float getMusicTimePlayed();
        void SetMusicTimePlayed(float dur);
        std::vector<CHARACTER_CHOOSEN> *getCharChoosen();
        void addCharacterChoosen(CHARACTER_CHOOSEN charChoosen);
        void resetCharacterChoosen();
        int nb_characters;
        
    protected:
    private:
        Texture2D _background_texture;
        Texture2D _btn_textures[3];
        Texture2D _title_texture;
        Texture2D _box_texture;
        Texture2D _box[4];
        Font _btn_font;
        Font _title_font;
        Music _music;
        std::vector<Texture2D> _textures_mcg;
        std::vector<Texture2D> _textures_sprout;
        std::vector<Texture2D> _texturesTre;
        std::vector<Texture2D> _textures_snape;
        std::vector<Model> models;
        Sound mcgSound;
        Sound sproutSound;
        Sound treSound;
        Sound snapeSound;
        Sound trelawneySound;
        std::vector<int> _idBoxes;
        std::vector<Sound> _SoundMcg;
        std::vector<Sound> _SoundSprout;
        std::vector<Sound> _SoundTrelawney;
        std::vector<Sound> _SoundSnape;
        std::vector<CHARACTER_CHOOSEN> *_characterChoosen;
};

#endif /* !CHARACTERSELECTOR_HPP_ */
