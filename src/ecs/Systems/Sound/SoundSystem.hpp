/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Sound
*/

#ifndef SOUND_HPP_
#define SOUND_HPP_

#include "../../ISystem/ISystem.hpp"

class SoundSystem : public ISystem {
    public:
        SoundSystem();
        ~SoundSystem();
        void apply(std::vector<IComponent *> component) override;
        virtual SYSTEM_TYPES getType() override;
    protected:
    private:
};

#endif /* !SOUND_HPP_ */
