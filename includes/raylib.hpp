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
    std::pair<int, int> x_y_mouse;
public:
    raylib();
    ~raylib();
    void Windowsinit(int &screenWidth, int &screenHeight, std::string const &title, std::size_t const &Fps) noexcept;
    bool WindowShouldEnd() const noexcept;
    bool isKeyPres(int &button) const noexcept;
    void GetScreenWidth() const noexcept;
    void GetScreenHeight() const noexcept;
    static float getFrameT() noexcept;
    char GetCharPres() noexcept;
    bool IsMouseBDown() const noexcept;
    bool IsMouseBReleased() const noexcept;
    bool IsMouseBPressed() const noexcept;
    void GetMX() noexcept;
    void GetMY() noexcept;
    Vector2 GetMousePos() noexcept;
};








#endif