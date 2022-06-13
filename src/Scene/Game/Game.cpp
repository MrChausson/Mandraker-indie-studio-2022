/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Game
*/

#include <iostream>
#include <fstream>
#include "raylib.hpp"
#include "Game.hpp"
#include "raymath.h"
#include "../../ecs/Components/CameraComponent/CameraComponent.hpp"
#include "../../ecs/Components/Animable/Animable.hpp"
#include "../../ecs/Components/Playable/Playable.hpp"
#include "../../ecs/Components/Timable/Timable.hpp"
#include "../../ecs/Components/Collisionable/Collisionable.hpp"
#include "../../ecs/Components/Breakable/Breakable.hpp"
#include "../../ecs/Systems/Animation/Animation.hpp"
#include "../../ecs/Systems/Player/Player.hpp"
#include "../../ecs/Systems/Timer/Timer.hpp"
#include "../../ecs/Systems/Save/SaveSystem.hpp"
#include "../../ecs/Components/Drawable/DrawableCube.hpp"
#include "../../ecs/Components/Drawable/DrawableCubeTexture.hpp"

float mapHeight = 14;
float mapWidth = 10;

Game::Game(std::vector<Model> models, CHARACTER_CHOOSEN characterChoosen)
{
    Raylib::Raylib_encap Raylib_encp;

    this->_characterChoosen = characterChoosen;
    this->_ecsManager = std::make_unique<ECSManager>();
    this->_mapEntities = std::make_unique<std::vector<Entity *>>();
    this->_gryf_infos_texture = Raylib_encp.LTexture("assets/materials/game/gryffindor.png");
    this->_rav_infos_texture = Raylib_encp.LTexture("assets/materials/game/ravenclaw.png");
    this->_slyth_infos_texture = Raylib_encp.LTexture("assets/materials/game/slytherin.png");
    this->_huff_infos_texture = Raylib_encp.LTexture("assets/materials/game/hufflepuff.png");

    // Create camera vectors
    Vector3 position = { 7.0f, 50.0f, 25.0f };
    Vector3 target = { 7.0f, -20.0f, 0.0f };
    Vector3 up = { 0.0f, 1.0f, 0.0f };

    // Createing plane vectors
    Vector2 size = { 128.0f, 128.0f };

    // Creating entities
    int camera = this->_ecsManager->createEntity();
    int text = this->_ecsManager->createEntity();
    int player = this->_ecsManager->createEntity();
    int ai = this->_ecsManager->createEntity();
    int model = this->_ecsManager->createEntity();
    int test_pot = this->_ecsManager->createEntity();
    int trelawney = this->_ecsManager->createEntity();
    std::cout << "TRELAWNEY---------------------------------------------" << std::endl;
    int snape = this->_ecsManager->createEntity();
    int plane = this->_ecsManager->createEntity();
    int sprout = this->_ecsManager->createEntity();
    int gryf_infos = this->_ecsManager->createEntity();
    int rav_infos = this->_ecsManager->createEntity();
    int slyth_infos = this->_ecsManager->createEntity();
    int huff_infos = this->_ecsManager->createEntity();
    int music_id = this->_ecsManager->createEntity();
    // int plane = this->_ecsManager->createEntity();
    int mandrake = this->_ecsManager->createEntity();
    int game_clock = this->_ecsManager->createEntity();

    // Load Music
    this->music = Raylib_encp.LoadMStream("assets/sounds/game_bg.mp3");
    // Creating Model , vector texture and the mesh order for mcg
    this->mgmModel = models[0];
    this->trelawneyModel = models[1];
    this->snapeModel = models[2];
    this->sproutModel = models[3];

    // Creating Mandrake model
    this->mandrakeModel = Raylib_encp.LModel("assets/models/mandrake/mandrake.iqm");

    // Configuring Player vector
    Vector3 position_player = { 1.0f, 0.0f, 0.0f };

    //Configure Music
    Raylib_encp.PlayMStream(music);
    this->_ecsManager->addComponent(music_id, std::make_unique<Musicable>(music));

    // Adding components
    this->_ecsManager->addComponent(camera, std::make_unique<CameraComponent>(position, target, up, 18.0f, CAMERA_PERSPECTIVE));
    //this->_ecsManager->addComponent(text, std::make_unique<Placable>(1000, 150));
    //this->_ecsManager->addComponent(text, std::make_unique<DrawableText>(0,"Mandraker", Color{255, 255, 255, 255}));

    // Adding HUD
    this->_ecsManager->addComponent(gryf_infos, std::make_unique<Placable>(0, 0));
    this->_ecsManager->addComponent(gryf_infos, std::make_unique<DrawableSprite>(this->_gryf_infos_texture, 1));
    this->_ecsManager->addComponent(huff_infos, std::make_unique<Placable>(1792, 0));
    this->_ecsManager->addComponent(huff_infos, std::make_unique<DrawableSprite>(this->_huff_infos_texture, 1));
    this->_ecsManager->addComponent(rav_infos, std::make_unique<Placable>(0, 937));
    this->_ecsManager->addComponent(rav_infos, std::make_unique<DrawableSprite>(this->_rav_infos_texture, 1));
    this->_ecsManager->addComponent(slyth_infos, std::make_unique<Placable>(1792, 937));
    this->_ecsManager->addComponent(slyth_infos, std::make_unique<DrawableSprite>(this->_slyth_infos_texture, 1));


    // Adding Timer
    this->_font = Raylib_encp.LFontEx("assets/fonts/wizarding.ttf", 100, 0, 0);
    this->_ecsManager->addComponent(game_clock, std::make_unique<Placable>(1792/2 - 3, 20));
    this->_ecsManager->addComponent(game_clock, std::make_unique<DrawableText>(1, "", Color{255, 255, 255, 255}, this->_font, 80));
    this->_ecsManager->addComponent(game_clock, std::make_unique<Timable>(120, GAME_CLOCK, game_clock));

    // Configuring player MCG
    this->_ecsManager->addComponent(player, std::make_unique<Placable>(1.0f, 0.0f, 1.0f, position_player, -90.0f));
    if (characterChoosen == CHARACTER_CHOOSEN::MCG)
        this->_ecsManager->addComponent(player, std::make_unique<Movable>(4.0f, MOVABLE_PLAYER));
    else
        this->_ecsManager->addComponent(player, std::make_unique<Movable>(4.0f, MOVABLE_AI));
    this->_ecsManager->addComponent(player, std::make_unique<Playable>(1));
    this->_ecsManager->addComponent(player, std::make_unique<DrawableModel>(texturesMgm, mgmModel, meshOrderMgm));
    this->_ecsManager->addComponent(player, std::make_unique<Animable>("assets/models/mcg/mcg.iqm", ANIMATION_TYPE::IDLE));


    // Configuring player TRELAWNEY
    this->_ecsManager->addComponent(trelawney, std::make_unique<Placable>(1.0f, 0.0f, 11.0f, position_player, -90.0f));
    if (characterChoosen == CHARACTER_CHOOSEN::TRELAWNEY)
        this->_ecsManager->addComponent(trelawney, std::make_unique<Movable>(4.0f, MOVABLE_PLAYER));
    else
        this->_ecsManager->addComponent(trelawney, std::make_unique<Movable>(4.0f, MOVABLE_AI));
        this->_ecsManager->addComponent(trelawney, std::make_unique<Playable>(1));
    this->_ecsManager->addComponent(trelawney, std::make_unique<DrawableModel>(texturesTre, trelawneyModel, meshOrderTrelawney));
    this->_ecsManager->addComponent(trelawney, std::make_unique<Animable>("assets/models/trelawney/trelawney.iqm", ANIMATION_TYPE::IDLE));

    // Configuring player SNAPE
    this->_ecsManager->addComponent(snape, std::make_unique<Placable>(13.0f, 0.0f, 11.0f, position_player, -90.0f));
    if (characterChoosen == CHARACTER_CHOOSEN::SNAPE)
        this->_ecsManager->addComponent(snape, std::make_unique<Movable>(4.0f, MOVABLE_PLAYER));
    else
        this->_ecsManager->addComponent(snape, std::make_unique<Movable>(4.0f, MOVABLE_AI));
    this->_ecsManager->addComponent(snape, std::make_unique<Playable>(1));
    this->_ecsManager->addComponent(snape, std::make_unique<DrawableModel>(texturesSnape, snapeModel, meshOrderSnape));
    this->_ecsManager->addComponent(snape, std::make_unique<Animable>("assets/models/snape/snape.iqm", ANIMATION_TYPE::IDLE));

    //Drawing the plane
    this->_ecsManager->addComponent(plane, std::make_unique<Placable>(0, -1, 0));
    this->_ecsManager->addComponent(plane, std::make_unique<DrawablePlane>(size, DARKBROWN));

    // Configuring player SPROUT
    this->_ecsManager->addComponent(sprout, std::make_unique<Placable>(13.0f, 0.0f, 1.0f, position_player, -90.0f));
    if (characterChoosen == CHARACTER_CHOOSEN::SPROUT)
        this->_ecsManager->addComponent(sprout, std::make_unique<Movable>(4.0f, MOVABLE_PLAYER));
    else
        this->_ecsManager->addComponent(sprout, std::make_unique<Movable>(4.0f, MOVABLE_AI));
    this->_ecsManager->addComponent(sprout, std::make_unique<Playable>(1));
    this->_ecsManager->addComponent(sprout, std::make_unique<DrawableModel>(texturesSprout, sproutModel, meshOrderSprout));
    this->_ecsManager->addComponent(sprout, std::make_unique<Animable>("assets/models/sprout/sprout.iqm", ANIMATION_TYPE::IDLE));

    // Configuring ai
    // this->_ecsManager->addComponent(ai, std::make_unique<Placable>(0, 0));
    // this->_ecsManager->addComponent(ai, std::make_unique<Movable>(1, MOVABLE_AI));

    // Adding systems
    this->_ecsManager->addSystem(std::make_unique<Draw>(Draw()));
    this->_ecsManager->addSystem(std::make_unique<Music_sys>(Music_sys()));
    this->_ecsManager->addSystem(std::make_unique<Move>(Move()));
    this->_ecsManager->addSystem(std::make_unique<Animation>(Animation()));
    this->_ecsManager->addSystem(std::make_unique<Player>(this->_ecsManager.get()));
    this->_ecsManager->addSystem(std::make_unique<SaveSystem>(this->_ecsManager->getEntities()));
    this->loadMap("assets/map/map.txt");
    this->_ecsManager->addSystem(std::make_unique<Timer>(this->_ecsManager.get(), this->_mapEntities.get()));

    // Collision configuration
    this->_ecsManager->addComponent(player, std::make_unique<Collisionable>(this->_mapEntities.get()));
    this->_ecsManager->addComponent(sprout, std::make_unique<Collisionable>(this->_mapEntities.get()));
    this->_ecsManager->addComponent(trelawney, std::make_unique<Collisionable>(this->_mapEntities.get()));
    this->_ecsManager->addComponent(snape, std::make_unique<Collisionable>(this->_mapEntities.get()));

    // this->_ecsManager->addSystem(std::make_unique<Move>());
    std::cout << "Game created" << std::endl;
}

