/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Drawable
*/

#ifndef DRAWABLE_HPP_
    #define DRAWABLE_HPP_
    #include "../../IComponent/IComponent.hpp"

enum DRAWABLE_TYPE {
    DRAWABLE_TYPE_SPRITE,
    DRAWABLE_TYPE_TEXT,
    DRAWABLE_TYPE_CUBE
};

class Drawable : public IComponent {
    public:
        Drawable();
        Drawable(int plan);
        ~Drawable();
        COMPONENT_TYPES getType() override { return DRAWABLE; };
        DRAWABLE_TYPE getComponentType () { return _type; };
        void setPlan(int plan);
        int getPlan();

    protected:
        DRAWABLE_TYPE _type;
        int _plan;
};

#endif /* !DRAWABLE_HPP_ */
