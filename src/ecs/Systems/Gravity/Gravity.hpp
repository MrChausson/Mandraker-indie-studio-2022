/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Gravity
*/

#ifndef GRAVITY_HPP_
#define GRAVITY_HPP_

    #include "../../Entity/Entity.hpp"
    #include "../../ISystem/ISystem.hpp"

class Gravity : public ISystem {
    public:
        Gravity();
        ~Gravity();
        void apply(std::unique_ptr<IComponent> component) override;

    protected:
    private:
};

#endif /* !GRAVITY_HPP_ */
