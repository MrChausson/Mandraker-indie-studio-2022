/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** ECSManager
*/

#ifndef ECSMANAGER_HPP_
    #define ECSMANAGER_HPP_
    #include <vector>
    #include <memory>
    #include "../Components/Hoverable/Hoverable.hpp"
    #include "../Components/Clickable/Clickable.hpp"
    #include "../Systems/MouseHover/MouseHover.hpp"
    #include "../Systems/MouseClick/MouseClick.hpp"
    #include "../Components/Drawable/Drawable.hpp"
    #include "../Systems/Draw/Draw.hpp"
    #include "../Entity/Entity.hpp"
    #include "../ISystem/ISystem.hpp"
    #include "raylib.h"

class ECSManager {
    public:
        ECSManager();
        ~ECSManager();
        // Entities Functions //
        int createEntity();
        void deleteEntity(int id);
        Entity *getEntity(int id);
        // updateEntity
        // Components Functions //
        void addComponent(int entityId, std::unique_ptr<IComponent> component);
        // Systems Functions //
        void addSystem(std::unique_ptr<ISystem> system);
        void applySystems();
        bool entityHasComponent(Entity entity, COMPONENT_TYPES type);
        IComponent *getComponent(std::unique_ptr<Entity> &entity, COMPONENT_TYPES type);

    protected:
        std::vector<std::unique_ptr<Entity>> _entities = {};
        std::vector<std::unique_ptr<ISystem>> _systems = {};
        std::vector<int> _deletedEntityIds;
        unsigned int current_id = 0;
    private:
};

#endif /* !ECSMANAGER_HPP_ */
