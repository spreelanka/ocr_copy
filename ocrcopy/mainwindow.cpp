#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "screenshotfactory.h"
#include <Qt>
#include <QMouseEvent>
#include <QPoint>




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setAcceptDrops(true);
    QPushButton *takeScreenshotButton = this->findChild<QPushButton *>("takeScreenshotButton");
    takeScreenshotButton->hide();



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_takeScreenshotButton_clicked()
{
///////old stuff that works
////    ScreenshotFactory* scf= new ScreenshotFactory;
////    scf->takeScreenshot();
////    scf->saveScreenshot();
///////old stuff that works
}

void MainWindow::on_takeScreenshotButton_pressed()
{

}


void MainWindow::mousePressEvent(QMouseEvent *event)
 {
//    if (event->button() == Qt::LeftButton ){//&& iconLabel->geometry().contains(event->pos())) {

//        QString actionText;
//        actionText = tr("The text was copied.");
//        statusBar()->showMessage(actionText);
//    }

//    const QString childname;("takeScreenshotButton");
////    childname = this->findChild();
//    this->findChild()
//    QObject *takeScreenshotButton = this->findChild( TAKESCREENSHOTBUTTONNAME);
    QPushButton *takeScreenshotButton = this->findChild<QPushButton *>("takeScreenshotButton");
    takeScreenshotButton->hide();
     if (event->button() == Qt::LeftButton){// && takeScreenshotButton->geometry().contains(event->pos())) {

//         QString actionText((int)(event->pos().x()));

//                 actionText = tr("The text was copied.");

         statusBar()->showMessage(QString().setNum((event->pos()).x()));
         drag_start=event->pos();


//         QDrag *drag = new QDrag(this);
//         QMimeData *mimeData = new QMimeData;

//         mimeData->setText(this->toPlainText());
//         drag->setMimeData(mimeData);
//         drag->setPixmap(iconPixmap);

//         Qt::DropAction dropAction = drag->exec();
     }
 }

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    statusBar()->showMessage(statusBar()->currentMessage() + tr(" , ") + QString().setNum((event->pos()).x()));

    drag_end=event->pos();

    int tmp=0;
    if(drag_start.x()>drag_end.x()){
        tmp=drag_start.x();
        drag_start.setX(drag_end.x());
        drag_end.setX(tmp);
    }
    if(drag_start.y()>drag_end.y()){
        tmp=drag_start.y();
        drag_start.setY(drag_end.y());
        drag_end.setY(tmp);
    }
    QRect sc_coords(drag_start,drag_end);

    ScreenshotFactory* scf= new ScreenshotFactory;
    scf->takeScreenshot(sc_coords);
    scf->saveScreenshot();

}

void MainWindow::on_centralWidget_destroyed()
{

}
