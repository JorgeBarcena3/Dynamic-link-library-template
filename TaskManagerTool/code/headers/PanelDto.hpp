// Author: Jorge Bárcena Lumbreras

// © Copyright (C) 2020  Jorge Bárcena Lumbreras

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.



#ifndef PANELDTO_HEADER
#define PANELDTO_HEADER

#include <vector>
#include <string>
#include "StateDto.hpp"
#include "TaskStatus.hpp"

using namespace std;

namespace TaskManager
{

    /**
    * Guarda los datos de cada panel
    */
    class PanelDto
    {


    private:

        std::string title; ///< Titulo del panel

        vector<StateDto*> states; ///< Cantidad de estados que tiene

    public:

        /**
        * Constructor por defecto
        */
        PanelDto() {}

        /**
        * Constructor que pide un titulo para el panel
        */
        PanelDto(string t) : title(t) { }

        /**
        * Añade un estado al panel
        */
        TaskStatus_b addState(StateDto t);

        /**
        * Elimina un estado
        */
        TaskStatus_b removeTask(string title);

        /**
        * Devuelve el estado con el mismo titulo
        */
        StateDto* getState(string title);

        /**
        * Devuelve todos los estados
        */
        inline vector<StateDto*> getStates() { return states; }

        /**
        * Devuelve el titulo del panel
        */
        inline std::string getTitle() { return title; }

        /**
        * Determina el titulo del panel
        */
        inline void setTitle(std::string t) { title = t; }

    private:

        /**
        * Determina si un estado ya ha sido creado
        */
        bool itsCreated(string t);

    };

}
#endif