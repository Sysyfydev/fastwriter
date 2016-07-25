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

#include "CircleOpen.h"

#include "StateManager.h"
#include "ResourceManager.h"
#include <SFML/Graphics/Texture.hpp>

CircleOpen::CircleOpen(StateManager& stateManager)
    : Transition
      (
           stateManager,
           stateManager
           .getSharedContext()
           .resourceManager
           .getShader(Shaders::ID::Circle)
      )
{
}

void CircleOpen::configure(const sf::Time& duration,
                     const States::ID& next,
                     const sf::Texture& from,
                     const sf::Texture& to)
{
    nextState = next;
    effectDuration = duration;
    shader.setParameter("from", from);
    shader.setParameter("to", to);
    shader.setParameter("progress", progress);
    shader.setParameter("resolution", sf::Vector2f(from.getSize().x, from.getSize().y));
    shader.setParameter("smoothness", 3.f);
    shader.setParameter("opening", true);
    handler.setTexture(from);
}