Game::~Game()
{
}

void Game::loadMap(std::string map_src)
{
    Raylib::Raylib_encap Raylib_encp;
    std::ifstream myfile (map_src);
    std::string line;
    int i = 0;

    // Gass
    this->grass_texture = Raylib_encp.LTexture("assets/materials/grass.png");
    // Stone
    this->stone_texture = Raylib_encp.LTexture("assets/materials/game/stone.png");
    this->textures_bag = {
        Raylib_encp.LTexture("assets/models/bag/p_FertiliserBag_Diffuse_v1@4x.png")
    };

    //bag
    std::vector<int> texture_po_mesh_order = {
        0
    };
    this->bagModel = Raylib_encp.LModel("assets/models/bag/bag.obj");

    //Table
    this->textures_tables = {
        Raylib_encp.LTexture("assets/models/table/leaves2_v73@4x.png"),
        Raylib_encp.LTexture("assets/models/table/Metal_potteryHolders_v11@4x.png"),
        Raylib_encp.LTexture("assets/models/table/pottery02_v18@4x.png"),
    };
    std::vector<int> texture_table_mesh_order = {
        2, 0, 1
    };
    this->tableModel = Raylib_encp.LModel("assets/models/table/table.obj");
    this->tableModelRotate = Raylib_encp.LModel("assets/models/table/table.obj");
    tableModelRotate.transform = MatrixRotateY(1.55 );

    // Gnome
    this->gnome = Raylib_encp.LModel("assets/models/gnome/gnome.iqm");
    gnome.transform = MatrixRotateX(1.55);
    this->textures_gnome = {
        Raylib_encp.LTexture("assets/models/gnome/gnome_DIF_v1@4x.png"),
        Raylib_encp.LTexture("assets/models/gnome/GnomeHoles_DIF_v1@4x.png")
    };
    std::vector<int> texture_gnome_mesh_order = {
        0, 2
    };
    Vector3 gnome_scale = {0.015, 0.015, 0.015};
    // 
    Vector3 zeroVector3 = {0.0f, 0.0f, 0.0f};
    Vector3 rotation_gnome = {0.0f, 90.0f, 0.0f};
    Vector3 bag_scale = {0.03, 0.03, 0.03};
    Vector2 size = { 1, 1 };
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    if (!myfile.is_open())
        throw Error_file("Error while opening map file");
    while (std::getline(myfile, line)) {
        for (int j = 0; j < line.size(); j++) {
            Entity *entity = nullptr;
            Entity *grass_block = this->_ecsManager->getEntity(this->_ecsManager->createEntity());
            if (line[j] == 'r') {
                entity = this->_ecsManager->getEntity(this->_ecsManager->createEntity());
                entity->addComponent(std::make_unique<Placable>(j, -0.5f, i, zeroVector3 , -45, bag_scale));
                entity->addComponent(std::make_unique<DrawableModel>(textures_bag, bagModel, texture_po_mesh_order));
                // we have to put grass also
                grass_block->addComponent(std::make_unique<Placable>(j, -1.0f, i, zeroVector3));
                grass_block->addComponent(std::make_unique<DrawableCubeTexture>(grass_texture, CubeTextureType::GRASS));
            } else if (line[j] == 'B') {
                entity = this->_ecsManager->getEntity(this->_ecsManager->createEntity());
                entity->addComponent(std::make_unique<Placable>(j, -1.0f, i, zeroVector3));
                entity->addComponent(std::make_unique<DrawableModel>(textures_tables, tableModel, texture_table_mesh_order));
                // we have to put grass also
                grass_block->addComponent(std::make_unique<Placable>(j, -1.0f, i, zeroVector3));
                grass_block->addComponent(std::make_unique<DrawableCubeTexture>(grass_texture, CubeTextureType::GRASS));
            } else if (line[j] == '*') {
                grass_block->addComponent(std::make_unique<Placable>(j, -1.0f, i, zeroVector3));
                grass_block->addComponent(std::make_unique<DrawableCubeTexture>(stone_texture, CubeTextureType::STONE));
            } else {
                if (std::rand() % 2 == 1) { // 50% chance to spawn a gnome
                    entity = this->_ecsManager->getEntity(this->_ecsManager->createEntity());
                    entity->addComponent(std::make_unique<Placable>(j, -0.7, i, zeroVector3, 0, gnome_scale));
                    entity->addComponent(std::make_unique<DrawableModel>(textures_gnome, gnome, texture_gnome_mesh_order));
                    entity->addComponent(std::make_unique<Breakable>());
                }
                // we have to put grass also
                grass_block->addComponent(std::make_unique<Placable>(j, -1.0f, i, zeroVector3));
                grass_block->addComponent(std::make_unique<DrawableCubeTexture>(grass_texture, CubeTextureType::GRASS));
            }
            if (entity != nullptr)
                this->_mapEntities->push_back(entity);
        }
        i++;
    }
    myfile.close();
}


