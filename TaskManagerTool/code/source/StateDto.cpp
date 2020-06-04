#include "..\headers\StateDto.hpp"

TaskManager::TaskStatus_b TaskManager::StateDto::addTask(TaskDto t)
{
    if (!itsCreated(t.getTitle()))
    {
        task.push_back(new TaskDto(t));
        task.at(task.size() - 1)->setState(this);
        return true;

    }

    return TaskManager::TaskStatus_b("Tarea con el nombre [" + t.getTitle() + "] ya creada", false);
}

TaskManager::TaskStatus_b TaskManager::StateDto::removeState(string title)
{
    for(int i = 0; i < task.size(); i++)
    {
        if (task[i]->getTitle() == title)
        {
            task.erase(task.begin() + i);
            return true;
        }
    }

    return TaskManager::TaskStatus_b("Tarea con el nombre [" + title + "] no encotrada para eliminar", false);
}

TaskManager::TaskDto* TaskManager::StateDto::getTask(string t)
{
    for (auto s : task)
    {
        if (s->getTitle() == t)
            return s;
    }
    return nullptr;
}

bool TaskManager::StateDto::itsCreated(string t)
{
    for (auto s : task)
    {
        if (s->getTitle() == t)
            return true;
    }
    return false;
}
