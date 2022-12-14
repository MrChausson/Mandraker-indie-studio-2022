/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Settings
*/

#include "raylib.hpp"
#include "CharacterSelector.hpp"
#include "raymath.h"
#include "../../ecs/Components/Clickable/Clickable.hpp"
#include "../../Tools/Button.hpp"
#include <string>
#include "../../ecs/Components/CameraComponent/CameraComponent.hpp"
#include "../../ecs/Components/Animable/Animable.hpp"
#include "../../ecs/Systems/Animation/Animation.hpp"
#include "../../ecs/Systems/Sound/SoundSystem.hpp"

CharacterSelector::CharacterSelector(int nb_characters, std::vector<CHARACTER_CHOOSEN> *characterChoosen)
{
    Raylib::Raylib_encap Raylib_encp;
    Vector3 position = { 0.0f, 10.0f, 180.0f };
    Vector3 target = { 32.0f, 25.0f, 0.0f };
    Vector3 up = { 0.0f, 1.0f, 0.0f };
    Vector3 scale = { 0.5, 0.5, 0.5 };

    this->_characterChoosen = characterChoosen;
    std::cout << "Options creating" << std::endl;
    this->_ecsManager = std::make_unique<ECSManager>();
    this->nb_characters = nb_characters;
    int bg_id = this->_ecsManager->createEntity();
    int title_id = this->_ecsManager->createEntity();
    int title_text = this->_ecsManager->createEntity();
    int music_id = this->_ecsManager->createEntity();
    int character_mcg = this->_ecsManager->createEntity();
    int character_sprout = this->_ecsManager->createEntity();
    int character_trelawney = this->_ecsManager->createEntity();
    int character_snape = this->_ecsManager->createEntity();
    int camera = this->_ecsManager->createEntity();
    std::string text = "";

    int total = 420 * 4;
    int start_pos = (1920/2 - total/2);

    this->_music = Raylib_encp.LoadMStream("assets/sounds/char_select_bg.mp3");
    this->_type = SCENE_CHARACTER_SELECTOR;
    this->_title_texture = Raylib_encp.LTexture("assets/materials/selection/title_bar.png");
    this->_btn_font = Raylib_encp.LFontEx("assets/fonts/wizarding.ttf", 90, 0, 0);
    this->_btn_textures[0] = Raylib_encp.LTexture("assets/materials/buttons/btn_hovered.png");
    this->_btn_textures[1] = Raylib_encp.LTexture("assets/materials/buttons/btn_inactive.png");
    this->_btn_textures[2] = Raylib_encp.LTexture("assets/materials/buttons/btn_clicked.png");
    this->_background_texture = Raylib_encp.LTexture("assets/materials/selection/background.png");

    //this->_box Textures
    this->_box[0] = Raylib_encp.LTexture("assets/materials/selection/btn_hovered.png");
    this->_box[1] = Raylib_encp.LTexture("assets/materials/selection/btn_inactive.png");
    this->_box[2] = Raylib_encp.LTexture("assets/materials/selection/btn_clicked.png");
    this->_box[3] = Raylib_encp.LTexture("assets/materials/selection/btn_selected.png");

    // Creating vector texture and the mesh order for mcg
    this->_textures_mcg = {
        Raylib_encp.LTexture("assets/models/mcg/c_McGonagall_Body_Diffuse_v1@4x.png"),
        Raylib_encp.LTexture("assets/models/mcg/c_McGonagall_eyes_Diffuse_v1@4x.png"),
        Raylib_encp.LTexture("assets/models/mcg/c_McGonagall_hands_Diffuse_v1@4x.png"),
        Raylib_encp.LTexture("assets/models/mcg/c_McGonagall_Hat_Diffuse_v1@4x.png"),
        Raylib_encp.LTexture("assets/models/mcg/c_McGonagall_Head_Diffuse_v1@4x.png"),
        Raylib_encp.LTexture("assets/models/mcg/glass.png")
    };
    std::vector<int> meshOrder_mcg = {
        1, 2, 3, 5, 0, 4
    };
    Vector3 rotationAxis = {2.0f, 0.0f, 0.0f};

    //sprout
        this->_textures_sprout = {
        Raylib_encp.LTexture("assets/models/sprout/Sprout_body_diffuse_v1@4x.png"),
        Raylib_encp.LTexture("assets/models/sprout/Sprout_cloak_diffuse_v1@4x.png"),
        Raylib_encp.LTexture("assets/models/sprout/Sprout_eyes_diffuse_v1@4x.png"),
        Raylib_encp.LTexture("assets/models/sprout/Sprout_face_diffuse_v1@4x.png"),
        Raylib_encp.LTexture("assets/models/sprout/Sprout_hair_diffuse_v1@4x.png"),
        Raylib_encp.LTexture("assets/models/sprout/Sprout_hand_diffuse_v1@4x.png"),
        Raylib_encp.LTexture("assets/models/sprout/Sprout_hat_diffuse_v1@4x.png")
    };
    std::vector<int> meshOrder_sprout = {
        1, 5, 4, 0, 6, 3, 2
    };

        // Creating Model , vector texture and the mesh order for Trelawney
    this->_texturesTre = {
        Raylib_encp.LTexture("assets/models/trelawney/ProfTrelawney_accessory_diffuse_v1@4x.png"),
        Raylib_encp.LTexture("assets/models/trelawney/ProfTrelawney_body_diffuse_v1@4x.png"),
        Raylib_encp.LTexture("assets/models/trelawney/Trelawney_face_diffuse_v1@4x.png"),
        Raylib_encp.LTexture("assets/models/trelawney/Trelawney_hair_diffuse_v1@4x.png"),
        Raylib_encp.LTexture("assets/models/trelawney/Trelawney_hands_diffuse_v1@4x.png"),
        Raylib_encp.LTexture("assets/models/trelawney/Trelawney_eyes_diffuse_v1@4x.png")
    };
    std::vector<int> meshOrderTrelawney = {
        2, 1, 0, 6, 3, 4
    };

    // Creating Model , vector texture and the mesh order for Snape
    this->_textures_snape = {
        Raylib_encp.LTexture("assets/models/snape/c_Snape_Hair_diffuse_v3@4x.png"),
        Raylib_encp.LTexture("assets/models/snape/c_Snape_Hands_diffuse_v8@4x.png"),
        Raylib_encp.LTexture("assets/models/snape/c_Snape_Head_diffuse_v3@4x.png"),
        Raylib_encp.LTexture("assets/models/snape/c_Snape_Outfit_diffuse_v3@4x.png"),
        Raylib_encp.LTexture("assets/models/snape/EyesBW_v169@4x.png")
    };
    std::vector<int> meshOrderSnape = {
       4, 3, 0, 2, 1
    };

    Raylib_encp.PlayMStream(this->_music);

    // Title
    this->_ecsManager->addComponent(title_id, std::make_unique<Placable>(960 - _title_texture.width / 2, 0));
    this->_ecsManager->addComponent(title_id, std::make_unique<DrawableSprite>(this->_title_texture, 1));

    // Text
    this->_ecsManager->addComponent(title_text, std::make_unique<Placable>(500, 60));
    if (nb_characters == 1)
        text = "player 1 : character";
    else
        text = "player 2 : character";
    this->_ecsManager->addComponent(title_text, std::make_unique<DrawableText>(2, text, Color{255, 255, 255, 255}, this->_btn_font));
    // Background texture
    this->_ecsManager->addComponent(bg_id, std::make_unique<Placable>(0, 0));
    this->_ecsManager->addComponent(bg_id, std::make_unique<DrawableSprite>(this->_background_texture, 0));

    this->_SoundMcg = {
        Raylib_encp.LSound("assets/sounds/mcg/selection/mcg_select_01.wav"),
        Raylib_encp.LSound("assets/sounds/mcg/selection/mcg_select_02.wav"),
        Raylib_encp.LSound("assets/sounds/mcg/selection/mcg_select_03.wav"),
    };
    this->_SoundSprout = {
        Raylib_encp.LSound("assets/sounds/sprout/selection/sprout_select_01.wav"),
        Raylib_encp.LSound("assets/sounds/sprout/selection/sprout_select_02.wav"),
        Raylib_encp.LSound("assets/sounds/sprout/selection/sprout_select_03.wav"),
    };
    this->_SoundSnape = {
        Raylib_encp.LSound("assets/sounds/snape/selection/snape_select_01.wav"),
        Raylib_encp.LSound("assets/sounds/snape/selection/snape_select_02.wav"),
        Raylib_encp.LSound("assets/sounds/snape/selection/snape_select_03.wav"),
    };
    this->_SoundTrelawney = {
        Raylib_encp.LSound("assets/sounds/trelawney/selection/trelawney_select_01.wav"),
        Raylib_encp.LSound("assets/sounds/trelawney/selection/trelawney_select_02.wav"),
        Raylib_encp.LSound("assets/sounds/trelawney/selection/trelawney_select_03.wav"),
    };

    // Box for the characters selection
    if ((*characterChoosen).size() == 1 && (*characterChoosen)[0] == MCG)
        this->_idBoxes.push_back(Button(this->_ecsManager.get(), start_pos, 260, this->_box).getIdSprite());
    else
        this->_idBoxes.push_back(Button(this->_ecsManager.get(), start_pos, 260, this->_box, CLICKABLE_ACTION_CHOOSE_MCG, this, &_SoundMcg).getIdSprite());
    if ((*characterChoosen).size() == 1 && (*characterChoosen)[0] == SPROUT)
        this->_idBoxes.push_back(Button(this->_ecsManager.get(), start_pos + (420*1), 260, this->_box).getIdSprite());
    else
        this->_idBoxes.push_back(Button(this->_ecsManager.get(), start_pos + (420*1), 260, this->_box, CLICKABLE_ACTION_CHOOSE_SPROUT, this, &_SoundSprout).getIdSprite());
    if ((*characterChoosen).size() == 1 && (*characterChoosen)[0] == TRELAWNEY)
        this->_idBoxes.push_back(Button(this->_ecsManager.get(), start_pos + (420*2), 260, this->_box).getIdSprite());
    else
        this->_idBoxes.push_back(Button(this->_ecsManager.get(), start_pos + (420*2), 260, this->_box, CLICKABLE_ACTION_CHOOSE_TRELAWNEY, this, &_SoundTrelawney).getIdSprite());
    if ((*characterChoosen).size() == 1 && (*characterChoosen)[0] == SNAPE)
        this->_idBoxes.push_back(Button(this->_ecsManager.get(), start_pos + (420*3), 260, this->_box).getIdSprite());
    else
        this->_idBoxes.push_back(Button(this->_ecsManager.get(), start_pos + (420*3), 260, this->_box, CLICKABLE_ACTION_CHOOSE_SPANE, this, &_SoundSnape).getIdSprite());
    //mcg
    this->_ecsManager->addComponent(camera, std::make_unique<CameraComponent>(position, target, up, 45.0f, CAMERA_PERSPECTIVE));
    this->_ecsManager->addComponent(character_mcg, std::make_unique<Placable>(-52.0f, -2.0f, 0.0f, rotationAxis, -90.0f, scale));
    Model mgmModel = Raylib_encp.LModel("assets/models/mcg/mcg.iqm");
    mgmModel.transform = Raylib_encp.MatrixRotZ(-0.1);
    this->_ecsManager->addComponent(character_mcg, std::make_unique<DrawableModel>(_textures_mcg, mgmModel, meshOrder_mcg, 2));
    this->_ecsManager->addComponent(character_mcg, std::make_unique<Animable>("assets/models/mcg/mcg.iqm", ANIMATION_TYPE::IDLE));

    //sprout
    this->_ecsManager->addComponent(character_sprout, std::make_unique<Placable>(0.0f, -2.0f, 0.0f, rotationAxis, -90.0f, scale));
    Model sproutModel = Raylib_encp.LModel("assets/models/sprout/sprout.iqm");
    this->_ecsManager->addComponent(character_sprout, std::make_unique<DrawableModel>(_textures_sprout, sproutModel, meshOrder_sprout, 2));
    this->_ecsManager->addComponent(character_sprout, std::make_unique<Animable>("assets/models/sprout/sprout.iqm", ANIMATION_TYPE::IDLE));

    //Trelawney
    this->_ecsManager->addComponent(character_trelawney, std::make_unique<Placable>(59.0f, -2.0f, 0.0f, rotationAxis, -90.0f, scale));
    Model trelawneyModel = Raylib_encp.LModel("assets/models/trelawney/trelawney.iqm");
    trelawneyModel.transform = Raylib_encp.MatrixRotZ(0.2);
    this->_ecsManager->addComponent(character_trelawney, std::make_unique<DrawableModel>(_texturesTre, trelawneyModel, meshOrderTrelawney, 2));
    this->_ecsManager->addComponent(character_trelawney, std::make_unique<Animable>("assets/models/trelawney/trelawney.iqm", ANIMATION_TYPE::IDLE));

    //Snape
    this->_ecsManager->addComponent(character_snape, std::make_unique<Placable>(126.0f, -2.0f, 0.0f, rotationAxis, -90.0f, scale));
    Model snapeModel = Raylib_encp.LModel("assets/models/snape/snape.iqm");
    snapeModel.transform = Raylib_encp.MatrixRotZ(0.6);
    this->_ecsManager->addComponent(character_snape, std::make_unique<DrawableModel>(_textures_snape, snapeModel, meshOrderSnape, 2));
    this->_ecsManager->addComponent(character_snape, std::make_unique<Animable>("assets/models/snape/snape.iqm", ANIMATION_TYPE::IDLE));

    models.push_back(mgmModel);
    models.push_back(trelawneyModel);
    models.push_back(snapeModel);
    models.push_back(sproutModel);
    //button play
    Button(this->_ecsManager.get(), "confirm", 724, 900, this->_btn_font, this->_btn_textures, SCENE_GAME, CLICKABLE_ACTION_CHANGE_ECS, this);

    this->_ecsManager->addComponent(music_id, std::make_unique<Musicable>(this->_music));
    // System to add
    this->_ecsManager->addSystem(std::make_unique<Draw>(Draw()));
    this->_ecsManager->addSystem(std::make_unique<MouseClick>(MouseClick()));
    this->_ecsManager->addSystem(std::make_unique<MouseHover>(MouseHover()));
    this->_ecsManager->addSystem(std::make_unique<Music_sys>(Music_sys()));
    this->_ecsManager->addSystem(std::make_unique<Animation>());
    this->_ecsManager->addSystem(std::make_unique<SoundSystem>(SoundSystem()));
}

