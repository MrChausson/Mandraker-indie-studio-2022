/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** SplashScreen
*/

#ifndef SPLASHSCREEN_HPP_
#define SPLASHSCREEN_HPP_

#include "../../Scene/Scene.hpp"

class SplashScreen : public Scene {
    public:
        SplashScreen();
        ~SplashScreen();
        void Unload() override;

    protected:
    private:
        Texture2D _back;
        Texture2D _load;
        Music _music;
        
};

#endif /* !SPLASHSCREEN_HPP_ */
