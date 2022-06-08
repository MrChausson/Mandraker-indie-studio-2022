/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Game
*/

#include <iostream>
#include <fstream>
#include "Game.hpp"
#include "../../ecs/Components/CameraComponent/CameraComponent.hpp"
#include "../../ecs/Components/Animable/Animable.hpp"
#include "../../ecs/Systems/Animation/Animation.hpp"
#include "../../ecs/Components/Drawable/DrawableCube.hpp"
#include "../../ecs/Components/Drawable/DrawableCubeTexture.hpp"


Game::Game()
{
    this->_ecsManager = std::make_unique<ECSManager>();
    this->_mapEntities = std::make_unique<std::vector<Entity *>>();

    // Create camera vectors
    Vector3 position = { 10.0f, 60.0f, 25.0f };
    Vector3 target = { 10.0f, -25.0f, 0.0f };
    Vector3 up = { 0.0f, 1.0f, 0.0f };

    // Createing plane vectors
    Vector2 size = { 12.0f, 8.0f };

    // Creating entities
    int camera = this->_ecsManager->createEntity();
    int text = this->_ecsManager->createEntity();
    int player = this->_ecsManager->createEntity();
    int ai = this->_ecsManager->createEntity();
    int model = this->_ecsManager->createEntity();
    int test_pot = this->_ecsManager->createEntity();
    // int plane = this->_ecsManager->createEntity();

    // Creating vector texture and the mesh order for mcg 
    std::vector<Texture2D> textures = {
        LoadTexture("assets/models/mcg/c_McGonagall_Body_Diffuse_v1@4x.png"),
        LoadTexture("assets/models/mcg/c_McGonagall_eyes_Diffuse_v1@4x.png"),
        LoadTexture("assets/models/mcg/c_McGonagall_hands_Diffuse_v1@4x.png"),
        LoadTexture("assets/models/mcg/c_McGonagall_Hat_Diffuse_v1@4x.png"),
        LoadTexture("assets/models/mcg/c_McGonagall_Head_Diffuse_v1@4x.png"),
        LoadTexture("assets/models/mcg/glass.png")
    };
    std::vector<int> meshOrder = {
        1, 2, 3, 5, 0, 4
    };


    // Adding components
    this->_ecsManager->addComponent(camera, std::make_unique<CameraComponent>(position, target, up, 18.0f, CAMERA_PERSPECTIVE));
    // this->_ecsManager->addComponent(test_cube, std::make_unique<DrawableCube>(WHITE));
    // this->_ecsManager->addComponent(test_cube, std::make_unique<Placable>(0.0f, 0.0f, 0.0f ));
    this->_ecsManager->addComponent(text, std::make_unique<Placable>(1000, 150));
    this->_ecsManager->addComponent(text, std::make_unique<DrawableText>(0,"Mandraker", Color{255, 255, 255, 255}));
    // Configuring player
    this->_ecsManager->addComponent(player, std::make_unique<Placable>(1.0f, 0.0f, 1.0f, (Vector3){1.0f, 0.0f, 0.0f}, -90.0f));
    this->_ecsManager->addComponent(player, std::make_unique<Movable>(4.0f, MOVABLE_PLAYER));
    Model mgmModel = LoadModel("assets/models/mcg/mcg.iqm");
    this->_ecsManager->addComponent(player, std::make_unique<DrawableModel>(textures, mgmModel, meshOrder));
    this->_ecsManager->addComponent(player, std::make_unique<Animable>("assets/models/mcg/mcg.iqm", ANIMATION_TYPE::LOST));
    // Configuring bag
    // // Configuring ai
    // this->_ecsManager->addComponent(ai, std::make_unique<Placable>(0, 0));
    // this->_ecsManager->addComponent(ai, std::make_unique<Movable>(1, MOVABLE_AI));

    // Adding systems
    this->_ecsManager->addSystem(std::make_unique<Draw>());
    this->_ecsManager->addSystem(std::make_unique<Move>());
    this->_ecsManager->addSystem(std::make_unique<Animation>());
    this->loadMap("assets/map/map.txt");
    // this->_ecsManager->addSystem(std::make_unique<Move>());
    std::cout << "Game created" << std::endl;
}

Game::~Game()
{
    std::cout << "Game destructor" << std::endl;
}

void Game::loadMap(std::string map_src)
{
    //load map from file
    std::ifstream myfile (map_src);
    std::string line;
    int i = 0;
    std::vector<Texture2D> textures_pot = {
        LoadTexture("assets/models/bag/p_FertiliserBag_Diffuse_v1@4x.png")
    };
    std::vector<int> texture_po_mesh_order = {
        0
    };
    //Table model
    std::vector<Texture2D> textures_tables = {
        LoadTexture("assets/models/table/leaves2_v73@4x.png"),
        LoadTexture("assets/models/table/Metal_potteryHolders_v11@4x.png"),
        LoadTexture("assets/models/table/pottery02_v18@4x.png"),
    };
    std::vector<int> texture_table_mesh_order = {
        2, 0, 1
    };
    Model tableModel = LoadModel("assets/models/table/table.obj");
    Model bagModel = LoadModel("assets/models/bag/bag.obj");
    Vector3 zeroVector3 = {0.0f, 0.0f, 0.0f};
    Vector3 bag_scale = {0.03, 0.03, 0.03};
    Vector2 size = { 1, 1 };

    if (!myfile.is_open())
        throw Error_file("Error while opening map file");
    while (std::getline(myfile, line)) {
        for (int j = 0; j < line.size(); j++) {
            Entity *entity = this->_ecsManager->getEntity(this->_ecsManager->createEntity());
            if (line[j] == 'r') {
                entity->addComponent(std::make_unique<Placable>(j, 0.0f, i, zeroVector3 , -45, bag_scale));
                entity->addComponent(std::make_unique<DrawableModel>(textures_pot, bagModel, texture_po_mesh_order));
            } else if (line[j] == 'B') {
                entity->addComponent(std::make_unique<Placable>(j, 0.5f, i, zeroVector3));
                entity->addComponent(std::make_unique<DrawableModel>(textures_tables, tableModel, texture_table_mesh_order));
            } else if (line[j] == '*') {
                entity->addComponent(std::make_unique<Placable>(j, 0.0f, i, zeroVector3));
                entity->addComponent(std::make_unique<DrawablePlane>(size));
            }
            this->_mapEntities->push_back(entity);
        }
        i++;
    }
    myfile.close();
}