CharacterSelector::~CharacterSelector()
{
}

std::vector<Model> CharacterSelector::getModels()
{
    return this->models;
}

void CharacterSelector::Unload()
{
    std::cout << "Unload Character Selector Scene Texture" << std::endl;
    Raylib::Raylib_encap RaylibEncap;
    
    RaylibEncap.UnlTexture(this->_background_texture);
    RaylibEncap.UnlTexture(this->_title_texture);
    RaylibEncap.UnlTexture(this->_box_texture);
    for (auto &i : this->_box)
        RaylibEncap.UnlTexture(i);
    for (auto &i : this->_btn_textures)
        RaylibEncap.UnlTexture(i);
    RaylibEncap.UnlSound(this->mcgSound);
    RaylibEncap.UnlSound(this->sproutSound);
    RaylibEncap.UnlSound(this->trelawneySound);
    RaylibEncap.UnlSound(this->snapeSound);
    RaylibEncap.UnloadMStream(this->_music);
}

void CharacterSelector::resetBoxClicked()
{
    DrawableSprite *sprite;
    for (auto &i : this->_idBoxes){
        sprite = static_cast<DrawableSprite *>(this->_ecsManager.get()->getEntity(i)->getComponentsByType(DRAWABLE));
        if (sprite->isSelected())
            sprite->setTexture(this->_box[1]);
        sprite->setSelected(false);
    }
}

void CharacterSelector::resetCharacterChoosen()
{
    if (this->getCharChoosen() != nullptr && this->getCharChoosen()->size() != 0)
        this->getCharChoosen()->pop_back();
}

float CharacterSelector::getMusicTimePlayed()
{
    Raylib::Raylib_encap Raylib_encp;
    return Raylib_encp.GetMTimePlayed(this->_music);
}

void CharacterSelector::SetMusicTimePlayed(float dur)
{
    Raylib::Raylib_encap Raylib_encp;
    Raylib_encp.SeekMStream(this->_music, dur);
}

std::vector<CHARACTER_CHOOSEN> *CharacterSelector::getCharChoosen()
{
    return this->_characterChoosen;
}

void CharacterSelector::addCharacterChoosen(CHARACTER_CHOOSEN charChoosen)
{
    this->_characterChoosen->push_back(charChoosen);
}