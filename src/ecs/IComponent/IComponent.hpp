/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Icomponent
*/

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

enum COMPONENT_TYPES {
    PLACABLE,
    DRAWABLE,
    BOUNDABLE,
    HOVERABLE,
    CLICKABLE,
    MOVABLE,
    MUSICABLE,
    CAMERA,
    ANIMABLE,
    LOADABLE,
    COLLISIONABLE,
    SOUNDABLE,
    TIMABLE
};

class IComponent {
    public:
        ~IComponent();
        virtual COMPONENT_TYPES getType() = 0;

    protected:
    private:
};

#endif /* !ICOMPONENT_HPP_ */
