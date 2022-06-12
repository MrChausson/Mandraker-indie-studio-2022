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
        std::unique_ptr<IComponent> saveDrawableSprite(std::vector<std::string> lines);
        std::unique_ptr<IComponent> saveDrawableText(std::vector<std::string> lines);
        std::unique_ptr<IComponent> saveCollisionable(std::vector<std::string> lines);
    private:
        std::string _fileToSaveTo;
};

#endif /* !SAVE_HPP_ */
