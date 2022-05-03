using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Classes
{
    internal class Rose : Flower
    {
        private string colour;
        public string Colour_
        {
            get => colour;
            set => colour = value;
        }

        public Rose(string name, string _colour, string field)
            : base(name)
        {
            Colour_ = colour;
            Growth_Field(field);
        }
        
        public override void Growth_Field(string field)
        {
            GrowthField = field;
        }


        public override void PrintData()
        {
            Console.WriteLine($"{Name} \nЦвет: {Colour_}\nМесто выращивания: {GrowthField}"); 
        }

        

    }
}
