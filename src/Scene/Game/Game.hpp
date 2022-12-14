/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Game
*/

#ifndef GAME_HPP_
#define GAME_HPP_

#include "../Scene.hpp"

class Game : public Scene {
    public:
        Game(std::vector<Model> models, std::vector<CHARACTER_CHOOSEN> *characterChoosen, std::vector<std::unique_ptr<Entity>> entities = std::vector<std::unique_ptr<Entity>>());
        ~Game();
        void Unload() override;
        void loadMap(std::string map);

    protected:
    private:
        std::vector <Entity *> *_mapEntities;
        std::vector <Entity *> _playerEntities;
        Texture2D _gryf_infos_texture;
        Texture2D _rav_infos_texture;
        Texture2D _slyth_infos_texture;
        Texture2D _huff_infos_texture;
        Music music;

        Model mgmModel;
        std::vector<Texture2D> texturesMgm;
        std::vector<int> meshOrderMgm;

        Model trelawneyModel;
        std::vector<Texture2D> texturesTre;
        std::vector<int> meshOrderTrelawney;

        Model snapeModel;
        std::vector<Texture2D> texturesSnape;
        std::vector<int> meshOrderSnape;

        Model sproutModel;
        std::vector<Texture2D> texturesSprout;
        std::vector<int> meshOrderSprout;

        Model mandrakeModel;
        std::vector<Texture2D> texturesMandrake;
        std::vector<int> meshOrderMandrake;
        
        Texture2D grass_texture;
        Texture2D stone_texture;
        std::vector<Texture2D> textures_bag;
        Model bagModel;
        std::vector<Texture2D> textures_tables;
        Model tableModel;
        Model tableModelRotate;
        Model gnome;
        std::vector<Texture2D> textures_gnome;
        std::vector<CHARACTER_CHOOSEN> *_characterChoosen;
        Font _font;
        std::vector<std::unique_ptr<Entity>> *_entities_ecs;
};

#endif /* !GAME_HPP_ */
