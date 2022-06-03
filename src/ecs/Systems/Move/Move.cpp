/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Move
*/

#include "Move.hpp"

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
    Placable *placable = static_cast<Placable *> (component[0]);
    Movable *movable = static_cast<Movable *> (component[1]);

    std::chrono::duration<double> elapsed_seconds = std::chrono::system_clock::now() - this->_clock;
    float to_move = movable->getSpeed() * elapsed_seconds.count();
    this->_clock = std::chrono::system_clock::now();
    MOVABLE_TYPE type = movable->getMovableType();

    if (type == MOVABLE_PLAYER) {
        if (IsKeyDown(KEY_RIGHT))
            placable->setX(placable->getX() + to_move);
        if (IsKeyDown(KEY_LEFT))
            placable->setX(placable->getX() - to_move);
        if (IsKeyDown(KEY_UP))
            placable->setY(placable->getY() - to_move);
        if (IsKeyDown(KEY_DOWN))
            placable->setY(placable->getY() + to_move);
    }
    else if (type == MOVABLE_AI) {
        //TODO: AI moving parameters here Alexandre
        placable->setX(placable->getX() + to_move);
    }
    //This is just to debug moving values - to be removed later
    std::cout << type << " " << placable->getX() << " " << placable->getY() << std::endl;
 }
