/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.de-laage-de-meux
** File description:
** raylib
*/

#include <iostream>
#include <fstream>
#include "raylib.hpp"

Raylib::Raylib_encap::Raylib_encap()
{
}

Raylib::Raylib_encap::~Raylib_encap()
{
}

void Raylib::Raylib_encap::Windowsinit(std::string const &title, std::size_t const &fps) noexcept
{
    GetScreenWidth();
    GetScreenHeight();
    InitWindow(x_y_screen.first, x_y_screen.second, title.c_str());
    SetExitKey(KEY_NULL);
    SetTargetFPS(fps);
}

void Raylib::Raylib_encap::InitWind(int width, int height, std::string title) noexcept
{
    return InitWindow(width, height, title.c_str());
}


int Raylib::Raylib_encap::GetScreenWidth() noexcept
{
    x_y_screen.first = GetScreenWidth();
    return GetScreenWidth();
}

int Raylib::Raylib_encap::GetScreenHeight() noexcept
{
    x_y_screen.second = GetScreenHeight();
    return GetScreenHeight();
}

bool Raylib::Raylib_encap::WindowShouldEnd() const noexcept
{
    return WindowShouldClose();
}

bool Raylib::Raylib_encap::isKeyPres(int key) const noexcept
{
    return (IsKeyPressed(key));
}

bool Raylib::Raylib_encap::IsKDown(int key) const noexcept
{
    return (IsKeyDown(key));
}

bool Raylib::Raylib_encap::isKReleased(int &key) const noexcept
{
    return (IsKeyReleased(key));
}

void Raylib::Raylib_encap::SetExitK(int &key) const noexcept
{
    return (SetExitKey(key));
}

bool Raylib::Raylib_encap::IsMouseBPressed() const noexcept
{
    return (IsMouseButtonPressed(MOUSE_BUTTON_LEFT));
}

float Raylib::Raylib_encap::GetFrameT() noexcept
{
    return GetFrameTime();
}

int Raylib::Raylib_encap::GetCharPres() const noexcept
{
    int i = GetCharPressed();

    if (IsKeyPressed(KEY_BACKSPACE))
        return (-1);
    return i;
}

bool Raylib::Raylib_encap::IsMouseBDown(int button) const noexcept
{
    return IsMouseButtonDown(MOUSE_BUTTON_LEFT);
}

bool Raylib::Raylib_encap::IsMouseBReleased(int button) const noexcept
{
    return IsMouseButtonReleased(MOUSE_BUTTON_LEFT);
}

void Raylib::Raylib_encap::GetMX() noexcept
{
    x_y_mouse.first = GetMouseX();
}

void Raylib::Raylib_encap::GetMY() noexcept
{
    x_y_mouse.second = GetMouseY();
}

Vector2 Raylib::Raylib_encap::GetMousePos() noexcept
{
    return GetMousePosition();
}

void Raylib::Raylib_encap::SetMousePos(std::pair<int, int> const &pos) const noexcept
{
    return SetMousePosition(pos.first, pos.second);
}

int Raylib::Raylib_encap::GetKeyPres(void) noexcept
{
    return GetKeyPressed();
}

Music Raylib::Raylib_encap::LoadMStream(std::string fileName) const noexcept
{
    return LoadMusicStream(fileName.c_str());
}

void Raylib::Raylib_encap::UnloadMtream(Music music) noexcept
{
    return UnloadMusicStream(music);
}

void Raylib::Raylib_encap::PlayMStream(Music music) noexcept
{
    return PlayMusicStream(music);
}

bool Raylib::Raylib_encap::IsMStreamPlaying(Music music) noexcept
{
    return IsMusicStreamPlaying(music);
}

void Raylib::Raylib_encap::StopMStream(Music music) noexcept
{
    return StopMusicStream(music);
}

void Raylib::Raylib_encap::PauseMStream(Music music) noexcept
{
    return PauseMusicStream(music);
}

void Raylib::Raylib_encap::ResumeMStream(Music music) noexcept
{
    return ResumeMusicStream(music);
}

void Raylib::Raylib_encap::SeekMStream(Music music, float position) noexcept
{
    return SeekMusicStream(music, position);
}

void Raylib::Raylib_encap::SetMVolume(Music music, float volume) noexcept
{
    return SetMusicVolume(music, volume);
}

void Raylib::Raylib_encap::BeginM3D(Camera3D camera) noexcept
{
    return BeginMode3D(camera);
}

void Raylib::Raylib_encap::EndM3D(void) noexcept
{
    return EndMode3D();
}

void Raylib::Raylib_encap::BeginTextMode(RenderTexture2D target) noexcept
{
    return BeginTextureMode(target);
}

void Raylib::Raylib_encap::EndTextMode(void) noexcept
{
    return EndTextureMode();
}

void Raylib::Raylib_encap::BeginShadMode(Shader shader) noexcept
{
    return BeginShaderMode(shader);
}

void Raylib::Raylib_encap::EndShadMode(void) noexcept
{
    return EndShaderMode();
}

void Raylib::Raylib_encap::BeginBMode(int mode) noexcept
{
    return BeginBlendMode(mode);
}

void Raylib::Raylib_encap::EndBMode(void) noexcept
{
    return EndBlendMode();
}

bool Raylib::Raylib_encap::checkCollPointRec(Vector2 vec, Rectangle rect) noexcept
{
    return (CheckCollisionPointRec(vec, rect));
}

Sound Raylib::Raylib_encap::LSound(std::string fileName) noexcept
{
    return LoadSound(fileName.c_str());
}

