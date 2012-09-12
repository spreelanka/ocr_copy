#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QPoint drag_start;
    QPoint drag_end;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_takeScreenshotButton_clicked();

    void on_takeScreenshotButton_pressed();

    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void on_centralWidget_destroyed();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
