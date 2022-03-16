#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_main_window.h"
#include "qgraphicsscene.h"
#include "weak_ptr.h"
#include "Circle_for_weak.h"

class main_window : public QMainWindow
{
    Q_OBJECT

public:
    main_window(QWidget *parent = Q_NULLPTR);

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

private:

    QGraphicsScene* scene;
    My_shared_ptr<Circle> shared_2 = make_shared_ptr<Circle>(100, 150, 0, 25, 230);
    My_shared_ptr<Circle> shared_1 = make_shared_ptr<Circle>(100, 370, 0, 25, 230);
    My_shared_ptr<Circle> shared_3 = make_shared_ptr<Circle>(450, 370, 0, 25, 230);
    My_weak_ptr<Circle> weak = shared_2;
    Ui::main_windowClass ui;
};
