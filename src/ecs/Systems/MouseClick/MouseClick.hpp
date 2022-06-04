/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** MouseClick
*/

#ifndef MOUSECLICK_HPP_
#define MOUSECLICK_HPP_

#include "raylib.h"
#include "../../ISystem/ISystem.hpp"
#include "../../Components/Clickable/ClickableActionType.hpp"

class MouseClick : public ISystem {
    public:
        MouseClick();
        ~MouseClick();
        void apply(std::vector<IComponent *> component) override;
        SYSTEM_TYPES getType() override;

    protected:
    private:
        void clickAction(ClickableActionType actionType, IComponent *component);
};

#endif /* !MOUSECLICK_HPP_ */
