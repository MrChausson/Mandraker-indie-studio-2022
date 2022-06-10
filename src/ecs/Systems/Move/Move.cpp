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
    Movable *movable = static_cast<Movable *> (component[3]);

    std::chrono::duration<double> elapsed_seconds = std::chrono::system_clock::now() - this->_clock;
    float to_move = movable->getSpeed() * elapsed_seconds.count();
    this->_clock = std::chrono::system_clock::now();
    MOVABLE_TYPE type = movable->getMovableType();

    if (type == MOVABLE_PLAYER) {
        if (Raylib_encp.IsKDown(KEY_RIGHT)) {
            anims->setAnimationType(RUN);
            // placable->setRotationAxis(rot_right);
            model->getPtrModel()->transform = MatrixRotateZ(-1.5);
            placable->setX(placable->getX() + to_move);
        } else if (Raylib_encp.IsKDown(KEY_LEFT)) {
            anims->setAnimationType(RUN);
            // placable->setRotationAxis(rot_left);
            model->getPtrModel()->transform = MatrixRotateZ(1.5);
            placable->setX(placable->getX() - to_move);
        } else if (Raylib_encp.IsKDown(KEY_UP)) {
            anims->setAnimationType(RUN);
            // placable->setRotationAxis(rot_up);
            model->getPtrModel()->transform = MatrixRotateZ(3);
            placable->setZ(placable->getZ() - to_move);
        } else if (Raylib_encp.IsKDown(KEY_DOWN)) {
            anims->setAnimationType(RUN);
            // placable->setRotationAxis(rot_down);
            model->getPtrModel()->transform = MatrixRotateZ(0);
            placable->setZ(placable->getZ() + to_move);
        } else
            anims->setAnimationType(IDLE);
    }
    else if (type == MOVABLE_AI) {
        //TODO: AI moving parameters here Alexandre
        int rngvalue = Raylib_encp.GetRngValue(0, 3);
        // go right
        if (rngvalue == 0) {
            anims->setAnimationType(RUN);
            model->getPtrModel()->transform = MatrixRotateZ(-1.5);
            placable->setX(placable->getX() + to_move);
        }
        // go left
        else if (rngvalue == 1) {
            anims->setAnimationType(RUN);
            model->getPtrModel()->transform = MatrixRotateZ(1.5);
            placable->setX(placable->getX() - to_move);
        }
        // go up
        else if (rngvalue == 2) {
            anims->setAnimationType(RUN);
            model->getPtrModel()->transform = MatrixRotateZ(3);
            placable->setZ(placable->getZ() - to_move);
        }
        // go down
        else if (rngvalue == 3) {
            anims->setAnimationType(RUN);
            model->getPtrModel()->transform = MatrixRotateZ(0);
            placable->setZ(placable->getZ() + to_move);
        }
        // nothing
        else
            anims->setAnimationType(IDLE);
    }
 }
