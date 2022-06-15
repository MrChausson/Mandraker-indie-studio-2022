/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Timer.hpp
*/

#ifndef Timer_HPP_
#define Timer_HPP_

#include "../../ISystem/ISystem.hpp"
#include "../../../ecs/ECSManager/ECSManager.hpp"
#include <chrono>

class Timer : public ISystem {
    public:
        Timer(ECSManager *ecsManager = nullptr, std::vector<Entity *> *mapEntities = nullptr, std::vector<Entity *> *playerEntities = nullptr);
        ~Timer();
        void apply(std::vector<IComponent *> component) override;
        SYSTEM_TYPES getType() override;
        void deleteGnome(Vector3 position, void *play);
        void updateGnome(Vector3 position, void *play);
        bool isInRange(Vector3 bomb_pos, Vector3 breakable_pos, float range);
        void deletePlayer(Vector3 position, void *play);
        void updatePlayer(Vector3 position, void *play);
    private:
        ECSManager *_ecsManager;
        bool _deleted = false;
        std::vector<Entity *> *_mapEntities;
        std::vector<Entity *> *_playerEntities;
        Sound _shoutSound;
        Texture2D _soundTexture;
        Vector3 _soundSize;
};

#endif /* !Timer_HPP_ */
