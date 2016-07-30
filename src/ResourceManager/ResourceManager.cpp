/*************************************************************************
**
** Fastwriter
** Copyright (C) 2016 Sysyfydev (sysyfydev@gmail.com)
**
** This software is provided 'as-is', without any express or implied warranty.
** In no event will the authors be held liable for any damages arising
** from the use of this software.
**
** Permission is granted to anyone to use this software for any purpose,
** including commercial applications, and to alter it and redistribute it freely,
** subject to the following restrictions:
**
** 1. The origin of this software must not be misrepresented;
**    you must not claim that you wrote the original software.
**    If you use this software in a product, an acknowledgment
**    in the product documentation is required.
**
** 2. Altered source versions must be plainly marked as such,
**    and must not be misrepresented as being the original software.
**
** 3. This notice may not be removed or altered from any source distribution.
**
*************************************************************************/

#include "ResourceManager.h"

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Shader.hpp>
#include <SFML/Graphics/Texture.hpp>

ResourceManager::ResourceManager()
{
    dicHolder[Dictionaries::ID::EN_DIC] = "res/dictionaries/en.dic";

    fontHolder.load(Fonts::ID::Default, "res/fonts/saxmono.ttf");

    shaderHolder.load(Shaders::ID::Fade, "res/shaders/fade.frag", sf::Shader::Fragment);
    shaderHolder.load(Shaders::ID::Circle, "res/shaders/circle.frag", sf::Shader::Fragment);

    textureHolder.load(Textures::ID::Background, "res/textures/background.png");
    textureHolder.load(Textures::ID::MainMenu, "res/textures/main-menu.png");
    textureHolder.load(Textures::ID::About, "res/textures/about.png");
    textureHolder.load(Textures::ID::DifftyMenu, "res/textures/difficulty-menu.png");
    textureHolder.load(Textures::ID::Starting, "res/textures/starting.png");
    textureHolder.load(Textures::ID::Paused, "res/textures/paused-menu.png");
    textureHolder.load(Textures::ID::QuitConfirm, "res/textures/quit-confirm-menu.png");
    textureHolder.load(Textures::ID::RestartConfirm, "res/textures/restart-confirm-menu.png");
    textureHolder.load(Textures::ID::Wellcome, "res/textures/wellcome.png");
    textureHolder.load(Textures::ID::Game, "res/textures/game.png");
    textureHolder.load(Textures::ID::Letters, "res/textures/letters.png");

    soundHolder.load(Sounds::ID::MenuOpen, "res/sounds/menu-open.ogg");
    soundHolder.load(Sounds::ID::MenuClose, "res/sounds/menu-close.ogg");
    soundHolder.load(Sounds::ID::TabChange, "res/sounds/tab-change.ogg");
    soundHolder.load(Sounds::ID::LifesIncrement, "res/sounds/life-increment.wav");
    soundHolder.load(Sounds::ID::GameEnd, "res/sounds/game-end.ogg");
    soundHolder.load(Sounds::ID::CountDown, "res/sounds/count-down.ogg");
    soundHolder.load(Sounds::ID::CountDownFinish, "res/sounds/count-down-finish.ogg");
    soundHolder.load(Sounds::ID::ShiftModeStart, "res/sounds/shift-mode-start.wav");
    soundHolder.load(Sounds::ID::ShiftModeFinish, "res/sounds/shift-mode-finish.wav");
    soundHolder.load(Sounds::ID::ShiftModeReady, "res/sounds/shift-mode-ready.wav");
    soundHolder.load(Sounds::ID::CleanerActive, "res/sounds/cleaner-active.ogg");
    soundHolder.load(Sounds::ID::LetterTake, "res/sounds/letter-take.ogg");
    soundHolder.load(Sounds::ID::LetterTrap, "res/sounds/letter-trap.ogg");
    soundHolder.load(Sounds::ID::LetterTakeFail, "res/sounds/letter-take-fail.wav");

    musicHolder[Music::ID::Started] = "res/music/started.ogg";
}

const sf::Texture& ResourceManager::getTexture(const Textures::ID& textureId) const
{
    return textureHolder.get(textureId);
}

const sf::Font& ResourceManager::getFont(const Fonts::ID& fontId) const
{
    return fontHolder.get(fontId);
}

sf::Shader& ResourceManager::getShader(const Shaders::ID& shaderId)
{
    return shaderHolder.get(shaderId);
}

const sf::SoundBuffer& ResourceManager::getSound(const Sounds::ID& soundId) const
{
    return soundHolder.get(soundId);
}

const std::string& ResourceManager::getDictionary(const Dictionaries::ID& dicId) const
{
    return dicHolder.at(dicId);
}

const std::string& ResourceManager::getMusic(const Music::ID& musicId) const
{
    return musicHolder.at(musicId);
}
