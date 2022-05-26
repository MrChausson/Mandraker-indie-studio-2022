/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** ISystem
*/

#ifndef ISYSTEM_HPP_
#define ISYSTEM_HPP_

#include <vector> 
#include "../IComponent/IComponent.hpp"

enum SYSTEM_TYPES {
    GRAVITY,
    DRAW
};

class ISystem {
    public:
        ISystem() = default;
        ~ISystem() = default;
        virtual void apply(IComponent *component) = 0;
        virtual SYSTEM_TYPES getType() = 0;
        virtual std::vector<SYSTEM_TYPES> getAffectedComponents() = 0;
};

#endif /* !ISYSTEM_HPP_ */
