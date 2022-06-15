/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Move
*/

#include "Move.hpp"
#include "raymath.h"
#include "../../Components/Drawable/Drawable.hpp"
#include "../../Components/Drawable/DrawableModel.hpp"
#include "../../Components/Animable/Animable.hpp"
#include "../../Components/Playable/Playable.hpp"
#include "raylib.hpp"
#include "extern.hpp"

int controllerId = 0;

Move::Move(std::vector<Entity *> *map_entities)
{

    this->mapEntities = map_entities;
    std::string controllerStr("Controller");
    std::string name;

    for (int i = 0; i < 50; i++)
        if (IsGamepadAvailable(i)) {
            name = GetGamepadName(i);
            if (name.find(controllerStr) != std::string::npos && name.find("Touchpad") == std::string::npos) {
                controllerId = i;
                break;
            }
            controllerId = -1;
        }
}

Move::~Move()
{
}

SYSTEM_TYPES Move::getType()
{
    return MOVE;
}

void Move::apply(std::vector<IComponent *> component)
{
    Raylib::Raylib_encap Raylib_encp;
    Animable *anims = static_cast<Animable *> (component[0]);
    DrawableModel *model = static_cast<DrawableModel *>(component[1]);
    Placable *placable = static_cast<Placable *> (component[2]);
    Collisionable *collision;
    Movable *movable = static_cast<Movable *> (component[4]);
    auto timelimit = std::chrono::seconds{1};

    std::chrono::duration<double> elapsed_seconds = movable->getElapsedSeconds();
    float to_move = movable->getSpeed() * elapsed_seconds.count();
    movable->RestartClock();
    MOVABLE_TYPE type = movable->getMovableType();
    movable->setEndIAclock();
    movable->setTimedurationIAclock();
    this->timeduration = movable->getTimedurationIA();

    if (type == MOVABLE_PLAYER && anims->getAnimationType() != ANIMATION_TYPE::FALL) {
        collision = static_cast<Collisionable *> (component[3]);
        if (collision == nullptr)
            throw MissingCollisionableComponent("No collisionable component found");
        if (Raylib_encp.IsKDown(KEY_D) && !collision->isColliding(placable->getX() + to_move, placable->getY() ,placable->getZ(), this->mapEntities)) {
            anims->setAnimationType(RUN);
            model->getPtrModel()->transform = Raylib_encp.MatrixRotZ(-1.5);
            placable->setX(placable->getX() + to_move);
        } else if (Raylib_encp.IsKDown(KEY_A) && !collision->isColliding(placable->getX() - to_move, placable->getY() ,placable->getZ(), this->mapEntities)) {
            anims->setAnimationType(RUN);
            model->getPtrModel()->transform = Raylib_encp.MatrixRotZ(1.5);
            placable->setX(placable->getX() - to_move);
        } else if (Raylib_encp.IsKDown(KEY_W) && !collision->isColliding(placable->getX(), placable->getY() ,placable->getZ() - to_move, this->mapEntities)) {
            anims->setAnimationType(RUN);
            model->getPtrModel()->transform = Raylib_encp.MatrixRotZ(3);
            placable->setZ(placable->getZ() - to_move);
        } else if (Raylib_encp.IsKDown(KEY_S) && !collision->isColliding(placable->getX(), placable->getY() ,placable->getZ() + to_move, this->mapEntities)) {
            anims->setAnimationType(RUN);
            model->getPtrModel()->transform = Raylib_encp.MatrixRotZ(0);
            placable->setZ(placable->getZ() + to_move);
        } else
            anims->setAnimationType(IDLE);
    }
    else if (type == MOVABLE_PLAYER_2 && IsGamepadAvailable(controllerId) && anims->getAnimationType() != ANIMATION_TYPE::FALL) {
        collision = static_cast<Collisionable *> (component[3]);
        if (IsGamepadButtonDown(controllerId, BUTTON_RIGHT) && !collision->isColliding(placable->getX() + to_move, placable->getY() ,placable->getZ(), this->mapEntities)) {
            anims->setAnimationType(RUN);
            model->getPtrModel()->transform = Raylib_encp.MatrixRotZ(-1.5);
            placable->setX(placable->getX() + to_move);
        } else if (IsGamepadButtonDown(controllerId, BUTTON_LEFT) && !collision->isColliding(placable->getX() - to_move, placable->getY() ,placable->getZ(), this->mapEntities)) {
            anims->setAnimationType(RUN);
            model->getPtrModel()->transform = Raylib_encp.MatrixRotZ(1.5);
            placable->setX(placable->getX() - to_move);
        } else if (IsGamepadButtonDown(controllerId, BUTTON_UP) && !collision->isColliding(placable->getX(), placable->getY() ,placable->getZ() - to_move, this->mapEntities)) {
            anims->setAnimationType(RUN);
            model->getPtrModel()->transform = Raylib_encp.MatrixRotZ(3);
            placable->setZ(placable->getZ() - to_move);
        } else if (IsGamepadButtonDown(controllerId, BUTTON_DOWN) && !collision->isColliding(placable->getX(), placable->getY() ,placable->getZ() + to_move, this->mapEntities)) {
            anims->setAnimationType(RUN);
            model->getPtrModel()->transform = Raylib_encp.MatrixRotZ(0);
            placable->setZ(placable->getZ() + to_move);
        } else
            anims->setAnimationType(IDLE);
    }
    else if (type == MOVABLE_PLAYER_2  && anims->getAnimationType() != ANIMATION_TYPE::FALL) {
        collision = static_cast<Collisionable *> (component[3]);
        if (Raylib_encp.IsKDown(KEY_RIGHT) && !collision->isColliding(placable->getX() + to_move, placable->getY() ,placable->getZ(), this->mapEntities)) {
            anims->setAnimationType(RUN);
            model->getPtrModel()->transform = Raylib_encp.MatrixRotZ(-1.5);
            placable->setX(placable->getX() + to_move);
        } else if (Raylib_encp.IsKDown(KEY_LEFT) && !collision->isColliding(placable->getX() - to_move, placable->getY() ,placable->getZ(), this->mapEntities)) {
            anims->setAnimationType(RUN);
            model->getPtrModel()->transform = Raylib_encp.MatrixRotZ(1.5);
            placable->setX(placable->getX() - to_move);
        } else if (Raylib_encp.IsKDown(KEY_UP) && !collision->isColliding(placable->getX(), placable->getY() ,placable->getZ() - to_move, this->mapEntities)) {
            anims->setAnimationType(RUN);
            model->getPtrModel()->transform = Raylib_encp.MatrixRotZ(3);
            placable->setZ(placable->getZ() - to_move);
        } else if (Raylib_encp.IsKDown(KEY_DOWN) && !collision->isColliding(placable->getX(), placable->getY() ,placable->getZ() + to_move, this->mapEntities)) {
            anims->setAnimationType(RUN);
            model->getPtrModel()->transform = Raylib_encp.MatrixRotZ(0);
            placable->setZ(placable->getZ() + to_move);
        } else
            anims->setAnimationType(IDLE);
    }
    else if (type == MOVABLE_AI && anims->getAnimationType() != ANIMATION_TYPE::FALL) {
        collision = static_cast<Collisionable *> (component[3]);
        if (this->timeduration >= timelimit) {
            //TODO: AI moving parameters here Alexandre
            int rngvalue = Raylib_encp.GetRngValue(0, 3);
            // int rngvalue = getdirection(collision, placable);
            // go right
            if (rngvalue == 0 /*&& !collision->isColliding(placable->getX() + to_move, placable->getY() ,placable->getZ())*/&& !collision->isColliding(placable->getX() + 1, placable->getY() ,placable->getZ(), this->mapEntities)) {
                anims->setAnimationType(RUN);
                model->getPtrModel()->transform = Raylib_encp.MatrixRotZ(1.5);
                placable->setX(placable->getX() + 1);
                movable->setIAActionType(IA_ACTION::IA_MOVE);
            }
            // go left
            else if (rngvalue == 1 /*&& !collision->isColliding(placable->getX() - to_move, placable->getY() ,placable->getZ())*/ && !collision->isColliding(placable->getX() - 1, placable->getY() ,placable->getZ(), this->mapEntities)) {
                anims->setAnimationType(RUN);
                model->getPtrModel()->transform = Raylib_encp.MatrixRotZ(1.5);
                placable->setX(placable->getX() - 1);
                movable->setIAActionType(IA_ACTION::IA_MOVE);
            }
            // go up
            else if (rngvalue == 2 /*&& !collision->isColliding(placable->getX(), placable->getY() ,placable->getZ() - to_move)*/ && !collision->isColliding(placable->getX(), placable->getY() ,placable->getZ() - 1, this->mapEntities)) {
                anims->setAnimationType(RUN);
                model->getPtrModel()->transform = Raylib_encp.MatrixRotZ(3);
                placable->setZ(placable->getZ() - 1);
                movable->setIAActionType(IA_ACTION::IA_MOVE);
            }
            // go down
            else if (rngvalue == 3/* && !collision->isColliding(placable->getX(), placable->getY() ,placable->getZ() + to_move)*/ && !collision->isColliding(placable->getX(), placable->getY() ,placable->getZ() + 1, this->mapEntities)) {
                anims->setAnimationType(RUN);
                model->getPtrModel()->transform = Raylib_encp.MatrixRotZ(0);
                placable->setZ(placable->getZ() + 1);
                movable->setIAActionType(IA_ACTION::IA_MOVE);
            }
            // nothing
            else {
                anims->setAnimationType(IDLE);
                movable->setIAActionType(IA_ACTION::IA_STAY);
            }
            movable->restartTimedurationIAclock();
        }
    }
    movable->setstartIAclock();
}

int Move::getdirection(Collisionable *collision, Placable *placable)
{
    Raylib::Raylib_encap Raylib_encp;
    int i = Raylib_encp.GetRngValue(0, 3);

    if (i = 0 && !collision->isColliding(placable->getX() + 1, placable->getY() ,placable->getZ(), this->mapEntities))
        return i;
    else if (i = 1 && !collision->isColliding(placable->getX() - 1, placable->getY() ,placable->getZ(), this->mapEntities))
        return i;
    else if (i = 2 && !collision->isColliding(placable->getX(), placable->getY() ,placable->getZ() - 1, this->mapEntities))
        return i;
    else if (i = 3 && !collision->isColliding(placable->getX(), placable->getY() ,placable->getZ() + 1, this->mapEntities))
        return i;
    else
        return 42;
}