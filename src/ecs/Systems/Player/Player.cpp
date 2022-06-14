/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Player.cpp
*/


#include "Player.hpp"
#include "raylib.hpp"
#include "../Timer/Timer.hpp"
#include "../../Components/Animable/Animable.hpp"
#include "../../Components/Timable/Timable.hpp"
#include "../../Components/Playable/Playable.hpp"
#include "../../../Scene/GameSettings/GameSettings.hpp"
#include "../../Components/Breakable/Breakable.hpp"


Player::Player(ECSManager *ecsManager, std::vector<Entity *> *mapEntities)
{
    Raylib::Raylib_encap Raylib_encp;
    this->_ecsManager = ecsManager;
    this->_toWait = std::chrono::system_clock::now();
    this->_mapEntities = mapEntities;

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
    // [0] Placable [1] Movable [2] Playable [3] Animable
    Raylib::Raylib_encap Raylib_encp;
    Placable *playerPlace = static_cast<Placable *>(component[0]);
    Movable *playerMove = static_cast<Movable *>(component[1]);
    Playable *playable = static_cast<Playable *>(component[2]);
    Animable *animable = static_cast<Animable *>(component[3]);
    Vector3 playerPos = {1.0f, 0.0f, 0.0f};
    MOVABLE_TYPE type = playerMove->getMovableType();
    int bomb_id;
    if ( Raylib_encp.isKeyPres(KEY_SPACE)  && type == MOVABLE_PLAYER  && playable->getNbMandrake( ) < playable->getNbMaxMandrake() && animable->getAnimationType() != ANIMATION_TYPE::FALL) {
        playable->setNbMandrake(playable->getNbMandrake() + 1);
        bomb_id = this->_ecsManager->createEntity();
        Raylib_encp.PlayS(this->_shoutSound);
        Raylib_encp.PlayS(this->_plantSound);
        this->_ecsManager->addComponent(bomb_id, std::make_unique<Placable>(round(playerPlace->getX()), round(playerPlace->getY()), round(playerPlace->getZ()), playerPos, -90.0f, this->_scaleMandrake));
        this->_ecsManager->addComponent(bomb_id, std::make_unique<DrawableModel>(this->_texturesMandrake, this->_mandrakeModel, this->_meshOrderMandrake));
        this->_ecsManager->addComponent(bomb_id, std::make_unique<Animable>("assets/models/mandrake/mandrake.iqm", ANIMATION_TYPE::IDLE));
        this->_ecsManager->addComponent(bomb_id, std::make_unique<Soundable>(this->_shoutSound));
        this->_ecsManager->addComponent(bomb_id, std::make_unique<Timable>(3, GAME_MANDRAKE, bomb_id, playable));
        // this->_ecsManager->addComponent(bomb_id, std::make_unique<DrawableSprite>(this->_texturesBoom, 2));
    } else if ( ((Raylib_encp.isKeyPres(KEY_RIGHT_SHIFT)  && !IsGamepadAvailable(0))||  IsGamepadButtonPressed(0, BUTTON_A))&&  type == MOVABLE_PLAYER_2  && playable->getNbMandrake( ) < playable->getNbMaxMandrake() && animable->getAnimationType() != ANIMATION_TYPE::FALL) {
        playable->setNbMandrake(playable->getNbMandrake() + 1);
        bomb_id = this->_ecsManager->createEntity();
        Raylib_encp.PlayS(this->_shoutSound);
        Raylib_encp.PlayS(this->_plantSound);
        this->_ecsManager->addComponent(bomb_id, std::make_unique<Placable>(round(playerPlace->getX()), round(playerPlace->getY()), round(playerPlace->getZ()), playerPos, -90.0f, this->_scaleMandrake));
        this->_ecsManager->addComponent(bomb_id, std::make_unique<DrawableModel>(this->_texturesMandrake, this->_mandrakeModel, this->_meshOrderMandrake));
        this->_ecsManager->addComponent(bomb_id, std::make_unique<Animable>("assets/models/mandrake/mandrake.iqm", ANIMATION_TYPE::IDLE));
        this->_ecsManager->addComponent(bomb_id, std::make_unique<Soundable>(this->_shoutSound));
        this->_ecsManager->addComponent(bomb_id, std::make_unique<Timable>(3, GAME_MANDRAKE, bomb_id, playable));
        // this->_ecsManager->addComponent(bomb_id, std::make_unique<DrawableSprite>(this->_texturesBoom, 2));
    }
    if ( checkNearBreakableBlock(playerPlace->getPosition()) && type == MOVABLE_AI  && playable->getNbMandrake( ) < playable->getNbMaxMandrake() && animable->getAnimationType() != ANIMATION_TYPE::FALL) {
        playable->setNbMandrake(playable->getNbMandrake() + 1);
        bomb_id = this->_ecsManager->createEntity();
        Raylib_encp.PlayS(this->_plantSound);
        Raylib_encp.PlayS(this->_shoutSound);
        this->_ecsManager->addComponent(bomb_id, std::make_unique<Placable>(playerPlace->getX(), playerPlace->getY(), playerPlace->getZ(), playerPos, -90.0f, this->_scaleMandrake));
        this->_ecsManager->addComponent(bomb_id, std::make_unique<DrawableModel>(this->_texturesMandrake, this->_mandrakeModel, this->_meshOrderMandrake));
        this->_ecsManager->addComponent(bomb_id, std::make_unique<Animable>("assets/models/mandrake/mandrake.iqm", ANIMATION_TYPE::IDLE));
        this->_ecsManager->addComponent(bomb_id, std::make_unique<Soundable>(this->_shoutSound));
        this->_ecsManager->addComponent(bomb_id, std::make_unique<Timable>(3, GAME_MANDRAKE, bomb_id, playable));
        // this->_ecsManager->addComponent(bomb_id, std::make_unique<DrawableSprite>(this->_texturesBoom, 2));
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

bool Player::checkNearBreakableBlock(Vector3 position)
{
    Timer *timer;
    Vector3 pos;
    Placable *place;
    Breakable *breakable;
    float range = 3;
    IComponent *component;
    Drawable *drawable;

    for (auto entity : *this->_mapEntities) {
        component = entity->getComponentsByType(BREAKABLE);
        if (entity->getComponents().size() != 0 && component != nullptr) {
            breakable = static_cast<Breakable *>(component);
            place = static_cast<Placable *>(entity->getComponentsByType(PLACABLE));
            pos = place->getPosition();
            if (timer->isInRange(position, pos, range)) {
                return true;
            }
        }
    }
    return false;
}
