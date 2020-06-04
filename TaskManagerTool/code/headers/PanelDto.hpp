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



#ifndef PANELDTO_HEADER
#define PANELDTO_HEADER

#include <vector>
#include <string>
#include "StateDto.hpp"
#include "TaskStatus.hpp"

using namespace std;

namespace TaskManager
{


    class PanelDto
    {


    private:

        std::string title;

        vector<StateDto*> states;

    public:

        PanelDto() = default;

        PanelDto(string t) : title(t)
        {

        }

        inline vector<StateDto*> getStates() { return states; };

        TaskStatus_b addState(StateDto t);

        TaskStatus_b removeState(string title);

        StateDto* getState(string title);

        inline std::string getTitle() { return title; };

        inline void setTitle(std::string t) { title = t; };

    private:

        bool itsCreated(string t);

    };

}
#endif