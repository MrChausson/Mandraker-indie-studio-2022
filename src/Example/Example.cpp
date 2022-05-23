/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Example
*/

#include <iostream>
#include <memory>
#include "../ecs/ECSManager/ECSManager.hpp"
#include "../ecs/Components/Placable/Placable.hpp"
#include "../ecs/Systems/Gravity/Gravity.hpp"


int main(void)
{
    ECSManager manager;

    int id_test = manager.createEntity();
    std::unique_ptr<IComponent> placable = std::make_unique<Placable>(Placable(1.1, 2.2, 3.3));
    manager.addComponent(id_test, std::move(placable));
    manager.addSystem(std::make_unique<Gravity>(Gravity()));
    Placable *placable_test = (Placable *) manager.getEntity(id_test)->getComponents()[0];  
    std::cout << "z: " << placable_test->getZ() << std::endl;
    manager.applySystems();
    placable_test = (Placable *) manager.getEntity(id_test)->getComponents()[0];
    std::cout << "z: " << placable_test->getZ() << std::endl;
    // manager.deleteEntity(id_test);
}
