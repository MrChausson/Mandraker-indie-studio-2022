/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Boundable
*/

#ifndef BOUNDABLE_HPP_
#define BOUNDABLE_HPP_

#include "raylib.h"
#include "../../IComponent/IComponent.hpp"

class Boundable : public IComponent {
    public:
        Boundable(float x, float y, float width, float height);
        ~Boundable();
        COMPONENT_TYPES getType() override;
        void setBounds(float x, float y, float width, float height);
        Rectangle getBounds();

    protected:
    private:
        COMPONENT_TYPES _type;
        Rectangle _bounds;
};

#endif /* !BONDABLE_HPP_ */
