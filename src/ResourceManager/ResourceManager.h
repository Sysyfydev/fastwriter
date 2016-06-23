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

#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

////////////////////////////////////////////////////////////
/// \brief Inclusiones internas
///
////////////////////////////////////////////////////////////
#include "ResourceHolder.h"

////////////////////////////////////////////////////////////
/// \brief Declaraciones fordward
///
////////////////////////////////////////////////////////////
namespace sf
{
    class Texture;
    class Font;
}

////////////////////////////////////////////////////////////
/// \brief Contenedor de los recursos necesarios por la aplicacion
///
////////////////////////////////////////////////////////////
class ResourceManager
{
public:

    ////////////////////////////////////////////////////////////
    /// \brief Identificardores de texturas
    ///
    ////////////////////////////////////////////////////////////
    enum class Textures
    {
        Background, ///< Textura de fondo general para el juego
        MainMenu
    };

    ////////////////////////////////////////////////////////////
    /// \brief Identificardores de fuentes
    ///
    ////////////////////////////////////////////////////////////
    enum class Fonts
    {
        Default ///< Id de la fuente por defecto
    };

    ////////////////////////////////////////////////////////////
    /// \brief Carga e inicializa los recursos y los relaciona con un id
    ///
    ////////////////////////////////////////////////////////////
    ResourceManager();

    ////////////////////////////////////////////////////////////
    /// \brief Obtiene una referencia a la textura que concuerde con el id
    /// \param textureId Identificador de la textura
    /// \return Referencia la textura
    ///
    ////////////////////////////////////////////////////////////
    sf::Texture& getTexture(const Textures& textureId);

    ////////////////////////////////////////////////////////////
    /// \brief Obtiene una referencia a la fuente que concuerde con el id
    /// \param textureId Identificador de la fuente
    /// \return Referencia a la fuente
    ///
    ////////////////////////////////////////////////////////////
    sf::Font& getFont(const Fonts& fontId);

private:
    ResourceHolder<Textures, sf::Texture> textureHolder; ///< Contenedor de texturas
    ResourceHolder<Fonts, sf::Font>       fontHolder;    ///< Contenedor de fuentes
};

#endif // RESOURCEMANAGER_H
