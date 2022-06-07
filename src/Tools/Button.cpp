/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Button
*/

#include "Button.hpp"


Button::Button(ECSManager *ecsManager, std::string text, int x, int y, Font font, Texture2D textures[3], SCENE_TYPE scene, ClickableActionType actionType)
{
    int button_id = ecsManager->createEntity();
    int button_text = ecsManager->createEntity();

    ecsManager->addComponent(button_id, std::make_unique<Placable>(x, y));
    ecsManager->addComponent(button_id, std::make_unique<DrawableSprite>(textures[1], 1));    
    ecsManager->addComponent(button_id, std::make_unique<Clickable>(ecsManager->getEntity(button_id) ,textures[2], scene, actionType));
    ecsManager->addComponent(button_id, std::make_unique<Hoverable>(ecsManager->getEntity(button_id), textures[0]));
    if (text.compare("") != 0) {
        if (text.length() > 6)
            x = x - 90;
        ecsManager->addComponent(button_text, std::make_unique<Placable>(static_cast<float>(x - 10 + (textures[1].width / 2 - font.baseSize)),static_cast<float>(y + (textures[1].height / 2 - font.baseSize / 2))));
        ecsManager->addComponent(button_text, std::make_unique<DrawableText>(2 ,text, Color{255, 255, 255, 255}, font));
    }
}

Button::~Button()
{
}
