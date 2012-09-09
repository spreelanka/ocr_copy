#include "screenshotfactory.h"
#include "screenshot.h"
#include <QPixmap>
#include <QDir>
#include <QFileDialog>
#include <QtGui>
#include <QtGui/QApplication>

ScreenshotFactory::ScreenshotFactory()
{


}

void ScreenshotFactory::takeScreenshot()
{
    originalPixmap = QPixmap::grabWindow(QApplication::desktop()->winId());

}


void ScreenshotFactory::saveScreenshot()
{
    QString format = "png";
     QString initialPath = QDir::currentPath() + QObject::tr("/untitled_screenshot.") + format;

     QString fileName = QObject::tr("/untitled_screenshot.") + format;
     if (!fileName.isEmpty())
         originalPixmap.save(fileName, format.toAscii());

}

