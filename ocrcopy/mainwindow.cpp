#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "screenshotfactory.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_takeScreenshotButton_clicked()
{
    ScreenshotFactory* scf= new ScreenshotFactory;
    scf->takeScreenshot();
    scf->saveScreenshot();

}
