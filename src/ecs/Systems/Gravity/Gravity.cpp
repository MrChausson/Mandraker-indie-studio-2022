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

void Gravity::apply(std::vector<IComponent *> component)
{
    Placable *placable = (Placable *) component[0];
    placable->setZ(placable->getZ() - 1.0);
}

SYSTEM_TYPES Gravity::getType()
{
    return (GRAVITY);
}