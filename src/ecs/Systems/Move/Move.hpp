/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Move
*/

#ifndef MOVE_HPP_
#define MOVE_HPP_

#include <chrono>
#include <iostream>
#include "../../ISystem/ISystem.hpp"
#include "../../Components/Movable/Movable.hpp"
#include "../../Components/Placable/Placable.hpp"

class Move : public ISystem {
    public:
        Move();
        ~Move();
        void apply(std::vector<IComponent *> component) override;
        SYSTEM_TYPES getType() override;

    protected:
    private:
        std::chrono::time_point<std::chrono::system_clock> _clock;
};

#endif /* !MOVE_HPP_ */
