/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Gravity
*/

#include "Gravity.hpp"
#include "../../Components/Placable/Placable.hpp"
#include  <memory>

Gravity::Gravity()
{
}

Gravity::~Gravity()
{
}

void Gravity::apply(std::unique_ptr<IComponent> component)
{
    Placable *placable = (Placable *) component.get();
    placable->setZ(placable->getZ() - 1.0);
}