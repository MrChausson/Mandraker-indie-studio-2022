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
    void Windowsinit(int &screenWidth, int &screenHeight, std::string const &title, std::size_t const &fps) noexcept;
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
    void SetMousePos(std::pair<int, int> const &pos) const noexcept;
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
    void BeginM3D(Camera3D camera) noexcept;
    void EndM3D(void) noexcept;
    void BeginTextMode(RenderTexture2D target) noexcept;
    void EndTextMode(void) noexcept;
    void BeginShadMode(Shader shader) noexcept;
    void EndShadMode(void) noexcept;
    void BeginBMode(int mode) noexcept;
    void EndBMode(void) noexcept;
    bool checkCollPointRec(std::pair<float, float> mouse_xy, float width, float height, float X, float Y) noexcept;
    Sound LSound(std::string fileName) noexcept;
    Font LFontEx(std::string fileName, int fontSize, int *fontChars, int glyphCount) noexcept;
    Texture2D LTexture(std::string fileName) noexcept;
    void PlayS(Sound sound) noexcept;
    void StopS(Sound sound) noexcept;
    void PauseS(Sound sound) noexcept;
    void ResumeS(Sound sound) noexcept;
    void ClearBkground(Color color) noexcept;
    void BgDrawing(void) noexcept;
    void EDrawing(void) noexcept;
    void DwTexture(Texture2D texture, int posX, int posY, Color tint) noexcept;
    void DwFPS(std::pair<int, int> const &pos) noexcept;
    void DwText(std::string text, std::pair<int, int> const &pos, int fontSize, Color color) noexcept;
    void DwTextEx(Font font, std::string text, Vector2 position, float fontSize, float spacing, Color tint) noexcept;
    void UpdtMusicStream(Music music) noexcept;
    void UnlTexture(Texture2D texture) noexcept;
    void UnlFont(Font font) noexcept;
    void UnlSound(Sound sound) noexcept;

};








#endif