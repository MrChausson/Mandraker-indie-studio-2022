/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Game
*/

#include "Game.hpp"
#include "../../ecs/Components/CameraComponent/CameraComponent.hpp"
#include "../../ecs/Components/Drawable/DrawableCube.hpp"
#include "../../ecs/Components/Drawable/DrawableCubeTexture.hpp"

Game::Game(Engine *engine)
{
    this->_ecsManager = std::make_unique<ECSManager>();
    this->_engine = engine;

    // Create camera vectors
    Vector3 position = { 0.0f, 15.0f, 5.0f };
    Vector3 target = { 0.0f, 0.0f, 0.0f };
    Vector3 up = { 0.0f, 1.0f, 0.0f };

    // Creating entities
    int camera = this->_ecsManager->createEntity();
    int text = this->_ecsManager->createEntity();
    int player = this->_ecsManager->createEntity();
    int ai = this->_ecsManager->createEntity();
    int test_cube = this->_ecsManager->createEntity();
    int texture_cube = this->_ecsManager->createEntity();
    int model = this->_ecsManager->createEntity();

    // Creating vector textur for mcg 
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
    this->_ecsManager->addComponent(camera, std::make_unique<CameraComponent>(position, target, up, 70.0f, CAMERA_PERSPECTIVE));
    // this->_ecsManager->addComponent(test_cube, std::make_unique<DrawableCube>(WHITE));
    // this->_ecsManager->addComponent(test_cube, std::make_unique<Placable>(0.0f, 0.0f, 0.0f ));
    this->_ecsManager->addComponent(texture_cube, std::make_unique<Placable>(1.0f, 0.0f, 0.0f ));
    this->_ecsManager->addComponent(texture_cube, std::make_unique<DrawableCubeTexture>(LoadTexture("assets/materials/brique.png")));
    this->_ecsManager->addComponent(text, std::make_unique<Placable>(1000, 150));
    this->_ecsManager->addComponent(text, std::make_unique<DrawableText>(0,"Mandraker", Color{255, 255, 255, 255}));
    // Configuring player
    this->_ecsManager->addComponent(player, std::make_unique<Placable>(0.0f, 0.0f, 0.0f));
    this->_ecsManager->addComponent(player, std::make_unique<DrawableModel>(textures, "assets/models/mcg/mcg.iqm", meshOrder));
    // // Configuring ai
    // this->_ecsManager->addComponent(ai, std::make_unique<Placable>(0, 0));
    // this->_ecsManager->addComponent(ai, std::make_unique<Movable>(1, MOVABLE_AI));

    // Adding systems
    this->_ecsManager->addSystem(std::make_unique<Draw>());
    // this->_ecsManager->addSystem(std::make_unique<Move>());
    std::cout << "Game created" << std::endl;
}

Game::~Game()
{
    std::cout << "Game destructor" << std::endl;
}



// Model model = LoadModel("assets/models/mcg/mcg.iqm");
//     Texture2D texture = LoadTexture("assets/models/mcg/c_McGonagall_Body_Diffuse_v1@4x.png");
//     Texture2D texture1 = LoadTexture("assets/models/mcg/c_McGonagall_eyes_Diffuse_v1@4x.png");
//     Texture2D texture2 = LoadTexture("assets/models/mcg/c_McGonagall_hands_Diffuse_v1@4x.png");
//     Texture2D texture3 = LoadTexture("assets/models/mcg/c_McGonagall_Hat_Diffuse_v1@4x.png");
//     Texture2D texture4 = LoadTexture("assets/models/mcg/c_McGonagall_Head_Diffuse_v1@4x.png");
//     Texture2D texture5 = LoadTexture("assets/models/mcg/glass.png");

//     SetMaterialTexture(&model.materials[0], MATERIAL_MAP_DIFFUSE, texture);
//     SetMaterialTexture(&model.materials[1], MATERIAL_MAP_DIFFUSE, texture1);
//     SetMaterialTexture(&model.materials[2], MATERIAL_MAP_DIFFUSE, texture2);
//     SetMaterialTexture(&model.materials[3], MATERIAL_MAP_DIFFUSE, texture3);
//     SetMaterialTexture(&model.materials[4], MATERIAL_MAP_DIFFUSE, texture4);
//     SetMaterialTexture(&model.materials[5], MATERIAL_MAP_DIFFUSE, texture5);

//     SetModelMeshMaterial(&model, 1, 0); // Robe
//     SetModelMeshMaterial(&model, 2, 1); // Yeux
//     SetModelMeshMaterial(&model, 3, 2);  // Main
//     SetModelMeshMaterial(&model, 5, 3); // Chapeau
//     SetModelMeshMaterial(&model, 0, 4); // tete
//     SetModelMeshMaterial(&model, 4, 5); // Cheveux

//     Vector3 position = { 0.0f, 0.0f, 0.0f };

//     unsigned int animsCount = 0;
//     ModelAnimation *anims = LoadModelAnimations("assets/models/mcg/mcg.iqm", &animsCount);
//     int animFrameCounter = 0;