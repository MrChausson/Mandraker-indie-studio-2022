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
    
    int text = this->_ecsManager->createEntity();
    this->_ecsManager->addComponent(text, std::make_unique<DrawableText>(0, "Mandraker", Color{255, 255, 255, 255}));
    this->_ecsManager->addComponent(text, std::make_unique<Placable>(1000, 150));
    this->_ecsManager->addSystem(std::make_unique<Draw>());
}

Game::~Game()
{
    std::cout << "Game destructor" << std::endl;
}