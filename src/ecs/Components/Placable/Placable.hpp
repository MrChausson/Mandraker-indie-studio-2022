/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Placable
*/

#ifndef PLACABLE_HPP_
    #define PLACABLE_HPP_
    #include "../../IComponent/IComponent.hpp"

class Placable : public IComponent {
    public:
        Placable(TYPE type);
        ~Placable();
        void setZ(float z);
        float getZ();
        void setX(float x);
        float getX();
        void setY(float y);
        float getY();

    protected:
        TYPE _type;
        float _x;
        float _y;
        float _z;
    private:
};

#endif /* !PLACABLE_HPP_ */
