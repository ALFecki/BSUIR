#pragma once
#include "Abiturients.h"
#include <QtWidgets/QMainWindow>
#include <qcombobox.h>
#include "ui_Window.h"
#include <qfiledialog.h>
#include "ui_QDialog.h"



class Window : public QMainWindow
{
	Q_OBJECT;

public:
	Window(QWidget* parent = Q_NULLPTR);
	Abiturients* main_abitur;


private slots:
	void on_pushButtonOpen_clicked();
	void on_pushButtonAddFromFile_clicked();
	void on_pushButtonAdd_clicked();
	void comboBoxChanges();

private:
	int class_size;
	void printInfo();

	Ui::WindowClass ui;
	QWidget* dialog;
	Ui::Form form_ui;


};



