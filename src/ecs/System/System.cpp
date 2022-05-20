/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** System
*/

#include "System.hpp"

template <class T>
void System::add_component(Components<T> component)
{
    v_components.push_back(component);
}