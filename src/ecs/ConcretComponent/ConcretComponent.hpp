/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** ConcretComponent
*/

#ifndef CONCRETCOMPONENT_HPP_
    #define CONCRETCOMPONENT_HPP_
    #include "../../../includes/ecs.hpp"

template<class ConcretComponent>
class Components {
    public:
        Components(size_t size = 1000);
        ConcretComponent& create(Entity entity);
        void remove(Entity entity);
    protected:                                          // can add algos in derived classes
        std::vector<ConcretComponent> m_components{};   // not sorted array
};

#endif /* !CONCRETCOMPONENT_HPP_ */
