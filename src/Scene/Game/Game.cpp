/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Game
*/

#include "Game.hpp"

Game::Game()
{
    std::cout << "Game created" << std::endl;
    this->_ecsManager = std::make_unique<ECSManager>();

    // Creating entities
    int text = this->_ecsManager->createEntity();
    int player = this->_ecsManager->createEntity();
    int ai = this->_ecsManager->createEntity();

    // Adding components
    this->_ecsManager->addComponent(text, std::make_unique<Placable>(1000, 150));
    this->_ecsManager->addComponent(text, std::make_unique<DrawableText>(0,"Mandraker", Color{255, 255, 255, 255}));
    // Configuring player
    this->_ecsManager->addComponent(player, std::make_unique<Placable>(0, 0, 0));
    this->_ecsManager->addComponent(player, std::make_unique<Movable>(1, MOVABLE_PLAYER));
    // Configuring ai
    this->_ecsManager->addComponent(ai, std::make_unique<Placable>(0, 0));
    this->_ecsManager->addComponent(ai, std::make_unique<Movable>(1, MOVABLE_AI));

    // Adding systems
    this->_ecsManager->addSystem(std::make_unique<Draw>());
    this->_ecsManager->addSystem(std::make_unique<Move>());
}

Game::~Game()
{
    std::cout << "Game destructor" << std::endl;
}