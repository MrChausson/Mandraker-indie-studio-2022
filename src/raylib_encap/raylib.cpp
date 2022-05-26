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

bool Raylib::isKeyPres(int &key) const noexcept
{
    return (IsKeyPressed(key));
}

bool Raylib::IsKDown(int &key) const noexcept
{
    return (IsKeyDown(key));
}

bool Raylib::isKReleased(int &key) const noexcept
{
    return (IsKeyReleased(key));
}

void Raylib::SetExitK(int &key) const noexcept
{
    return (SetExitKey(key));
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

void Raylib::SetMousePos(int x, int y) const noexcept
{
    return SetMousePosition(x, y);
}

int GetKeyPres(void) noexcept
{
    return GetKeyPressed();
}

Music Raylib::LoadMStream(std::string& fileName) const noexcept
{
    return LoadMusicStream(fileName.c_str());
}

void Raylib::UnloadMtream(Music music) noexcept
{
    return UnloadMusicStream(music);
}

void RAylib::PlayMStream(Music music) noexcept
{
    return PlayMusicStream(music);
}

bool IsMStreamPlaying(Music music) noexcept
{
    return IsMusicStreamPlaying(music);
}

void StopMStream(Music music) noexcept
{
    return StopMusicStream(music);
}

void PauseMStream(Music music) noexcept
{
    return PauseMusicStream(music);
}

void ResumeMStream(Music music) noexcept
{
    return ResumeMusicStream(music);
}

void SeekMStream(Music music, float position) noexcept
{
    return SeekMusicStream(music, position);
}

void SetMVolume(Music music, float volume) noexcept
{
    return SetMusicVolume(music, volume);
}