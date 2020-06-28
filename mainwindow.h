#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QColorDialog>
#include <QColor>
#include <QMessageBox>
#include "objload.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_toolButton_3_clicked();

    void on_toolButton_6_clicked();

    void on_quitButton_clicked();

    void on_toolButton_2_clicked();

    void on_checkBox_stateChanged(int arg1);

    void on_toolButton_4_pressed();

    void on_toolButton_5_pressed();

    void on_toolButton_4_released();

    void on_toolButton_5_released();

    void on_verticalSlider_actionTriggered(int action);

    void on_verticalSlider_2_actionTriggered(int action);

    void on_verticalSlider_3_actionTriggered(int action);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
