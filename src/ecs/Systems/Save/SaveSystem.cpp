/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** SaveSystem
*/

#include "SaveSystem.hpp"
#include "../../../Engine/Save/Save.hpp"


SaveSystem::SaveSystem(std::vector<std::unique_ptr<Entity>> *entities)
{
    this->_entities = entities;
}

void SaveSystem::apply(std::vector<IComponent *> component)
{
    if (IsKeyReleased(KEY_F1)) {
        std::vector<Entity *> entities;
        for (auto &entity : *this->_entities) {
            entities.push_back(entity.get());
        }
        Save save("game.save");
        std::cout << "Saving..." << std::endl;
        save.save(entities);
    }
}

SaveSystem::~SaveSystem()
{
}

SYSTEM_TYPES SaveSystem::getType()
{
    return SAVE;
}