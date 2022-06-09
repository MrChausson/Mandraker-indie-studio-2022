/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Draw
*/

#include "Draw.hpp"
#include "raymath.h"
#include "raylib.hpp"

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
    Raylib::Raylib_encap Raylib_encp;

    if (component_type == DRAWABLE_TYPE_TEXT) {
        drawableText = static_cast<DrawableText *>(component[1]);
        vec = {static_cast<float>(placable->getX()), static_cast<float>(placable->getY())};
        Raylib_encp.DwTextEx(drawableText->getFont(), drawableText->getText().c_str(), vec, drawableText->getFontsize(), 2, drawableText->getColor());
    } else if (component_type == DRAWABLE_TYPE_SPRITE) {
        drawableSprite = static_cast<DrawableSprite *>(component[1]);
        Raylib_encp.DwTexture(drawableSprite->getTexture(), placable->getX(), placable->getY(), WHITE);
    } else if (component_type == DRAWABLE_TYPE_CUBE) {
        if (component.size() < 3)
            throw CameraNotFound();
        if (placable == nullptr)
            throw PlacableNotFound();
        camera = static_cast<CameraComponent *>(component[2]);
        drawableCube = static_cast<DrawableCube *>(component[1]);
        //TODO begin mode with camera
        Raylib_encp.BeginM3D(camera->getCamera());
        Raylib_encp.SetCamMode(camera->getCamera(), CAMERA_FREE);
        Raylib_encp.DwCube(placable->getPosition(), drawableCube->getWidth(), drawableCube->getHeight(), drawableCube->getLength(), drawableCube->getColor());
    } else if (component_type == DRAWABLE_TYPE_TEXTURE_CUBE) {
        if (component.size() < 3)
            throw CameraNotFound();
        if (placable == nullptr)
            throw PlacableNotFound();
        camera = static_cast<CameraComponent *>(component[2]);
        drawableCubeTexture = static_cast<DrawableCubeTexture *>(component[1]);
        //TODO begin mode with camera
        Raylib_encp.BeginM3D(camera->getCamera());
        Raylib_encp.SetCamMode(camera->getCamera(), CAMERA_FREE);
        Raylib_encp.DwCubeTexture(drawableCubeTexture->getTexture(), placable->getPosition(), drawableCubeTexture->getWidth(), drawableCubeTexture->getHeight(), drawableCubeTexture->getLength(), drawableCubeTexture->getColor());
        Raylib_encp.EndM3D();
    } else if (component_type == DRAWABLE_TYPE_MODEL) {
        if (component.size() < 3)
            throw CameraNotFound();
        if (placable == nullptr)
            throw PlacableNotFound();
        camera = static_cast<CameraComponent *>(component[2]);
        DrawableModel *drawableModel = static_cast<DrawableModel *>(component[1]);
        Raylib_encp.BeginM3D(camera->getCamera());
        Raylib_encp.SetCamMode(camera->getCamera(), CAMERA_FREE);
        Raylib_encp.DwModelEx(drawableModel->getModel(), placable->getPosition(), placable->getRotationAxis(), placable->getRotationAngle(), placable->getScale(), WHITE);
        Raylib_encp.EndM3D();
    } else if (component_type == DRAWABLE_TYPE_PLANE) {
        if (component.size() < 3)
            throw CameraNotFound();
        if (placable == nullptr)
            throw PlacableNotFound();
        camera = static_cast<CameraComponent *>(component[2]);
        DrawablePlane *drawablePlane = static_cast<DrawablePlane *>(component[1]);
        Raylib_encp.BeginM3D(camera->getCamera());
        Raylib_encp.SetCamMode(camera->getCamera(), CAMERA_FREE);
        Raylib_encp.DwPlane(placable->getPosition(), drawablePlane->getSize(), drawablePlane->getColor());
        Raylib_encp.EndM3D();
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