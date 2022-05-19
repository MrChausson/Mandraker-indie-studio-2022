/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** ConcretComponent
*/

#include "ConcretComponent.hpp"

template<class ConcretComponent>
Components<ConcretComponent>::Components(size_t size) {
    m_components.reserve(size);
}
    
template<class ConcretComponent>
ConcretComponent& Components<ConcretComponent>::create(Entity entity) {
    m_components.push_back(ConcretComponent(entity));
}
    
template<class ConcretComponent>
void Components<ConcretComponent>::remove(Entity entity) {
    std::remove_if(begin(m_components), end(m_components), 
        [entity](const ConcretComponent &component){ return (component.entity() == entity); });
}
