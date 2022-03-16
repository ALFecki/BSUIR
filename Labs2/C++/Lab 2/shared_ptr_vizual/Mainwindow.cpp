#include "Mainwindow.h"

Mainwindow::Mainwindow(QWidget* parent)
	: QMainWindow(parent)
{
	srand(time(NULL));
	ui.setupUi(this);

	ui.pushButton_2->setDisabled(1);
	ui.pushButton_3->setDisabled(1);

	scene = new QGraphicsScene(0, 0, 1000, 615, this);
	ui.graphicsView->setScene(scene);
	connect(ui.comboBox, &QComboBox::currentIndexChanged, this, &Mainwindow::comboBox_changed);
}


void Mainwindow::on_pushButton_clicked()
{
	number_of_elements++;
	if (number_of_elements == 7)
	{
		ui.pushButton->setDisabled(1);
	}
	circle_arr_copy.resize(7);
	circle_arr.resize(number_of_elements);
	circle_arr[number_of_elements - 1] = make_shared_ptr<Circle>(rand() % 900, rand() % 400,
		rand() % 255, rand() % 255, rand() % 255);
	ui.comboBox->addItem(QString("shared_pointer %1").arg(number_of_elements));
	scene->addItem(circle_arr[number_of_elements - 1].get());
	ui.pushButton_2->setDisabled(0);
	ui.pushButton_3->setDisabled(0);
	scene->update();
}

void Mainwindow::on_pushButton_2_clicked()
{
	int i = ui.comboBox->currentIndex();
	
	for (int j = 0; j < 7; j++)
	{
		circle_arr_copy[i] = nullptr;
	}

	My_shared_ptr<Circle> circle = make_shared_ptr<Circle>(circle_arr[i]->x + 50, circle_arr[i]->y,
		circle_arr[i]->red, circle_arr[i]->green, circle_arr[i]->blue);

	circle_arr_copy[i] = circle;
	scene->addItem(circle_arr_copy[i].get());
	//ui.pushButton_2->setDisabled(1);
	scene->update();
}

void Mainwindow::on_pushButton_3_clicked()
{
	int i = ui.comboBox->currentIndex();
	if (circle_arr_copy[i].get() == nullptr)
	{
		scene->removeItem(circle_arr[i].get());
		ui.comboBox->setItemText(i, "Empty");
		circle_arr[i] = nullptr;
		if (ui.comboBox->currentIndex() == -1)
		{
			circle_arr.clear();
			circle_arr_copy.clear();
		}
		ui.pushButton_3->setDisabled(1);
		//ui.pushButton->setDisabled(0);
	}
	else
	{
		scene->removeItem(circle_arr_copy[i].get());
		circle_arr_copy[i] = nullptr;
	}
	scene->update();
}

void Mainwindow::on_pushButton_4_clicked()
{
	scene->clear();
	for (int i = 0; i < number_of_elements; i++)
	{
		ui.comboBox->setItemText(i, "Empty");
		ui.pushButton->setDisabled(1);
		ui.pushButton_2->setDisabled(1);
		ui.pushButton_3->setDisabled(1);
		ui.pushButton_4->setDisabled(1);
	}
	scene->update();
}

void Mainwindow::comboBox_changed()
{
	if (ui.comboBox->currentText() == "Empty")
	{
		ui.pushButton_2->setDisabled(1);
		ui.pushButton_3->setDisabled(1);
		return;
	}
	ui.pushButton_3->setDisabled(0);
	int i = ui.comboBox->currentIndex();
	if (circle_arr_copy[i].get() == nullptr)
	{
		ui.pushButton_2->setDisabled(0);
		ui.pushButton_3->setDisabled(0);
	}
	if (circle_arr[i].get() != nullptr)
	{
	}
	//else
	//{
	//	ui.pushButton_2->setDisabled(0);
	//	ui.pushButton_3->setDisabled(0);
	//}

}