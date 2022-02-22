#include "mainwindow.h"

mainwindow::mainwindow(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	scene = new QGraphicsScene;
	ui.graphicsView->setScene(scene);
	scene->setSceneRect(0, 0, 1280, 720);
	house = new House();
	window = new Window();
	door = new Door();
	timer_w = new QTimer(this);
	timer_c1 = new QTimer(this);
	timer_d = new QTimer(this);
	timer_c2 = new QTimer(this);
	window->setPos(190, 250);
	door->setPos(190, 250);
	house->setPos(190, 250);
	scene->addItem(house);
	scene->addItem(door);
	scene->addItem(window);

	connect(ui.pushButton, &QPushButton::clicked, this, &mainwindow::openWindow);
	connect(ui.pushButton_2, &QPushButton::clicked, this, &mainwindow::closeWindow);
	connect(ui.pushButton_3, &QPushButton::clicked, this, &mainwindow::openDoor);
	connect(ui.pushButton_4, &QPushButton::clicked, this, &mainwindow::closeDoor);
}



void mainwindow::open()
{
	if (position == 100)
	{
		timer_w->stop();
		window->setPos(190, position);
		return;
	}
	window->setPos(190, --position);
}


void mainwindow::openWindow()
{
	connect(timer_w, SIGNAL(timeout()), this, SLOT(open()));
	timer_w->start(1000 / 200);
}


void mainwindow::close()
{
	if (position == 250)
	{
		timer_c1->stop();
		window->setPos(190, position);
		return;
	}
	window->setPos(190, ++position);
}

void mainwindow::closeWindow()
{
	connect(timer_c1, SIGNAL(timeout()), this, SLOT(close()));
	timer_c1->start(1000 / 200);
}

void mainwindow::open_d()
{
	if (door->width == 5)
	{
		door->width = -5;
	}
	door->width -= 1;
	scene->update();
	if (door->width == -150)
	{
		timer_d->stop();
	}
}

void mainwindow::openDoor()
{
	connect(timer_d, SIGNAL(timeout()), this, SLOT(open_d()));
	timer_d->start(1000 / 200);
}

void mainwindow::close_d()
{
	if (door->width == -5)
	{
		door->width = 5;
	}
	door->width += 1;
	scene->update();
	if (door->width == 150)
	{
		timer_c2->stop();
	}
}

void mainwindow::closeDoor()
{
	connect(timer_c2, SIGNAL(timeout()), this, SLOT(close_d()));
	timer_c2->start(1000 / 200);
}