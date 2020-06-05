#include "..\headers\StateDto.hpp"

TaskManager::StateDto::~StateDto()
{

   
}

TaskManager::TaskStatus_b TaskManager::StateDto::addTask(TaskDto t)
{
    if (!itsCreated(t.getTitle()))
    {
        tasks.push_back(new TaskDto(t));
        tasks.at(tasks.size() - 1)->setState(this);
        return true;

    }

    return TaskManager::TaskStatus_b("Tarea con el nombre [" + t.getTitle() + "] ya creada", false);
}

TaskManager::TaskStatus_b TaskManager::StateDto::removeTask(string title)
{
    for(int i = 0; i < tasks.size(); i++)
    {
        if (tasks[i]->getTitle() == title)
        {
            tasks.erase(tasks.begin() + i);
            return true;
        }
    }

    return TaskManager::TaskStatus_b("Tarea con el nombre [" + title + "] no encotrada para eliminar", false);
}

TaskManager::TaskDto* TaskManager::StateDto::getTask(string t)
{
    for (auto s : tasks)
    {
        if (s->getTitle() == t)
            return s;
    }
    return nullptr;
}

bool TaskManager::StateDto::itsCreated(string t)
{
    for (auto s : tasks)
    {
        if (s->getTitle() == t)
            return true;
    }
    return false;
}
