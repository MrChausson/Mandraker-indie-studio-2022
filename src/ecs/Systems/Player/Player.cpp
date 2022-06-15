/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Player.cpp
*/


#include "Player.hpp"
#include "raylib.hpp"
#include "../../Components/Animable/Animable.hpp"
#include "../../Components/Timable/Timable.hpp"
#include "../../Components/Playable/Playable.hpp"
#include "../../../Scene/GameSettings/GameSettings.hpp"
#include "extern.hpp"


Player::Player(ECSManager *ecsManager)
{
    Raylib::Raylib_encap Raylib_encp;
    this->_ecsManager = ecsManager;
    this->_toWait = std::chrono::system_clock::now();

    this->_texturesBoom = {
        Raylib_encp.LTexture("assets/materials/game/sounds.png"),
    };
    
    // Creating Mandrake model
    this->_mandrakeModel = Raylib_encp.LModel("assets/models/mandrake/mandrake.iqm");
    this->_texturesMandrake = {
        Raylib_encp.LTexture("assets/models/mandrake/target_mandrake_d.png"),
        Raylib_encp.LTexture("assets/models/mandrake/target_plantpot_d.png"),
    };
    this->_meshOrderMandrake = {
       1, 0
    };
    this->_scaleMandrake = {0.00025f, 0.00025f, 0.00025f};
    this->_plantSound = Raylib_encp.LSound("assets/sounds/mandrake/potting.mp3");
    this->_shoutSound = Raylib_encp.LSound("assets/sounds/mandrake/cries.wav");
    Raylib_encp.SetSVolume(this->_plantSound, soundVolume);
    Raylib_encp.SetSVolume(this->_shoutSound, soundVolume/5);
}

Player::~Player()
{
    Raylib::Raylib_encap Raylib_encp;
    Raylib_encp.UnloadMdl(this->_mandrakeModel);
    Raylib_encp.UnlSound(this->_plantSound);
    Raylib_encp.UnlSound(this->_shoutSound);
    Raylib_encp.UnlTexture(this->_texturesMandrake[0]);
    Raylib_encp.UnlTexture(this->_texturesMandrake[1]);
}

void Player::apply(std::vector<IComponent *> component)
{
    Raylib::Raylib_encap Raylib_encp;
    Placable *playerPlace = static_cast<Placable *>(component[0]);
    Movable *playerMove = static_cast<Movable *>(component[1]);
    Playable *playable = static_cast<Playable *>(component[2]);
    Vector3 playerPos = {1.0f, 0.0f, 0.0f};
    MOVABLE_TYPE type = playerMove->getMovableType();
    int bomb_id;
    if ( Raylib_encp.isKeyPres(KEY_SPACE)  && type == MOVABLE_PLAYER  && playable->getNbMandrake( ) < playable->getNbMaxMandrake()) {
        playable->setNbMandrake(playable->getNbMandrake() + 1);
        bomb_id = this->_ecsManager->createEntity();
        Raylib_encp.PlayS(this->_shoutSound);
        Raylib_encp.PlayS(this->_plantSound);
        this->_ecsManager->addComponent(bomb_id, std::make_unique<Placable>(round(playerPlace->getX()), round(playerPlace->getY()), round(playerPlace->getZ()), playerPos, -90.0f, this->_scaleMandrake));
        this->_ecsManager->addComponent(bomb_id, std::make_unique<DrawableModel>(this->_texturesMandrake, this->_mandrakeModel, this->_meshOrderMandrake));
        this->_ecsManager->addComponent(bomb_id, std::make_unique<Animable>("assets/models/mandrake/mandrake.iqm", ANIMATION_TYPE::IDLE));
        this->_ecsManager->addComponent(bomb_id, std::make_unique<Soundable>(this->_shoutSound));
        this->_ecsManager->addComponent(bomb_id, std::make_unique<Timable>(3, GAME_MANDRAKE, bomb_id, playable));
    } else if ( ((Raylib_encp.isKeyPres(KEY_RIGHT_SHIFT)  && !IsGamepadAvailable(0))||  IsGamepadButtonPressed(0, BUTTON_A))&&  type == MOVABLE_PLAYER_2  && playable->getNbMandrake( ) < playable->getNbMaxMandrake()) {
        playable->setNbMandrake(playable->getNbMandrake() + 1);
        bomb_id = this->_ecsManager->createEntity();
        Raylib_encp.PlayS(this->_shoutSound);
        Raylib_encp.PlayS(this->_plantSound);
        this->_ecsManager->addComponent(bomb_id, std::make_unique<Placable>(round(playerPlace->getX()), round(playerPlace->getY()), round(playerPlace->getZ()), playerPos, -90.0f, this->_scaleMandrake));
        this->_ecsManager->addComponent(bomb_id, std::make_unique<DrawableModel>(this->_texturesMandrake, this->_mandrakeModel, this->_meshOrderMandrake));
        this->_ecsManager->addComponent(bomb_id, std::make_unique<Animable>("assets/models/mandrake/mandrake.iqm", ANIMATION_TYPE::IDLE));
        this->_ecsManager->addComponent(bomb_id, std::make_unique<Soundable>(this->_shoutSound));
        this->_ecsManager->addComponent(bomb_id, std::make_unique<Timable>(3, GAME_MANDRAKE, bomb_id, playable));
    }
    if (Raylib_encp.isKeyPres(KEY_ESCAPE)) {
        GameSettings *settings = new GameSettings(this->_ecsManager);
        this->_ecsToChangeTo = settings->getECS();
    }
}


SYSTEM_TYPES Player::getType()
{
    return (PLAYER);
}

ECSManager  *Player::getEcsToChangeTo()
{
    return (this->_ecsToChangeTo);
}

void Player::setEcsToChangeTo(ECSManager *ecsToChangeTo)
{
    this->_ecsToChangeTo = ecsToChangeTo;
}