Font Raylib::Raylib_encap::LFontEx(std::string fileName, int fontSize, int *fontChars, int glyphCount) noexcept
{
    return LoadFontEx(fileName.c_str(), fontSize, fontChars, glyphCount);
}

Texture2D Raylib::Raylib_encap::LTexture(std::string fileName) noexcept
{
    return LoadTexture(fileName.c_str());
}

void Raylib::Raylib_encap::PlayS(Sound sound) noexcept
{
    return PlaySound(sound);
}

void Raylib::Raylib_encap::StopS(Sound sound) noexcept
{
    return StopSound(sound);
}

void Raylib::Raylib_encap::PauseS(Sound sound) noexcept
{
    return PauseSound(sound);
}

void Raylib::Raylib_encap::ResumeS(Sound sound) noexcept
{
    return ResumeSound(sound);
}

void Raylib::Raylib_encap::SetSVolume(Sound sound, float volume) noexcept
{
    return SetSoundVolume(sound, volume);
}

void Raylib::Raylib_encap::ClearBkground(Color color) noexcept
{
    return ClearBackground(color);
}

void Raylib::Raylib_encap::BgDrawing(void) noexcept
{
    return BeginDrawing();
}

void Raylib::Raylib_encap::EDrawing(void) noexcept
{
    return EndDrawing();
}

void Raylib::Raylib_encap::DwTexture(Texture2D texture, int X, int Y, Color tint) noexcept
{
    return DrawTexture(texture, X, Y, tint);
}

void Raylib::Raylib_encap::DwFPS(std::pair<int, int> const &pos) noexcept
{
    return DrawFPS(pos.first, pos.second);
}

void Raylib::Raylib_encap::DwText(std::string text, std::pair<int, int> const &pos, float fontSize, Color color) noexcept
{
    return DrawText(text.c_str(), pos.first, pos.second, fontSize, color);
}

void Raylib::Raylib_encap::DwTextEx(Font font, std::string text, Vector2 position, float fontSize, float spacing, Color tint) noexcept
{
    return DrawTextEx(font, text.c_str(), position, fontSize, spacing, tint);
}

void Raylib::Raylib_encap::UpdtMusicStream(Music music) noexcept
{
    return UpdateMusicStream(music);
}

void Raylib::Raylib_encap::UnlTexture(Texture2D texture) noexcept
{
    return UnloadTexture(texture);
}

void Raylib::Raylib_encap::UnlFont(Font font) noexcept
{
    return UnloadFont(font);
}

void Raylib::Raylib_encap::UnlSound(Sound sound) noexcept
{
    return UnloadSound(sound);
}

void Raylib::Raylib_encap::SetCamMode(Camera camera, int mode) noexcept
{
    return SetCameraMode(camera, mode);
}

void Raylib::Raylib_encap::DwCube(Vector3 position, float width, float height, float length, Color color) noexcept
{
    return DrawCube(position, width, height, length, color);
}

void Raylib::Raylib_encap::DwCubeTexture(Texture2D texture, Vector3 position, float width, float height, float length, Color color) noexcept
{
    return DrawCubeTexture(texture, position, width, height, length, color);
}

void Raylib::Raylib_encap::DwModelEx(Model model, Vector3 position, Vector3 rotationAxis, float rotationAngle, Vector3 scale, Color tint) noexcept
{
    return DrawModelEx(model, position, rotationAxis, rotationAngle, scale, tint);
}

Model Raylib::Raylib_encap::LModel(std::string fileName) noexcept
{
    return LoadModel(fileName.c_str());
}

ModelAnimation *Raylib::Raylib_encap::LoadMAnimations(std::string fileName, unsigned int *animCount) noexcept
{
    return LoadModelAnimations(fileName.c_str(), animCount);
}

void Raylib::Raylib_encap::SetMTexture(Material *material, int mapType, Texture2D texture) noexcept
{
    return SetMaterialTexture(material, mapType, texture);
}

void Raylib::Raylib_encap::SetMMeshMaterial(Model *model, int meshId, int materialId) noexcept
{
    return SetModelMeshMaterial(model, meshId, materialId);
}

void Raylib::Raylib_encap::SetConfFlags(unsigned int flags) noexcept
{
    return SetConfigFlags(flags);
}

void Raylib::Raylib_encap::InitAudioDev(void) noexcept
{
    return InitAudioDevice();
}

void Raylib::Raylib_encap::CloseAudioDev(void) noexcept
{
    return CloseAudioDevice();
}

void Raylib::Raylib_encap::CloseWind(void) noexcept
{
    return CloseWindow();
}

void Raylib::Raylib_encap::SetTargFPS(int fps) noexcept
{
    return SetTargetFPS(fps);
}

void Raylib::Raylib_encap::DwPlane(Vector3 centerPos, Vector2 size, Color color) noexcept
{
    return DrawPlane(centerPos, size, color);
}

void Raylib::Raylib_encap::DwTexturePro(Texture2D texture, Rectangle source, Rectangle dest, Vector2 origin, float rotation, Color tint) noexcept
{
    return DrawTexturePro(texture, source, dest, origin, rotation, tint);
}

void Raylib::Raylib_encap::UpdtModelAnimation(Model model, ModelAnimation anim, int frame) noexcept
{
    return UpdateModelAnimation(model, anim, frame);
}

Matrix Raylib::Raylib_encap::MatrixRotZ(float angle) noexcept
{
    return MatrixRotateZ(angle);
}

bool Raylib::Raylib_encap::CheckCollBoxes(BoundingBox box1, BoundingBox box2) noexcept
{
    return CheckCollisionBoxes(box1, box2);
}

float Raylib::Raylib_encap::GetMSTimePlayed(Music music) noexcept
{
    return GetMusicTimePlayed(music);
}