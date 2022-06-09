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
        Game();
        ~Game();
        void loadMap(std::string map);

    protected:
    private:
        std::unique_ptr<std::vector <Entity *>> _mapEntities;
        Texture2D _gryf_infos_texture;
        Texture2D _rav_infos_texture;
        Texture2D _slyth_infos_texture;
        Texture2D _huff_infos_texture;
};

#endif /* !GAME_HPP_ */
