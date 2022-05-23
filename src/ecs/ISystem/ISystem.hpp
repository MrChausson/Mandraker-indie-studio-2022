/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** ISystem
*/

#ifndef ISYSTEM_HPP_
#define ISYSTEM_HPP_

#include <memory>
#include "../IComponent/IComponent.hpp"

class ISystem {
    public:
        ISystem() = default;
        ~ISystem() = default;
        virtual void apply(std::unique_ptr<IComponent> component) = 0;
        virtual int getType() = 0;

    protected:
    private:
};

#endif /* !ISYSTEM_HPP_ */
