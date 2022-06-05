/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** DrawableCube
*/

#ifndef DRAWABLECUBE_HPP_
#define DRAWABLECUBE_HPP_

#include "raylib.h"
#include "Drawable.hpp"

class DrawableCube : public Drawable {
    public:
        DrawableCube(Color color = BLACK, float width = 1.0f, float height = 1.0f, float length = 1.0f);
        ~DrawableCube();
        void setColor(Color color);
        Color getColor();
        void setWidth(float width);
        float getWidth();
        void setHeight(float height);
        float getHeight();
        void setLength(float length);
        float getLength();

    protected:
    private:
    float _width;
    float _height;
    float _length;
    Color _color;
};

#endif /* !DRAWABLECUBE_HPP_ */
