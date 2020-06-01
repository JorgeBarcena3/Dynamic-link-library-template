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

using namespace std;

namespace TaskManager
{

    class PanelDto;

    class StateDto
    {


    private:

        std::string title;

        vector<TaskDto *> task;

        PanelDto * panel;

    public:

        StateDto() = default;

        inline vector<TaskDto*> getTask() { return task; };

        inline void addTask(TaskDto t) { task.push_back(new TaskDto(t)); task.at(task.size() - 1)->setState(this); };

        inline bool removeTask(string title);

        inline void setPanel(PanelDto* p) { panel = p; };

        inline PanelDto* getPanel() { return panel; };

        inline std::string getTitle() { return title; };

        inline void setTitle(std::string t) { title = t; };
        
    };

}
#endif