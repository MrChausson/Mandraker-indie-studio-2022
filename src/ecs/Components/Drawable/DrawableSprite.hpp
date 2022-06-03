/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** DrawableSprite
*/

#ifndef DRAWABLESPRITE_HPP_
#define DRAWABLESPRITE_HPP_

#include "raylib.h"
#include <string>
#include "Drawable.hpp"

class DrawableSprite : public Drawable {
    public:
        DrawableSprite(Texture2D texture, int plan = 0);
        ~DrawableSprite();
        void setTexture(Texture2D texture);
        Texture2D getTexture();
        Rectangle getBounds();

    protected:
    private:
        Texture2D _texture;
        Rectangle _bounds;
};

#endif /* !DRAWABLESPRITE_HPP_ */
