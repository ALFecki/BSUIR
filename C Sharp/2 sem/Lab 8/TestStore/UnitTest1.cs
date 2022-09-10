using Microsoft.VisualStudio.TestTools.UnitTesting;
using Store;
using System;

namespace TestStore
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void TestAddProduct()
        {
            Store.Store store = new Store.Store("test");
            string[] names = { "test1", "test2", "test3" };
            int[] prices = { 1, 2, 3 };
            for (int i = 0; i < 3; i++)
            {
                store.AddProduct(names[i], prices[i]);

                Assert.AreEqual(names[i], store.GetProduct(names[i]).Name);
                Assert.AreEqual(prices[i], store.GetProduct(names[i]).Price.getPrice());
            }
        }

        [TestMethod]
        public void TestAddDiscountProduct()
        {
            Store.Store store = new Store.Store("test");
            string[] names = { "test1", "test2", "test3" };

            int[] prices = { 10, 20, 30 };
            int[] discounts = { 1, 2, 3 };
            double[] expected = { 9.9, 19.6, 29.1};
            for (int i = 0; i < 3; i++)
            {
                store.AddDiscountProduct(names[i], prices[i], discounts[i]);
                Assert.AreEqual(names[i], store.GetProduct(names[i]).Name);
                Assert.AreEqual(expected[i], store.GetProduct(names[i]).Price.getPrice());
            }
        }

        [TestMethod]
        public void TestGetTotalPrice()
        {
            Store.Store store = new Store.Store("test");
            string[] names = { "test1", "test2", "test3" };
            double[] prices = { 10, 20.2, 34.56 };
            double expected = 10 + 20.2 + 34.56;
            Math.Round(expected, 3);

            for (int i = 0; i < 3; i++)
            {
                store.AddProduct(names[i], prices[i]);
            }
            Assert.AreEqual(expected, store.GetTotalPrice());
        }
    }
}