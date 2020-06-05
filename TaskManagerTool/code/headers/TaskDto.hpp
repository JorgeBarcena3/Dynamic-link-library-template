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



#ifndef TASKDTO_HEADER
#define TASKDTO_HEADER

#include <string>
#include <ctime>

using namespace std;

namespace TaskManager
{

    class StateDto;

    /**
    * Guarda los datos de cada tarea
    */
    class TaskDto
    {


    private:

        string title; ///< Titulo de la tarea

        string description; ///< Descripcion de la tarea

        string assigned; ///< Persona que llevará a cargo la tarea

        time_t  creationDate; ///< Fecha de creacion

        StateDto* stateDto; ///< Estado al que pertenece

    public:

        /**
        * Constructor de la tarea
        */
        TaskDto(string tit, string descp, string assign, time_t creation)
        {

            title = tit;
            description = descp;
            assigned = assign;
            creationDate = creation;

        }

        /**
        * Devuelve el titulo de la tarea
        */
        inline string getTitle() { return title; };

        /**
        * Devuelve la descripcion de la tarea
        */
        inline string getDescription() { return description; };

        /**
        * Devuelve el usuario asignado a la tarea
        */
        inline string getAssigned() { return assigned; };

        /**
        * Devuelve la fecha de creacion
        */
        inline time_t  getCreationDate() { return creationDate; };

        /**
        * Devuelve la fecha de creacion formateado
        */
        string getCreationDateString()
        {
            char buff[20];

            tm timeinfo;
            localtime_s(&timeinfo, &creationDate);

            strftime(buff, 20, "%Y-%m-%d %H:%M:%S", &timeinfo);

            return string(buff);
        };

        /**
        * Devuelve el estado de la tarea
        */
        inline StateDto& getStateDto() { return *stateDto; };

        /**
        * Determina el estado de la tarea
        */
        inline void setState(StateDto* s) { stateDto = s; };

        /**
        * Determina el titulo de la tarea
        */
        inline void setTitle(string text) { title = text; }

        /**
        * Determina la descripcion de la tarea
        */
        inline void setDescription(string text) { description = text; }

        /**
        * Determina aquien esta asginado la tarea
        */
        inline void setAssigned(string text) { assigned = text; }

      

    };

}
#endif