void Game::Unload()
{
    std::cout << "Game destructor" << std::endl;
    Raylib::Raylib_encap RaylibEncap;
    RaylibEncap.UnlTexture(this->_gryf_infos_texture);
    RaylibEncap.UnlTexture(this->_rav_infos_texture);
    RaylibEncap.UnlTexture(this->_slyth_infos_texture);
    RaylibEncap.UnlTexture(this->_huff_infos_texture);
    RaylibEncap.UnloadMStream(this->music);
    RaylibEncap.UnloadMdl(mgmModel);
    RaylibEncap.UnloadMdl(trelawneyModel);
    RaylibEncap.UnloadMdl(snapeModel);
    RaylibEncap.UnloadMdl(sproutModel);
    for (auto &i : texturesMgm)
        RaylibEncap.UnlTexture(i);
    for (auto &i : texturesTre)
        RaylibEncap.UnlTexture(i);
    for (auto &i : texturesSnape)
        RaylibEncap.UnlTexture(i);
    for (auto &i : texturesSprout)
        RaylibEncap.UnlTexture(i);
    RaylibEncap.UnlTexture(grass_texture);
    RaylibEncap.UnlTexture(stone_texture);
    for (auto &i : textures_bag)
        RaylibEncap.UnlTexture(i);
    for (auto &i : textures_tables)
        RaylibEncap.UnlTexture(i);
    for (auto &i : textures_gnome)
        RaylibEncap.UnlTexture(i);
    RaylibEncap.UnloadMdl(bagModel);
    RaylibEncap.UnloadMdl(tableModel);
    RaylibEncap.UnloadMdl(tableModelRotate);
    RaylibEncap.UnloadMdl(gnome);
    RaylibEncap.UnlFont(this->_font);
}