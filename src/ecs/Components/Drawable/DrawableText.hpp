/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** DrawableText
*/

#ifndef DRAWABLETEXT_HPP_
#define DRAWABLETEXT_HPP_
    #include "Drawable.hpp"
    #include <iostream>

class DrawableText : public Drawable {
    public:
        DrawableText(int plan = 0, int x = 0 , int y = 0, std::string text = "Default text", int fontsize = 30, Color color = WHITE);
        ~DrawableText();
        void setText(std::string text);
        std::string getText();
        void setColor(Color color);
        Color getColor();
        void setFontsize(int fontsize);
        int getFontsize();

    protected:
    private:
        std::string _text;
        DRAWABLE_TYPE _type = DRAWABLE_TYPE_TEXT;
        int _fontsize;
        Color _color;
};

#endif /* !DRAWABLETEXT_HPP_ */
