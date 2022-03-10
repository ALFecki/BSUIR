using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Task_2_test
{
    [TestClass]
    public class Task_2_test
    {
        [TestMethod]
        public void IsInArea_x7_and_y2_1returned()
        {
            // arrange
            int x = 7, y = 2, expected = 1;
            // act
            Belonging belonging = new Belonging();
            int actual = belonging.isInArea(x, y);
            //assert
            Assert.AreEqual(expected, actual);

        }
        [TestMethod]
        public void IsInArea_x5_y0_2returned()
        {
            int x = 5, y = 0, expected = 2;
            Belonging belonging = new Belonging();
            int actual = belonging.isInArea(x, y);
            Assert.AreEqual(expected, actual);
        }
    }
}