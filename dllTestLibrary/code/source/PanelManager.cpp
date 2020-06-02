#include "../headers/PanelManager.hpp"
#include "../headers\PanelDto.hpp"

using namespace TaskManager;

TaskStatus TaskManager::PanelManager::addState(string title)
{
    return panels[currentPanelId]->addState(StateDto(title, panels[currentPanelId]));
}

TaskStatus TaskManager::PanelManager::addTaskToState(string stateTitle, string t, string d, string a)
{
    auto s = panels[currentPanelId]->getState(stateTitle);

    if (s)
    {
        return s->addTask(TaskDto(t, d, a));
    }

    return TaskManager::TaskStatus("Estado con el titlulo [" + stateTitle + "] no encontrado", false);
}

TaskStatus TaskManager::PanelManager::removeTaskofState(string stateTitle, string t)
{
    auto s = panels[currentPanelId]->getState(stateTitle);

    if (s)
    {
        return s->removeTask(t);

    }

    return TaskManager::TaskStatus("Estado con el titlulo [" + stateTitle + "] no encontrado", false);
}

TaskStatus TaskManager::PanelManager::changeTaskToState(string stateTile, string t, string toStateTitle)
{
    auto s = panels[currentPanelId]->getState(stateTile);

    if (s)
    {

        auto task = s->getTask(t);

        if (task)
        {
            s->removeTask(t);
            auto ns = panels[currentPanelId]->getState(toStateTitle);
            ns->addTask(*task);

        }
        else
        {
            return TaskManager::TaskStatus("Tarea con el nombre [" + t + "] en el estado [" + stateTile + "] no econtrado", false);
        }
        return s->removeTask(t);

    }

    return TaskManager::TaskStatus("Estado con el nombre [" + stateTile + "] no econtrado", false);
}

TaskStatus TaskManager::PanelManager::removeTask(string t)
{
    return true;
}

TaskStatus TaskManager::PanelManager::initializeLuaScripting(TaskManager::LuaScripting& scripting)
{
    return true;
}
