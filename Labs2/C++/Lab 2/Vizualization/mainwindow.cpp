#include "mainwindow.h"

mainwindow::mainwindow(QWidget *parent)
    : QMainWindow(parent)
{
    unique_dialog = new QWidget();
    ui_unique.setupUi(unique_dialog);
    unique_dialog->hide();
    ui.setupUi(this);
    
    scene = new QGraphicsScene(0, 0, 820, 560, this);
    
    ui_unique.graphicsView->setScene(scene);
    ui_unique.label->hide();
    ui_unique.label_2->hide();
    connect(ui.pushButton_unique_ptr, &QPushButton::clicked, unique_dialog, &QWidget::show);
    connect(ui_unique.pushButton_make, &QPushButton::clicked, this, &mainwindow::make_u_pointer);
}


void mainwindow::make_u_pointer()
{
    ui_unique.pushButton_make->hide();
    Unique_vizual* unique = new Unique_vizual();
    scene->addItem(unique);
    ui_unique.label->setText("unique_ptr<Type>");
    ui_unique.label_2->setText("Type object");
    ui_unique.label->show();
    ui_unique.label_2->show();
}


