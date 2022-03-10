using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

// variant 4

namespace Task_2
{
    public class Services
    {
        public void GetResult(double z, double b)
        {
            double x;
            if (z < 1)
            {
                x = z / b;
                this.num_of_branch = 1;
            }
            else
            {
                x = Math.Sqrt(Math.Pow(z * b, 3));
                this.num_of_branch = 2;
            }
            this.result = Math.Pow(Math.Cos(Math.Pow(x, 2)), 3) + Math.Pow(Math.Sin(Math.Pow(x, 3)), 2);
        }

        public double result;
        public int num_of_branch;
    }
}
