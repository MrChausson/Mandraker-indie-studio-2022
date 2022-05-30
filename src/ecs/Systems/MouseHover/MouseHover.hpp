/*
** EPITECH PROJECT, 2022
** $
** File description:
** MouseHover
*/

#ifndef MOUSEHOVER_HPP_
#define MOUSEHOVER_HPP_

#include "raylib.h"
#include "../../Components/Hoverable/Hoverable.hpp"
#include "../../Components/Drawable/DrawableSprite.hpp"
#include "../../ISystem/ISystem.hpp"

class MouseHover : public ISystem {
    public:
        MouseHover();
        ~MouseHover();
        void apply(std::vector<IComponent *> component) override;
        SYSTEM_TYPES getType() override;

    protected:
    private:
};

#endif /* !MOUSEHOVER_HPP_ */
