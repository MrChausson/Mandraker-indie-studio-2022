/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Musicable
*/

#ifndef MUSICABLE_HPP_
#define MUSICABLE_HPP_

#include "raylib.h"
#include "../../IComponent/IComponent.hpp"

class Musicable : public IComponent{
    public:
        Musicable(Music music);
        ~Musicable();
        COMPONENT_TYPES getType() override;
        void updatePause();
        bool isPaused();
        Music getMusic();

    protected:
    private:
        bool _pause;
        Music _music;
};

#endif /* !MUSICABLE_HPP_ */
