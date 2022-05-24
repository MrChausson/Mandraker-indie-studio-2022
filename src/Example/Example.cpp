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
    // On fait une instance de ECSManager
    ECSManager manager; 
    // On crée deux entités et on enregistre leur ids
    int id_test = manager.createEntity();
    int id_test2 = manager.createEntity();
    // On crée deux composants "Placable"
    std::unique_ptr<IComponent> placable = std::make_unique<Placable>(Placable(1.1, 2.2, 3.3));
    std::unique_ptr<IComponent> placable2 = std::make_unique<Placable>(Placable(1.1, 2.2, 5.0));

    // On ajoute ces composants aux entités
    // Attention le std::move déplace le pointeur et donc le composant sera inutilisable ici
    manager.addComponent(id_test2, std::move(placable2));
    manager.addComponent(id_test, std::move(placable));

    // On crée un système de gravité qu'on ajoute au manager
    manager.addSystem(std::make_unique<Gravity>(Gravity()));

    // On récupère les composants des deux entités
    // On peut récupérer les composants en récupérant la liste entière
    Placable *placable_test = (Placable *) manager.getEntity(id_test)->getComponents()[0];  
    // On peut aussi récupérer les composants en récupérant uniquement leur type (Conseillé)
    Placable *placable_test2;
    //on fait un try catch pour éviter les erreurs où le type de composant n'existe pas
    try {
        placable_test2 = static_cast<Placable *>(manager.getEntity(id_test2)->getComponentsByType((PLACABLE)));
    } catch (ComponentNotFound &e) {
        std::cout << e.what() << std::endl;
        exit(84);
    }

    // On affiche les valeurs Z des deux composants "Placable"
    std::cout << "z: " << placable_test->getZ() << std::endl;
    std::cout << "z2: " << placable_test2->getZ() << std::endl;

    // On applique tous les systèmes ajoutés dans le manager (ici la gravité par exemple)
    manager.applySystems();
    
    // On ré-affiche pour voir si il y a eu modification
    std::cout << "z: " << placable_test->getZ() << std::endl;
    std::cout << "z2: " << placable_test2->getZ() << std::endl;

    // On supprime les entités
    manager.deleteEntity(id_test2);
    manager.deleteEntity(id_test);
}
