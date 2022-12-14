/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Timer.cpp
*/


#include "Timer.hpp"
#include "raylib.hpp"
#include "../../Components/Timable/Timable.hpp"
#include "../../Components/Playable/Playable.hpp"
#include "../../Components/Breakable/Breakable.hpp"
#include "../../Components/Animable/Animable.hpp"
#include "powerUp.hpp"

Timer::Timer(ECSManager *ecsManager, std::vector<Entity *> *mapEntities, std::vector<Entity *> *playerEntities)
{
    Raylib::Raylib_encap Raylib_encp;
    this->_ecsManager = ecsManager;
    this->_mapEntities = mapEntities;
    this->_playerEntities = playerEntities;
    this->_powerUpsTexture = {
        Raylib_encp.LTexture("assets/models/gloves/gloves.png"),
        Raylib_encp.LTexture("assets/models/pot/target_plantpot_d.png"),
        Raylib_encp.LTexture("assets/models/shoes/shoes.png"),
        Raylib_encp.LTexture("assets/models/watering_can/wateringCan.obj")
    };
    this->_powerUps = {
        Raylib_encp.LModel("assets/models/gloves/gloves.obj"),
        Raylib_encp.LModel("assets/models/pot/pot.obj"),
        Raylib_encp.LModel("assets/models/shoes/shoes.obj"),
        Raylib_encp.LModel("assets/models/watering_can/wateringCan.obj")
    };
    this->_meshOrderPowerUps = {
        0
    };
    this->_playersFallSounds = {
        Raylib_encp.LSound("assets/sounds/sprout/hurt/sprout_hurt_01.wav"),
    };

    this->_playersFallSoundsa = {

        Raylib_encp.LSound("assets/sounds/trelawney/hurt/trelawney_hurt_01.wav"),
    };

    this->_playersFallSoundsz = {
        Raylib_encp.LSound("assets/sounds/mcg/hurt/mcg_hurt_01.wav"),
    };

    this->_playersFallSoundse = {
        Raylib_encp.LSound("assets/sounds/snape/hurt/snape_hurt_01.wav"),
    };

    this->_soundSize = {0.00025f, 0.00025f, 0.00025f};
    this->_soundTexture = Raylib_encp.LTexture("assets/materials/game/sound.png");
}

Timer::Timer(ModelType modelType)
{
    Raylib::Raylib_encap Raylib_encp;
    if (modelType == ModelType::MCG) {
        this->_SoundMcg = {
            Raylib_encp.LSound("assets/sounds/mcg/win/mcg_win_01.wav"),
            Raylib_encp.LSound("assets/sounds/mcg/win/mcg_win_02.wav"),
            Raylib_encp.LSound("assets/sounds/mcg/win/mcg_win_03.wav"),
        };
    } else {
        this->_SoundMcg = {
            Raylib_encp.LSound("assets/sounds/mcg/lost/mcg_lost_01.wav"),
            Raylib_encp.LSound("assets/sounds/mcg/lost/mcg_lost_02.wav"),
            Raylib_encp.LSound("assets/sounds/mcg/lost/mcg_lost_03.wav"),
        };
    }
    if (modelType == ModelType::SPROUT) {
        this->_SoundSprout = {
            Raylib_encp.LSound("assets/sounds/sprout/win/sprout_win_01.wav"),
            Raylib_encp.LSound("assets/sounds/sprout/win/sprout_win_02.wav"),
            Raylib_encp.LSound("assets/sounds/sprout/win/sprout_win_03.wav"),
        };
    } else {
        this->_SoundSprout = {
            Raylib_encp.LSound("assets/sounds/sprout/lost/sprout_lost_01.wav"),
            Raylib_encp.LSound("assets/sounds/sprout/lost/sprout_lost_02.wav"),
            Raylib_encp.LSound("assets/sounds/sprout/lost/sprout_lost_03.wav"),
        };
    }
    if (modelType == ModelType::TRELAWNEY) {
        this->_SoundTrelawney = {
            Raylib_encp.LSound("assets/sounds/trelawney/win/trelawney_win_01.wav"),
            Raylib_encp.LSound("assets/sounds/trelawney/win/trelawney_win_02.wav"),
            Raylib_encp.LSound("assets/sounds/trelawney/win/trelawney_win_03.wav"),
        };
    } else {
        this->_SoundTrelawney = {
            Raylib_encp.LSound("assets/sounds/trelawney/lost/trelawney_lost_01.wav"),
            Raylib_encp.LSound("assets/sounds/trelawney/lost/trelawney_lost_02.wav"),
            Raylib_encp.LSound("assets/sounds/trelawney/lost/trelawney_lost_03.wav"),
        };
    }
    if (modelType == ModelType::SNAPE) {
        this->_SoundSnape = {
            Raylib_encp.LSound("assets/sounds/snape/win/snape_win_01.wav"),
            Raylib_encp.LSound("assets/sounds/snape/win/snape_win_02.wav"),
            Raylib_encp.LSound("assets/sounds/snape/win/snape_win_03.wav"),
        };
    } else {
        this->_SoundSnape = {
            Raylib_encp.LSound("assets/sounds/snape/lost/snape_lost_01.wav"),
            Raylib_encp.LSound("assets/sounds/snape/lost/snape_lost_02.wav"),
            Raylib_encp.LSound("assets/sounds/snape/lost/snape_lost_03.wav"),
        };
    }
}

