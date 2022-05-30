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

class Draw : public ISystem {
    public:
        Draw();
        ~Draw();
        void apply(IComponent *component) override;
        SYSTEM_TYPES getType() override { return DRAW; };
        std::vector<SYSTEM_TYPES> getAffectedComponents() override { return {DRAW}; };
};