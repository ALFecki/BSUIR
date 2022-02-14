#include "Dates.h"

Date* g_dt = 0;


Dates::Dates(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	ui.tableWidget->setColumnCount(7);
	QStringList lst;
	lst << "Date" << "Next day" << "Previous day" << "Week number" << "Leap" << "Days till birthday" << "Duration";
	ui.tableWidget->setHorizontalHeaderLabels(lst);
	ui.lineEdit->setInputMask("00.00.0000");
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


void Dates::on_pushButton_clicked() // set new date
{
	std::ifstream file("input.txt");
    
    for (int i = 1; !file.eof(); i++)
    {
		ui.tableWidget->insertRow(i - 1);
		g_dt = AddMemory(g_dt, i - 1);
        file >> g_dt[i - 1];
		ui.tableWidget->setItem(i - 1, 0, (g_dt[i - 1]).PrintDate());
		ui.comboBox->addItem(QString("Date %1").arg(i));
    }
} 

void Dates::on_pushButton_2_clicked()
{
	int index = ui.comboBox->currentIndex();
	Date new_day = g_dt[index].NextDay();
	ui.tableWidget->setItem(index, 1, new_day.PrintDate());
}


void Dates::on_pushButton_3_clicked()
{
	int index = ui.comboBox->currentIndex();
	Date previous_day = g_dt[index].PreviousDay();
	ui.tableWidget->setItem(index, 2, previous_day.PrintDate());
}

void Dates::on_pushButton_4_clicked()
{
	int index = ui.comboBox->currentIndex();
	short week_number = g_dt[index].WeekNumber(g_dt[index]);
	QTableWidgetItem* it = new QTableWidgetItem(QString("%1 week").arg(week_number));
	ui.tableWidget->setItem(index, 3, it);
}

void Dates::on_pushButton_5_clicked()
{
	int index = ui.comboBox->currentIndex();
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