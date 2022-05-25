/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Chrono
*/

#include "Chrono.hpp"

Chrono::Chrono(int fps)
{
    this->_toSleep = std::chrono::duration<double>(1.0 / fps);
}

Chrono::~Chrono()
{
}

void Chrono::init()
{
    this->_start = std::chrono::system_clock::now();
    this->_end = std::chrono::system_clock::now();
}

void Chrono::startLoop()
{
    this->_elapsedSeconds = this->_end - this->_start;
    this->_start = std::chrono::system_clock::now();
}

void Chrono::sleepEndLoop()
{
    std::chrono::duration<double> sleep_here = this->_toSleep - this->_elapsedSeconds;

    this->_end = std::chrono::system_clock::now();
    if (sleep_here.count() < 0)
        return;
    #ifdef _WIN32
        Sleep(sleep_here.count() * 1000);
    #endif
    #ifdef __linux__
        usleep(sleep_here.count() * 1000000);
    #endif
}

void Chrono::setFps(int fps)
{
    this->_toSleep = std::chrono::duration<double>(1.0 / fps);
}