/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.de-laage-de-meux
** File description:
** raylib
*/

#ifndef RAYLIB_H_

#include <string.h>
#include <stddef.h>
#include "../raylib/src/raylib.h"

class raylib
{
private:
    std::pair<int, int> x_y_screen;
public:
    raylib();
    ~raylib();
    void Windowsinit(int &screenWidth, int &screenHeight, std::string const &title, std::size_t const &Fps) noexcept;
    bool WindowShouldClose() const noexcept;
    bool isKeyPressed(int &button) const noexcept;
    bool isMousePressed() const noexcept;
    void GetScreenWidth(int &width) const noexcept;
    void GetScreenHeight(int &height) const noexcept;
    static float getFrameTime() noexcept;
    int GetKeyPressed() const noexcept;
    char GetCharPressed() noexcept;

};








#endif