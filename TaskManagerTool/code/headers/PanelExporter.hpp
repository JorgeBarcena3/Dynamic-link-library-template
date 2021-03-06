// Author: Jorge B�rcena Lumbreras

// � Copyright (C) 2020  Jorge B�rcena Lumbreras

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



#ifndef PANELEXPORTER_HEADER
#define PANELEXPORTER_HEADER

#define LUA_COMPAT_APIINTCASTS

#include <string>
#include "Component.hpp"

namespace TaskManager
{

    /**
    * Realiza todas las tareas de exportacion de los datos de la herramienta
    */
    class TASKMANAGERAPI PanelExporter : public Component
    {

    public:

        /**
        * Exporta los datos actuales a un formato XML
        */
        TaskStatus_b exportDataAsXML(std::string directory);

        /**
        * Exporta los datos actuales a un formato binario con extension .SAV
        */
        TaskStatus_b exportData(std::string directory);

        /**
        * Funcion que inicializa las acciones que se pueden ejecutar atraves de LUA desde cada componente
        */
        TaskStatus_b initializeLuaScripting(TaskManager::LuaScripting& scripting) override;

    private:

        /**
        * Crea el archivo XML a raiz de los datos de la herramienta
        */
        string createXML();

    };

}
#endif