using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using Task_3;



namespace Task_3_tests
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void TestGetDay()
        {
            string[] dates = { "22.03.2022", "24.06.2022", "09.03.2022" };
            string[] expected = { "Tuesday", "Friday", "Wednesday" };

            DateService date = new DateService();
            for (int i = 0; i < 3; i++)
            {
                Assert.AreEqual(date.GetDay(dates[i]), expected[i]);
            }
        }

        [TestMethod]
        public void TestGetDaysSpan()
        {
            string[] dates = { "18.03.2022", "29.03.2022" };
            int[] expected = { 1, 10 };

            DateService daySpan = new DateService();    
            for (int i = 0; i < 2; i++)
            {
                string[] parametrs = dates[i].Split(new char[] { '.' }, StringSplitOptions.RemoveEmptyEntries);
                Assert.AreEqual(daySpan.GetDaysSpan(Convert.ToInt32(parametrs[0]), Convert.ToInt32(parametrs[1]), Convert.ToInt32(parametrs[2])), expected[i]);
            }
        }
    }
}