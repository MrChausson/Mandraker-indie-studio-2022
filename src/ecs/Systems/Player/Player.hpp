/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Player.hpp
*/

#ifndef Player_HPP_
#define Player_HPP_

#include "../../ISystem/ISystem.hpp"
#include "../../../ecs/ECSManager/ECSManager.hpp"
#include <chrono>

class Player : public ISystem {
    public:
        Player(ECSManager *ecsManager, std::vector<Entity *> *mapEntities);
        ~Player();
        void apply(std::vector<IComponent *> component) override;
        SYSTEM_TYPES getType() override;
        ECSManager  *getEcsToChangeTo();
        void setEcsToChangeTo(ECSManager *ecsManager);
        bool checkNearBreakableBlock(Vector3 position);
        Texture2D assetSounds;
        bool isInRange(Vector3 bomb_pos, Vector3 breakable_pos, float range);

    private:
        std::chrono::time_point<std::chrono::system_clock>  _toWait;
        ECSManager *_ecsManager;
        Model _mandrakeModel;
        std::vector<Texture2D> _texturesMandrake;
        std::vector<Texture2D> _texturesBoom;
        std::vector<int> _meshOrderMandrake;
        Vector3 _scaleMandrake;
        Sound _plantSound;
        Sound _shoutSound;
        ECSManager *_ecsToChangeTo = nullptr;
        std::vector<Entity *> *_mapEntities;
};

#endif /* !Player_HPP_ */
