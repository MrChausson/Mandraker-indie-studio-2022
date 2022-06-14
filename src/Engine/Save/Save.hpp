/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Save
*/

#ifndef SAVE_HPP_
    #define SAVE_HPP_
    #include <iostream>
    #include <fstream>
    #include <sstream>
    #include "../../ecs/Entity/Entity.hpp"

class Save {
    public:
        Save(std::string file_to_save);
        ~Save();
        void save(std::vector<Entity *> entities);
        std::vector<std::unique_ptr<Entity>> load();

    protected:
        std::unique_ptr<IComponent> saveTimable(std::vector<std::string> lines);
        std::unique_ptr<IComponent> savePlacable(std::vector<std::string> lines);
        std::unique_ptr<IComponent> saveMovable(std::vector<std::string> lines);
        std::unique_ptr<IComponent> saveAnimable(std::vector<std::string> lines);
        std::unique_ptr<IComponent> saveCamera(std::vector<std::string> lines);
        std::unique_ptr<IComponent> saveDrawableCube(std::vector<std::string> lines);
        std::unique_ptr<IComponent> saveDrawableCubeTexture(std::vector<std::string> lines);
        std::unique_ptr<IComponent> saveDrawableModel(std::vector<std::string> lines);
        std::unique_ptr<IComponent> saveDrawablePlane(std::vector<std::string> lines);
        std::unique_ptr<IComponent> saveDrawableText(std::vector<std::string> lines);
        std::unique_ptr<IComponent> saveCollisionable(std::vector<std::string> lines);
        std::unique_ptr<IComponent> saveBreakable();
    private:
        std::string _fileToSaveTo;
        Texture2D _grassTexture;
        Texture2D _stoneTexture;
        Font _font;
        Model _mgmModel;
        Model _trelawneyModel;
        Model _snapeModel;
        Model _sproutModel;
        Model _gnomeModel;
        Model _bagModel;
        Model _tableModel;
        std::vector<Texture2D> _textures_mcg;
        std::vector<Texture2D> _textures_sprout;
        std::vector<Texture2D> _texturesTre;
        std::vector<Texture2D> _textures_snape;
        std::vector<Texture2D> _texturesGnome;
        std::vector<Texture2D> _texturesBag;
        std::vector<Texture2D> _texturesTable;
        std::vector<int> _meshOrder_mcg;
        std::vector<int> _meshOrder_sprout;
        std::vector<int> _meshOrderTrelawney;
        std::vector<int> _meshOrderSnape;
        std::vector<int> _texture_gnome_mesh_order;
        std::vector<int> _textureBagMeshOrder;
        std::vector<int> _textureTableMeshOrder;
};

#endif /* !SAVE_HPP_ */
