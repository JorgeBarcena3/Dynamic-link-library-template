#include "../headers/TaskManagerEditor.h"
#include <QtWidgets/QApplication>
#include <QTTaskWidget.h>


int main(int argc, char *argv[])
{
    

    QApplication a(argc, argv);

    TaskManagerEditor mainWindow;
    mainWindow.show();
   
    return a.exec();
}
