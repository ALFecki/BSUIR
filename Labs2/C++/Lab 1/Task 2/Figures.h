#pragma once


#include "ui_Figures.h"
#include "Shape.h"



class Figures : public QMainWindow
{
    Q_OBJECT

public:
    Figures(QWidget *parent = Q_NULLPTR);    

private:
    
    Shape* sh = nullptr;
    QGraphicsScene* scene;
    QTimer* timer;


private slots:
    void on_horizontalSlider();
    
    void on_pushButtonCenter_clicked();
    //void on_pushButtonPerimetr_clicked();
    //void on_pushButtonArea_clicked();
    
    void on_radioButtonTriangle_clicked();
    void on_radioButtonRhombus_clicked();
    void on_radioButtonRectangle_clicked();
    void on_radioButtonSquare_clicked();
    void on_radioButtonCircle_clicked();
    void on_radioButtonHexagon_clicked();


protected:
    Ui::FiguresClass ui;

};