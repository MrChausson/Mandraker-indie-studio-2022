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
    std::this_thread::sleep_for(sleep_here);
}

void Chrono::setFps(int fps)
{
    this->_toSleep = std::chrono::duration<double>(1.0 / fps);
}