/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** CameraComponent
*/

#ifndef CAMERA_HPP_
#define CAMERA_HPP_

#include "raylib.h"
#include "../../IComponent/IComponent.hpp"

class CameraComponent : public IComponent {
    public:
        CameraComponent(Vector3 position, Vector3 target, Vector3 up, float fov= 70.0f, int projection = CAMERA_PERSPECTIVE);
        ~CameraComponent();
        COMPONENT_TYPES getType() override;
        Camera3D getCamera();

    protected:
    private:
        Vector3 _position;
        Vector3 _target;
        Vector3 _up;
        float _fov;
        int _projection;
};

#endif /* !CAMERA_HPP_ */
