#include <iostream>
#include "Example.hpp"
#include <Aplication.hpp>
#include <LuaScripting.hpp>
#include <PanelManager.hpp>
#include <TaskStatus.hpp>
#include <TaskDto.hpp>
#include <StateDto.hpp>
#include <PanelExporter.hpp>

using namespace std;
using namespace TaskManager;

void errorOk(TaskStatus_b & err)
{
    if (!err.itsOk())
    {
        throw new std::exception();
    }
}

void showThings(PanelManager& manager)
{
    auto a = manager.getStatesFromPanel("Test");

    for (auto state : a.getReturnObj())
    {
        cout << state->getTitle() << endl;

        for (auto t : manager.getTaskFromState(state->getTitle()).getReturnObj())
        {
            cout << t->getTitle() << " " << t->getDescription() << " " << t->getAssigned() << " " << t->getCreationDate() << endl;
        }

        cout << endl << endl;
    }

}

int main()
{
    Aplication app = Aplication::instance();

    PanelManager * manager = (PanelManager * )app.getComponent("PanelManager");

    TaskStatus_b err(true);

    err = manager->createPanel("Test");
    err = manager->changeToPanel("Test");

    for (size_t i = 0; i < 10; i++)
    {
        string stateName = "State " + to_string( i );
        err = manager->addState(stateName);

        errorOk(err);        

        for (size_t j = 0; j < 5; j++)
        {
            err = manager->addTaskToState(
                stateName, 
                "Tarea " + to_string(i) + to_string(j),
                "Descripcion " + to_string(i) + to_string(j), 
                "Jorge"
            );

            errorOk(err);

        }

    }

    showThings(*manager);

    system("pause");
    system("cls");

    err = manager->changeTaskToState("State 0", "Tarea 02", "State 3");
    errorOk(err);

    showThings(*manager);

    system("pause");
    system("cls");

    PanelExporter* ex = ((PanelExporter*)app.getComponent("PanelExporter"));
    ex->exportData("");

    return 0;
}