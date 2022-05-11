using Store;


namespace Store
{
    class Program
    {
        static void Main(string[] args)
        {
            var store = new Store("Vesta");
            store.AddProduct("Milk", 1.545);
            store.AddProduct("Bread", 1.45);
            store.AddDiscountProduct("Cucumber", 5.29, 20);
            store.AddDiscountProduct("Tomato", 2.99, 10);
            store.Print();
            Console.WriteLine("Total price: {0}", store.GetTotalPrice());
        }
    }
}
