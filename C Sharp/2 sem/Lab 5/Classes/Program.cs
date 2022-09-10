
using Classes;

Store online_store = new Store();
bool t = true;

while (t)
{
    Console.WriteLine("\n===============MENU===============\n");
    Console.WriteLine("1. Show all products");
    Console.WriteLine("2. Show all customers");
    Console.WriteLine("3. Show the information about customer's order");
    Console.WriteLine("4. Show the total price of customer's orders");
    Console.WriteLine("5. Enter new product");
    Console.WriteLine("6. Make a new order");
    Console.WriteLine("7. Exit");
    Console.WriteLine("Choose your variant: ");
    int choose = Convert.ToInt32(Console.ReadLine());
    switch (choose)
    {
        case 1:
            {
                online_store.ShowAllProducts();
                break;
            }
        case 2:
            {
                online_store.ShowAllCustomers();
                break;
            }
        case 3:
            {
                Console.WriteLine("Enter the name: ");
                online_store.PrintInfo(Console.ReadLine());
                break;
            }
        case 4:
            {
                Console.WriteLine("Enter the name: ");
                online_store.PrintTotalPrice(Console.ReadLine());
                break;
            }
        case 5:
            {
                Console.WriteLine("Enter the title of new product: ");
                string? temp = Console.ReadLine();
                Console.WriteLine("Enter the price of new product: ");
                int temp_ = Convert.ToInt32(Console.ReadLine());
                online_store.AddProduct(temp, temp_);
                break;
            }
        case 6:
            {
                Console.WriteLine("Enter the name of customer: ");
                string? temp = Console.ReadLine();
                Console.WriteLine("Enter the title of product: ");
                string temp_ = Console.ReadLine();
                online_store.MakeNewOrder(temp, temp_);
                break;
            }
        case 7:
            {
                t = false;
                break;
            }

        default:
            {

                Console.WriteLine("Incorrect input. Try again.");
                break;
            }
    }


}