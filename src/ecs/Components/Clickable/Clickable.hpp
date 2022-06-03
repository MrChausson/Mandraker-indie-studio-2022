/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Clickable
*/

#ifndef Clickable_HPP_
#define Clickable_HPP_

#include "raylib.h"
#include "../../ECSManager/ECSManager.hpp" 
#include "../../../Scene/Scene.hpp"

class Clickable : public IComponent {
    public:
        Clickable(float x, float y, Texture2D texture, Scene *sceneToChangeTo);
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
        Scene *getScene();
        void setScene(Scene *scene);
        Scene *_tmpScene;

    protected:
    private:
        Scene *_sceneToChangeTo;
        COMPONENT_TYPES _type;
        bool _isClicked;
        Rectangle _bounds;
};

#endif /* !Clickable_HPP_ */
