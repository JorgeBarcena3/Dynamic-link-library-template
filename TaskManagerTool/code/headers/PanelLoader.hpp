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



#ifndef PANELLOADER_HEADER
#define PANELLOADER_HEADER

#define LUA_COMPAT_APIINTCASTS

#include <string>
#include "Component.hpp"

namespace TaskManager
{

    /**
    * Realiza todas las tareas de importacion de los datos de la herramienta
    */
    class TASKMANAGERAPI PanelLoader : public Component
    {

    public:

        /**
        * Importa los datos de la herramienta desde un XML
        */
        TaskStatus_b importPanelAsXML(std::string path);


        /**
        * Importa los datos de la herramienta desde un fichero binario
        */
        TaskStatus_b importPanel(std::string path);

        /**
        * Funcion que inicializa las acciones que se pueden ejecutar atraves de LUA desde cada componente
        */
        TaskStatus_b initializeLuaScripting(TaskManager::LuaScripting& scripting) override;

    private:

        /**
        * Parsea unos datos de XML al modelo de datos de la herramienta
        */
        TaskStatus_b parseXML(char* data);

    };

}
#endif