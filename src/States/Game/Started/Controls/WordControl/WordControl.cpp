/*************************************************************************
** Copyright (C) 2016 Sysyfydev <sysyfydev@gmail.com>.
**
** This program is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 2 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program.  If not, see <http://www.gnu.org/licenses/>.
*************************************************************************/

#include "WordControl.h"

#include <random>

WordControl::WordControl(const std::string& dictionaryPath,
                         const sf::FloatRect& dropArea,
                         const sf::Texture& lettersTexture)
    : dropArea(dropArea),
      lettTexture(lettersTexture)
{
    dictionary = std::make_unique<Dictionary>(dictionaryPath);
    wordMap = std::make_unique<WordMap>(dictionary->getWords());
}

void WordControl::reset()
{
    elapsedTime = sf::Time::Zero;
    letters.clear();
}

int WordControl::takeAll()
{
    int takeCount = letters.size();
    letters.clear();
    return takeCount;
}

bool WordControl::take(char letter)
{
    for (auto it = letters.begin(); it != letters.end();)
    {
        if (it->character == letter)
        {
            it = letters.erase(it);
            return true;
        }
        else
        {
            ++it;
        }
    }

    return false;
}

void WordControl::drop(const sf::Time& elapsed, const WordConfig& config)
{
    elapsedTime += elapsed;
    if (elapsedTime > config.dropInterval)
    {
        const std::string& word = getRandWord(config.length);
        float wordVel = config.velocity;

        int wordSize = word.size();
        int wordXpos = rand(dropArea.left, dropArea.width - (wordSize * 43));

        for (int i = 0; i != wordSize; ++i)
        {
            char lettChar = word.at(i);
            sf::IntRect lettRect
            (
                decodeLettChar(lettChar) * 43,
                43 * rand(0, 7),
                43, 43
            );

            sf::Sprite lettSprite(lettTexture, lettRect);
            lettSprite.setPosition(wordXpos + (i * 43), dropArea.top);

            letters.push_back(Letter{lettChar, wordVel, lettSprite});
        }

        elapsedTime = sf::Time::Zero;
    }
}

void WordControl::moveDown(const sf::Time& dt)
{
    for (auto& letter : letters)
    {
        letter.graph.move(0, letter.velocity * dt.asSeconds());
    }
}

int WordControl::trap()
{
    sf::FloatRect trapRect
    (
        dropArea.left, dropArea.top + dropArea.height,
        dropArea.width, 1
    );

    int counter = 0;
    for (auto it = letters.begin(); it != letters.end();)
    {
        if (it->graph.getGlobalBounds().intersects(trapRect))
        {
            it = letters.erase(it);
            counter++;
        }
        else
        {
            ++it;
        }
    }

    return counter;
}

const std::list<WordControl::Letter>& WordControl::getGraph() const
{
    return letters;
}

int WordControl::decodeLettChar(char letter) const
{
    int ret = 0;

    switch (letter)
    {
        case 'a': case 'A': ret = 0; break;
        case 'b': case 'B': ret = 1; break;
        case 'c': case 'C': ret = 2; break;
        case 'd': case 'D': ret = 3; break;
        case 'e': case 'E': ret = 4; break;
        case 'f': case 'F': ret = 5; break;
        case 'g': case 'G': ret = 6; break;
        case 'h': case 'H': ret = 7; break;
        case 'i': case 'I': ret = 8; break;
        case 'j': case 'J': ret = 9; break;
        case 'k': case 'K': ret = 10; break;
        case 'l': case 'L': ret = 11; break;
        case 'm': case 'M': ret = 12; break;
        case 'n': case 'N': ret = 13; break;
        case 'o': case 'O': ret = 14; break;
        case 'p': case 'P': ret = 15; break;
        case 'q': case 'Q': ret = 16; break;
        case 'r': case 'R': ret = 17; break;
        case 's': case 'S': ret = 18; break;
        case 't': case 'T': ret = 19; break;
        case 'u': case 'U': ret = 20; break;
        case 'v': case 'V': ret = 21; break;
        case 'w': case 'W': ret = 22; break;
        case 'x': case 'X': ret = 23; break;
        case 'y': case 'Y': ret = 24; break;
        case 'z': case 'Z': ret = 25; break;
    default:
        throw std::invalid_argument("Invalid character!");
    }

    return ret;
}

const std::string& WordControl::getRandWord(int length) const
{
    const WordMap::WordVector& words = wordMap->getWords(length);

    if (words.empty() && length > 1)
    {
        return getRandWord(length - 1);
    }

    return words.at(rand(0, words.size() - 1));
}

int WordControl::rand(int min, int max) const
{
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> uni(min, max);

    return uni(rng);
}
