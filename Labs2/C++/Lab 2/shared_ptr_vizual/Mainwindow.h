#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Mainwindow.h"
#include "qgraphicsscene.h"
#include "qlist.h"
#include "qevent.h"
#include "qpainter.h"
#include "shared_ptr.h"
#include "Circle_.h"
#include <ctime>

class Mainwindow : public QMainWindow
{
    Q_OBJECT

public:
    Mainwindow(QWidget *parent = Q_NULLPTR);

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void comboBox_changed();

private:
    
    int number_of_elements = 0;
    QGraphicsScene* scene;
    QList<My_shared_ptr<Circle>> circle_arr;
    QList<My_shared_ptr<Circle>> circle_arr_copy;
    Ui::MainwindowClass ui;
};
