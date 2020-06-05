#include <TaskManagerEditor.h>
#include <QTTaskWidget.h>
#include <PanelLoader.hpp>

#include <QtWidgets/QApplication>
#include <iostream>

bool parseArguments(int argc, char* argv[])
{
    for (size_t i = 0; i < argc; i++)
    {
        string argument = argv[i];

        if (strcmp(argv[i], "-p") == 0)
        {
            auto loader = ((TaskManager::PanelLoader*)TaskManager::Aplication::instance()->getComponent("PanelLoader"));
            auto err = loader->importPanel(argv[++i]);

            if (!err.itsOk())
            {
                cout << "No se ha podido cargar el archivo que esta pidiendo" << endl;
                return false;
            }
        }

    }

    return true;
}

int main(int argc, char* argv[])
{

    if (!parseArguments(argc, argv))
        return 0;

    QApplication a(argc, argv);

    TaskManagerEditor mainWindow;
    mainWindow.show();



    return a.exec();



}
