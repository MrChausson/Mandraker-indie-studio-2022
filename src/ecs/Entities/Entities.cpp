/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Entities
*/

#include "Entities.hpp"

Entities::Entities(size_t size) {
    m_entities.reserve(size);
}

Entity Entities::create() {
    const auto it = std::adjacent_find(begin(m_entities),
        end(m_entities), [](Entity lhs, Entity rhs){ return (lhs+1 != rhs); });
    if (it == end(m_entities)) {
        m_entities.push_back(m_entities.size());
        return m_entities.back();
    } else {
        const auto result = m_entities.insert(it+1, (*it)+1);
        return *result;
    }
}

void Entities::remove(Entity entity) {
    const auto it = std::find(begin(m_entities), end(m_entities), entity);
    if (it != end(m_entities)) {
        m_entities.erase(it);
    }
}
    
void Entities::print() const {
    for(auto i: m_entities) { 
        std::cout << i << ' '; 
    }; 
    std::cout << std::endl;
}

std::vector<Entity> Entities::getEntities()
{
    return this->m_entities;
}