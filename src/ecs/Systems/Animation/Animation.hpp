/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Animation
*/

#ifndef ANIMATION_HPP_
#define ANIMATION_HPP_

#include "../../ISystem/ISystem.hpp"
#include "../../Components/Animable/Animable.hpp"
#include "../../Components/Drawable/DrawableModel.hpp"
#include <chrono>

class Animation : public ISystem {
    public:
        Animation();
        ~Animation();
        void apply(std::vector<IComponent *> component) override;
        virtual SYSTEM_TYPES getType() override;

    protected:
    private:
    std::chrono::time_point<std::chrono::system_clock> _clock;
};

#endif /* !ANIMATION_HPP_ */
