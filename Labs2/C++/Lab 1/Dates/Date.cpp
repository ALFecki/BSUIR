#include "Dates.h"

bool Date::isValidEnter()
{
	if ((c_day == 31 || c_day == 30) && !MonthCheck(c_month))
	{
		return 0;
	}
	else if (c_day == 29 && !isLeap())
	{
		return 0;
	}
	else return 1;
}

Date Date::NextDay()
{
	if (c_day == 31 && c_month == 12) // checking for the next year
	{
		Date next_day(1, 1, c_year + 1);
		return next_day;
	}
	else if (c_day == 28 && !isLeap() || c_day == 29 && isLeap()) // checking for the last day of Feb
	{
		Date next_day(1, c_month + 1, c_year);
		return next_day;
	}
	else if (c_day == 30 && !MonthCheck(c_month) || c_day == 31 && MonthCheck(c_month)) // checking for the count of days in month
	{
		Date next_day(1, c_month + 1, c_year);
		return next_day;
	}
	else
	{
		Date next_day(c_day + 1, c_month, c_year);
		return next_day;
	}
}

Date Date::PreviousDay()
{
	if (c_day == 1 && c_month == 1) // checking for the previous year
	{
		Date previous_day(31, 12, c_year - 1);
		return previous_day;
	}
	else if (c_day == 1 && c_month == 3 && !isLeap()) // checking for Feb
	{
		Date previous_day(28, c_month - 1, c_year);
		return previous_day;
	}
	else if (c_day == 1 && c_month == 3 && isLeap()) // checking for the leap Feb
	{
		Date previous_day(29, c_month - 1, c_year);
	}
	else if (c_day == 1 && !MonthCheck(c_month - 1)) // checking for 30 days
	{
		Date previous_day(30, c_month - 1, c_year);
		return previous_day;
	}
	else if (c_day == 1 && MonthCheck(c_month - 1)) // checking for 31 days
	{
		Date previous_day(31, c_month - 1, c_year);
		return previous_day;
	}
	else
	{
		Date previous_day(c_day - 1, c_month, c_year);
		return previous_day;
	}
}

bool Date::isLeap()
{
	if (c_year % 4 == 0 && c_year % 100 != 0)
	{
		return 1;
	}
	else return 0;
}


int Date::CountOfDays(int b_day = 1, int b_month = 1) {
	int days_count = 0, i = 1;
	if (b_month < c_month)
	{
		i = c_month;
	}
	else if (b_month == c_month)
	{
		if (b_day >= c_day)
		{
			return b_day - c_day;
		}
		else
		{
			if (MonthCheck(b_month))
			{
				days_count += 31 - b_day;
			}
			else if (b_month == 2 && isLeap())
			{
				days_count += 29 - b_day;
			}
			else if (b_month == 2)
			{
				days_count += 28 - b_day;
			}
			else
			{
				days_count += 30 - b_day;
			}
			i = ++b_month;
		}
	}

	for (; b_month != i; b_month++)
	{
		if (c_month == 13)
		{
			c_month = 1;
		}
		if (MonthCheck(i))
		{
			days_count += 31;
		}
		else if (i == 2 && isLeap())
		{
			days_count += 29;
		}
		else if (i == 2)
		{
			days_count += 28;
		}
		else
		{
			days_count += 30;

		}
	}
	if (c_month != 1)
	{
		days_count += c_day;
	}
	return days_count;
}

short Date::WeekNumber(Date dt)
{
	short week_number = 1;
	int days_count = dt.CountOfDays();
	double week_number_d = static_cast<double>(days_count) / 7;
	if (days_count % 7 > 0)
	{
		week_number = week_number_d + 1;
	}
	else week_number = week_number_d;
	return week_number;
}

int Date::DaysTillBirthday(Date birthday)
{
	int days_count = CountOfDays(birthday.c_day, birthday.c_month);
	return days_count;
}

Date& Date::operator++() {
	this->NextDay();
	return *this;
}

std::istream& operator>>(std::istream &os,Date &dt) {
	
	os >> dt.c_day;
	os.ignore();
	os >> dt.c_month;
	os.ignore();
	os >> dt.c_year;
	return os;
}

int Date::Duration(Date now_date)
{
	int i;
	if (now_date.c_year > c_year)
	{
		i = c_year;
	}
	else
	{
		
	}
	for (int i = 0; i < 0; i++)
	{

	}
	return 0;
}

QTableWidgetItem* Date::PrintDate()
{
	QTableWidgetItem* it = new QTableWidgetItem(QString("%1.%2.%3").arg(c_day).arg(c_month).arg(c_year));;
	return it;
}


bool Date::MonthCheck(int month)
{
	if ((month % 2 != 0 && month <= 7) || (month % 2 == 0 && month > 7))
		return 1;
	else return 0;
}

