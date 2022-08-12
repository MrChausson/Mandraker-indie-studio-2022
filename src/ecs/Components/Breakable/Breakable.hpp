/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Breakable
*/

#ifndef BREAKABLE_HPP_
    #define BREAKABLE_HPP_
    #include "../../IComponent/IComponent.hpp"


class Breakable : public IComponent {
    public:
        Breakable();
        ~Breakable();
        COMPONENT_TYPES getType() override;

    protected:
    private:
        COMPONENT_TYPES _type;
};

#endif /* !BREAKABLE_HPP_ */
