using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Classes
{
    public class Product
    {
        public string name;
        public int price;
        public string Name
        {
            get
            {
                return Name;
            }

            set
            {
                if (value == null)
                {
                    Name = "Cucumber";
                    return;
                }
                Name = value;
            }
        }
        public int Price
        {
            get
            {
                return Price;
            }

            set
            {
                if (value < 0)
                {
                    Price = 10;
                    return;
                }
                Price = value;
            }
        }

        Product() 
        {
            name = "Cucumber";
            price = 10;
        }
        
    }
}
