/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** System
*/

#ifndef SYSTEM_HPP_
    #define SYSTEM_HPP_
    #include "../../../includes/ecs.hpp"
    #include "../ConcretComponent/ConcretComponent.hpp"

template <class T>
class System {
    public:
        void add_component(Components<T> component);
    private:
        std::vector<Components<T>> v_components;
};

template <class T>
class System2 {
    public:
        System2(Components<T>& attachedComponents);
    private:
        Components<T>& m_components;
};

#endif /* !SYSTEM_HPP_ */
