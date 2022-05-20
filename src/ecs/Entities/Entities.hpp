/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Entities
*/

#ifndef ENTITIES_HPP_
    #define ENTITIES_HPP_

    #include "../../../includes/ecs.hpp"

class Entities {
    public:
        Entities(size_t size = 1000);
        Entity create();
        void remove(Entity entity);
        void print() const;
        std::vector<Entity> getEntities();
    private:
        std::vector<Entity> m_entities{};
};

#endif /* !ENTITIES_HPP_ */
