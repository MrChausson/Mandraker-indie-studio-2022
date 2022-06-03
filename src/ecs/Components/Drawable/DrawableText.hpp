/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** DrawableText
*/

#ifndef DRAWABLETEXT_HPP_
#define DRAWABLETEXT_HPP_
    #include "Drawable.hpp"
    #include "raylib.h"
    #include <iostream>

class DrawableText : public Drawable {
    public:
        DrawableText(int plan = 0, std::string text = "Default text", Color color = WHITE, Font font = GetFontDefault(), int fontsize = 0);
        ~DrawableText();
        void setText(std::string text);
        std::string getText();
        void setColor(Color color);
        Color getColor();
        void setFontsize(int fontsize);
        int getFontsize();
        void setFont(Font font);
        Font getFont();

    protected:
    private:
        std::string _text;
        int _fontsize;
        Color _color;
        Font _font;
};

#endif /* !DRAWABLETEXT_HPP_ */
