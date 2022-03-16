#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"
#include "qgraphicsscene.h"
#include "qlist.h"
#include "Vector.h"
#include "qevent.h"
#include "qpainter.h"
#include "unique_ptr.h"
#include "Rectangle.h"

class mainwindow : public QMainWindow
{
    Q_OBJECT

public:
    mainwindow(QWidget *parent = Q_NULLPTR);



private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

private:

    My_unique_ptr<Rectangle> rect = make_unique_ptr<Rectangle>(405, 250);
    QGraphicsScene* scene;
    Ui::mainwindowClass ui;
};
