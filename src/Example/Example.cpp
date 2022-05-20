/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Example
*/

#include "Example.hpp"

Example::Example()
{
}

Example::~Example()
{
}

Entities Example::CreatingRemovingEntities(void)
{
    // First we create the Etity class which will store entities
    // An entity is just a ID
    Entities entities;
    // Then we add two entities: me and you
    Entity me = entities.create();
    Entity you = entities.create();
    // Let's print those Entities, meaning their ids
    entities.print();

    // Let's create a vector which is going to store the bad guys.
    std::vector<Entity> badGuys;
    for (int i=0; i<10; ++i)
        badGuys.push_back(entities.create());
    // So we created 10 bad guys, let's print them out
    entities.print();
    // The bad guys killed you ! Let's remove you
    entities.remove(you); // you're dead xD
    // let's print all of the entities and now you'll see you're missing
    entities.print();
    // Jesus Christ comes in and revives you
    you = entities.create();
    // Now you're alive, lucky you
    entities.print();
    return entities;
}

