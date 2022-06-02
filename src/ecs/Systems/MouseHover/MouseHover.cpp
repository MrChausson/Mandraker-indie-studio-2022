/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** MouseHover
*/

#include "MouseHover.hpp"

MouseHover::MouseHover()
{
}

MouseHover::~MouseHover()
{
}

SYSTEM_TYPES MouseHover::getType()
{
    return (MOUSE_HOVER);
}

void MouseHover::apply(std::vector<IComponent *> component)
{
    Hoverable *hover = static_cast<Hoverable *>(component[1]);
    Clickable *click = static_cast<Clickable *>(component[2]);
    bool isClick = IsMouseButtonDown(MOUSE_LEFT_BUTTON);
    Vector2 mouse = GetMousePosition();
    
    //Drawable first, hoverable second
    if (hover->changedState(mouse) && !click->isClicked(mouse, isClick))
        if (hover->isHovered(mouse)) {
            DrawableSprite *draw = static_cast<DrawableSprite *>(component[0]);
            hover->_textureSaved = draw->getTexture();
            draw->setTexture(hover->getTexture());
        } else {
            DrawableSprite *draw = static_cast<DrawableSprite *>(component[0]);
            draw->setTexture(hover->_textureSaved);
        }
}