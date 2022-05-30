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
    MENU,
    GAME
};
class Scene {
    public:
        Scene() = default;
        ~Scene() = default;
        ECSManager *getECS() { return this->_ecsManager.get();};

    protected:
        SCENE_TYPE _type;
        std::unique_ptr<ECSManager> _ecsManager;
};

#endif /* !SCENE_HPP_ */
