#include "mainwindow.h"

mainwindow::mainwindow(QWidget *parent)
    : QMainWindow(parent)
{
    rect_dialog = new QWidget();
    square_dialog = new QWidget();
    rhomb_dialog = new QWidget();
    trian_dialog = new QWidget();
    trap_dialog = new QWidget();
    circle_dialog = new QWidget();
    canva_dialog = new QWidget();
    rect_ui.setupUi(rect_dialog);
    square_ui.setupUi(square_dialog);
    rhomb_ui.setupUi(rhomb_dialog);
    trian_ui.setupUi(trian_dialog);
    trap_ui.setupUi(trap_dialog);
    circle_ui.setupUi(circle_dialog);
    canva_ui.setupUi(canva_dialog);
    square_dialog->hide();
    rect_dialog->hide();
    rhomb_dialog->hide();
    trian_dialog->hide();
    trap_dialog->hide();
    circle_dialog->hide();
    canva_dialog->hide();
    ui.setupUi(this);
    
    trian_ui.lineEdit->setInputMask("0000");
    trian_ui.lineEdit_2->setInputMask("0000");
    trian_ui.lineEdit_3->setInputMask("0000");
    trian_ui.lineEdit_4->setInputMask("0000");
    trian_ui.lineEdit_5->setInputMask("0000");
    trian_ui.lineEdit_6->setInputMask("0000");

    rect_ui.lineEdit->setInputMask("0000");
    rect_ui.lineEdit_2->setInputMask("0000");

    square_ui.lineEdit->setInputMask("0000");

    circle_ui.lineEdit->setInputMask("0000");

    rhomb_ui.lineEdit->setInputMask("0000");
    rhomb_ui.lineEdit_2->setInputMask("0000");
    
    trap_ui.lineEdit->setInputMask("0000");
    trap_ui.lineEdit_2->setInputMask("0000");
    trap_ui.lineEdit_3->setInputMask("0000");
    trap_ui.lineEdit_4->setInputMask("0000");
    
    
    scene = new QGraphicsScene(0, 0, 1280, 720, this);

    ui.graphicsView->setScene(scene);


    connect(ui.pushButtonRectangle_2, &QPushButton::clicked, rect_dialog, &QWidget::show);
    connect(rect_ui.pushButton, &QPushButton::clicked, this, &mainwindow::CreateRect);
    connect(ui.pushButtonSquare_2, &QPushButton::clicked, square_dialog, &QWidget::show);
    connect(square_ui.pushButton, &QPushButton::clicked, this, &mainwindow::CreateSquare);
    connect(ui.pushButtonRhombus_2, &QPushButton::clicked, rhomb_dialog, &QWidget::show);
    connect(rhomb_ui.pushButton, &QPushButton::clicked, this, &mainwindow::CreateRhombus);
    connect(ui.pushButtonTriangle_2, &QPushButton::clicked, trian_dialog, &QWidget::show);
    connect(trian_ui.pushButton, &QPushButton::clicked, this, &mainwindow::CreateTriangle);
    connect(ui.pushButtonTrapezoid_2, &QPushButton::clicked, trap_dialog, &QWidget::show);
    connect(trap_ui.pushButton, &QPushButton::clicked, this, &mainwindow::CreateTrapezoid);
    connect(ui.pushButtonCircle_2, &QPushButton::clicked, circle_dialog, &QWidget::show);
    connect(circle_ui.pushButton, &QPushButton::clicked, this, &mainwindow::CreateCircle);
}

void mainwindow::CreateRect()
{
    int width = rect_ui.lineEdit->text().toInt();
    int height = rect_ui.lineEdit_2->text().toInt();
    Rectangle* rect = new Rectangle(width, height, 0);
    rect->setPos(rand() % 700, rand() % 800);
    rect_dialog->close();
    scene->clear();
    scene->addItem(rect);
    ui.label->setText(rect->infoAboutRect());
}

void mainwindow::CreateSquare()
{
    int width = square_ui.lineEdit->text().toInt();
    Square* square = new Square(width,0);
    square->setPos(rand() % 700, rand() % 800);
    square_dialog->close();
    scene->clear();
    scene->addItem(square);
    ui.label->setText(square->infoAboutRect());
}

void mainwindow::CreateRhombus()
{
    int diagonal_1 = rhomb_ui.lineEdit->text().toInt();
    int diagonal_2 = rhomb_ui.lineEdit_2->text().toInt();
    Rhombus* rhombus = new Rhombus(diagonal_1, diagonal_2);
    rhombus->setPos(rand() % 700, rand() % 800);
    rhomb_dialog->close();
    scene->clear();
    scene->addItem(rhombus);
    ui.label->setText(rhombus->infoAboutRhomb());
}

void mainwindow::CreateTriangle()
{
    
    int x1 = trian_ui.lineEdit->text().toInt();
    int x2 = trian_ui.lineEdit_2->text().toInt();
    int x3 = trian_ui.lineEdit_3->text().toInt();
    
    int y1 = trian_ui.lineEdit_4->text().toInt();
    int y2 = trian_ui.lineEdit_5->text().toInt();
    int y3 = trian_ui.lineEdit_6->text().toInt();

    Triangle* triangle = new Triangle(x1, y1, x2, y2, x3, y3);
    triangle->setPos(rand() % 700, rand() % 800);
    trian_dialog->close();
    scene->clear();
    scene->addItem(triangle);
    ui.label->setText(triangle->infoAboutTriangle());
}

void mainwindow::CreateCircle()
{
    int radius = circle_ui.lineEdit->text().toInt();
    Circle* circle = new Circle(radius);
    circle->setPos(rand() % 700, rand() % 800);
    circle_dialog->close();
    scene->clear();
    scene->addItem(circle);
    ui.label->setText(circle->infoAboutCircle());
}

void mainwindow::on_pushButtonHexagon_2_clicked()
{
    Hexagon* hexag = new Hexagon;
    hexag->setPos(rand() % 700, rand() % 800);
    scene->clear();
    scene->addItem(hexag);
    ui.label->setText(hexag->infoAboutHexagon());
}

void mainwindow::on_pushButtonStar_2_clicked()
{
    Star* star = new Star;
    star->setPos(rand() % 700, rand() % 800);
    scene->clear();
    scene->addItem(star);
}


void mainwindow::CreateTrapezoid()
{
    int x1 = trap_ui.lineEdit->text().toInt();
    int x2 = trap_ui.lineEdit_2->text().toInt();

    int y1 = trap_ui.lineEdit_3->text().toInt();
    int y2 = trap_ui.lineEdit_4->text().toInt();

    Trapezoid* trapezoid = new Trapezoid(x1, y1, x2, y2);
    trapezoid->setPos(rand() % 700, rand() % 800);
    trap_dialog->close();
    scene->clear();
    scene->addItem(trapezoid);
    ui.label->setText(trapezoid->infoAboutTrapezoid());
}

void mainwindow::on_pushButton_clicked()
{
    Canva* canva = new Canva(canva_dialog);
    canva->resize(700, 500);
    canva->setDraw(true);
    
    canva_dialog->show();
}

