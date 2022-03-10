using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Task_1_test
{ 
    [TestClass]
    public class Task_1_test
    {
        [TestMethod]
        public void IsEven_145_false_returned()
        {
            // arrange
            int c = 145;
            
            // act
            Number number = new Number();
            bool t = number.isEven(c);
            // assert
            Assert.IsFalse(t);
        }
    }
}