#include "Window.h"


Window::Window(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.plainTextEdit->setReadOnly(true);
	//ui.comboBox->addItem("Any");
}

Abiturients* AddMemory(Abiturients* abitur, int num_elements)
{
	if (num_elements == 0)
	{
		abitur = new Abiturients[num_elements + 1];
	}
	else
	{
		Abiturients* abitur_temp = new Abiturients[num_elements + 1];

		for (int i = 0; i < num_elements; i++)
		{
			abitur_temp[i] = abitur[i];
		}
		delete[] abitur;
		abitur = abitur_temp;
	}
	return abitur;
}


void Window::on_pushButtonOpen_clicked()
{
	QString filename = QFileDialog::getOpenFileName(this, tr("Open"), "C:/Users/AleXandR/Documents/BSUIR/Labs2/C++/Lab 1/Task 4",
		tr("Text Files (*.txt)"));
	std::ifstream file(filename.toStdString());

	for (int i = 0; !file.eof(); i++)
	{
		main_abitur = AddMemory(main_abitur, i);
		file >> main_abitur[i];
		if (ui.comboBox->findText(QString::fromStdString(main_abitur[i].specialization)) == -1)
		{
			ui.comboBox->addItem(QString(QString::fromStdString(main_abitur[i].specialization)));
		}
		*class_size = i;
	}
	printInfo();

}

void Window::on_pushButtonAdd_clicked()
{
	QString filename = QFileDialog::getOpenFileName(this, tr("Open"), "C:/Users/AleXandR/Documents/BSUIR/Labs2/C++/Lab 1/Task 4",
		tr("Text Files (*.txt)"));
	std::ifstream fileAdd(filename.toStdString());
	for (; !fileAdd.eof(); (*class_size)++)
	{
		main_abitur = AddMemory(main_abitur, *class_size);
		fileAdd >> main_abitur[*class_size];
		if (ui.comboBox->findText(QString::fromStdString(main_abitur[*class_size].specialization)) == -1)
		{
			ui.comboBox->addItem(QString(QString::fromStdString(main_abitur[*class_size].specialization)));
		}
	}
	ui.plainTextEdit->clear();
	printInfo();
}


void Window::printInfo()
{
	for (int i = 0; i < *class_size; i++)
	{
		ui.plainTextEdit->appendPlainText(QString::fromStdString(main_abitur[i].name));
		ui.plainTextEdit->appendPlainText(QString::fromStdString(main_abitur[i].specialization));
		ui.plainTextEdit->appendPlainText(QString("Average mark: %1").arg(main_abitur[i].avg_mark));
		ui.plainTextEdit->appendPlainText(QString("Math: %1").arg(main_abitur[i].math));
		ui.plainTextEdit->appendPlainText(QString("Physics: %1").arg(main_abitur[i].physics));
		ui.plainTextEdit->appendPlainText(QString("Russian: %1").arg(main_abitur[i].russian));
		//for (int j = 0; j < main_abitur[i].tmp_math.length() / 2 + 1; j++)
		//{
		//	ui.plainTextEdit->insertPlainText(QString(" %1").arg(main_abitur[i].math[j]));
		//}
		//for (int j = 0; j < main_abitur[i].tmp_phys.length() / 2 + 1; j++)
		//{
		//	ui.plainTextEdit->insertPlainText(QString(" %1").arg(main_abitur[i].physics[j]));
		//}
		//for (int j = 0; j < main_abitur[i].tmp_rus.length() / 2 + 1; j++)
		//{
		//	ui.plainTextEdit->insertPlainText(QString(" %1").arg(main_abitur[i].russian[j]));
		//}
		ui.plainTextEdit->appendPlainText("==================================================");
	}
}