
namespace Task_1
{
    class Program
    {
        static void Main(string[] args)
        {
            OnlineStore store = OnlineStore.getInstance("Интернет-магазин");
            Console.WriteLine(store.StoreName);
            OnlineStore store1 = OnlineStore.getInstance("Catalog Onliner");
            Console.WriteLine(store1.StoreName);

            store.NumberOfPurchases = 50;

            store.EditPrice = 100;
            Console.WriteLine(store.EditPrice);
            var income = store.TotalIncome();
            Console.WriteLine(income);
            store.StoreName = "New Store";
            Console.WriteLine(store.StoreName);
        }
    }
}