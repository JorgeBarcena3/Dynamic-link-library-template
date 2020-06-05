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



#ifndef PANELMANAGER_HEADER
#define PANELMANAGER_HEADER

#define LUA_COMPAT_APIINTCASTS

#include <string>
#include <vector>
#include "Component.hpp"

using namespace std;


namespace TaskManager
{
    class PanelDto;
    class TaskDto;
    class StateDto;

    /**
    * Realiza todas las acciones para manejar el modelo de datos de la aplicacion
    */
    class TASKMANAGERAPI PanelManager : public Component
    {

    private:

        int currentPanelId; ///< Panel sobre el que se esta actuando actualmente

        vector<PanelDto*> * panels; ///< Cantidad de paneles que tiene la aplicacion en ejecucion

    public:

        /**
        * Constructor por defecto 
        */
        PanelManager() : currentPanelId(-1), panels(new vector<PanelDto*>()){ };

        /**
        * Destructor por defecto
        */
        ~PanelManager();

        /**
        * Elimina todos los paneles de la aplicacion
        */
        TaskStatus_b removeAllPanels();

        /**
        * Elimina un panel en concreto
        */
        TaskStatus_b removePanel(string t);

        /**
        * Devuelve el panel que está activo
        */
        inline PanelDto* getCurrentPanel() { return (currentPanelId == -1) ? nullptr : (*panels)[currentPanelId]; }

        /**
        * Añade un estado a la aplicacion
        */
        TaskStatus_b addState(string title);

        /**
        * Añade una tarea a un estado
        */
        TaskStatus_b addTaskToState(string stateTitle, string t, string d, string a, string date = "EMPTY");

        /**
        * Elimina una tarea de un estado
        */
        TaskStatus_b removeTaskofState(string stateTitle, string t);

        /**
        * Cambia una tarea de un estado a otro
        */
        TaskStatus_b changeTaskToState(string stateTile, string t, string toStateTitle);

        /**
        * Elimina un estado
        */
        TaskStatus_b removeTask(string t);

        /**
        * Crea un panel nuevo
        */
        TaskStatus_b createPanel(string t);

        /**
        * Se cambia a un panel dado su nombre
        */
        TaskStatus_b changeToPanel(string t);

        /**
        * Se cambia a un panel dado su indice
        */
        TaskStatus_b changeToPanel(int t);

        /**
        * Cambia el nombre de un estado
        */
        TaskStatus_b changeStatusName(string old, string newName);

        /**
        * Crea un panel nuevo
        */
        void createNewPanel();

        /**
        * Devuelve las tareas de un estado
        */
        TaskStatus<vector<TaskDto* >> getTaskFromState(string t);

        /**
        * Devuelve los estados de un panel
        */
        TaskStatus<vector<StateDto* >> getStatesFromPanel(string t);

        /**
        * Devuelve los estados del panel actual
        */
        TaskStatus<TaskManager::StateDto*> getStatesFromCurrentPanel(string s);

        /**
        * Devuelve todos los paneles de la aplicacion
        */
        TaskStatus<vector<PanelDto* >> getAllPanels();

        /**
        * Funcion que inicializa las acciones que se pueden ejecutar atraves de LUA desde cada componente
        */
        TaskStatus_b initializeLuaScripting(TaskManager::LuaScripting& scripting) override;


    };

}
#endif