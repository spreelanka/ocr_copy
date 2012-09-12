#include <QtGui/QApplication>
#include <Qt>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowOpacity(0.5);
    w.setWindowState(w.windowState() ^ Qt::WindowFullScreen);
    w.show();

//    QWidget *pTestWidget = new QWidget;
//    pTestWidget->setWindowOpacity(0.5);
//    pTestWidget->setGeometry(100,100,200,200);
//    pTestWidget->show();

    return a.exec();
}
