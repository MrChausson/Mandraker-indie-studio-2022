/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** MouseClick
*/

#include <iostream>
#include "raylib.hpp"
#include "MouseClick.hpp"
#include "../../Components/Clickable/Clickable.hpp"
#include "../../../Engine/Engine.hpp"
#include "../../../Scene/Game/Game.hpp"
#include "../../../Scene/Menu/Menu.hpp"
#include "../../../Scene/Settings/Settings.hpp"
#include "../../../Scene/GameSettings/GameSettings.hpp"
#include "../../../Scene/CharacterSelector/CharacterSelector.hpp"
#include "../../../Scene/CharacterSelector/NbPlayer.hpp"
#include "../../../Engine/Save/Save.hpp"

MouseClick::MouseClick()
{
}

MouseClick::~MouseClick()
{
}


SYSTEM_TYPES MouseClick::getType()
{
    return (MOUSE_CLICK);
}

void MouseClick::clickAction(ClickableActionType actionType, IComponent *component, IComponent *component2)
{
    Clickable *click = static_cast<Clickable *>(component);
    DrawableSprite *sprite = static_cast<DrawableSprite *>(component2);
    DrawableText *text;
    Entity *entity;
    ECSManager *ecs = click->getEcsToChangeTo();
    Scene *scene = click->getScene();
    std::vector<Model> models;
    CHARACTER_CHOOSEN character = CHARACTER_CHOOSEN::NO_CHARACTER;
    CharacterSelector *characterSelector;
    Settings *settings;
    std::vector<std::unique_ptr<Entity>> entities_load;
    std::vector<Entity *> entities;
    Menu *menu;
    Save *save;
    Game *game;
    NbPlayer *nbPlayer;
    Raylib::Raylib_encap r;

    switch (actionType)
    {
    case CLICKABLE_ACTION_CHANGE_ECS:
        if (click->_tmpEcs == SCENE_GAME && this->_characterChoosen != NO_CHARACTER) {
            if (scene == nullptr)
                throw std::runtime_error("Scene is null");
            if (click->_sound != nullptr)
                r.PlayS(*click->_sound);
            characterSelector = static_cast<CharacterSelector *>(scene);
            if (characterSelector->nb_characters == 2) {
                std::cout << "ici" << std::endl;
                int dur = 0;
                characterSelector = static_cast<CharacterSelector *>(scene);
                dur = characterSelector->getMusicTimePlayed();
                characterSelector = new CharacterSelector(characterSelector->nb_characters - 1);
                characterSelector->SetMusicTimePlayed(dur);
                click->setEcs(characterSelector->getECS());
            }
            else {
                Game *game = new Game(characterSelector->getModels(), this->_characterChoosen);
                click->setEcs(game->getECS());
            }
        } else if (click->_tmpEcs == SCENE_MENU) {
            if (click->_sound != nullptr)
                r.PlayS(*click->_sound);
            Menu *menu = new Menu();
            click->setEcs(menu->getECS());
            if (scene != nullptr)
                delete (static_cast<Settings *>(scene));
        } else if (click->_tmpEcs == SCENE_SETTINGS) {
            if (click->_sound != nullptr)
                r.PlayS(*click->_sound);
            menu = static_cast<Menu *>(scene);
            int dur = menu->getMusicTimePlayed();
            Settings *settings = new Settings();
            settings->SetMusicTimePlayed(dur);
            click->setEcs(settings->getECS());
            if (scene != nullptr)
                scene->Unload();
        }
        else if (click->_tmpEcs == SCENE_CHARACTER_SELECTOR) {
            int dur = 0;
            if (click->_sound != nullptr)
                r.PlayS(*click->_sound);
            if (scene->_type == SCENE_PLAYERS_SELECTOR) {
                nbPlayer = static_cast<NbPlayer *>(scene);
                dur = nbPlayer->getMusicTimePlayed();
                characterSelector = new CharacterSelector(nbPlayer->nb_characters);
            }
            else {
                characterSelector = static_cast<CharacterSelector *>(scene);
                dur = characterSelector->getMusicTimePlayed();
                characterSelector = new CharacterSelector(characterSelector->nb_characters);
            }
            characterSelector->SetMusicTimePlayed(dur);
            click->setEcs(characterSelector->getECS());
            if (scene != nullptr)
                scene->Unload();
        }
        else if (click->_tmpEcs == SCENE_PLAYERS_SELECTOR) {
            if (click->_sound != nullptr)
                r.PlayS(*click->_sound);
            NbPlayer *nbPlayer = new NbPlayer();
            click->setEcs(nbPlayer->getECS());
            if (scene != nullptr)
                scene->Unload();
        }
    break;
    case CLICKABLE_ACTION_QUIT_GAME:
        std::cout << "Goodbye!" << std::endl;
        if (click->_sound != nullptr)
            r.PlayS(*click->_sound);
        loop_status = false;
        if (scene != nullptr)
            scene->Unload();
    break;
    case CLICKABLE_ACTION_CHOOSE_SPANE:
        if (click->_sound != nullptr && !sprite->isSelected())
            r.PlayS(*click->_sound);
        this->_characterChoosen = SNAPE;
        characterSelector = static_cast<CharacterSelector *>(scene);
        if (!sprite->isSelected())
            characterSelector->resetBoxClicked();
        sprite->setSelected(!sprite->isSelected());
    break;
    case CLICKABLE_ACTION_CHOOSE_MCG:
        if (click->_sound != nullptr && !sprite->isSelected())
            r.PlayS(*click->_sound);
        this->_characterChoosen = MCG;
        characterSelector = static_cast<CharacterSelector *>(scene);
        if (!sprite->isSelected())
            characterSelector->resetBoxClicked();
        sprite->setSelected(!sprite->isSelected());
    break;
    case CLICKABLE_ACTION_CHOOSE_SPROUT:
        if (click->_sound != nullptr && !sprite->isSelected())
            r.PlayS(*click->_sound);
        this->_characterChoosen = SPROUT;
        characterSelector = static_cast<CharacterSelector *>(scene);
        if (!sprite->isSelected())
            characterSelector->resetBoxClicked();
        sprite->setSelected(!sprite->isSelected());
    break;
    case CLICKABLE_ACTION_CHOOSE_TRELAWNEY:
        if (click->_sound != nullptr)
            r.PlayS(*click->_sound);
        this->_characterChoosen = TRELAWNEY;
        characterSelector = static_cast<CharacterSelector *>(scene);
        if (!sprite->isSelected())
            characterSelector->resetBoxClicked();
        sprite->setSelected(!sprite->isSelected());
    break;
    case CLICKABLE_ACTION_MINUS_MUSIC:
        if (click->_sound != nullptr && musicVolume > 0) {
            int mvolume = 0;
            settings = static_cast<Settings *>(scene);
            entity = settings->getECS()->getEntity(7);
            text = static_cast<DrawableText *>(entity->getComponentsByType(DRAWABLE));
            r.PlayS(*click->_sound);
            musicVolume -= 0.1;
            mvolume = round(musicVolume * 100);
            text->setText(std::to_string(mvolume));
        }
    break;
    case CLICKABLE_ACTION_PLUS_MUSIC:
        if (click->_sound != nullptr && musicVolume < 1) {
            int mvolume = 0;
            settings = static_cast<Settings *>(scene);
            entity = settings->getECS()->getEntity(7);
            text = static_cast<DrawableText *>(entity->getComponentsByType(DRAWABLE));
            r.PlayS(*click->_sound);
            musicVolume += 0.1;
            mvolume = round(musicVolume * 100);
            text->setText(std::to_string(mvolume));
        }
    break;
    case CLICKABLE_ACTION_MINUS_SOUND:
    if (click->_sound != nullptr && soundVolume > 0) {
            int svolume = 0;
            settings = static_cast<Settings *>(scene);
            entity = settings->getECS()->getEntity(11);
            text = static_cast<DrawableText *>(entity->getComponentsByType(DRAWABLE));
            r.PlayS(*click->_sound);
            soundVolume -= 0.1;
            svolume = round(soundVolume * 100);
            text->setText(std::to_string(svolume));
        } 
    break;
    case CLICKABLE_ACTION_PLUS_SOUND:
        if (click->_sound != nullptr && soundVolume < 1) {
            int svolume = 0;
            settings = static_cast<Settings *>(scene);
            entity = settings->getECS()->getEntity(11);
            text = static_cast<DrawableText *>(entity->getComponentsByType(DRAWABLE));
            r.PlayS(*click->_sound);
            soundVolume += 0.1;
            svolume = round(soundVolume * 100);
            text->setText(std::to_string(svolume));
        }
    break;
    case CLICKABLE_ACTION_MINUS_FPS:
        if (click->_sound != nullptr && max_fps > 30) {
            settings = static_cast<Settings *>(scene);
            entity = settings->getECS()->getEntity(15);
            text = static_cast<DrawableText *>(entity->getComponentsByType(DRAWABLE));
            r.PlayS(*click->_sound);
            max_fps -= 30;
            r.SetTargFPS(max_fps);
            text->setText(std::to_string(max_fps));
        }
    break;
    case CLICKABLE_ACTION_PLUS_FPS:
        if (click->_sound != nullptr && max_fps < 210) {
            settings = static_cast<Settings *>(scene);
            entity = settings->getECS()->getEntity(15);
            text = static_cast<DrawableText *>(entity->getComponentsByType(DRAWABLE));
            r.PlayS(*click->_sound);
            max_fps += 30;
            r.SetTargFPS(max_fps);
            text->setText(std::to_string(max_fps));
        }
    break;
    case CLICKABLE_ACTION_MINUS_PLAYER:
        nbPlayer = static_cast<NbPlayer *>(scene);
        entity = nbPlayer->getECS()->getEntity(5);
        text = static_cast<DrawableText *>(entity->getComponentsByType(DRAWABLE));
        if (click->_sound != nullptr && nbPlayer->nb_characters == 2) {
            r.PlayS(*click->_sound);
            text->setText("1");
            nbPlayer->nb_characters = 1;
        }
    break;
    case CLICKABLE_ACTION_PLUS_PLAYER:
        nbPlayer = static_cast<NbPlayer *>(scene);
        entity = nbPlayer->getECS()->getEntity(5);
        text = static_cast<DrawableText *>(entity->getComponentsByType(DRAWABLE));
        if (click->_sound != nullptr && nbPlayer->nb_characters == 1) {
            r.PlayS(*click->_sound);
            text->setText("2");
            nbPlayer->nb_characters = 2;
        }
    break;
    case CLICKABLE_ACTION_SAVE_AND_QUIT:
        std::cout << "Goodbye!" << std::endl;
        loop_status = false;
        for (auto &entity : *scene->getECS()->getEntities())
            entities.push_back(entity.get());
        save = new Save("game.save");
        save->save(entities);
        delete(save);
        if (scene != nullptr)
            scene->Unload();

    break;
    case CLICKABLE_ACTION_SAVE_AND_MENU:
        menu = new Menu();
        for (auto &entity : *scene->getECS()->getEntities())
            entities.push_back(entity.get());
        save = new Save("game.save");
        save->save(entities);
        delete(save);
        click->setEcs(menu->getECS());
        if (scene != nullptr)
            scene->Unload();
    break;
    case CLICKABLE_ACTION_LOAD_GAME:
        save = new Save("game.save");
        // entities_load = 
        game = new Game(models, character, save->load());
        break;
    case CLICKABLE_ACTION_RETURN_GAME:
        if (scene == nullptr)
           throw std::runtime_error("Scene is null");
        std::cout << "Change scene" << std::endl;
        GameSettings *gameSet = static_cast<GameSettings *>(scene);
        click->setEcs(gameSet->_previousEcs);
        std::cout << "Change scene to game" << std::endl;
        if (scene != nullptr)
            scene->Unload();
    break;
    }
}

void MouseClick::apply(std::vector<IComponent *> component)
{
    // component : [0] = DrawableSprite, [1] = Clickable 
    Raylib::Raylib_encap Raylib_encp;
    Clickable *click = static_cast<Clickable *>(component[1]);
    Vector2 mouse = Raylib_encp.GetMousePos();
    bool pressed = Raylib_encp.IsMouseBDown(MOUSE_LEFT_BUTTON);
    bool released = Raylib_encp.IsMouseBReleased(MOUSE_LEFT_BUTTON);

    //Drawable first, clickable second
    if (click->changedState(mouse, pressed))
        if (pressed) {
            DrawableSprite *draw = static_cast<DrawableSprite *>(component[0]);
            click->_textureSaved = draw->getTexture();
            draw->setTexture(click->getTexture());
        } else if (released && click->getActionType() != CLICKABLE_ACTION_NONE) {
            this->clickAction(click->getActionType(), component[1], component[0]);
        } else {
            DrawableSprite *draw = static_cast<DrawableSprite *>(component[0]);
            draw->setTexture(click->_textureSaved);
        }
}