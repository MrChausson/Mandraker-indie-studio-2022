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
#include "raylib.hpp"

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

    std::chrono::duration<double> elapsed_seconds = movable->getElapsedSeconds();
    float to_move = movable->getSpeed() * elapsed_seconds.count();
    movable->RestartClock();
    MOVABLE_TYPE type = movable->getMovableType();

    if (type == MOVABLE_PLAYER) {
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
        //TODO: AI moving parameters here Alexandre
        // placable->setX(placable->getX() + to_move);
    }
 }
