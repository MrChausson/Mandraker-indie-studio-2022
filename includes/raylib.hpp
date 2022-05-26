/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.de-laage-de-meux
** File description:
** raylib
*/

#ifndef RAYLIB_H_

#include <string.h>
#include <stddef.h>
#include "../_deps/raylib-src/src/raylib.h"

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
    bool isKeyPres(int &key) const noexcept;
    bool IsKDown(int &key) const noexcept;
    bool isKReleased(int &key) const noexcept;
    void SetExitK(int key) const noexcept;
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
    void SetMousePos(int x, int y) const noexcept;
    int GetKeyPres(void) noexcept;
    Music LoadMStream(std::string& fileName) const noexcept;
    void UnloadMStream(Music music) noexcept;
    void PlayMStream(Music music) noexcept;
    bool IsMStreamPlaying(Music music) noexcept;
    void StopMStream(Music music) noexcept;
    void PauseMStream(Music music) noexcept;
    void ResumeMStream(Music music) noexcept;
    void SeekMStream(Music music, float position) noexcept;
    void SetMVolume(Music music, float volume) noexcept;
};








#endif