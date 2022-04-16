using Microsoft.VisualStudio.TestTools.UnitTesting;
using Classes;

namespace Test_Classes
{
    [TestClass]
    public class Test
    {
        [TestMethod]
        public void TestGetTotalPrice()
        {
            int[] expected = { 10, 15, 30, 45, 70, 105 };
            Store online_store = new Store();
            online_store.AddProduct(new Product("Bread", 15));
            online_store.AddProduct(new Product("Milk", 25));
            online_store.AddProduct(new Product("Eggs", 35));
            online_store.AddCustomer("John");
            for (int i = 0; i < 6; i++)
            {
                online_store.customers[0].Buy(online_store.products[i]);
                int temp = online_store.customers[0].GetTotalPrice();
                Assert.AreEqual(expected[i], temp);

            }
        }

        [TestMethod]
        public void TestMakeOrder()
        {
            string[] expected = { "Chocolate", "Coffee", "Tea", "Bread" };
            Store online_store = new Store();
            online_store.AddProduct(new Product("Bread", 15));
            online_store.AddCustomer("John");
            for (int i = 0; i < 4; i++)
            {
                online_store.customers[0].Buy(online_store.products[i]);
                Assert.AreEqual(online_store.customers[0].Products[i].Title, expected[i]);
            }
        }
    }
}