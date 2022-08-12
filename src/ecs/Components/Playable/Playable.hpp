/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Playable
*/

#ifndef PLAYABLE_HPP_
#define PLAYABLE_HPP_

#include "raylib.h"
#include "../../IComponent/IComponent.hpp"

class Playable : public IComponent {
    public:
        Playable(int nbMaxMandrake);
        ~Playable();
        COMPONENT_TYPES getType() override;
        int getNbMandrake();
        int getNbMaxMandrake();
        void setNbMandrake(int nbMandrake);
        void setNbMaxMandrake(int nbMaxMandrake);
        void setRange(int range);
        int getRange();

    protected:
    private:
        int _nbMandrakeMax;
        int _nbMandrake;
        int _range;
};

#endif /* !PLAYABLE_HPP_ */
