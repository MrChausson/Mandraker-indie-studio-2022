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
    this->_clock = std::chrono::system_clock::now();
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

    std::chrono::duration<double> elapsed_seconds = std::chrono::system_clock::now() - this->_clock;
    float to_move = movable->getSpeed() * elapsed_seconds.count();
    this->_clock = std::chrono::system_clock::now();
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
        collision = static_cast<Collisionable *> (component[3]);
        //TODO: AI moving parameters here Alexandre
        int rngvalue = Raylib_encp.GetRngValue(0, 3);
        // int rngvalue = getdirection(collision, placable);
        // go right
        if (rngvalue == 0 /*&& !collision->isColliding(placable->getX() + to_move, placable->getY() ,placable->getZ())*/ && !collision->isColliding(placable->getX() + 0.5, placable->getY() ,placable->getZ())) {
            anims->setAnimationType(RUN);
            model->getPtrModel()->transform = Raylib_encp.MatrixRotZ(1.5);
            placable->setX(placable->getX() + 0.5);
        }
        // go left
        else if (rngvalue == 1 /*&& !collision->isColliding(placable->getX() - to_move, placable->getY() ,placable->getZ())*/ && !collision->isColliding(placable->getX() - 1, placable->getY() ,placable->getZ())) {
            anims->setAnimationType(RUN);
            model->getPtrModel()->transform = Raylib_encp.MatrixRotZ(1.5);
            placable->setX(placable->getX() - 0.5);
        }
        // go up
        else if (rngvalue == 2 /*&& !collision->isColliding(placable->getX(), placable->getY() ,placable->getZ() - to_move)*/ && !collision->isColliding(placable->getX(), placable->getY() ,placable->getZ() - 1)) {
            anims->setAnimationType(RUN);
            model->getPtrModel()->transform = Raylib_encp.MatrixRotZ(3);
            placable->setZ(placable->getZ() - 0.5);
        }
        // go down
        else if (rngvalue == 3/* && !collision->isColliding(placable->getX(), placable->getY() ,placable->getZ() + to_move)*/ && !collision->isColliding(placable->getX(), placable->getY() ,placable->getZ() + 1)) {
            anims->setAnimationType(RUN);
            model->getPtrModel()->transform = Raylib_encp.MatrixRotZ(0);
            placable->setZ(placable->getZ() + 0.5);
        }
        // nothing
        else
            anims->setAnimationType(IDLE);
    }
 }

int Move::getdirection(Collisionable *collision, Placable *placable)
{
    int i = 0;
    Raylib::Raylib_encap Raylib_encp;

    while (1) {
        i = Raylib_encp.GetRngValue(0, 3);
        if (i = 0 && !collision->isColliding(placable->getX() + 0.5, placable->getY() ,placable->getZ()))
            return i;
        if (i = 1 && !collision->isColliding(placable->getX() - 0.5, placable->getY() ,placable->getZ()))
            return i;
        if (i = 2 && !collision->isColliding(placable->getX(), placable->getY() ,placable->getZ() - 0.5))
            return i;
        if (i = 3 && !collision->isColliding(placable->getX(), placable->getY() ,placable->getZ() + 0.5))
            return i;
    }
}