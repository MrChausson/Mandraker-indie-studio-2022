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

void Gravity::apply(IComponent *component)
{
    Placable *placable = (Placable *) component;
    placable->setZ(placable->getZ() - 1.0);
}

SYSTEM_TYPES Gravity::getType()
{
    return (GRAVITY);
}

std::vector<SYSTEM_TYPES> Gravity::getAffectedComponents()
{
    std::vector<SYSTEM_TYPES> affectedComponents;
    affectedComponents.push_back(GRAVITY);
    return (affectedComponents);
}