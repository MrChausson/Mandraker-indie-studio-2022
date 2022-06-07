/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Game
*/

#ifndef GAME_HPP_
#define GAME_HPP_

#include "../Scene.hpp"

class Game : public Scene {
    public:
        Game(Engine *engine = nullptr);
        ~Game();
        void loadMap(std::string map);

    protected:
    private:
        std::unique_ptr<std::vector <Entity *>> _mapEntities;
};

#endif /* !GAME_HPP_ */
