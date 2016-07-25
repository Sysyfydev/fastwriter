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

#include "CountDownControl.h"

CountDownControl::CountDownControl(const sf::Time& start,
                                   const sf::Color& color,
                                   unsigned charSize,
                                   const sf::Vector2f& position,
                                   const sf::Font& font)
    : start(start),
      elapsed(start),
      graph(std::to_string(static_cast<int>(elapsed.asSeconds())), font, charSize)
{
    graph.setPosition(position);
    graph.setColor(color);
}

bool CountDownControl::finished(const sf::Time& dt)
{
    elapsed -= dt;
    bool ret = false;

    if (elapsed <= sf::Time::Zero)
    {
        ret = true;
        elapsed = sf::Time::Zero;
    }

    graph.setString(std::to_string(static_cast<int>(elapsed.asSeconds())));

    return ret;
}

void CountDownControl::reset()
{
    elapsed = start;
    graph.setString(std::to_string(static_cast<int>(elapsed.asSeconds())));
}

const sf::Text& CountDownControl::getGraph() const
{
    return graph;
}