Timer::~Timer()
{
    Raylib::Raylib_encap Raylib_encp;
    Raylib_encp.UnlTexture(this->_soundTexture);
}

std::vector<Entity *> *Timer::getMapEntites()
{
    return this->_mapEntities;
}

void Timer::apply(std::vector<IComponent *> component)
{
    // Components [0] Timable [1] DrawableText [2] Placable [3] Animable [4] Soundable
    Raylib::Raylib_encap Raylib_encp;
    srand(time(NULL));
    Timable *time = static_cast<Timable *>(component[0]);
    Placable *place = static_cast<Placable *>(component[2]);
    Animable *anim = static_cast<Animable *>(component[3]);
    Soundable *sound;
    DrawableText *text;
    TIMABLE_TYPE time_type = time->getTimeType();
    Playable *playable;
    Vector3 playerPos = {1.0f, 0.0f, 0.0f};
    int i;
    int count = 0;

    if (time_type == GAME_CLOCK) {
        if (time->isTimeOut()) {
            for (auto &entity : *this->_playerEntities) {
                this->_ecsManager->getEntity(entity->getId())->clearComponent();
                //this->_playerEntities->erase(this->_playerEntities->begin() + count);
                count++;
            }
        }
        text = static_cast<DrawableText *>(component[1]);
        text->setText(std::to_string(time->getTimeLeft()) + "s");
    } else if (time_type == GAME_MANDRAKE) {
        if (time->isTimeOut()) {
            time->setTimer(0.2);
            time->RestartClock();
            time->setTimeType(GAME_MANDRAKE_SECOND);
            anim->setAnimationType(ANIMATION_TYPE::RUN);
        }
    } else if  (time_type == GAME_MANDRAKE_SECOND) {
        if (time->isTimeOut()) {
            sound = static_cast<Soundable *>(component[4]);
            if (sound != nullptr)
                sound->stopSound();
            time->setFinished(true);
            playable = static_cast<Playable *>(time->getPlayable());
            playable->setNbMandrake(playable->getNbMandrake() - 1);
            this->updatePlayer(place->getPosition(), time->getPlayable());
            this->deleteGnome(place->getPosition(), time->getPlayable());
            this->_ecsManager->deleteEntity(time->getIdEntity());

            int particles_id = this->_ecsManager->createEntity();
            this->_ecsManager->addComponent(particles_id, std::make_unique<Placable>(round(place->getX()) + 1, round(place->getY()), round(place->getZ()), playerPos, -90.0f, this->_soundSize));
            this->_ecsManager->addComponent(particles_id, std::make_unique<DrawableCubeTexture>(this->_soundTexture, CubeTextureType::SOUND));
        }
    } else if (time_type == GAME_GNOME && place != nullptr) {
        if (time->isTimeOut()) {
            time->setFinished(true);
            this->deleteGnome(place->getPosition(), time->getPlayable());
            // this->createPowerups(place->getPosition());
        }
    } else if (time_type == GAME_PLAYER_FALL) {
        if (time->isTimeOut()) {
            time->setFinished(true);
            this->deletePlayer(place->getPosition(), time->getPlayable());
        }
    } else if (time_type == END_MCG) {
        if (time->isTimeOut() && this->mcg == false) {
            i = rand() % 3;
            Raylib_encp.PlayS(this->_SoundMcg[i]);
            this->mcg = true;

        }
    } else if (time_type == END_SPROUT) {
        if (time->isTimeOut() && this->sprout == false) {
            i = rand() % 3;
            Raylib_encp.PlayS(this->_SoundSprout[i]);
            this->sprout = true;
        }
    } else if (time_type == END_TRELAWNEY) {
        if (time->isTimeOut() && this->tre == false) {
            i = rand() % 3;
            Raylib_encp.PlayS(this->_SoundTrelawney[i]);
            this->tre = true;
        }
    } else if (time_type == END_SNAPE && this->snape == false) {
        if (time->isTimeOut()) {
            i = rand() % 3;
            Raylib_encp.PlayS(this->_SoundSnape[i]);
            this->snape = true;
        }
    }
}

