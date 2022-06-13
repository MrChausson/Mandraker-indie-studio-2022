/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Finish.hpp
*/

#ifndef FINISH_HPP_
#define FINISH_HPP_

#include "../../ISystem/ISystem.hpp"
#include "../../ECSManager/ECSManager.hpp"

class Finish : public ISystem {
    public:
        Finish(ECSManager *ecsManager = nullptr, std::vector<Entity *> *playerEntities = nullptr);
        ~Finish();
        void apply(std::vector<IComponent *> component) override;
        SYSTEM_TYPES getType() override;
        ECSManager *getEcsManager();
        bool isFinished();

    private:
        ECSManager *_ecsManager;
        std::vector<Entity *> *_playerEntities;
};

#endif /* !FINISH_HPP_ */
