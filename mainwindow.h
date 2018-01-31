#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "openscad_interface.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButtonRotate_clicked();

    void on_pushButtonRotateTo_clicked();

    void on_pushButtonTranslate_clicked();

    void on_pushButtonTranslateTo_clicked();

    void on_pushButtonZoom_clicked();

    void on_pushButtonZoomTo_clicked();

    void on_pushButtonAction_clicked();

protected:
    void timerEvent(QTimerEvent *event);

private:
    Ui::MainWindow *ui;
    org::openscad::OpenSCAD* OpenSCAD;
};

#endif // MAINWINDOW_H
