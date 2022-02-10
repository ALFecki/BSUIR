#pragma once

#include <QtWidgets/QMainWindow>
#include<QPushButton>
#include "ui_Dates.h"
#include <iostream>

class Date
{

public:
    Date(int day = 1, int month = 1, int year = 1979)
        : c_day(day), c_month(month), c_year(year)
    {
        
    }
    bool isValidEnter();    
    Date NextDay();
    Date PreviousDay();
    bool isLeap();
    int CountOfDays(int,int);
    short WeekNumber();
    int DaysTillBirthday(Date);
    int Duration(Date);
    bool MonthCheck(int month);

private:
    
    int c_day, c_month, c_year;
    
};



class Dates : public QMainWindow
{
    Q_OBJECT

public:
    Dates(QWidget *parent = Q_NULLPTR);

private:
    Ui::DatesClass ui;
};


