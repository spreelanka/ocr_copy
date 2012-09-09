#ifndef SCREENSHOTFACTORY_H
#define SCREENSHOTFACTORY_H

#include "screenshot.h"
#include <QPixmap>


class ScreenshotFactory
{
private:

    QPixmap originalPixmap;
public:
    ScreenshotFactory();
    void takeScreenshot();
    void saveScreenshot();
};

#endif // SCREENSHOTFACTORY_H
