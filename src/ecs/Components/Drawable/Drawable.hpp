/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Drawable
*/

#ifndef DRAWABLE_HPP_
    #define DRAWABLE_HPP_
    #include "../../IComponent/IComponent.hpp"

class Drawable : public IComponent {
    public:
        Drawable(int plan);
        ~Drawable();
        COMPONENT_TYPES getType() override { return DRAWABLE; };
        void setPlan(int plan);
        int getPlan();

    protected:
    private:
        int _plan;
};

#endif /* !DRAWABLE_HPP_ */
