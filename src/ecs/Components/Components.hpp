/*
** EPITECH PROJECT, 2022
** *
** File description:
** Components
*/

#ifndef COMPONENTS_HPP_
    #define COMPONENTS_HPP_

    #include "../../../includes/ecs.hpp"

class Component {
    protected:
        Component(Entity entity);
    public:
        Entity entity() const;
    private:
        Entity m_entity{};
};

#endif /* !COMPONENTS_HPP_ */
