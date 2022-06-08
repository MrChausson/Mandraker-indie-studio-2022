/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** DrawablePlane
*/

#ifndef DRAWABLEPLANE_HPP_
#define DRAWABLEPLANE_HPP_

#include "raylib.h"
#include "Drawable.hpp"

class DrawablePlane : public Drawable {
    public:
        DrawablePlane(Vector2 size, Color color = LIGHTGRAY);
        ~DrawablePlane();
        Color getColor();
        Vector2 getSize();

    protected:
    private:
        Vector2 _size;
        Color _color;
};

#endif /* !DRAWABLEPLANE_HPP_ */
