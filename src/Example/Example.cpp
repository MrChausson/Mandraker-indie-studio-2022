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


int main(void)
{
    ECSManager manager;
    std::unique_ptr<IComponent> placable = std::make_unique<Placable>(Placable(1.1, 2.2, 3.3));

    int id_test = manager.createEntity();
    int second_id = manager.createEntity();
    std::cout << "id_test = " << id_test << std::endl;
    Entity *test = manager.getEntity(id_test);
    manager.addComponent(id_test, std::move(placable));
    manager.deleteEntity(second_id);
}
