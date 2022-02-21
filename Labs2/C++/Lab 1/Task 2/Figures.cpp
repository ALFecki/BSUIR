#include "Figures.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Rhombus.h"
#include "Circle.h"


Figures::Figures(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    this->setFixedSize(1280, 720);
    scene = new QGraphicsScene();
    timer = new QTimer(this);

    ui.graphicsView->setScene(scene);
    
    scene->setSceneRect(0, 0, 1200, 600);

    connect(ui.horizontalSlider, &QSlider::valueChanged, this, &Figures::on_horizontalSlider);
}

void Figures::on_horizontalSlider()
{
    
}


void Figures::on_pushButtonCenter_clicked()
{
    //sh->area_and_perim();
}

void Figures::on_radioButtonTriangle_clicked()
{
    scene->clear();
    sh = new Triangle;
    sh->setPos(rand() % 1000, rand() % 1000);
    scene->addItem(sh);
    
}


void Figures::on_radioButtonRhombus_clicked()
{
    scene->clear();
    sh = new Rhombus;
    sh->setPos(rand() % 1000, rand() % 1000);
    scene->addItem(sh);

}

void Figures::on_radioButtonRectangle_clicked()
{
    scene->clear();
    //sh = new Rectangle;
    sh->setPos(rand() % 1000, rand() % 1000);
    scene->addItem(sh);
}

void Figures::on_radioButtonSquare_clicked()
{
    scene->clear();
    sh = new Square;
    sh->setPos(rand() % 1000, rand() % 1000);
    scene->addItem(sh);
}

void Figures::on_radioButtonCircle_clicked()
{
    scene->clear();
    sh = new Circle;
    sh->setPos(rand() % 1000, rand() % 1000);
    scene->addItem(sh);
}


void Figures::on_radioButtonHexagon_clicked()
{
    scene->clear();
    sh = new Hexagon;
    sh->setPos(rand() % 1000, rand() % 1000);
    scene->addItem(sh);
}


