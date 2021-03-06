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

#ifndef COMPONENT_HEADER
#define COMPONENT_HEADER

#include "Aplication.hpp"
#include "TaskStatus.hpp"


namespace lua
{
    class State;
}

namespace TaskManager
{

    class LuaScripting;

    /**
    * Componente base que tendra la herramienta
    */
    class TASKMANAGERAPI Component
    {

    public:

        /**
        * Funcion que inicializa las acciones que se pueden ejecutar atraves de LUA desde cada componente
        */
        virtual TaskStatus_b initializeLuaScripting(TaskManager::LuaScripting& scripting);

        /**
        * Destructor por defecto
        */
        ~Component() {};

    };
}

#endif