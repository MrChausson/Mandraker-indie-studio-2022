/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Clickable
*/

#ifndef Clickable_HPP_
#define Clickable_HPP_

#include "raylib.h"
#include "../../IComponent/IComponent.hpp"

class Clickable : public IComponent {
    public:
        Clickable(float x, float y, Texture2D texture);
        ~Clickable();
        void setBound(float x, float y);
        bool isClicked(Vector2 mouse);
        COMPONENT_TYPES getType() override;
        Rectangle getBound();
        Texture2D getTexture();
        void setClick(bool hover);
        void setTexture(Texture2D texture);
        bool changedState(Vector2 mouse);
        Texture2D _textureSaved;
        Texture2D _textureClick;
        Texture2D _tmp;
    protected:
    private:
        COMPONENT_TYPES _type;
        bool _isClicked;
        Rectangle _bounds;
};

#endif /* !Clickable_HPP_ */
