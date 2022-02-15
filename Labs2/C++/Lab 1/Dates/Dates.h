#pragma once

#define foreach Q_FOREACH 


#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include "ui_Dates.h"
#include <qwidget.h>
#include <fstream>
#include <istream>


class Date
{
    friend class Dates;
public:
    Date(int day = 1, int month = 1, int year = 1979)
        : c_day(day), c_month(month), c_year(year) {}
     
    Date NextDay();
    Date PreviousDay();
    bool isLeap();
    int CountOfDays(int,int);
    short WeekNumber(Date);
    int DaysTillBirthday(Date);
    int Duration(Date);
    bool isValidEnter();
    bool MonthCheck(int month);
    QTableWidgetItem* PrintDate();
    Date& operator++();
    friend std::istream& operator>>(std::istream&, Date&);

private:
    
    int c_day, c_month, c_year;
    int month_days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 ,31 };
    
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
    

private:
    Ui::DatesClass ui;
};


