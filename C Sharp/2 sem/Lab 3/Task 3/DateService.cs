using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Task_3
{
    public class DateService
    {
        public string GetDay(string date)
        {
            string s_year = date;
            s_year = s_year.Remove(0, 6);
            int year = Convert.ToInt32(s_year);
            string s_month = date;
            s_month = s_month.Remove(0,3);
            s_month = s_month.Remove(2, 5);
            int month = Convert.ToInt32(s_month);
            string s_day = date;
            s_day = s_day.Remove(2,8);
            int day = Convert.ToInt32(s_day);
            DateOnly date_ = new DateOnly(year, month, day);
            string day_of_week = (date_.DayOfWeek).ToString();
            return day_of_week;
        }

        public int GetDaysSpan(int day, int month, int year)
        {
            var date = new DateTime(year, month, day);
            var duration = now_date.Subtract(date);
            if (duration.Days <= 0)
            {
                return Math.Abs(duration.Days) + 1;
            }
            return duration.Days;
        }

        public DateTime now_date = DateTime.Now;

        
        public string[] days = new string[7]
        {
            "Monday",
            "Tuesday",
            "Wednesday",
            "Thursday",
            "Friday",
            "Saturday",
            "Sunday"
        };
        
           
    }
}
