/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Draw
*/

#include "Draw.hpp"

Draw::Draw()
{
}

Draw::~Draw()
{
}

void Draw::apply(IComponent *component)
{
    Drawable *drawable = static_cast<Drawable *>(component);
    DrawableText *drawableText;
    if (drawable->getComponentType() == DRAWABLE_TYPE_TEXT) {
        drawableText = static_cast<DrawableText *>(component);
        drawableText->getText();
        DrawText(drawableText->getText().c_str(), drawable->getX(), drawable->getY(), drawableText->getFontsize(), drawableText->getColor());
    }
}