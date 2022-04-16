using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Classes
{
    public class Product
    {
        private string title_;
        private int price_;
        public Product(string title, int price)
        {
            Title = title;
            Price = price;
        }
        public string Title
        {
            get
            {
                return title_;
            }

            set
            {
                if (value == null)
                {
                    title_ = "Cucumber";
                    return;
                }
                title_ = value;
            }
        }
        public int Price
        {
            get
            {
                return price_;
            }

            set
            {
                if (value < 0)
                {
                    price_ = 10;
                    return;
                }
                price_ = value;
            }
        }

        Product() 
        {
            title_ = "Cucumber";
            price_ = 10;
        }
        
    }
}
