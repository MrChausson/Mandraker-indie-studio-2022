/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** MouseHover
*/

#include "MouseHover.hpp"
#include "raylib.hpp"

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
    Raylib::Raylib_encap Raylib_encp;
    Hoverable *hover = static_cast<Hoverable *>(component[1]);
    Vector2 mouse = Raylib_encp.GetMousePos();

    //Drawable first, hoverable second
    if (hover->changedState(mouse))
        if (hover->isHovered(mouse)) {
            DrawableSprite *draw = static_cast<DrawableSprite *>(component[0]);
            hover->_textureSaved = draw->getTexture();
            draw->setTexture(hover->getTexture());
        } else {
            DrawableSprite *draw = static_cast<DrawableSprite *>(component[0]);
            draw->setTexture(hover->_textureSaved);
        }
}