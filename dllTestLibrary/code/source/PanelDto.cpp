#include "../headers/PanelDto.hpp"
#include "../headers/StateDto.hpp"

TaskManager::TaskStatus TaskManager::PanelDto::addState(StateDto t)
{

    if (!itsCreated(t.getTitle()))
    {
        states.push_back(new StateDto(t));
        states.at(states.size() - 1)->setPanel(this);
        return true;

    }

    return TaskManager::TaskStatus("Estado ya creado con el mismo nombre", false);

}

TaskManager::TaskStatus TaskManager::PanelDto::removeTask(string title)
{
    for (int i = 0; i < states.size(); i++)
    {
        if (states[i]->getTitle() == title)
        {
            states.erase(states.begin() + i);
            return true;
        }
    }

    return TaskManager::TaskStatus("Tarea no encontrada", false);;
}

TaskManager::StateDto* TaskManager::PanelDto::getState(string t)
{
    for (auto s : states)
    {
        if (s->getTitle() == t)
            return s;
    }
    return nullptr;
}

bool TaskManager::PanelDto::itsCreated(string t)
{
    for (auto s : states)
    {
        if (s->getTitle() == t)
            return true;
    }
    return false;
}
