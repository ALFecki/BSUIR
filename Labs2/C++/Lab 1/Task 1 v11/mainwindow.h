#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"
#include <qpainter.h>
#include <qpushbutton.h>
#include <qwidget.h>
#include <qgraphicsitem.h>
#include "House.h"
#include <qthread.h>

class mainwindow : public QMainWindow
{
    Q_OBJECT

public:
    mainwindow(QWidget *parent = Q_NULLPTR);

private slots:
    void open();
    void openWindow();
    void close();
    void closeWindow();
    void open_d();
    void openDoor();
    void close_d();
    void closeDoor();


private:
    QGraphicsScene* scene;
    int position = 250, width_door = 150;
    Window* window;
    Door* door;
    House* house;
    QTimer* timer_w, *timer_c1,* timer_d, *timer_c2;
    Ui::mainwindowClass ui;
};
