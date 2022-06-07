/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Loadable
*/

#ifndef LOADABLE_HPP_
#define LOADABLE_HPP_

#include "../../IComponent/IComponent.hpp"
#include "../../ECSManager/ECSManager.hpp"
#include "raylib.h"

class Loadable : public IComponent {
    public:
        Loadable(Texture2D texture, Texture2D textureBack , float rotation = 0.0f, ECSManager *_ecs = nullptr, float second = 2.0f);
        ~Loadable();
        COMPONENT_TYPES getType() override;
        Texture2D getTexture();
        Texture2D getTextureBack();
        void setRotation(float rotation);
        float getRotation();
        bool isLoaded();
        void setLoaded(bool loaded);
        ECSManager *getEcs();
        float getTime();

    protected:
    private:
        float _rotation;
        Texture2D _texture;
        Texture2D _textureBack;
        bool _isLoaded = false;
        ECSManager *_ecs = nullptr;
        float _second;

};

#endif /* !LOADABLE_HPP_ */
