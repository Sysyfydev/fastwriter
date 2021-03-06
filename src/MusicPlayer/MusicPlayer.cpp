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

#include "MusicPlayer.h"

#include "ResourceManager.h"

MusicPlayer::MusicPlayer(const ResourceManager& resMngr)
    : resMngr(resMngr)
{
}

void MusicPlayer::play(const Music::ID& theme)
{
    if (!music.openFromFile(resMngr.getMusic(theme)))
    {
        throw std::runtime_error("Failed to load: " + resMngr.getMusic(theme));
    }

    music.setLoop(true);
    music.play();
}

void MusicPlayer::pause(bool pause)
{
    if (pause)
    {
        music.pause();
    }
    else
    {
        music.play();
    }
}

void MusicPlayer::stop()
{
    music.stop();
}

void MusicPlayer::setVolume(float volume)
{
    music.setVolume(volume);
}
