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
        DrawableSprite(int plan = 0, int x = 0, int y = 0, Texture2D *texture = nullptr);
        ~DrawableSprite();
        void setTexture(Texture2D *texture);
        Texture2D *getTexture();
        Rectangle getBounds();

    protected:
    private:
        Texture2D *_texture;
        Rectangle _bounds;
};

#endif /* !DRAWABLESPRITE_HPP_ */
