/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Bomber.hpp
*/

#ifndef BOMBER_HPP_
#define BOMBER_HPP_

#include "../../ISystem/ISystem.hpp"
#include <chrono>

class Bomber : public ISystem {
    public:
        Bomber();
        ~Bomber();
        void apply(std::vector<IComponent *> component) override;
        SYSTEM_TYPES getType() override;

    private:
        std::chrono::time_point<std::chrono::system_clock>  _toWait;
};

#endif /* !BOMBER_HPP_ */
