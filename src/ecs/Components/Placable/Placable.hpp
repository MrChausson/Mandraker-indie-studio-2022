/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Placable
*/

#ifndef PLACABLE_HPP_
    #define PLACABLE_HPP_
    #include "raylib.h"
    #include "../../IComponent/IComponent.hpp"

class Placable : public IComponent {
    public:
        Placable(float x = 0, float y = 0, float z = 0);
        ~Placable();
        COMPONENT_TYPES getType() override;
        void setZ(float z);
        float getZ();
        void setX(float x);
        float getX();
        void setY(float y);
        float getY();
        Vector3 getPosition();

    protected:
        COMPONENT_TYPES _type = PLACABLE;
        float _x;
        float _y;
        float _z;
    private:
};

#endif /* !PLACABLE_HPP_ */
