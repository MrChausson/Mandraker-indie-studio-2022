/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Scene
*/

#ifndef SCENE_HPP_
    #define SCENE_HPP_
    #include <memory>
    #include "../ecs/ECSManager/ECSManager.hpp"

enum SCENE_TYPE {
    SCENE_MENU,
    SCENE_SETTINGS,
    SCENE_GAME,
    SCENE_NONE,
    SCENE_CHARACTER_SELECTOR
};
class Scene {
    public:
        Scene() = default;
        ~Scene() = default;
        virtual void Unload() = 0;
        ECSManager *getECS() { return this->_ecsManager.get();};
    protected:
        SCENE_TYPE _type;
        std::unique_ptr<ECSManager> _ecsManager;
};

#endif /* !SCENE_HPP_ */
