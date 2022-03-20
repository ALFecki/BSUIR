using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Task_1
{
    public class Numbers
    {
        public Numbers()
        {
            number = 143;
        }
        public Numbers(int number_)
        {
            number = number_;
        }    
        
        public int Switch_numbers()
        {
            this.first = number / 100;
            this.last = number % 10;
            int new_number = last * 100 + (number % 100 - this.last) + this.first; 
            return new_number;
        }

        private int number, first, last;

    }
}
