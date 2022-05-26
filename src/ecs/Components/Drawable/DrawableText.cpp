/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** DrawableText
*/

#include "DrawableText.hpp"

DrawableText::DrawableText(std::string text, int fontsize, Color color)
{
    this->_text = text;
    this->_fontsize = fontsize;
    this->_color = color;
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
