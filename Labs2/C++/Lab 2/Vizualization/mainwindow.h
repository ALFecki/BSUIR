#pragma once

#include <QtWidgets/QMainWindow>
#include "Unique_vizual.h"
#include "ui_mainwindow.h"
#include "ui_unique_ptr.h"
#include "qlabel.h"
#include "qgraphicsscene.h"

class mainwindow : public QMainWindow
{
	Q_OBJECT

public:
	mainwindow(QWidget* parent = Q_NULLPTR);

private slots:
	void make_u_pointer();

private:


	Ui::mainwindowClass ui;
	Ui::Form_unique ui_unique;
	QWidget* unique_dialog;
	QGraphicsScene* scene;
	QLabel* lbl_obj, lbl_ptr;


};
