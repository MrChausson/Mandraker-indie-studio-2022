/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Music_sys
*/

#ifndef MUSIC_HPP_
#define MUSIC_HPP_

#include "../../ISystem/ISystem.hpp"
#include "../../Components/Musicable/Musicable.hpp"

class Music_sys : public ISystem {
    public:
        Music_sys();
        ~Music_sys();
        void apply(std::vector<IComponent *> component) override;
        virtual SYSTEM_TYPES getType() override;
    protected:
    private:
};

#endif /* !MUSIC_HPP_ */
