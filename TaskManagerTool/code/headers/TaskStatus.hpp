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


    template<class T>
    class TaskStatus
    {

    private:

        string error;

        T* returnObj;

    public:

        TaskStatus(string e, T* s) : error(e), returnObj(s)
        {

        }

        TaskStatus(T* s) : returnObj(s), error("")
        {

        }

        inline string getError() { return error; };

        inline T getReturnObj() { return *returnObj; };

        inline bool itsOk() { return returnObj != nullptr; };

    };


    template <>
    class TaskStatus<bool>
    {
    private:

        string error;

        bool returnObj;

    public:

        TaskStatus(string e, bool s) : error(e), returnObj(s)
        {

        }

        TaskStatus(bool s) : returnObj(s), error("")
        {

        }

        inline bool itsOk() { return returnObj; };

        inline string getError() { return error; };


    };

    typedef TaskStatus<bool> TaskStatus_b;

   


}
#endif