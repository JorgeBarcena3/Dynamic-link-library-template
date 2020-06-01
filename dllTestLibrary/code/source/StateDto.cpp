#include "StateDto.hpp"

inline bool TaskManager::StateDto::removeTask(string title)
{
    for(int i = 0; i < task.size(); i++)
    {
        if (task[i]->getTitle() == title)
        {
            task.erase(task.begin() + i);
            return true;
        }
    }

    return false;
}
