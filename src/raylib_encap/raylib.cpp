/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.de-laage-de-meux
** File description:
** raylib
*/

#include <iostream>
#include <fstream>
#include "raylib.hpp"

raylib::raylib()
{
}

raylib::~raylib()
{
    CloseWindow();
}

void Raylib::Windowsinit(int &screenWidth, int &screenHeight, std::string const &title, std::size_t const &fps) noexcept
{
    GetScreenWidth(screenWidth);
    GetScreenHeight(screenHeight);
    InitWindow(x_y_screen.first, x_y_screen.second, title.c_str());
    SetExitKey(KEY_NULL);
    SetTargetFPS(fps);
}

void Raylib::GetScreenWidth() const noexcept
{
    x_y_screen.first = GetScreenWidth()
}

void Raylib::GetScreenHeight()) const noexcept
{
    x_y_screen.second = GetScreenHeight()
}

bool Raylib::WindowShouldEnd() const noexcept
{
    return !WindowShouldClose();
}

bool Raylib::isKeyPres(int &button) const noexcept
{
    return (IsKeyPressed(button));
}

bool Raylib::IsMouseBPressed() const noexcept
{
    return (IsMouseButtonPressed(MOUSE_BUTTON_LEFT));
}

float Raylib::GetFrameT() noexcept
{
    return GetFrameTime();
}

char Raylib::GetCharPres() noexcept
{
    if (IsKeyPressed(KEY_BACKSPACE))
        return (-1);
    return (GetCharPressed);
}

bool Raylib::IsMouseBDown() const noexcept
{
    return IsMouseButtonDown(MOUSE_BUTTON_LEFT)
}

bool Raylib::IsMouseBReleased() const noexcept
{
    return IsMouseButtonReleased(MOUSE_BUTTON_LEFT)
}

void Raylib::GetMX() noexcept
{
    x_y_mouse.first = GetMouseX()
}

void Raylib::GetMY() noexcept
{
    x_y_mouse.second = GetMouseY()
}

Vector2 Raylib::GetMousePos() noexcept
{
    return GetMousePosition();
}

void Raylib::SetMousePos(int x, int y) noexcept
{
    return SetMousePosition(x, y);
}

int GetKeyPres(void) noexcept
{
    return GetKeyPressed();
}
