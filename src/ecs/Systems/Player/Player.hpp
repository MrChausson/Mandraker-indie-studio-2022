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
        Player(ECSManager *ecsManager);
        ~Player();
        void apply(std::vector<IComponent *> component) override;
        SYSTEM_TYPES getType() override;

    private:
        std::chrono::time_point<std::chrono::system_clock>  _toWait;
        ECSManager *_ecsManager;
        Model _mandrakeModel;
        std::vector<Texture2D> _texturesMandrake;
        std::vector<int> _meshOrderMandrake;
        Vector3 _scaleMandrake;
        Sound _plantSound;
};

#endif /* !Player_HPP_ */
