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
#include <LuaState.h>
#include "Component.hpp"

using namespace std;

namespace TaskManager
{

    class PanelDto;

    class TASKMANAGERAPI PanelManager : public Component
    {

    private:

        int currentPanelId;

        vector<PanelDto*> panels;

    public:

        inline PanelDto* getCurrentPanel() { return (currentPanelId == -1) ? nullptr : panels[currentPanelId]; };

        bool addState(string title);

        bool addTaskToState(string stateTitle, string t, string d, string a);

        bool removeTaskofState(string stateTitle, string t);

        bool changeTaskToState(string stateTile, string t, string toStateTitle);

        bool removeState(string t);

        bool initializeLuaScripting(TaskManager::LuaScripting& scripting) override;

    };

}
#endif