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

void Raylib::GetScreenHeight() const noexcept
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

void Raylib::SetMousePos(std::pair<int, int> const &pos) const noexcept
{
    return SetMousePosition(pos.first, pos.second);
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

void BeginM3D(Camera3D camera) noexcept
{
    return BeginMode3D(camera);
}

void EndM3D(void) noexcept
{
    return EndMode3D();
}

void BeginTextMode(RenderTexture2D target) noexcept
{
    return BeginTextureMode(target);
}

void EndTextMode(void) noexcept
{
    return EndTextureMode();
}

void BeginShadMode(Shader shader) noexcept
{
    return BeginShaderMode(shader);
}

void EndShadMode(void) noexcept
{
    return EndShaderMode();
}

void BeginBMode(int mode) noexcept
{
    return BeginBlendMode(mode);
}

void EndBMode(void) noexcept
{
    return EndBlendMode();
}

bool Raylib::checkCollision(std::pair<float, float> mouse_xy, float width, float height, float X, float Y)
{
    Rectangle rect = {posX, posY, width, height};
    Vector2 vec = {pos.first, pos.second};

    return (CheckCollisionPointRec(vec, rect));
}

Sound Rayib::LSound(std::string fileName) noexcept
{
    return Loadsound(fileName.c_str());
}

Font Rayib::LFontEx(std::string fileName, int fontSize, int *fontChars, int glyphCount) noexcept
{
    return LoadFontEx(fileName.c_str(), fontSize, fontChars, glyphCount);
}

Texture2D Rayib::LTexture(std::string fileName) noexcept
{
    return LoadTexture(filename.c_str());
}

void Rayib::PlayS(Sound sound) noexcept
{
    return PlaySound(sound);
}

void Rayib::StopS(Sound sound) noexcept
{
    return StopSound(sound);
}

void Rayib::PauseS(Sound sound) noexcept
{
    return PaueSound(sound);
}

void Rayib::ResumeS(Sound sound) noexcept
{
    return ResumeSound(sound);
}

void Rayib::ClearBkground(Color color) noexcept
{
    return ClearBackground(color);
}

void Rayib::BgDrawing(void) noexcept
{
    return BeginDrawing();
}

void Rayib::EDrawing(void) noexcept
{
    return EndDrawing();
}

void Rayib::DwTexture(Texture2D texture, std::pair<int, int> conts &pos, Color tint) noexcept
{
    return DrawTexture(texture, pos.first, pos.second, tint);
}

void Rayib::DwFPS(std::pair<int, int> const &pos) noexcept
{
    return DrawFPS(pos.first, pos.second);
}

void Rayib::DwText(std::string text, std::pair<int, int> const &pos, float fontSize, Color color) noexcept
{
    return DrawText(text.c_str(), pos.first, pos.second, fontSize, color);
}

void Rayib::DwTextEx(Font font, std::string text, Vector2 position, float fontSize, float spacing, Color tint) noexcept
{
    return DrawTextEx(font, text.c_str(), position, fontSize, spacing, tint);
}


void Rayib::UpdtMusicStream(Music music) noexcept
{
    return UpdateMusicStream(music);
}

void Rayib::UnlTexture(Texture2D texture) noexcept
{
    return UnloadTexture(texture);
}

void Rayib::UnlFont(Font font) noexcept
{
    return UnloadFont(font);
}

void Rayib::UnlSound(Sound sound) noexcept
{
    return UnloadSound(sound);
}