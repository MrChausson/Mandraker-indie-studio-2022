/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Drawable
*/

#ifndef DRAWABLE_HPP_
    #define DRAWABLE_HPP_
    #include "raylib.h"
    #include "../../IComponent/IComponent.hpp"

enum DRAWABLE_TYPE {
    DRAWABLE_TYPE_SPRITE,
    DRAWABLE_TYPE_TEXT
};

class Drawable : public IComponent {
    public:
        Drawable();
        Drawable(int plan, int x, int y);
        ~Drawable();
        COMPONENT_TYPES getType() override { return DRAWABLE; };
        DRAWABLE_TYPE getComponentType () { return _type; };
        void setPlan(int plan);
        int getPlan();
        void setX(int x);
        int getX();
        void setY(int y);
        int getY();

    private:
        DRAWABLE_TYPE _type;
        int _plan;
        int _x;
        int _y;
};

#endif /* !DRAWABLE_HPP_ */
