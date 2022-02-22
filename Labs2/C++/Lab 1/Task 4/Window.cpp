#include "Window.h"


Window::Window(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	dialog = new QWidget();
	form_ui.setupUi(dialog);
	dialog->setWindowTitle("Error!");
	dialog->hide();
	ui.plainTextEdit->setReadOnly(true);
	ui.comboBox->addItem("Any");

	connect(ui.comboBox, &QComboBox::currentTextChanged, this, &Window::comboBoxChanges);
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
	class_size = 0;
	for (int i = 0; !file.eof(); i++, class_size++)
	{
		main_abitur = AddMemory(main_abitur, i);
		file >> main_abitur[i];
		if (ui.comboBox->findText(QString::fromStdString(main_abitur[i].specialization)) == -1)
		{
			ui.comboBox->addItem(QString(QString::fromStdString(main_abitur[i].specialization)));
		}
		
	}
	printInfo();

}

void Window::on_pushButtonAddFromFile_clicked()
{
	QString filename = QFileDialog::getOpenFileName(this, tr("Open"), "C:/Users/AleXandR/Documents/BSUIR/Labs2/C++/Lab 1/Task 4",
		tr("Text Files (*.txt)"));
	std::ifstream fileAdd(filename.toStdString());
	for (; !fileAdd.eof(); class_size++)
	{
		main_abitur = AddMemory(main_abitur, class_size);
		fileAdd >> main_abitur[class_size];
		if (ui.comboBox->findText(QString::fromStdString(main_abitur[class_size].specialization)) == -1)
		{
			ui.comboBox->addItem(QString(QString::fromStdString(main_abitur[class_size].specialization)));
		}
	}
	ui.plainTextEdit->clear();
	printInfo();
}


void Window::on_pushButtonAdd_clicked()
{
	if (ui.lineEdit->text() == "\0" || ui.lineEdit_2->text() == "\0" ||
		ui.lineEdit_3->text() == "\0" || ui.lineEdit_4->text() == "\0" ||
		ui.lineEdit_5->text() == "\0" || ui.lineEdit_6->text() == "\0")
	{
		dialog->show();
	}
	else
	{
		main_abitur = AddMemory(main_abitur, class_size);
		main_abitur[class_size].name = ui.lineEdit->text().toStdString();
		ui.lineEdit->clear();
		main_abitur[class_size].specialization = ui.lineEdit_2->text().toStdString();
		ui.lineEdit_2->clear();
		if (ui.comboBox->findText(QString::fromStdString(main_abitur[class_size].specialization)) == -1)
		{
			ui.comboBox->addItem(QString(QString::fromStdString(main_abitur[class_size].specialization)));
		}
		main_abitur[class_size].avg_mark = ui.lineEdit_3->text().toDouble();
		ui.lineEdit_3->clear();
		main_abitur[class_size].math = ui.lineEdit_4->text().toInt();
		ui.lineEdit_4->clear();
		main_abitur[class_size].physics = ui.lineEdit_5->text().toInt();
		ui.lineEdit_5->clear();
		main_abitur[class_size].russian = ui.lineEdit_6->text().toInt();
		ui.lineEdit_6->clear();
		class_size++;
	}
}


void Window::comboBoxChanges()
{
	ui.plainTextEdit->clear();
	if (ui.comboBox->currentText() == "Any")
	{
		printInfo();
		return;
	}
	for (int i = 0; i < class_size; i++)
	{
		if (ui.comboBox->currentText() == QString::fromStdString(main_abitur[i].specialization))
		{
			ui.plainTextEdit->appendPlainText(QString("#%1 ").arg(i + 1));
			ui.plainTextEdit->insertPlainText(QString::fromStdString(main_abitur[i].name));
			int sum_rate = main_abitur[i].avg_mark * 10 + main_abitur[i].math + main_abitur[i].physics + main_abitur[i].russian;
			ui.plainTextEdit->appendPlainText(QString("Total score: %1").arg(sum_rate));
			//ui.plainTextEdit->appendPlainText(QString("Average mark: %1").arg(main_abitur[i].avg_mark));
			//ui.plainTextEdit->appendPlainText(QString("Math: %1").arg(main_abitur[i].math));
			//ui.plainTextEdit->appendPlainText(QString("Physics: %1").arg(main_abitur[i].physics));
			//ui.plainTextEdit->appendPlainText(QString("Russian: %1").arg(main_abitur[i].russian));
			ui.plainTextEdit->appendPlainText("==================================================");
		}
	}
}


void Window::printInfo()
{
	for (int i = 0; i < class_size; i++)
	{
		ui.plainTextEdit->appendPlainText(QString("#%1 ").arg(i + 1));
		ui.plainTextEdit->insertPlainText(QString::fromStdString(main_abitur[i].name));
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