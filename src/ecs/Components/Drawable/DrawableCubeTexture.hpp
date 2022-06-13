/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** DrawableCube
*/

#ifndef DRAWABLECUBETEXTURE_HPP_
#define DRAWABLECUBETEXTURE_HPP_

#include "raylib.h"
#include "Drawable.hpp"

enum class CubeTextureType {
    GRASS,
    STONE
};

class DrawableCubeTexture : public Drawable {
    public:
        DrawableCubeTexture(Texture2D texture, CubeTextureType textureType, float width = 1.0f, float height = 1.0f, float length = 1.0f, Color color = WHITE);
        ~DrawableCubeTexture();
        void setColor(Color color);
        Color getColor();
        void setWidth(float width);
        float getWidth();
        void setHeight(float height);
        float getHeight();
        void setLength(float length);
        float getLength();
        Texture2D getTexture();
        int getCubeTextureType();

    protected:
    private:
    float _width;
    float _height;
    float _length;
    Color _color;
    Texture2D _texture;
    CubeTextureType _cubeTextureType;

};

#endif /* !DRAWABLECUBETEXTURE_HPP_ */
