/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Draw
*/

#include "Draw.hpp"
#include "raymath.h"

Draw::Draw(DRAWMODE mode)
{
    this->_mode = mode;
}

Draw::~Draw()
{
}

void Draw::apply(std::vector<IComponent *> component)
{
    Placable *placable = static_cast<Placable *>(component[0]);
    Drawable *drawable = static_cast<Drawable *>(component[1]);
    DrawableText *drawableText;
    DrawableSprite *drawableSprite;
    DrawableCube *drawableCube;
    DrawableCubeTexture *drawableCubeTexture;
    CameraComponent *camera;
    Vector2 vec;
    DRAWABLE_TYPE component_type = drawable->getComponentType();

    if (component_type == DRAWABLE_TYPE_TEXT) {
        drawableText = static_cast<DrawableText *>(component[1]);
        vec = {static_cast<float>(placable->getX()), static_cast<float>(placable->getY())};
        DrawTextEx(drawableText->getFont(), drawableText->getText().c_str(), vec, drawableText->getFontsize(), 2, drawableText->getColor());
    } else if (component_type == DRAWABLE_TYPE_SPRITE) {
        drawableSprite = static_cast<DrawableSprite *>(component[1]);
        DrawTexture(drawableSprite->getTexture(), placable->getX(), placable->getY(), WHITE);
    } else if (component_type == DRAWABLE_TYPE_CUBE) {
        if (component.size() < 3)
            throw CameraNotFound();
        if (placable == nullptr)
            throw PlacableNotFound();
        camera = static_cast<CameraComponent *>(component[2]); 
        drawableCube = static_cast<DrawableCube *>(component[1]);
        //TODO begin mode with camera
        BeginMode3D(camera->getCamera());
        SetCameraMode(camera->getCamera(), CAMERA_FREE);
        DrawCube(placable->getPosition(), drawableCube->getWidth(), drawableCube->getHeight(), drawableCube->getLength(), drawableCube->getColor());
    } else if (component_type == DRAWABLE_TYPE_TEXTURE_CUBE) {
        if (component.size() < 3)
            throw CameraNotFound();
        if (placable == nullptr)
            throw PlacableNotFound();
        camera = static_cast<CameraComponent *>(component[2]); 
        drawableCubeTexture = static_cast<DrawableCubeTexture *>(component[1]);
        //TODO begin mode with camera
        BeginMode3D(camera->getCamera());
        SetCameraMode(camera->getCamera(), CAMERA_FREE);
        DrawCubeTexture(drawableCubeTexture->getTexture(), placable->getPosition(), drawableCubeTexture->getWidth(), drawableCubeTexture->getHeight(), drawableCubeTexture->getLength(), drawableCubeTexture->getColor());
        EndMode3D();
    } else if (component_type == DRAWABLE_TYPE_MODEL) {
        if (component.size() < 3)
            throw CameraNotFound();
        if (placable == nullptr)
            throw PlacableNotFound();
        camera = static_cast<CameraComponent *>(component[2]); 
        DrawableModel *drawableModel = static_cast<DrawableModel *>(component[1]);
        BeginMode3D(camera->getCamera());
        SetCameraMode(camera->getCamera(), CAMERA_FREE);

        DrawModelEx(drawableModel->getModel(), placable->getPosition(), placable->getRotationAxis(), placable->getRotationAngle(), placable->getScale(), WHITE);
        EndMode3D();
    } else if (component_type == DRAWABLE_TYPE_PLANE) {
        if (component.size() < 3)
            throw CameraNotFound();
        if (placable == nullptr)
            throw PlacableNotFound();
        camera = static_cast<CameraComponent *>(component[2]);
        DrawablePlane *drawablePlane = static_cast<DrawablePlane *>(component[1]);
        BeginMode3D(camera->getCamera());
        SetCameraMode(camera->getCamera(), CAMERA_FREE);

        DrawPlane(placable->getPosition(), drawablePlane->getSize(), drawablePlane->getColor());
        EndMode3D();
    }
}

DRAWMODE Draw::getMode()
{
    return this->_mode;
}

void Draw::setMode(DRAWMODE mode)
{
    this->_mode = mode;
}