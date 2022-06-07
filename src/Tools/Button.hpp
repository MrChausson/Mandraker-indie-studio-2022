/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Button
*/

#ifndef BUTTON_HPP_
#define BUTTON_HPP_

#include "../ecs/ECSManager/ECSManager.hpp"
#include "../ecs/Components/Clickable/Clickable.hpp"
#include "../Scene/Scene.hpp"

class Button {
    public:
        Button(ECSManager *ecsManager, std::string text, int x, int y, Font font, Texture2D textures[3], SCENE_TYPE, ClickableActionType actionType);
        ~Button();

    protected:
    private:
};

#endif /* !BUTTON_HPP_ */
