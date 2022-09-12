using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _153503_Skvortsov_Lab1.Entities
{
    public class Tariff
    {
        private string name;
        private int cost;

        public Tariff(string name, int cost)
        {
            this.name = name;
            this.cost = cost;
        }

        public string Name
        {
            get { return name; }
        }

        public int Cost
        {
            get { return cost; }
        }

    }
}
