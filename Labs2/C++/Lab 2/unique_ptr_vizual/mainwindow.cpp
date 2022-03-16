#include "mainwindow.h"

mainwindow::mainwindow(QWidget* parent)
	: QMainWindow(parent)
{
	srand(time(NULL));
	ui.setupUi(this);
	scene = new QGraphicsScene(0, 0, 1000, 615, this);
	ui.graphicsView->setScene(scene);
	ui.pushButton_2->setDisabled(1);
	ui.pushButton_3->setDisabled(1);
}



void mainwindow::on_pushButton_clicked()
{
	ui.pushButton_2->setDisabled(0);
	ui.pushButton_3->setDisabled(0);
	scene->update();
	scene->addItem(rect.get());
	rect->x = rand() % 900;
	rect->y = rand() % 400;

}


void mainwindow::on_pushButton_2_clicked()
{
	ui.pushButton_2->setDisabled(1);
	ui.pushButton_3->setDisabled(1);
	scene->removeItem(rect.get());
	scene->update();
}

void mainwindow::on_pushButton_3_clicked()
{
	ui.pushButton_2->setDisabled(1);
	ui.pushButton_3->setDisabled(1);
	scene->removeItem(rect.get());
	scene->update();
}


//void mainwindow::mousePressEvent(QMouseEvent* event)
//{
//	if (event->button() == Qt::LeftButton)
//	{
//		int x = event->x(), y = event->y();
//		rect = make_unique_ptr<Rectangle>(x, y);
//		
//	}
//	else if (event->button() == Qt::MiddleButton)
//	{
//			if (rect && event->x() >= rect->x 
//				&& event->x() <= rect->x + 100
//				&& event->y() >= rect->y
//				&& event->y() <= rect->y - 50)
//			{
//				rect->x = rand() % 100;
//				rect->y = rand() % 100;
//				
//			}
//	}
//}
