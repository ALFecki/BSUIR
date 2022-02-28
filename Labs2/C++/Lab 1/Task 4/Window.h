#pragma once
#include "Abiturients.h"
#include <QtWidgets/QMainWindow>
#include <qcombobox.h>
#include "ui_Window.h"
#include <qfiledialog.h>
#include "ui_QDialog.h"
#include "ui_Delete_form.h"
#include "ui_Warning.h"



class Window : public QMainWindow
{
	Q_OBJECT;

public:
	Window(QWidget* parent = Q_NULLPTR);
	Abiturients* main_abitur;
	Abiturients* spec_abitur;

private slots:
	void on_pushButtonOpen_clicked();
	void on_pushButtonAddFromFile_clicked();
	void on_pushButtonAdd_clicked();
	void deleteAbitur();
	void comboBoxChanges();
	void sortAbitur();
	void on_pushButtonSave_clicked();
	void on_pushButtonSearch_clicked();

private:
	int class_size, abiturs_from_file;
	int spec_size;
	QString filename;
	void printInfo();

	Ui::WindowClass ui;
	Ui::Form1 del_ui;
	Ui::Warning warning_ui;
	QWidget* dialog,* del_dialog, * warning_dialog;
	Ui::Form form_ui;
};