#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    OpenSCAD = new org::openscad::OpenSCAD("org.openscad.OpenSCAD", "/org/openscad/OpenSCAD/Application",
                           QDBusConnection::sessionBus(), this);
    startTimer(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event);
    if (OpenSCAD->isValid())
        ui->label->setText("connected");
    else
        ui->label->setText("disconnected");
}

void MainWindow::on_pushButtonRotate_clicked()
{
    double x=ui->doubleSpinBoxX->value();
    double y=ui->doubleSpinBoxY->value();
    double z=ui->doubleSpinBoxZ->value();

    OpenSCAD->rotate(x,y,z);
}

void MainWindow::on_pushButtonRotateTo_clicked()
{
    double x=ui->doubleSpinBoxX->value();
    double y=ui->doubleSpinBoxY->value();
    double z=ui->doubleSpinBoxZ->value();

    OpenSCAD->rotateTo(x,y,z);
}

void MainWindow::on_pushButtonTranslate_clicked()
{
    double x=ui->doubleSpinBoxX->value();
    double y=ui->doubleSpinBoxY->value();
    double z=ui->doubleSpinBoxZ->value();

    OpenSCAD->translate(x,y,z);
}

void MainWindow::on_pushButtonTranslateTo_clicked()
{
    double x=ui->doubleSpinBoxX->value();
    double y=ui->doubleSpinBoxY->value();
    double z=ui->doubleSpinBoxZ->value();

    OpenSCAD->translateTo(x,y,z);
}

void MainWindow::on_pushButtonZoom_clicked()
{
    double zoom=ui->doubleSpinBoxZoom->value();
    OpenSCAD->zoom(zoom);
}

void MainWindow::on_pushButtonZoomTo_clicked()
{
    double zoom=ui->doubleSpinBoxZoom->value();
    OpenSCAD->zoomTo(zoom);
}
