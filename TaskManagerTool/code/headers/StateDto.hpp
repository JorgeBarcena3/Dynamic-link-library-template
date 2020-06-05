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



#ifndef STATEDTO_HEADER
#define STATEDTO_HEADER

#include <vector>
#include <string>
#include "TaskDto.hpp"
#include "TaskStatus.hpp"

using namespace std;

namespace TaskManager
{

    class PanelDto;

    /**
    * Guarda los datos de cada estado
    */
    class StateDto
    {


    private:

        std::string title; ///< Titulo del estado

        vector<TaskDto *> tasks; ///< Tareas de cada estado

        PanelDto * panel; ///< Panel al que pertenece

    public:

        /**
        * Constructor por defecto
        */
        StateDto() {}

        /**
        * Destructor por defecto
        */
        ~StateDto();

        /**
        * Constructor que exige dos parametros
        */
        StateDto(string t, PanelDto * p) : title(t), panel(p) { };

        /**
        * Añade una tarea al estado
        */
        TaskStatus_b addTask(TaskDto t);

        /**
        * Elimina una tarea
        */
        TaskStatus_b removeTask(string title);

        /**
        * Devuelve una tarea
        */
        TaskDto * getTask(string t);

        /**
        * Devuelve la totalidad de las tareas
        */
        inline vector<TaskDto*> getTasks() { return tasks; };

        /**
        * Determina al panel que pertence
        */
        inline void setPanel(PanelDto* p) { panel = p; };

        /**
        * Devuelve el panel al que pertence
        */
        inline PanelDto* getPanel() { return panel; };

        /**
        * Devuelve el titulo del estado
        */
        inline std::string getTitle() { return title; };

        /**
        * Determina el titulo 
        */
        inline void setTitle(std::string t) { title = t; };

    private:

        /**
        * Determina si una tarea es creada o no
        */
        bool itsCreated(string t);

        
    };

}
#endif