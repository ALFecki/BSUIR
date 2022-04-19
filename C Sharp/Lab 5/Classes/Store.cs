namespace Classes
{
    public class Store
    {
        public Store()
        {
            products = new List<Product>();
            customers = new List<Customer>();
            AddProduct(new Product("Chocolate", 10));
            AddProduct(new Product("Coffee", 5));
            AddProduct(new Product("Tea", 15));
            AddCustomer("John");
            AddCustomer("Dave");
            AddCustomer("Jerry");
        }

        public void AddCustomer(string name)
        {
            customers.Add(new Customer(name));
        }
        public void AddProduct(Product product)
        {
            products.Add(product);
        }
        public void AddProduct(string Title, int Price)
        {
            products.Add(new Product(Title, Price));
        }
        public void BuyProduct(string customer_name, string product_name, int price)
        {
            foreach (Customer current_customer in customers)
            {
                if (current_customer.Name == customer_name)
                {
                    foreach (Product current_product in products)
                    {
                        if (current_product.Title == product_name)
                        {
                            if (current_product.Price == price)
                            {
                                current_customer.Buy(current_product);
                                return;
                            }
                        }
                    }
                    AddProduct(product_name, price);
                    current_customer.Buy(products.Last());
                    return;
                }
            }
            AddCustomer(customer_name);
            BuyProduct(customer_name, product_name, price);
            return;
        }


        public void PrintInfo(string customer_name)
        {
            foreach (Customer cuurent_customer in customers)
            {
                if (cuurent_customer.Name == customer_name)
                {
                    if (cuurent_customer.Products.Count == 0)
                    {
                        Console.WriteLine("\n*******************************************\n");
                        Console.WriteLine("{0} has no products", cuurent_customer.Name);
                        Console.WriteLine("\n*******************************************\n");
                        return;
                    }
                    else
                    {
                        Console.WriteLine("\n*******************************************\n");
                        Console.WriteLine("{0} has {1} products:", cuurent_customer.Name, cuurent_customer.Products.Count);
                        foreach (Product current_product in cuurent_customer.Products)
                        {
                            Console.WriteLine("{0} - {1}", current_product.Title, current_product.Price);
                        }
                        Console.WriteLine("\n*******************************************\n");
                        return;
                    }
                }
            }
            Console.WriteLine("Customer not found");
            return;

        }
        public void PrintTotalPrice(string customer_name)
        {
            foreach (Customer cuurent_customer in customers)
            {
                if (cuurent_customer.Name == customer_name)
                {
                    if (cuurent_customer.Products.Count == 0)
                    {
                        Console.WriteLine("\n*******************************************\n");
                        Console.WriteLine("{0} has no products", cuurent_customer.Name);
                        Console.WriteLine("\n*******************************************\n");
                        return;
                    }
                    else
                    {
                        Console.WriteLine("\n*******************************************\n");
                        Console.WriteLine("{0} has {1} products:", cuurent_customer.Name, cuurent_customer.Products.Count);
                        foreach (Product current_product in cuurent_customer.Products)
                        {
                            Console.WriteLine("{0} - {1}", current_product.Title, current_product.Price);
                        }
                        Console.WriteLine("Total price: {0}", cuurent_customer.GetTotalPrice());
                        Console.WriteLine("\n*******************************************\n");
                        return;
                    }
                }
            }
            Console.WriteLine("Customer not found");
            return;
        }

        public void ShowAllProducts()
        {
            Console.WriteLine("\n/////////////////////////////////////////////////");
            foreach (Product current_product in products)
            {
                Console.WriteLine("{0} - {1}", current_product.Title, current_product.Price);
            }
            Console.WriteLine("/////////////////////////////////////////////////\n");
        }

        public void ShowAllCustomers()
        {
            Console.WriteLine("\n/////////////////////////////////////////////////");
            foreach (Customer current_customer in customers)
            {
                Console.WriteLine("{0}", current_customer.Name);
            }
            Console.WriteLine("/////////////////////////////////////////////////\n");
        }

        public void MakeNewOrder(string customer_name, string product_name)
        {
            foreach (Customer cuurent_customer in customers)
            {
                if (cuurent_customer.Name == customer_name)
                {
                    foreach (Product current_product in products)
                    {
                        if (current_product.Title == product_name)
                        {
                            cuurent_customer.Buy(current_product);
                            return;
                        }
                    }
                    Console.WriteLine("Product not found");
                    Console.WriteLine("Enter price of new product: ");
                    AddProduct(product_name, Convert.ToInt32(Console.ReadLine()));
                    cuurent_customer.Buy(products.Last());
                    return;
                }
            }
            Console.WriteLine("You are a new customer, WELCOME!!!");
            AddCustomer(customer_name);
            MakeNewOrder(customer_name, product_name);
            return;
        }

        public List<Product> products;
        public List<Customer> customers;


    }
}
