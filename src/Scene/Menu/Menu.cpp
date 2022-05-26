/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Menu
*/

#include "Menu.hpp"


Menu::Menu()
{
    this->_type = MENU;
    this->_ecsManager = std::make_unique<ECSManager>();
}

Menu::~Menu()
{

}

void Menu::init()
{
    int text_id = this->_ecsManager->createEntity();
    this->_ecsManager->addComponent(text_id, std::make_unique<DrawableText>(0, 190, 200 ,"Hello World", 30, Color{255, 255, 255, 255}));
    int second_text = this->_ecsManager->createEntity();
    this->_ecsManager->addComponent(text_id, std::make_unique<DrawableText>(0, 190, 400 ,"Hello World Second", 10, Color{255, 255, 255, 255}));
    
    this->_ecsManager->addSystem(std::make_unique<Draw>(Draw()));
}