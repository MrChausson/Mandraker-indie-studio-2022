/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Engine
*/

#ifndef ENGINE_HPP_
    #define ENGINE_HPP_
    #include <iostream>
    #include "../ecs/ECSManager/ECSManager.hpp"

class Engine {
    public:
        Engine();
        ~Engine();
        void loop();

    protected:
    private:
        std::unique_ptr<ECSManager> ecsManager;
};

#endif /* !ENGINE_HPP_ */
