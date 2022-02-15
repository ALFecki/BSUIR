#include "Dates.h"
#include <iostream>
Date* g_dt = 0;


Dates::Dates(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.tableWidget->setColumnCount(7);
	QStringList lst;
	lst << "Date" << "Next day" << "Previous day" << "Week number" << "Leap" << "Days till birthday" << "Duration";
	ui.tableWidget->setHorizontalHeaderLabels(lst);
	/*QIntValidator* validator = new QIntValidator(0,3,parent);
	ui.lineEdit->setValidator(validator);*/
	ui.lineEdit->setInputMask("9D.BD.000D");
	connect(ui.lineEdit, &QLineEdit::returnPressed, this, &Dates::on_lineEdit);
	connect(ui.pushButton_7, &QPushButton::clicked, ui.lineEdit, &QLineEdit::clear);
}

Date* AddMemory(Date* dt, int num_elements)
{
	if (num_elements == 0)
	{
		dt = new Date[num_elements + 1];
	}
	else
	{
		Date* dt_temp = new Date[num_elements + 1];

		for (int i = 0; i < num_elements; i++)
		{
			dt_temp[i] = dt[i];
		}
		delete[] dt;
		dt = dt_temp;
	}
	return dt;
}

void Dates::on_lineEdit()
{
	int index = ui.comboBox->currentIndex();
	if (ui.comboBox->currentText() == "Empty")
	{
		QTableWidgetItem* it = new QTableWidgetItem(QString("Invalid enter :("));
		ui.tableWidget->setItem(index, 5, it);
		return;
	}
	Date b_day;
	QString birthday = (ui.lineEdit->text());
	b_day.c_day = birthday.left(2).toInt();
	b_day.c_month = birthday.mid(3, 2).toInt();
	b_day.c_year = birthday.right(4).toInt();
	int days_count = g_dt[index].DaysTillBirthday(b_day);
	QTableWidgetItem* it = new QTableWidgetItem(QString("%1").arg(days_count));
	ui.tableWidget->setItem(index, 5, it);
}


void Dates::on_pushButton_clicked() // set new date
{
	std::ifstream file("input.txt");

	for (int i = 1; !file.eof(); i++)
	{
		ui.tableWidget->insertRow(i - 1);
		g_dt = AddMemory(g_dt, i - 1);
		file >> g_dt[i - 1];
		if (!g_dt[i - 1].isValidEnter())
		{
			//QTableWidgetItem* it = new QTableWidgetItem(QString("Invalid enter :("));
			//ui.tableWidget->setItem(i - 1, 0, it);
			ui.comboBox->addItem(QString("Empty"));
			ui.tableWidget->setItem(i - 1, 0, (g_dt[i - 1]).PrintDate());
			continue;
		}
		ui.tableWidget->setItem(i - 1, 0, (g_dt[i - 1]).PrintDate());
		ui.comboBox->addItem(QString("Date %1").arg(i));
	}
}

void Dates::on_pushButton_2_clicked()
{
	int index = ui.comboBox->currentIndex();
	if (ui.comboBox->currentText() == "Empty")
	{
		QTableWidgetItem* it = new QTableWidgetItem(QString("Invalid enter :("));
		ui.tableWidget->setItem(index, 1, it);
		return;
	}
	Date new_day = g_dt[index].NextDay();
	ui.tableWidget->setItem(index, 1, new_day.PrintDate());
}


void Dates::on_pushButton_3_clicked()
{
	int index = ui.comboBox->currentIndex();
	if (ui.comboBox->currentText() == "Empty")
	{
		QTableWidgetItem* it = new QTableWidgetItem(QString("Invalid enter :("));
		ui.tableWidget->setItem(index, 2, it);
		return;
	}
	Date previous_day = g_dt[index].PreviousDay();
	if (previous_day.c_year == 0)
	{
		QTableWidgetItem* it = new QTableWidgetItem(QString("31.12.1 BC :)"));
		ui.tableWidget->setItem(index, 2, it);
		return;
	}
	ui.tableWidget->setItem(index, 2, previous_day.PrintDate());
}

void Dates::on_pushButton_4_clicked()
{
	int index = ui.comboBox->currentIndex();
	if (ui.comboBox->currentText() == "Empty")
	{
		QTableWidgetItem* it = new QTableWidgetItem(QString("Invalid enter :("));
		ui.tableWidget->setItem(index, 3, it);
		return;
	}
	Date temp_date(1, 1, g_dt[index].c_year);
	short week_number = temp_date.WeekNumber(g_dt[index]);
	QTableWidgetItem* it = new QTableWidgetItem(QString("%1 week").arg(week_number));
	ui.tableWidget->setItem(index, 3, it);
}

void Dates::on_pushButton_5_clicked()
{
	int index = ui.comboBox->currentIndex();
	if (ui.comboBox->currentText() == "Empty")
	{
		QTableWidgetItem* it = new QTableWidgetItem(QString("Invalid enter :("));
		ui.tableWidget->setItem(index, 4, it);
		return;
	}
	bool is_leap = g_dt[index].isLeap();
	if (is_leap)
	{
		QTableWidgetItem* it = new QTableWidgetItem(QString("Year is leap"));
		ui.tableWidget->setItem(index, 4, it);
	}
	else
	{
		QTableWidgetItem* it = new QTableWidgetItem(QString("Year isn't leap"));
		ui.tableWidget->setItem(index, 4, it);
	}
}

void Dates::on_pushButton_6_clicked()
{
	int index = ui.comboBox->currentIndex();
	if (ui.comboBox->currentText() == "Empty")
	{
		QTableWidgetItem* it = new QTableWidgetItem(QString("Invalid enter :("));
		ui.tableWidget->setItem(index, 6, it);
		return;
	}
	struct tm* local;
	time_t t;
	t = time(NULL);
	local = localtime(&t);
	int year = local->tm_year + 1900;
	int month = local->tm_mon + 1;
	int day = local->tm_mday;
	Date now_date(local->tm_mday, local->tm_mon + 1, local->tm_year + 1900);
	int days_count = g_dt[index].Duration(now_date);
	QTableWidgetItem* it = new QTableWidgetItem(QString("%1 day(-s)").arg(days_count));
	ui.tableWidget->setItem(index, 6, it);
}