#include "../headers/TaskManagerEditor.h"
#include <QtWidgets/QApplication>


int main(int argc, char *argv[])
{
    

    QApplication a(argc, argv);
    TaskManagerEditor * mainWindow = TaskManagerEditor::getInstance();
    mainWindow->show();
    
    return a.exec();
}
