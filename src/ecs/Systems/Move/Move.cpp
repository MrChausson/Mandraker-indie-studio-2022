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

    std::chrono::duration<double> elapsed_seconds = movable->getElapsedSeconds();
    float to_move = movable->getSpeed() * elapsed_seconds.count();
    movable->RestartClock();
    MOVABLE_TYPE type = movable->getMovableType();
    // time_t start;
    // start = time(0);
    int a=clock()/CLOCKS_PER_SEC;//this gets the time in sec.


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
        while(clock()/CLOCKS_PER_SEC-a<1);
        // while (timeDelta <= 1) {
        //     temp = clock() - clk;
        //     clk = clock();
        //     timeDelta += (float)((float)temp / CLOCKS_PER_SEC);
        // }
        // if(time(0)-start == 1) {
            //TODO: AI moving parameters here Alexandre
            int rngvalue = Raylib_encp.GetRngValue(0, 3);
            // int rngvalue = getdirection(collision, placable);
            // go right
            if (rngvalue == 0 /*&& !collision->isColliding(placable->getX() + to_move, placable->getY() ,placable->getZ())*/&& !collision->isColliding(placable->getX() + 1, placable->getY() ,placable->getZ())) {
                anims->setAnimationType(RUN);
                model->getPtrModel()->transform = Raylib_encp.MatrixRotZ(1.5);
                placable->setX(placable->getX() + 1);
            }
            // go left
            else if (rngvalue == 1 /*&& !collision->isColliding(placable->getX() - to_move, placable->getY() ,placable->getZ())*/ && !collision->isColliding(placable->getX() - 1, placable->getY() ,placable->getZ())) {
                anims->setAnimationType(RUN);
                model->getPtrModel()->transform = Raylib_encp.MatrixRotZ(1.5);
                placable->setX(placable->getX() - 1);
            }
            // go up
            else if (rngvalue == 2 /*&& !collision->isColliding(placable->getX(), placable->getY() ,placable->getZ() - to_move)*/ && !collision->isColliding(placable->getX(), placable->getY() ,placable->getZ() - 1)) {
                anims->setAnimationType(RUN);
                model->getPtrModel()->transform = Raylib_encp.MatrixRotZ(3);
                placable->setZ(placable->getZ() - 1);
            }
            // go down
            else if (rngvalue == 3/* && !collision->isColliding(placable->getX(), placable->getY() ,placable->getZ() + to_move)*/ && !collision->isColliding(placable->getX(), placable->getY() ,placable->getZ() + 1)) {
                anims->setAnimationType(RUN);
                model->getPtrModel()->transform = Raylib_encp.MatrixRotZ(0);
                placable->setZ(placable->getZ() + 1);
            }
            // nothing
            else
                anims->setAnimationType(IDLE);
            // placable->setX(placable->getX() + to_move);
            // start += 1;
           a=clock()/CLOCKS_PER_SEC;
        }
    // }
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