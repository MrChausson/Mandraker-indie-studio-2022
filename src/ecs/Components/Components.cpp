/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Components
*/

#include "Components.hpp"

Component::Component(Entity entity) : m_entity(entity) {
}
    
Entity Component::entity() const {
    return m_entity;
}
    
struct PositionComponent : public Component {
    int x{};
    int y{};
};
    
struct StateComponent : public Component {
    enum class State { Waiting, Walking, Running, Dead };
    State state { State::Waiting };
};