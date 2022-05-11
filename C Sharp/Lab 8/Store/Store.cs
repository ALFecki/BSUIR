using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Store
{
    public class Store
    {
        private string name;

        private List<Product> products;
        public string Name
        {
            get
            {
                return this.name;
            }
            set
            {
                this.name = value;
            }

        }

        public Product this[int index]
        {
            get
            {
                return this.products[index];
            }
        }

        public Store(string name)
        {
            this.Name = name;
            this.products = new List<Product>();
        }

        public Store(string name, List<Product> products)
        {
            this.Name = name;
            this.products = products;
        }

        public void AddDiscountProduct(string name, double price, double discount)
        {
            this.products.Add(new Product(name, new Discount(price, discount)));
        }

        public void AddProduct(string name, double price)
        {
            this.products.Add(new Product(name, new NoDiscount(price)));
        }

        public double GetTotalPrice()
        {
            double totalPrice = 0;
            foreach (var product in this.products)
            {
                totalPrice += product.Price.getPrice();
            }
            return Math.Round(totalPrice, 3);
        }


        public void Print()
        {
            Console.WriteLine("Store: {0}", this.Name);
            Console.WriteLine("Products:");
            foreach (var product in this.products)
            {
                Console.WriteLine("{0} {1}", product.Name, Math.Round(product.Price.getPrice(), 3));
            }
        }

        public Product GetProduct(string name)
        {
            foreach (var product in this.products)
            {
                if (product.Name == name)
                {
                    return product;
                }
            }
            return null;
        }

    }
        public class Product
        {
            private string name;
            private IPrice price;

            public string Name
            {
                get
                {
                    return this.name;
                }
                set
                {
                    this.name = value;
                }
            }

            public IPrice Price
            {
                get
                {
                    return this.price;
                }
                set
                {
                    this.price = value;
                }
            }


            public Product(string name, IPrice price)
            {
                this.Name = name;
                this.Price = price;
            }

        }

        public interface IPrice
        {
            double getPrice();
        }

        class NoDiscount : IPrice
        {
            private double price;

            public NoDiscount(double price)
            {
                this.price = price;
            }

            public double getPrice()
            {
                return this.price;
            }
        }


        class Discount : IPrice
        {
            private double price;
            private double discount;

            public Discount(double price, double discount)
            {
                this.price = price;
                this.discount = discount;
            }

            public double getPrice()
            {
                return this.price - (this.price * this.discount / 100);
            }
        }
           
}
