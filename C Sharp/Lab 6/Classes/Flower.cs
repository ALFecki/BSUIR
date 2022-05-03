using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Classes
{
    abstract class Flower
    {
        private string name;
        private string growthField;
        //private string color;
        public string Name
        {
            get => name;
            set => name = value;
        }

        public string GrowthField
        {
            get => growthField;
            set => growthField = value;
        }        
        /*public string Color_
        {
            get => color;
            set => color = value;
        }*/
        public Flower(string name_)
        {
            Name = name_;
        }

        public abstract void PrintData();
        
        public virtual void Growth_Field(string field)
        {
            GrowthField = "Default";
        }

    }
}
