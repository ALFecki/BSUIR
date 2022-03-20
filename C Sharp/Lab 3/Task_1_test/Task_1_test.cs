using Microsoft.VisualStudio.TestTools.UnitTesting;
using Task_1;

namespace Task_1_test
{
    [TestClass]
    public class Task_1_test
    {
        [TestMethod]
        public void SwitchNumbers_987_789_returned()
        {
            int num = 987, expected = 789;

            Numbers number = new Numbers(num);
            Assert.AreEqual(expected, number.Switch_numbers());
        }
        public void SwitchNumbers_566_665_returned()
        {
            int num = 566, expected = 665;

            Numbers number = new Numbers(num);
            Assert.AreEqual(expected, number.Switch_numbers());
        }
    }
}