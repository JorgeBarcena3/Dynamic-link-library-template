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

#define TASKMANAGERAPI __declspec(dllexport)


#ifndef APLICATION_HEADER
#define APLICATION_HEADER

#include "Singleton.hpp"
#include <string>

#include <map>

namespace TaskManager
{

    class Component;
    class LuaScripting;

    /**
    * Administrador de toda la aplicacion
    */
    class TASKMANAGERAPI Aplication
    {

    private:

        static Aplication * app; ///< Instancia de la aplicacion

    public:

        static Aplication* instance(); ///< Devuelve la instancia actual de la aplicacion

    private:

        /**
        * Componentes de la aplicacion
        */
        std::map<std::string, TaskManager::Component* >  * aplicationComponents;


    private:

        /**
        * Constructor que solos se puede acceder desde dentro de la clase
        */
        Aplication();


    public:
              

        /**
        * Destructor de la apliacion
        */
        ~Aplication();

        /**
        * Devuelve el componente de scripting de la aplicacion
        */
        LuaScripting& getScripting();

        /**
        * Devuelve un componente en concreto
        */
        TaskManager::Component* getComponent(std::string name);




    };
}

#endif