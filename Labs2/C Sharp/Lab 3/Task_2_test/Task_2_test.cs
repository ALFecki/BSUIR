using Microsoft.VisualStudio.TestTools.UnitTesting;
using Task_2;


namespace Task_2_test
{
    [TestClass]
    public class Task_2_test
    {
        [TestMethod]
        public void GetResult_z4()
        {
            double z = 4, expected = 0.12104569022534373;
            int expected_branch = 2;
            
            Services func = new Services();
            func.GetResult(z);
            Assert.AreEqual(expected, func.result);
            Assert.AreEqual(expected_branch, func.num_of_branch);
        }
        [TestMethod]
        public void GetResult_z0()
        {
            double z = 0, expected = 0.9976662375938783;
            int expected_branch = 1;

            Services func = new Services();
            func.GetResult(z);
            
            Assert.AreEqual(expected, func.result);
            Assert.AreEqual(expected_branch, func.num_of_branch);
        }
    }
}