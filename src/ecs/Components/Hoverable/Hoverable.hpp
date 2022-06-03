/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Hoverable
*/

#ifndef HOVERABLE_HPP_
#define HOVERABLE_HPP_

#include "raylib.h"
#include "../../IComponent/IComponent.hpp"
#include "../../Entity/Entity.hpp"
#include "../Drawable/Drawable.hpp"

class Hoverable : public IComponent {
    public:
        Hoverable(Entity *entity, Texture2D texture);
        ~Hoverable();
        void setBound(float x, float y);
        bool isHovered(Vector2 mouse);
        COMPONENT_TYPES getType() override;
        Rectangle getBound();
        Texture2D getTexture();
        void setHover(bool hover);
        void setTexture(Texture2D texture);
        bool changedState(Vector2 mouse);
        Texture2D _textureSaved;
        Texture2D _textureHover;
        Texture2D _tmp;

    protected:
    private:
        COMPONENT_TYPES _type;
        bool _isHovered;
        Rectangle _bounds;

};

#endif /* !HOVERABLE_HPP_ */
