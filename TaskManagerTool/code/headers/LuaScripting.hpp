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



#ifndef LUASCRIPTING_HEADER
#define LUASCRIPTING_HEADER

#define LUA_COMPAT_APIINTCASTS

#include <string>
#include "Component.hpp"


namespace TaskManager
{

    /**
    * Componente que se encarga de ejecutar el codigo LUA en nuestra aplicacion
    */
    class TASKMANAGERAPI LuaScripting : public Component
    {

    public:

        lua::State * vm; ///< Maquina virtual de LUA

    public:

        /**
        * Constructor por defecto
        */
        LuaScripting();

        /**
        * Ejecuta un fragmmento de codigo de LUA
        */
        TaskManager::TaskStatus_b exec(const std::string& luaCode);

        /**
        * Ejecuta un archivo de LUA
        */
        TaskManager::TaskStatus_b execFile(const std::string& luaFilePath);


    };

}
#endif