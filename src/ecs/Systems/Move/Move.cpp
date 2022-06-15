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
#include <time.h>

Move::Move()
{

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
        if (Raylib_encp.IsKDown(KEY_D) && !collision->isColliding(placable->getX() + to_move, placable->getY() ,placable->getZ())) {
            anims->setAnimationType(RUN);
            model->getPtrModel()->transform = Raylib_encp.MatrixRotZ(-1.5);
            placable->setX(placable->getX() + to_move);
        } else if (Raylib_encp.IsKDown(KEY_A) && !collision->isColliding(placable->getX() - to_move, placable->getY() ,placable->getZ())) {
            anims->setAnimationType(RUN);
            model->getPtrModel()->transform = Raylib_encp.MatrixRotZ(1.5);
            placable->setX(placable->getX() - to_move);
        } else if (Raylib_encp.IsKDown(KEY_W) && !collision->isColliding(placable->getX(), placable->getY() ,placable->getZ() - to_move)) {
            anims->setAnimationType(RUN);
            model->getPtrModel()->transform = Raylib_encp.MatrixRotZ(3);
            placable->setZ(placable->getZ() - to_move);
        } else if (Raylib_encp.IsKDown(KEY_S) && !collision->isColliding(placable->getX(), placable->getY() ,placable->getZ() + to_move)) {
            anims->setAnimationType(RUN);
            model->getPtrModel()->transform = Raylib_encp.MatrixRotZ(0);
            placable->setZ(placable->getZ() + to_move);
        } else
            anims->setAnimationType(IDLE);
    }
    else if (type == MOVABLE_PLAYER_2 && IsGamepadAvailable(0)) {
        collision = static_cast<Collisionable *> (component[3]);
        if (IsGamepadButtonDown(0, BUTTON_RIGHT) && !collision->isColliding(placable->getX() + to_move, placable->getY() ,placable->getZ())) {
            anims->setAnimationType(RUN);
            model->getPtrModel()->transform = Raylib_encp.MatrixRotZ(-1.5);
            placable->setX(placable->getX() + to_move);
        } else if (IsGamepadButtonDown(0, BUTTON_LEFT) && !collision->isColliding(placable->getX() - to_move, placable->getY() ,placable->getZ())) {
            anims->setAnimationType(RUN);
            model->getPtrModel()->transform = Raylib_encp.MatrixRotZ(1.5);
            placable->setX(placable->getX() - to_move);
        } else if (IsGamepadButtonDown(0, BUTTON_UP) && !collision->isColliding(placable->getX(), placable->getY() ,placable->getZ() - to_move)) {
            anims->setAnimationType(RUN);
            model->getPtrModel()->transform = Raylib_encp.MatrixRotZ(3);
            placable->setZ(placable->getZ() - to_move);
        } else if (IsGamepadButtonDown(0, BUTTON_DOWN) && !collision->isColliding(placable->getX(), placable->getY() ,placable->getZ() + to_move)) {
            anims->setAnimationType(RUN);
            model->getPtrModel()->transform = Raylib_encp.MatrixRotZ(0);
            placable->setZ(placable->getZ() + to_move);
        } else
            anims->setAnimationType(IDLE);
    }
    else if (type == MOVABLE_PLAYER_2 ) {
        collision = static_cast<Collisionable *> (component[3]);
        if (Raylib_encp.IsKDown(KEY_RIGHT) && !collision->isColliding(placable->getX() + to_move, placable->getY() ,placable->getZ())) {
            anims->setAnimationType(RUN);
            model->getPtrModel()->transform = Raylib_encp.MatrixRotZ(-1.5);
            placable->setX(placable->getX() + to_move);
        } else if (Raylib_encp.IsKDown(KEY_LEFT) && !collision->isColliding(placable->getX() - to_move, placable->getY() ,placable->getZ())) {
            anims->setAnimationType(RUN);
            model->getPtrModel()->transform = Raylib_encp.MatrixRotZ(1.5);
            placable->setX(placable->getX() - to_move);
        } else if (Raylib_encp.IsKDown(KEY_UP) && !collision->isColliding(placable->getX(), placable->getY() ,placable->getZ() - to_move)) {
            anims->setAnimationType(RUN);
            model->getPtrModel()->transform = Raylib_encp.MatrixRotZ(3);
            placable->setZ(placable->getZ() - to_move);
        } else if (Raylib_encp.IsKDown(KEY_DOWN) && !collision->isColliding(placable->getX(), placable->getY() ,placable->getZ() + to_move)) {
            anims->setAnimationType(RUN);
            model->getPtrModel()->transform = Raylib_encp.MatrixRotZ(0);
            placable->setZ(placable->getZ() + to_move);
        } else
            anims->setAnimationType(IDLE);
    }
    else if (type == MOVABLE_AI) {
        collision = static_cast<Collisionable *> (component[3]);
        if (this->timeduration >= timelimit) {
            //TODO: AI moving parameters here Alexandre
            int rngvalue = Raylib_encp.GetRngValue(0, 3);
            // int rngvalue = getdirection(collision, placable);
            // go right
            if (rngvalue == 0 /*&& !collision->isColliding(placable->getX() + to_move, placable->getY() ,placable->getZ())*/&& !collision->isColliding(placable->getX() + 1, placable->getY() ,placable->getZ())) {
                anims->setAnimationType(RUN);
                model->getPtrModel()->transform = Raylib_encp.MatrixRotZ(1.5);
                placable->setX(placable->getX() + 1);
                movable->setIAActionType(IA_ACTION::IA_MOVE);
            }
            // go left
            else if (rngvalue == 1 /*&& !collision->isColliding(placable->getX() - to_move, placable->getY() ,placable->getZ())*/ && !collision->isColliding(placable->getX() - 1, placable->getY() ,placable->getZ())) {
                anims->setAnimationType(RUN);
                model->getPtrModel()->transform = Raylib_encp.MatrixRotZ(1.5);
                placable->setX(placable->getX() - 1);
                movable->setIAActionType(IA_ACTION::IA_MOVE);
            }
            // go up
            else if (rngvalue == 2 /*&& !collision->isColliding(placable->getX(), placable->getY() ,placable->getZ() - to_move)*/ && !collision->isColliding(placable->getX(), placable->getY() ,placable->getZ() - 1)) {
                anims->setAnimationType(RUN);
                model->getPtrModel()->transform = Raylib_encp.MatrixRotZ(3);
                placable->setZ(placable->getZ() - 1);
                movable->setIAActionType(IA_ACTION::IA_MOVE);
            }
            // go down
            else if (rngvalue == 3/* && !collision->isColliding(placable->getX(), placable->getY() ,placable->getZ() + to_move)*/ && !collision->isColliding(placable->getX(), placable->getY() ,placable->getZ() + 1)) {
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

    if (i = 0 && !collision->isColliding(placable->getX() + 1, placable->getY() ,placable->getZ()))
        return i;
    else if (i = 1 && !collision->isColliding(placable->getX() - 1, placable->getY() ,placable->getZ()))
        return i;
    else if (i = 2 && !collision->isColliding(placable->getX(), placable->getY() ,placable->getZ() - 1))
        return i;
    else if (i = 3 && !collision->isColliding(placable->getX(), placable->getY() ,placable->getZ() + 1))
        return i;
    else
        return 42;
}