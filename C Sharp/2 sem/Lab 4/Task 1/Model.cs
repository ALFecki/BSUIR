using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Task_1
{
    public class Model
    {
        private int price;
        public Model(int price)
        {
            this.price = price;
        }

        public Model()
        {
            price = 1500;
        }

        public int Price
        {
            get
            {
                return price;
            }
            set
            {
                if (value < 0)
                {
                    Console.WriteLine("You entered negative price");
                    price = 10;
                    return;
                }
                price = value;
            }
        }

    }
}
