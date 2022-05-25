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
        DrawableText(std::string text) {this->_text = text;};
        ~DrawableText();

    protected:
    private:
        std::string _text;
        DRAWABLE_TYPE _type = DRAWABLE_TYPE_TEXT;
};

#endif /* !DRAWABLETEXT_HPP_ */
