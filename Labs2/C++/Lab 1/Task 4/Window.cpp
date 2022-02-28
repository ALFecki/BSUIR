#include "Window.h"


Window::Window(QWidget* parent)
	: QMainWindow(parent)
{
	dialog = new QWidget();
	del_dialog = new QWidget();
	warning_dialog = new QWidget();
	ui.setupUi(this);
	warning_ui.setupUi(warning_dialog);
	form_ui.setupUi(dialog);
	del_ui.setupUi(del_dialog);
	del_dialog->hide();
	dialog->setWindowTitle("Error!");
	del_dialog->setWindowTitle("Delete");
	dialog->hide();
	ui.plainTextEdit->setReadOnly(true);
	ui.comboBox->addItem("Any");
	ui.lineEdit_3->setInputMask("0.0");
	ui.lineEdit_4->setInputMask("000");
	ui.lineEdit_5->setInputMask("000");
	ui.lineEdit_6->setInputMask("000");

	connect(ui.comboBox, &QComboBox::currentTextChanged, this, &Window::comboBoxChanges);
	connect(ui.pushButtonDelete, &QPushButton::clicked, del_dialog, &QWidget::show);
	connect(del_ui.pushButton, &QPushButton::clicked, this, &Window::deleteAbitur);
	connect(ui.pushButtonSort, &QPushButton::clicked, this, &Window::sortAbitur);
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

void quick_sort(Abiturients* abitur, int first, int last) 
{
	int f = first, l = last;
	int middle = abitur[(f + l) / 2].total_rate;
	Abiturients temp;
	do {
		while (abitur[f].total_rate > middle) f++;
		while (abitur[l].total_rate < middle) l--;
		if (f <= l) {
			temp.name = abitur[f].name; temp.total_rate = abitur[f].total_rate;  
			abitur[f].name = abitur[l].name; abitur[f].total_rate = abitur[l].total_rate;
			abitur[l].name = temp.name; abitur[l].total_rate = temp.total_rate;
			f++;  l--;
		}
	} while (f < l);
	if (first > l) quick_sort(abitur, first, l);
	if (f > last) quick_sort(abitur, f, last);
}

void Window::sortAbitur()
{
	if (ui.comboBox->currentText() == "Any")
	{
		warning_dialog->show();
		return;
	}
	quick_sort(spec_abitur, 0, spec_size - 1);
	ui.plainTextEdit->clear();
	for (int i = 0; i < spec_size; i++)
	{
		ui.plainTextEdit->appendPlainText(QString("#%1 ").arg(i + 1));
		ui.plainTextEdit->insertPlainText(QString::fromStdString(spec_abitur[i].name));
		ui.plainTextEdit->appendPlainText(QString("Total score: %1").arg(spec_abitur[i].total_rate));
		ui.plainTextEdit->appendPlainText("==================================================");
	}
}



void Window::on_pushButtonOpen_clicked()
{
	filename = QFileDialog::getOpenFileName(this, tr("Open"), "C:/Users/AleXandR/Documents/BSUIR/Labs2/C++/Lab 1/Task 4",
		tr("Text Files (*.txt)"));
	if (filename.isEmpty())
	{
		return;
	}
	std::ifstream file(filename.toStdString());
	class_size = 0;
	for (int i = 0; !file.eof(); i++, class_size++)
	{
		main_abitur = AddMemory(main_abitur, i);
		file >> main_abitur[i];
		del_ui.comboBox->addItem(QString(QString::fromStdString(main_abitur[i].name)));
		if (ui.comboBox->findText(QString::fromStdString(main_abitur[i].specialization)) == -1)
		{
			ui.comboBox->addItem(QString(QString::fromStdString(main_abitur[i].specialization)));
		}
		
	}
	abiturs_from_file = class_size;
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
		del_ui.comboBox->addItem(QString(QString::fromStdString(main_abitur[class_size].name)));
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
		del_ui.comboBox->addItem(ui.lineEdit->text());
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
	ui.plainTextEdit->clear();
	printInfo();
}

void Window::deleteAbitur()
{
	QString name = del_ui.comboBox->currentText();
	for (int i = 0; i < class_size; i++)
	{
		if (name == QString::fromStdString(main_abitur[i].name))
		{
			Abiturients* temp_abitur = new Abiturients[class_size - 1];
			for (int j = 0, k = 0; j < class_size; j++, k++)
			{
				if (j == i)
				{
					j++;
				}
				temp_abitur[k] = main_abitur[j];
			}
			delete[] main_abitur;
			main_abitur = temp_abitur;
			break;
		}
	}
	class_size--;
	del_dialog->close();
	ui.plainTextEdit->update();
}

void Window::on_pushButtonSave_clicked()
{
	QFileDialog file_save;
	file_save.setAcceptMode(QFileDialog::AcceptSave);
	file_save.setFileMode(QFileDialog::AnyFile);
	QString save_name = file_save.getSaveFileName(this, tr("Save your abiturients"), "C:/Users/AleXandR/Documents/BSUIR/Labs2/C++/Lab 1/Task 4",
		tr("Text Files (*.txt)"));
	if (save_name.isEmpty()) return;
	if (filename != save_name)
	{
		filename = save_name;
		std::fstream out_file;
		out_file.open(filename.toStdString(),std::ios::out);
		for (int i = 0; i < class_size; i++)
		{
			out_file << main_abitur[i] << std::endl;
		}
	}
	//else
	//{
	//	std::fstream out_file(save_name.toStdString(),std::ios::app);
	//	out_file.seekp(0, std::ios::end);
	//	for (int i = abiturs_from_file; i < class_size; i++)
	//	{
	//		out_file << std::endl;
	//		out_file << main_abitur[i];
	//	}
	//}
}


void Window::on_pushButtonSearch_clicked()
{
	if (ui.lineEdit_7->text() == "\0")
	{
		dialog->show();
	}
	else
	{
		ui.plainTextEdit->clear();
		std::string name = ui.lineEdit_7->text().toStdString();
		for (int i = 0; i < class_size; i++)
		{
			if (main_abitur[i].name.find(name) != -1)
			{
				ui.plainTextEdit->appendPlainText(QString("#%1 ").arg(i + 1));
				ui.plainTextEdit->insertPlainText(QString::fromStdString(main_abitur[i].name));
				ui.plainTextEdit->appendPlainText(QString::fromStdString(main_abitur[i].specialization));
				ui.plainTextEdit->appendPlainText(QString("Average mark: %1").arg(main_abitur[i].avg_mark));
				ui.plainTextEdit->appendPlainText(QString("Math: %1").arg(main_abitur[i].math));
				ui.plainTextEdit->appendPlainText(QString("Physics: %1").arg(main_abitur[i].physics));
				ui.plainTextEdit->appendPlainText(QString("Russian: %1").arg(main_abitur[i].russian));
				ui.plainTextEdit->appendPlainText("==================================================");
			}

		}
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
	spec_size = 0;
	for (int i = 0; i < class_size; i++)
	{
		if (ui.comboBox->currentText() == QString::fromStdString(main_abitur[i].specialization))
		{
			spec_abitur = AddMemory(spec_abitur, spec_size);
			spec_size++;
			int sum_rate = main_abitur[i].avg_mark * 10 + main_abitur[i].math + main_abitur[i].physics + main_abitur[i].russian;
			spec_abitur[spec_size - 1].name = main_abitur[i].name;
			spec_abitur[spec_size - 1].total_rate = sum_rate;
			ui.plainTextEdit->appendPlainText(QString("#%1 ").arg(spec_size));
			ui.plainTextEdit->insertPlainText(QString::fromStdString(spec_abitur[spec_size - 1].name));
			ui.plainTextEdit->appendPlainText(QString("Total score: %1").arg(spec_abitur[spec_size - 1].total_rate));
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
		ui.plainTextEdit->appendPlainText("==================================================");
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
	}
}