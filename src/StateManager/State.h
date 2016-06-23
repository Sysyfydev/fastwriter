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

#ifndef STATE_H
#define STATE_H

#include <memory>

////////////////////////////////////////////////////////////
/// \brief Declaraciones fordward
///
////////////////////////////////////////////////////////////
class StateManager;

namespace sf
{
    class Event;
    class Time;
}

////////////////////////////////////////////////////////////
/// \brief Define la interfaz basica para todo tipo de estados/escenas
///
/// State conoce a su administrador de manera que la escena
/// es capaz de cambiar la escena actual por otra distinta.
///
/// Ademas mediante esta relacion la escena puede obtener informacion
/// externa a ella por medio del administrador de escenas.
///
////////////////////////////////////////////////////////////
class State
{
public:
    typedef std::unique_ptr<State> Ptr; ///< Define un puntero inteligente de tipo State

    ////////////////////////////////////////////////////////////
    /// \brief Crea una escena que conoce a su administrador
    /// \param stateManager Referencia hacia el administrador de la escena
    ///
    /// Para crear una escena es obligatorio que la escena conozca
    /// cual sera su administrador. Por lo tanto el parametro es obligatorio.
    ///
    ////////////////////////////////////////////////////////////
    explicit State(StateManager& stateManager);

    ////////////////////////////////////////////////////////////
    /// \brief Actualiza la logica de la escena en base a la entrada del usuario
    /// \param event Evento producido por el usuario
    ///
    ////////////////////////////////////////////////////////////
    virtual void handleInput(const sf::Event& event) = 0;

    ////////////////////////////////////////////////////////////
    /// \brief Actualiza los EG de la escena en base a la logica
    /// \param dt Tiempo transcurrido desde la ultima ejecucion del update
    ///
    /// \note EG: Elementos Graficos
    ///
    ////////////////////////////////////////////////////////////
    virtual void update(const sf::Time& dt) = 0;

    ////////////////////////////////////////////////////////////
    /// \brief Dibuja los elementos graficos en pantalla
    ///
    ////////////////////////////////////////////////////////////
    virtual void draw() = 0;

    ////////////////////////////////////////////////////////////
    /// \brief Destructor virtual por defecto
    ///
    /// Asegura que los destructores de las clases hijas sean
    /// llamados en caso de utilizar polimorfismo al destruir
    /// un objeto padre. Ejemplo:
    ///
    /// \code
    /// State *state = new ChildState;
    /// delete state;
    /// \endcode
    ///
    ////////////////////////////////////////////////////////////
    virtual ~State() = default;

protected:
    ////////////////////////////////////////////////////////////
    /// \brief Obtiene el administrador de la escena
    /// \return Referencia hacia el administrador de la escena
    ///
    /// Es protegido ya que solo las clases hijas y nadie mas
    /// necesita conocer el administrador de la esena.
    ///
    ////////////////////////////////////////////////////////////
    StateManager& getStateManager() const;

private:
    StateManager& mStateManager; ///< Administrador al que pertenece la escena
};

#endif // STATE_H
