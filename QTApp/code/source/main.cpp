#include "../headers/TaskManagerEditor.h"
#include <QtWidgets/QApplication>
#include <iostream>
#include <Aplication.hpp>
#include <LuaScripting.hpp>
#include <PanelManager.hpp>
#include <TaskStatus.hpp>
#include <TaskDto.hpp>
#include <StateDto.hpp>
#include <PanelExporter.hpp>
#include <PanelLoader.hpp>

using namespace std;
using namespace TaskManager;


void errorOk(TaskStatus_b& err)
{
    if (!err.itsOk())
    {
        throw new std::exception();
    }
}

void showThings(TaskManager::PanelManager& manager)
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

int main(int argc, char *argv[])
{

    Aplication* aplication_ = Aplication::instance();


    QApplication a(argc, argv);
    TaskManagerEditor w;
    w.show();
    
    return a.exec();
}
