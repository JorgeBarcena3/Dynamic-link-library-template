#include <TaskManagerEditor.h>
#include <QTTaskWidget.h>


#include <QtWidgets/QApplication>


int main(int argc, char *argv[])
{
    
    QApplication a(argc, argv);

    TaskManagerEditor mainWindow;
    mainWindow.show();
   
    return a.exec();
}
