#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtDebug"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setAutoFillBackground(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_toolButton_2_clicked()
{
    std::string fileName = QFileDialog::getOpenFileName(
                this,
                tr("Open File"),
                "..//OpenglOBJ//obj",
                "Object File (*.obj)"
                ).toStdString();

    objLoad loader(fileName);
//    objLoad loader("..//OpenglOBJ//obj//pen.obj");
    //loader.print();
    ui->widget16->grabObj(loader);
}

void MainWindow::on_quitButton_clicked()
{
    close();
}

void MainWindow::on_toolButton_3_clicked()
{
    bool on = ui->widget16->toggleTranslation();
    if (on)
        ui->toolButton_3->setDown(true);
}

void MainWindow::on_toolButton_6_clicked()
{
    QColor color = QColorDialog::getColor();
    ui->widget16->grabColor(color.red(), color.green(), color.blue());
}


void MainWindow::on_checkBox_stateChanged(int arg1)
{
    ui->widget16->toggleCulling();
}

void MainWindow::on_toolButton_4_pressed()
{
    ui->widget16->increaseScale();
}

void MainWindow::on_toolButton_5_pressed()
{
    ui->widget16->decreaseScale();
}

void MainWindow::on_toolButton_4_released()
{
    ui->widget16->setScale();
}

void MainWindow::on_toolButton_5_released()
{
    ui->widget16->setScale();
}

void MainWindow::on_verticalSlider_actionTriggered(int action)
{
    ui->widget16->rotate_x = ui->verticalSlider->value();

    qDebug() << "X:"<<  ui->verticalSlider->value();
    ui->widget16->update();
}

void MainWindow::on_verticalSlider_2_actionTriggered(int action)
{
    ui->widget16->rotate_y=ui->verticalSlider_2->value();

    qDebug() << "Y:" << ui->verticalSlider_2->value();
    ui->widget16->update();
}

void MainWindow::on_verticalSlider_3_actionTriggered(int action)
{
    ui->widget16->rotate_z=ui->verticalSlider_3->value();

    qDebug() << "Z:" << ui->verticalSlider_3->value();
    ui->widget16->update();
}
