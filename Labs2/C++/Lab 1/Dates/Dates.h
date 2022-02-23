#pragma once

#define foreach Q_FOREACH 


#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include "ui_Dates.h"
#include <qwidget.h>
#include <string>
#include <fstream>
#include <istream>
#include <qfiledialog.h>


class Date
{
    friend class Dates;
public:
    Date(int day = 1, int month = 1, int year = 1979);
     
    Date NextDay();
    Date PreviousDay();
    bool isLeap();
    int CountOfDays(int,int);
    short WeekNumber(Date);
    int DaysTillBirthday(Date);
    int Duration(Date);
    void isValid();
    bool MonthCheck(int month);
    QTableWidgetItem* PrintDate();
    friend std::istream& operator>>(std::istream&, Date&);
    friend std::fstream& operator<< (std::fstream&, Date&);


private:
    
 
    int c_day, c_month, c_year;
    
};



class Dates : public QMainWindow
{
    Q_OBJECT

public:
    Dates(QWidget *parent = Q_NULLPTR);

private slots:

    void on_lineEdit();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButtonAdd_clicked();
    void on_pushButtonSave_clicked();

private:
    Date* g_dt;
    QString filename;
    int date_size, date_from_file;
    Ui::DatesClass ui;
};


