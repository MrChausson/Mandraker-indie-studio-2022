/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Draw
*/

#include "raylib.h"
#include "../../ISystem/ISystem.hpp"
#include "../../Components/Drawable/DrawableText.hpp"
#include "../../Components/Drawable/DrawableSprite.hpp"
#include "../../Components/Drawable/DrawableCube.hpp"
#include "../../Components/Placable/Placable.hpp"
#include "../../Components/CameraComponent/CameraComponent.hpp"
#include "DrawMode.hpp"
#include "../../Components/Drawable/DrawableCubeTexture.hpp"
#include "../../Components/Drawable/DrawableModel.hpp"
#include "../../Components/Drawable/DrawablePlane.hpp"

class Draw : public ISystem {
    public:
        Draw(DRAWMODE mode = DRAW_MODE_2D);
        ~Draw();
        void apply(std::vector<IComponent *> component) override;
        SYSTEM_TYPES getType() override { return DRAW; };
        void setMode(DRAWMODE mode);
        DRAWMODE getMode();
    private:
        DRAWMODE _mode;
};