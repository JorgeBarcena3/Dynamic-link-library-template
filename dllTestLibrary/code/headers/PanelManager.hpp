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

    class TASKMANAGERAPI PanelManager : public Component
    {

    private:

        int currentPanelId;

        vector<PanelDto*> panels;

    public:

        PanelManager() : currentPanelId(-1) { };

        inline PanelDto* getCurrentPanel() { return (currentPanelId == -1) ? nullptr : panels[currentPanelId]; };

        TaskStatus_b addState(string title);

        TaskStatus_b addTaskToState(string stateTitle, string t, string d, string a);

        TaskStatus_b removeTaskofState(string stateTitle, string t);

        TaskStatus_b changeTaskToState(string stateTile, string t, string toStateTitle);

        TaskStatus_b removeState(string t);

        TaskStatus_b createPanel(string t);

        TaskStatus_b changeToPanel(string t);

        TaskStatus<vector<TaskDto* >> getTaskFromState(string t);

        TaskStatus<vector<StateDto* >> getStatesFromPanel(string t);

        TaskStatus_b initializeLuaScripting(TaskManager::LuaScripting& scripting) override;


    };

}
#endif