bool Timer::isInRange(Vector3 bomb_pos, Vector3 breakable_pos, float range)
{
    return (std::abs(breakable_pos.x - bomb_pos.x) < 0.5 && (std::abs(breakable_pos.z - bomb_pos.z)) < range
        || (std::abs(breakable_pos.z - bomb_pos.z) < 0.5 && (std::abs(breakable_pos.x - bomb_pos.x)) < range));
}

SYSTEM_TYPES Timer::getType()
{
    return (TIMER);
}

void Timer::deleteGnome(Vector3 position, void *play)
{
    Vector3 pos;
    Playable *playable = static_cast<Playable *>(play);
    Placable *place;
    Breakable *breakable;
    float range = playable->getRange();
    int count = 0;

    for (auto entity : *this->_mapEntities) {
        if (entity->getComponents().size() != 0 && static_cast<Breakable *>(entity->getComponentsByType(BREAKABLE)) != nullptr) {
            place = static_cast<Placable *>(entity->getComponentsByType(PLACABLE));
            pos = place->getPosition();
            if (isInRange(position, pos, range)) {
                this->_ecsManager->getEntity(entity->getId())->clearComponent();
                this->_mapEntities->erase(this->_mapEntities->begin() + count);
                // this->createPowerups(pos);
            }
        }
        count++;
    }
}

void Timer::updateGnome(Vector3 position, void *play)
{
    Vector3 pos;
    Playable *playable = static_cast<Playable *>(play);
    Placable *place;
    Breakable *breakable;
    float range = playable->getRange();
    for (auto &entity : *this->_mapEntities) {
        if (entity->getComponents().size() != 0 && static_cast<Breakable *>(entity->getComponentsByType(BREAKABLE)) != nullptr) {
            place = static_cast<Placable *>(entity->getComponentsByType(PLACABLE));
            pos = place->getPosition();
            if (isInRange(position, pos, range)) {
                this->_ecsManager->addComponent(entity->getId(), std::make_unique<Animable>("assets/models/gnome/gnome.iqm", ANIMATION_TYPE::RUN, 40));
                this->_ecsManager->addComponent(entity->getId(),std::make_unique<Timable>(0.3, GAME_GNOME, -1, playable));
                this->_ecsManager->addComponent(entity->getId(), std::make_unique<Playable>(3));
                this->_ecsManager->addComponent(entity->getId(), std::make_unique<Movable>());
            }
        }
    }
}

