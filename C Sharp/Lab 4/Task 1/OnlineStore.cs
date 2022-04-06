using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Task_1
{
    public class OnlineStore
    {
        private static OnlineStore? TVinstance;
        private string storeName = "Catalog Onliner";
        private int number_of_purchases = 10;
        public Model TVmodel = new Model();

        public string StoreName
        {
            get
            {
                if (storeName == null)
                {
                    Console.WriteLine("Store name is null");
                    return "Null";
                }
                return storeName;
            }
            set => storeName = value;
        }

        public int NumberOfPurchases
        {
            get
            {
                return number_of_purchases;
            }
            set
            {
                if (value < 0)
                {
                    Console.WriteLine("Number of purchases is negative");
                    number_of_purchases = 0;
                    return;
                }
                number_of_purchases = value;
            }
        }

        private OnlineStore() { }

        private OnlineStore(string name)
        {
            storeName = name;
        }

        public static OnlineStore getInstance(string? name)
        {
            name??= "Catalog Onliner";
            if (TVinstance == null)
            {
                TVinstance = new OnlineStore(name);
            }
            return TVinstance;

        }
        public int TotalIncome()
        {
            return TVmodel.Price * NumberOfPurchases;
        }

        public int EditPrice
        {
            get { return TVmodel.Price; }
            set
            {
                if (value < 0)
                {
                    Console.WriteLine("You entered negative price");
                    TVmodel.Price = 10;
                    return;
                }
                TVmodel.Price = value;
            }
        }
    }
}
