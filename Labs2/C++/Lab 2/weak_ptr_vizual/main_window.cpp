#include "main_window.h"

main_window::main_window(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	scene = new QGraphicsScene(0, 0, 1000, 615, this);
	ui.graphicsView->setScene(scene);
	ui.pushButton_2->setDisabled(1);
	ui.pushButton_3->setDisabled(1);
}


void main_window::on_pushButton_clicked()
{
	ui.pushButton->setDisabled(1);
	QPen pen;
	pen.setWidth(3);
	scene->addLine(180,50, 180, 150, pen);
	scene->addLine(180, 150, 170, 140, pen);
	scene->addLine(180, 150, 190, 140, pen);

	scene->addLine(180, 310, 180,370, pen);
	scene->addLine(180, 370, 190, 360, pen);
	scene->addLine(180, 370, 170, 360, pen);

	scene->addLine(260,450,450 ,450, pen);
	scene->addLine(450, 450, 440, 440, pen);
	scene->addLine(450, 450, 440, 460, pen);

	scene->addLine(475, 395, 250,270, pen);
	scene->addLine(250, 270, 250, 280, pen);
	scene->addLine(250, 270, 260, 265, pen);

	scene->addItem(shared_1.get());
	scene->addItem(shared_2.get());
	scene->addItem(shared_3.get());
	ui.pushButton_2->setDisabled(0);
}


void main_window::on_pushButton_2_clicked()
{
	ui.pushButton_2->setDisabled(1);
	ui.pushButton_3->setDisabled(0);
	QPen pen;
	pen.setWidth(3);
	pen.setColor(Qt::red);
	scene->addLine(475, 395, 250, 270, pen);
	scene->addLine(250, 270, 250, 280, pen);
	scene->addLine(250, 270, 260, 265, pen);
	scene->update();
}

void main_window::on_pushButton_3_clicked()
{
	scene->clear();
	scene->update();
	ui.pushButton_3->setDisabled(1);

}