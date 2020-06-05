
#include "..\headers\LuaScripting.hpp"
#include "LuaState.h"

#include "../headers/PanelManager.hpp"
#include "../headers\PanelDto.hpp"
#include "../headers\StateDto.hpp"

using namespace TaskManager;

TaskStatus_b TaskManager::PanelManager::removeAllPanels()
{
    currentPanelId = 0;

    for (auto panel : panels)
    {
        delete panel;
    }

    panels.clear();

    return true;
}

TaskStatus_b TaskManager::PanelManager::addState(string title)
{
    return panels[currentPanelId]->addState(StateDto(title, panels[currentPanelId]));
}

TaskStatus_b TaskManager::PanelManager::addTaskToState(string stateTitle, string t, string d, string a, string date)
{
    auto s = panels[currentPanelId]->getState(stateTitle);

    if (s)
    {
        return s->addTask(TaskDto(t, d, a, date != "EMPTY" ? time_t(stoi(date)) : time(0)));
    }

    return TaskManager::TaskStatus_b("Estado con el titlulo [" + stateTitle + "] no encontrado", false);
}

TaskStatus_b TaskManager::PanelManager::removeTaskofState(string stateTitle, string t)
{
    auto s = panels[currentPanelId]->getState(stateTitle);

    if (s)
    {
        return s->removeState(t);

    }

    return TaskManager::TaskStatus_b("Estado con el titlulo [" + stateTitle + "] no encontrado", false);
}

TaskStatus_b TaskManager::PanelManager::changeTaskToState(string stateTile, string t, string toStateTitle)
{
    auto s = panels[currentPanelId]->getState(stateTile);

    TaskStatus_b err(false);

    if (s)
    {

        auto task = s->getTask(t);

        if (task)
        {
            err = s->removeState(t);

            if (err.itsOk())
            {
                auto ns = panels[currentPanelId]->getState(toStateTitle);
                return ns->addTask(*task);
            }


        }
        else
        {
            return TaskManager::TaskStatus_b("Tarea con el nombre [" + t + "] en el estado [" + stateTile + "] no econtrado", false);
        }

        return s->removeState(t);

    }

    return TaskManager::TaskStatus_b("Estado con el nombre [" + stateTile + "] no econtrado", false);
}

TaskStatus_b TaskManager::PanelManager::removeState(string t)
{

    return panels[currentPanelId]->removeState(t);

}

TaskStatus_b TaskManager::PanelManager::createPanel(string t)
{
    for (auto p : panels)
    {
        if (p->getTitle() == t)
            return TaskStatus_b("Panel ya creado con el nombre [" + t + "]", false);
    }

    panels.push_back(new PanelDto(t));

    return true;
}

TaskStatus_b TaskManager::PanelManager::changeToPanel(string t)
{
    for (size_t i = 0; i < panels.size(); i++)
    {
        if (panels[i]->getTitle() == t)
        {
            currentPanelId = i;
            return true;
        }
    }

    return TaskStatus_b("No se ha encontrado el panel al que quiere cambiar.", false);
}

void TaskManager::PanelManager::createNewPanel()
{
    string newPanelTitle = "Panel 1";

    createPanel(newPanelTitle);
    currentPanelId = 0;
    addState("New State");
}

TaskStatus_b TaskManager::PanelManager::changeToPanel(int t)
{

    currentPanelId = t;
    return true;
}

TaskStatus_b TaskManager::PanelManager::changeStatusName(string old, string newName)
{
    if (getCurrentPanel()->getState(newName) != nullptr)
    {
        return TaskManager::TaskStatus_b("Ya existe un panel con el siguiente nombre: " + newName, false);
    }

    try
    {
        getCurrentPanel()->getState(old)->setTitle(newName);
        return true;
    }
    catch (exception e)
    {
        return TaskManager::TaskStatus_b("No se ha encontrado un panel con el siguiente nombre: " + old, false);

    }
}


TaskStatus<vector<TaskDto* >>  TaskManager::PanelManager::getTaskFromState(string t)
{
    auto s = panels[currentPanelId]->getState(t);

    if (s)
    {
        return (new vector<TaskDto*>(s->getTasks()));
    }

    return TaskStatus < vector<TaskDto* > >("No se ha encontrado el panel", nullptr);
}

TaskStatus<vector<StateDto* >>  TaskManager::PanelManager::getStatesFromPanel(string t = "")
{
    auto s = panels[currentPanelId];

    if (s)
    {
        return (new vector<StateDto*>(s->getStates()));
    }

    return TaskStatus < vector<StateDto* > >("No se ha encontrado el panel", nullptr);
}

TaskStatus<TaskManager::StateDto*> TaskManager::PanelManager::getStatesFromCurrentPanel(string s)
{
    TaskManager::StateDto* state = getCurrentPanel()->getState(s);

    return TaskStatus<TaskManager::StateDto*>(&state);
}

TaskStatus<vector<PanelDto*>> TaskManager::PanelManager::getAllPanels()
{
    return new vector<PanelDto*>(panels);
}

TaskStatus_b TaskManager::PanelManager::initializeLuaScripting(TaskManager::LuaScripting& scripting)
{
    scripting.vm->set("addState", [this](const char* t) {this->addState(t);  });
    scripting.vm->set("addTaskToState", [this](const char* st, const char* t, const char* d, const char* a) {this->addTaskToState(st, t, d, a);  });
    scripting.vm->set("removeTaskOfState", [this](const char* st, const char* t) {this->removeTaskofState(st, t);  });
    scripting.vm->set("changeTaskToState", [this](const char* st, const char* t, const char* tst) {this->changeTaskToState(st, t, tst);  });
    scripting.vm->set("removeState", [this](const char* t) { this->removeState(t);  });
    scripting.vm->set("createPanel", [this](const char* t) { this->createPanel(t);  });
    scripting.vm->set("changeToPanel", [this](const char* t) { this->changeToPanel(t);  });
    scripting.vm->set("getTaskFromState", [this](const char* t) { this->getTaskFromState(t);  });
    scripting.vm->set("getStatesFromPanel", [this](const char* t) { this->getStatesFromPanel(t);  });
    scripting.vm->set("getAllPanels", [this]() { this->getAllPanels();  });

    return true;
}
