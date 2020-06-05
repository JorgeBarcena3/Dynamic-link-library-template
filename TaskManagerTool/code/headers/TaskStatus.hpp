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



#ifndef TASKSTATUS_HEADER
#define TASKSTATUS_HEADER

#include <string>

using namespace std;

namespace TaskManager
{

    /**
    * Clase que devuelve la informacion de la tarea
    */
    template<class T>
    class TaskStatus
    {

    private:

        string error; ///< Error en caso de que lo hubiera

        T* returnObj; ///< Objeto que retorna si todo va OK

    public:

        /**
        * Constructor que exige el error (si lo hay), y el objeto a retornar
        */
        TaskStatus(string e, T* s) : error(e), returnObj(s)
        {

        }

        /**
        * Constructor que exige el objeto a retornar
        */
        TaskStatus(T* s) : returnObj(s), error("")
        {

        }

        /**
        * Devuelve el error
        */
        inline string getError() { return error; };

        /**
        * Devuelve el objeto
        */
        inline T getReturnObj() { return *returnObj; };

        /**
        * Devuelve si la tarea es ok
        */
        inline bool itsOk() { return returnObj != nullptr; };

    };


    /**
    * Especializacion de la clase de TaskStatus
    */
    template <>
    class TaskStatus<bool>
    {
    private:

        string error; ///< Error en caso de que lo hubiera

        bool returnObj; ///< Objeto que retorna si todo va OK

    public:

        /**
        * Constructor que exige el error (si lo hay), y el objeto a retornar
        */
        TaskStatus(string e, bool s) : error(e), returnObj(s)
        {

        }

        /**
        * Constructor que exige el objeto a retornar
        */
        TaskStatus(bool s) : returnObj(s), error("")
        {

        }

        /**
        * Devuelve si la tarea es ok
        */
        inline bool itsOk() { return returnObj; };

        /**
        * Devuelve el error
        */
        inline string getError() { return error; };


    };

    /**
    * Typedef de la especificacion de TaskStatus
    */
    typedef TaskStatus<bool> TaskStatus_b;

   


}
#endif