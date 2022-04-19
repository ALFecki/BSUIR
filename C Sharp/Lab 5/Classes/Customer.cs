namespace Classes
{
    public class Customer
    {
        private string name;
        public Customer(string Name_)
        {
            Name = Name_;
            Products = new List<Product>();
        }

        public void Buy(string Title, int Price)
        {
            Products.Add(new Product(Title, Price));
            return;
        }

        public void Buy(Product product)
        {
            Products.Add(product);
            return;
        }
        public int GetTotalPrice()
        {
            int TotalPrice = 0;
            foreach (Product Product in Products)
            {
                TotalPrice += Product.Price;
            }
            return TotalPrice;
        }
        public string Name
        {
            get { return name; }
            set
            {
                if (value == null)
                {
                    name = "Gabe Newell";
                    return;
                }
                name = value;
            }
        }
        private List<Product> products;
        public List<Product> Products
        {
            get { return products; }
            set { products = value; }
        }
    }
}
