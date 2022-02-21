#pragma once
#include "Abiturients.h"
#include <QtWidgets/QMainWindow>
#include <qcombobox.h>
#include "ui_Window.h"
#include <qfiledialog.h>



class Window : public QMainWindow
{
    Q_OBJECT

public:
    Window(QWidget *parent = Q_NULLPTR);
    Abiturients* main_abitur;


private slots:
    void on_pushButtonAdd_clicked();

private:
    void printInfo();
    
    Ui::WindowClass ui;

};



