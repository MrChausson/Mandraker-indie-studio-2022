/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** DrawableText
*/

#include "DrawableText.hpp"

DrawableText::DrawableText(int plan, std::string text, Color color, Font font, int fontsize)
{
    this->_text = text;
    if (fontsize == 0)
        this->_fontsize = font.baseSize;
    else
        this->_fontsize = fontsize;
    this->_color = color;
    this->_plan = plan;
    this->_type = DRAWABLE_TYPE_TEXT;
    this->_font = font;
}

DrawableText::~DrawableText()
{
}

void DrawableText::setText(std::string text)
{
    this->_text = text;
}

std::string DrawableText::getText()
{
    return this->_text;
}

void DrawableText::setColor(Color color)
{
    this->_color = color;
}

Color DrawableText::getColor()
{
    return this->_color;
}

void DrawableText::setFontsize(int fontsize)
{
    this->_fontsize = fontsize;
}

int DrawableText::getFontsize()
{
    return this->_fontsize;
}

void DrawableText::setFont(Font font)
{
    this->_font = font;
}

Font DrawableText::getFont()
{
    return this->_font;
}

int DrawableText::getSize()
{
    return this->_fontsize;
}
