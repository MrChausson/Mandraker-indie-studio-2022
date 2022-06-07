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
#include "../../ECSManager/ECSManager.hpp"
#include "ClickableActionType.hpp"


class Clickable : public IComponent {
    public:
        Clickable(Entity *entity, Texture2D texture, std::string ecsToChangeTo, ClickableActionType actionType = CLICKABLE_ACTION_NONE);
        ~Clickable();
        void setBound(float x, float y);
        bool isClicked(Vector2 mouse, bool pressed);
        COMPONENT_TYPES getType() override;
        Rectangle getBound();
        Texture2D getTexture();
        void setClick(bool hover);
        void setTexture(Texture2D texture);
        bool changedState(Vector2 mouse, bool pressed);
        Texture2D _textureSaved;
        Texture2D _textureClick;
        Texture2D _tmp;
        ECSManager *getEcs();
        void setEcs(ECSManager *ecs);
        std::string _tmpEcs;
        ClickableActionType getActionType();

    protected:
    private:
        ECSManager *_ecsToChangeTo = nullptr;
        COMPONENT_TYPES _type;
        bool _isClicked;
        Rectangle _bounds;
        ClickableActionType _actionType;
};

#endif /* !Clickable_HPP_ */
