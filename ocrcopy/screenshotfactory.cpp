#include "screenshotfactory.h"
#include "screenshot.h"
#include <QPixmap>
#include <QDir>
#include <QFileDialog>
#include <QtGui>
#include <QtGui/QApplication>

#include <tesseract/baseapi.h>
#include <tesseract/globals.h>
#include <leptonica/allheaders.h>


ScreenshotFactory::ScreenshotFactory()
{


}

void ScreenshotFactory::takeScreenshot(QRect r)
{

//    originalPixmap = QPixmap::grabWindow(QApplication::desktop()->winId(),500,500,500,500);
    //ok i shouldn't have to abs() the width/height so i should fix this at the source...but it's late...
    originalPixmap = QPixmap::grabWindow(QApplication::desktop()->winId(),r.topLeft().x(),r.topLeft().y(),abs(r.width()),abs(r.height()));
    this->saveScreenshot();
    QImage img=originalPixmap.toImage();
//    img.


    //TODO: recompile leptonica so that it works with tiffs
    Pix *pix = pixRead("/untitled_screenshot.tif");
//    pixWrite("/untitled_leptonica.bmp", pix ,IFF_BMP);


    //whatever, i'm doing it in here...
    tesseract::TessBaseAPI *myOCR = new tesseract::TessBaseAPI();

//    // [2]
//    printf(“Tesseract-ocr version: %s\n”,
//           myOCR->Version());
//    printf(“Leptonica version: %s\n”,
//           getLeptonicaVersion());

    // [3]
    if(myOCR->Init(NULL,"eng")){
      //errormsg??
      exit(1);
    }

//    // [4]
//    Pix *pix;// = pixRead(“phototest.tif”);
//    pix

    myOCR->SetImage(pix);

//    // [5]
    char* outText = myOCR->GetUTF8Text();
    printf("OCR output:\n\n");
    printf(outText);

    fflush(stdout);
//    // [6]
    myOCR->Clear();
    myOCR->End();
    delete [] outText;
    pixDestroy(&pix);

}



void ScreenshotFactory::saveScreenshot()
{
    QString format = "tif";
     QString initialPath = QDir::currentPath() + QObject::tr("/untitled_screenshot.") + format;

     QString fileName = QObject::tr("/untitled_screenshot.") + format;
     if (!fileName.isEmpty())
         originalPixmap.save(fileName, format.toAscii());

}

