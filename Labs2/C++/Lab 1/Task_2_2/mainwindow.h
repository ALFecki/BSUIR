#pragma once

#include <QtWidgets/QMainWindow>
#include <qgraphicsscene.h>

#include "Rectangle.h"
#include "Rhombus.h"
#include "Triangle.h"
#include "Canva.h"
#include "Circle.h"
#include "Star.h"

#include "ui_Rect_window.h"
#include "ui_Square.h"
#include "ui_Rhomb_window.h"
#include "ui_Triangle_window.h"
#include "ui_Trap_window.h"
#include "ui_Circle_wndow.h"
#include "ui_Canva.h"
#include "ui_mainwindow.h"

class mainwindow : public QMainWindow
{
    Q_OBJECT

public:
    mainwindow(QWidget *parent = Q_NULLPTR);

private slots:
    
    void CreateRect();
    void CreateSquare();
    void CreateRhombus();
    void CreateTriangle();
    void CreateCircle();
    void on_pushButtonHexagon_2_clicked();
    void on_pushButtonStar_2_clicked();


    void CreateTrapezoid();
    void on_pushButton_clicked();
    //void CreateStar();


private:
    Ui::mainwindowClass ui;
    Ui::Form rect_ui;
    Ui::Form_Square square_ui;
    Ui::Form_Rhomb rhomb_ui;
    Ui::Form_Triangle trian_ui;
    Ui::Form_Trap trap_ui;
    Ui::Form_Canva canva_ui;
    Ui::Form_Circle circle_ui;
    QGraphicsScene* scene;

    QWidget* rect_dialog, * square_dialog, * rhomb_dialog, * trian_dialog, * trap_dialog;
    QWidget* circle_dialog,*canva_dialog;

};
