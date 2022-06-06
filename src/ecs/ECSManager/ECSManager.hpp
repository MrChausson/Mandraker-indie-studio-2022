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
    #include "../Systems/MouseHover/MouseHover.hpp"
    #include "../Systems/MouseClick/MouseClick.hpp"
    #include "../Components/Drawable/Drawable.hpp"
    #include "../Systems/Draw/Draw.hpp"
    #include "../Entity/Entity.hpp"
    #include "../ISystem/ISystem.hpp"
    #include "../Components/Placable/Placable.hpp"
    #include "../Systems/Move/Move.hpp"
    #include "../Components/Movable/Movable.hpp"
    #include "../Components/Musicable/Musicable.hpp"
    #include "../Systems/Music_sys/Music_sys.hpp"
    #include "raylib.h"

class ECSManager {
    public:
        ECSManager(void *engine = nullptr);
        ~ECSManager();
        // Entities Functions //
        int createEntity();
        void deleteEntity(int id);
        Entity *getEntity(int id);
        // updateEntity
        // Components Functions //
        void addComponent(int entityId, std::unique_ptr<IComponent> component);
        bool entityHasComponent(Entity entity, COMPONENT_TYPES type);
        IComponent *getComponent(std::unique_ptr<Entity> &entity, COMPONENT_TYPES type);
        // Systems Functions //
        void addSystem(std::unique_ptr<ISystem> system);
        ISystem *getSystemByType(SYSTEM_TYPES type);
        // Apply
        ECSManager *applySystems();
        void applyDraw();
        void *getEngine();


    protected:
        std::vector<std::unique_ptr<Entity>> _entities = {};
        std::vector<std::unique_ptr<ISystem>> _systems = {};
        std::vector<int> _deletedEntityIds;
        unsigned int current_id = 0;
        void *_engine;
    private:
        IComponent *getCamera();
};

#endif /* !ECSMANAGER_HPP_ */
