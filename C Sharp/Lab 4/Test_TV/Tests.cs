using Task_1;
using Microsoft.VisualStudio.TestTools.UnitTesting;


namespace Test_TV
{
    [TestClass]
    public class Tests
    {
        [TestMethod]
        public void getInstance_test()
        {
            OnlineStore store = OnlineStore.getInstance("OZON");
            OnlineStore store2 = OnlineStore.getInstance("AliExpress");
            Assert.AreEqual(store, store2);
        }

        [TestMethod]
        public void EditPrice_test()
        {
            OnlineStore store = OnlineStore.getInstance("OZON");
            int[] prices = { 100, 200, 300, 400, 500 };
            int[] expected = { 100, 200, 300, 400, 500 };
            for (int i = 0; i < 5; i++)
            {
                store.EditPrice = prices[i];
                Assert.AreEqual(expected[i], store.EditPrice);
            }
        }

        [TestMethod]
        public void TotalIncome_test()
        {
            OnlineStore store = OnlineStore.getInstance("OZON");
            int[] prices = { 100, 200, 300, 400, 500 };
            int[] sold = { 1, 2, 3, 4, 5 };
            int[] expected = { 100, 400, 900, 1600, 2500 };
            for (int i = 0; i < 5; i++)
            {
                store.EditPrice = prices[i];
                store.NumberOfPurchases = sold[i];
                Assert.AreEqual(expected[i], store.TotalIncome());
            }
        }
    }
}
