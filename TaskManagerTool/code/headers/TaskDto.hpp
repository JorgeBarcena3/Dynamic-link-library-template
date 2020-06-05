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

    class TaskDto
    {


    private:

        unsigned int id; ///< Id de la tarea

        string title;

        string description;

        string assigned;

        time_t  creationDate;

        StateDto* stateDto;

    public:

        TaskDto(string tit, string descp, string assign, time_t creation)
        {
            static int global_id = 0;

            id = global_id++;

            title = tit;
            description = descp;
            assigned = assign;
            creationDate = creation;

        }

        inline unsigned int getId() { return id; };

        inline string getTitle() { return title; };

        inline string getDescription() { return description; };

        inline string getAssigned() { return assigned; };

        inline time_t  getCreationDate() { return creationDate; };

        string getCreationDateString()
        {
            char buff[20];

            tm timeinfo;
            localtime_s(&timeinfo, &creationDate);

            strftime(buff, 20, "%Y-%m-%d %H:%M:%S", &timeinfo);

            return string(buff);
        };

        inline StateDto& getStateDto() { return *stateDto; };

        inline void setState(StateDto* s) { stateDto = s; };

        inline void setTitle(string text) { title = text; }

        inline void setDescription(string text) { description = text; }

        inline void setAssigned(string text) { assigned = text; }

        inline void setDate(time_t  date) { creationDate = date; }

    };

}
#endif