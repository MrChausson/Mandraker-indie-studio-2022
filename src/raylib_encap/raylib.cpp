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

void Raylib::GetScreenWidth(int &width) const noexcept
{
    x_y_screen.first = width
}

void Raylib::GetScreenHeight(int &height) const noexcept
{
    x_y_screen.second = height
}

bool Raylib::WindowShouldClose() const noexcept
{
    return !WindowShouldClose();
}

bool Raylib::isKeyPressed(int &button) const noexcept
{
    return (IsKeyPressed(button));
}

bool Raylib::isMousePressed() const noexcept
{
    return (IsMouseButtonPressed(MOUSE_BUTTON_LEFT));
}

float Raylib::GetFrameTime() noexcept
{
    return GetFrameTime();
}

int Raylib::GetKeyPressed() const noexcept
{

}

char Raylib::GetCharPressed() noexcept
{

}
