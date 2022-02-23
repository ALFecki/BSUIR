#include "Dates.h"
#include <iostream>



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
	ui.lineEdit_2->setInputMask("9D.BD.000D");
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
	Date b_day;
	QString birthday = (ui.lineEdit->text());
	b_day.c_day = birthday.left(2).toInt();
	b_day.c_month = birthday.mid(3, 2).toInt();
	b_day.c_year = birthday.right(4).toInt();
	b_day.isValid();
	for (int i = 0; i < date_size; i++)
	{
		int days_count = g_dt[i].DaysTillBirthday(b_day);
		QTableWidgetItem* it = new QTableWidgetItem(QString("%1").arg(days_count));
		ui.tableWidget->setItem(i, 5, it);
	}
}






void Dates::on_pushButton_clicked() // set new date
{

	filename = QFileDialog::getOpenFileName(this, tr("Open your Dates"), "C:/Users/AleXandR/Documents/BSUIR/Labs2/C++/Lab 1/Dates",
		tr("Text File (*.txt)"));
	if (filename.isEmpty())
	{
		return;
	}
	std::ifstream file(filename.toStdString());
	for (date_size = 0; !file.eof(); date_size++)
	{
		ui.tableWidget->insertRow(date_size);
		g_dt = AddMemory(g_dt, date_size);
		file >> g_dt[date_size];
		g_dt[date_size].isValid();
		ui.tableWidget->setItem(date_size, 0, (g_dt[date_size]).PrintDate());
	}
	date_from_file = date_size;
}

void Dates::on_pushButton_2_clicked()
{

	for (int i = 0; i < date_size; i++)
	{
		Date new_day = g_dt[i].NextDay();
		ui.tableWidget->setItem(i, 1, new_day.PrintDate());
	}
}


void Dates::on_pushButton_3_clicked()
{

	for (int i = 0; i < date_size; i++)
	{
		Date previous_day = g_dt[i].PreviousDay();
		if (previous_day.c_year == 0)
		{
			QTableWidgetItem* it = new QTableWidgetItem(QString("31.12.0001 BC :)"));
			ui.tableWidget->setItem(i, 2, it);
			continue;
		}
		ui.tableWidget->setItem(i, 2, previous_day.PrintDate());

	}
}

void Dates::on_pushButton_4_clicked()
{

	for (int i = 0; i < date_size; i++)
	{
		Date temp_date(1, 1, g_dt[i].c_year);
		short week_number = temp_date.WeekNumber(g_dt[i]);
		QTableWidgetItem* it = new QTableWidgetItem(QString("%1 week").arg(week_number));
		ui.tableWidget->setItem(i, 3, it);

	}
}

void Dates::on_pushButton_5_clicked()
{

	for (int i = 0; i < date_size; i++)
	{
		bool is_leap = g_dt[i].isLeap();
		if (is_leap)
		{
			QTableWidgetItem* it = new QTableWidgetItem(QString("Year is leap"));
			ui.tableWidget->setItem(i, 4, it);
		}
		else
		{
			QTableWidgetItem* it = new QTableWidgetItem(QString("Year isn't leap"));
			ui.tableWidget->setItem(i, 4, it);
		}

	}
}

void Dates::on_pushButton_6_clicked()
{
	struct tm* local;
	time_t t;
	t = time(NULL);
	local = localtime(&t);
	int year = local->tm_year + 1900;
	int month = local->tm_mon + 1;
	int day = local->tm_mday;
	Date now_date(local->tm_mday, local->tm_mon + 1, local->tm_year + 1900);
	for (int i = 0; i < date_size; i++)
	{
		int days_count = g_dt[i].Duration(now_date);
		QTableWidgetItem* it = new QTableWidgetItem(QString("%1 day(-s)").arg(days_count));
		ui.tableWidget->setItem(i, 6, it);
	}
}


void Dates::on_pushButtonAdd_clicked()
{
	Date new_date;
	QString date_add = (ui.lineEdit_2->text());
	new_date.c_day = date_add.left(2).toInt();
	new_date.c_month = date_add.mid(3, 2).toInt();
	new_date.c_year = date_add.right(4).toInt();
	new_date.isValid();
	g_dt = AddMemory(g_dt, date_size);
	g_dt[date_size] = new_date;
	ui.tableWidget->insertRow(date_size);
	ui.tableWidget->setItem(date_size, 0, (g_dt[date_size]).PrintDate());
	date_size++;
}


void Dates::on_pushButtonSave_clicked()
{
	QFileDialog file_save;
	file_save.setAcceptMode(QFileDialog::AcceptSave);
	file_save.setFileMode(QFileDialog::AnyFile);
	QString save_name = file_save.getSaveFileName(this, tr("Save your dates"), "C:/Users/AleXandR/Documents/BSUIR/Labs2/C++/Lab 1/Dates",
		tr("Text Files (*.txt)"));
	if (save_name.isEmpty()) return;
	if (filename != save_name)
	{
		filename = save_name;
		std::fstream out_file;
		out_file.open(filename.toStdString(), std::ios::in | std::ios::out);
		for (int i = 0; i < date_size; i++)
		{
			out_file << g_dt[i] << std::endl;
		}
	}
	else
	{
		std::fstream out_file(save_name.toStdString(), std::ios::app);
		out_file.seekp(0, std::ios::end);
		for (int i = date_from_file; i < date_size; i++)
		{
			out_file << std::endl;
			out_file << g_dt[i];
		}
	}
}