void Timer::updatePlayer(Vector3 position, void *play)
{
    Vector3 pos;
    Playable *playable = static_cast<Playable *>(play);
    Placable *place;
    Breakable *breakable;
    ModelType modelType;
    Raylib::Raylib_encap r;
    float range = playable->getRange();
    for (auto &entity : *this->_playerEntities) {
        if (entity->getComponents().size() != 0 && static_cast<Breakable *>(entity->getComponentsByType(BREAKABLE)) != nullptr) {
            place = static_cast<Placable *>(entity->getComponentsByType(PLACABLE));
            pos = place->getPosition();
            if (isInRange(position, pos, range)) {
                static_cast<Animable *>(entity->getComponentsByType(ANIMABLE))->setAnimationType(ANIMATION_TYPE::FALL);
                static_cast<Animable *>(entity->getComponentsByType(ANIMABLE))->setAnimFrameCounter(0);
                // play sound
                modelType = (ModelType) static_cast<DrawableModel *> (entity->getComponentsByType(DRAWABLE))->getModelType();
                if (modelType == ModelType::SPROUT)
                    //play sprout sound
                    r.PlayS(this->_playersFallSounds[0]);
                entity->addComponent(std::make_unique<Timable>(1.5, GAME_PLAYER_FALL, -1, playable));

                if (modelType == ModelType::TRELAWNEY)
                    r.PlayS(this->_playersFallSoundsa[0]);
                entity->addComponent(std::make_unique<Timable>(1.5, GAME_PLAYER_FALL, -1, playable));
                if (modelType == ModelType::MCG)
                    r.PlayS(this->_playersFallSoundsz[0]);
                entity->addComponent(std::make_unique<Timable>(1.5, GAME_PLAYER_FALL, -1, playable));
                if (modelType == ModelType::SNAPE)
                    r.PlayS(this->_playersFallSoundse[0]);
                entity->addComponent(std::make_unique<Timable>(1.5, GAME_PLAYER_FALL, -1, playable));
            }
        }
    }
}

void Timer::deletePlayer(Vector3 position, void *play)
{
    Vector3 pos;
    Playable *playable = static_cast<Playable *>(play);
    Placable *place;
    Breakable *breakable;
    float range = playable->getRange();
    int count = 0;

    for (auto &entity : *this->_playerEntities) {
        if (entity->getComponents().size() != 0 && static_cast<Breakable *>(entity->getComponentsByType(BREAKABLE)) != nullptr) {
            place = static_cast<Placable *>(entity->getComponentsByType(PLACABLE));
            pos = place->getPosition();
            if (isInRange(position, pos, range)) {
                this->_ecsManager->getEntity(entity->getId())->clearComponent();
                //this->_playerEntities->erase(this->_playerEntities->begin() + count);
            }
        }
        count++;
    }
}

void Timer::createPowerups(Vector3 position)
{
    srand(time(NULL));
    int random = 0;//rand() % 5;
    int random_which_power_up = rand() % 4;
    int power_up;
    PowerUp powerUp;
    std::vector <Texture2D> texturePowerup;

    if (random == 0) {
        power_up = this->_ecsManager->createEntity();
        this->_ecsManager->addComponent(power_up, std::make_unique<Placable>(position.x, position.z, position.y));
        if (random_which_power_up == 0)
            powerUp = PowerUp::POWER_UP_WALL_PASS;
        else if (random_which_power_up == 1)
            powerUp = PowerUp::POWER_UP_BOMB;
        else if (random_which_power_up == 2)
            powerUp = PowerUp::POWER_UP_SPEED;
        else
            powerUp = PowerUp::POWER_UP_RANGE;

        this->_ecsManager->addComponent(power_up, std::make_unique<DrawableModel>(texturePowerup, this->_powerUps[0], this->_meshOrderPowerUps, 1 ));
    }
}