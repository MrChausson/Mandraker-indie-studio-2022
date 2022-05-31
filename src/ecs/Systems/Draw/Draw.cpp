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

void Draw::apply(std::vector<IComponent *> component)
{
    Drawable *drawable = static_cast<Drawable *>(component[0]);
    DrawableText *drawableText;
    DrawableSprite *drawableSprite;
    Vector2 vec;

    if (drawable->getComponentType() == DRAWABLE_TYPE_TEXT) {
        drawableText = static_cast<DrawableText *>(component[0]);
        vec = {static_cast<float>(drawableText->getX()), static_cast<float>(drawableText->getY())};
        DrawTextEx(drawableText->getFont(), drawableText->getText().c_str(), vec, drawableText->getFontsize(), 2, drawableText->getColor());
    }
    if (drawable->getComponentType() == DRAWABLE_TYPE_SPRITE) {
        drawableSprite = static_cast<DrawableSprite *>(component[0]);
        DrawTexture(drawableSprite->getTexture(), drawableSprite->getX(), drawableSprite->getY(), WHITE);
    }
}