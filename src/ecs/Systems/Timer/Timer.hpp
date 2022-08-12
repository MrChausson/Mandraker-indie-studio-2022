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
#include "../../../ecs/Components/Drawable/DrawableModel.hpp"
#include <chrono>

class Timer : public ISystem {
    public:
        Timer(ECSManager *ecsManager = nullptr, std::vector<Entity *> *mapEntities = nullptr, std::vector<Entity *> *playerEntities = nullptr);
        Timer(ModelType modelType);
        ~Timer();
        void apply(std::vector<IComponent *> component) override;
        SYSTEM_TYPES getType() override;
        void deleteGnome(Vector3 position, void *play);
        std::vector<Entity *> *getMapEntites();
        void updateGnome(Vector3 position, void *play);
        bool isInRange(Vector3 bomb_pos, Vector3 breakable_pos, float range);
        void deletePlayer(Vector3 position, void *play);
        void updatePlayer(Vector3 position, void *play);
        void createPowerups(Vector3 position);
    private:
        ECSManager *_ecsManager;
        bool _deleted = false;
        std::vector<Entity *> *_mapEntities;
        std::vector<Entity *> *_playerEntities;
        std::vector<Model> _powerUps;
        std::vector<int> _meshOrderPowerUps;
        std::vector<Sound> _playersFallSounds;
        std::vector<Sound> _playersFallSoundsa;
        std::vector<Sound> _playersFallSoundsz;
        std::vector<Sound> _playersFallSoundse;
        std::vector<Texture> _powerUpsTexture;
        Sound _shoutSound;
        Texture2D _soundTexture;
        Vector3 _soundSize;
        std::vector<Sound> _SoundMcg;
        std::vector<Sound> _SoundSprout;
        std::vector<Sound> _SoundTrelawney;
        std::vector<Sound> _SoundSnape;
        bool mcg = false;
        bool sprout = false;
        bool tre = false;
        bool snape = false;
};

#endif /* !Timer_HPP_ */
