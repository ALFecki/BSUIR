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
        public void GetResult(double z)
        {
            double x;
            if (z < 1)
            {
                x = Math.Pow(z,3) + 0.2;
                this.num_of_branch = 1;
            }
            else
            {
                x = z + Math.Log(z);
                this.num_of_branch = 2;
            }
            this.result = Math.Pow(Math.Cos(Math.Pow(x, 2)), 3) + Math.Pow(Math.Sin(Math.Pow(x, 3)), 2);
        }

        public double result;
        public int num_of_branch;
    }
}
