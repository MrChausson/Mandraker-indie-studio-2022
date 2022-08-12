/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Save
*/

#ifndef SAVESYSTEM_HPP_
#define SAVESYSTEM_HPP_

#include "../../ISystem/ISystem.hpp"

class SaveSystem : public ISystem {
    public:
        SaveSystem(std::vector<std::unique_ptr<Entity>> *entities);
        ~SaveSystem();
        void apply(std::vector<IComponent *> component) override;
        virtual SYSTEM_TYPES getType() override;
    protected:
    private:
        std::vector<std::unique_ptr<Entity>> *_entities;
};

#endif /* !SAVESYSTEM_HPP_ */
