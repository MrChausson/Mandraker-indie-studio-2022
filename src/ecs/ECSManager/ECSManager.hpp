/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** ECSManager
*/

#ifndef ECSMANAGER_HPP_
    #define ECSMANAGER_HPP_
    #include "../Entity/Entity.hpp"
    #include "../ISystem/ISystem.hpp"
    #include <vector>
    #include <memory>

class ECSManager {
    public:
        ECSManager();
        ~ECSManager();
        int createEntity();
        // deleteEntity
        void addComponent(int entityId, std::unique_ptr<IComponent> component);
        std::unique_ptr<Entity> getEntity(int id);
        // updateEntity

    protected:
        std::vector<std::unique_ptr<Entity>> _entities = {};
        std::vector<ISystem> _systems;
    private:
};

#endif /* !ECSMANAGER_HPP_ */
