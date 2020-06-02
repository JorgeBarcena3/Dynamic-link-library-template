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

    class TaskStatus
    {

    private:

        string error;

        bool succesful;

    public:

        TaskStatus(string e, bool s) : error(e), succesful(s)
        {

        }

        TaskStatus(bool s) : succesful(s), error("")
        {

        }

        inline string getError() { return error; };

        inline bool getSuccesful() { return succesful; };

    };

}
#endif