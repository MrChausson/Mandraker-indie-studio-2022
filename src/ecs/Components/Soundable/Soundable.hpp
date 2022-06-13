/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Soundable
*/

#ifndef SOUNDABLE_HPP_
    #define SOUNDABLE_HPP_
    #include "raylib.h"
    #include "../../IComponent/IComponent.hpp"

class Soundable : public IComponent {
    public:
        Soundable(Sound sound);
        ~Soundable();
        COMPONENT_TYPES getType() override;
        void setSound(Sound sound);
        void playSound();
        void setSoundPlaying(bool playing);
        void stopSound();

    protected:
        Sound _sound;
        bool _playing = true;
    private:
};

extern float soundVolume;

#endif /* !SOUNDABLE_HPP_ */
