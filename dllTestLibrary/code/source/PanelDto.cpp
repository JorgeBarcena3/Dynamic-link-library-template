#include "../headers/PanelDto.hpp"
#include "../headers/StateDto.hpp"

inline bool TaskManager::PanelDto::removeTask(string title)
{
    for (int i = 0; i < states.size(); i++)
    {
        if (states[i]->getTitle() == title)
        {
            states.erase(states.begin() + i);
            return true;
        }
    }

    return false;
}
