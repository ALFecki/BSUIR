using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Classes
{
    public abstract class Flower
    {
        public abstract string Nation { get; set; }
        public abstract string GrowthField { get; set; }
        public abstract int Age { get; set; }
        
        public Flower()
        {
            Nation = "";
            GrowthField = "";
            Age = 0;
        }

        public abstract void PrintData();

        public virtual void GetSeeds(int count)
        {
            Console.WriteLine("You get {0} seeds ", count);
        }

        public void Info()
        {
            Console.WriteLine("Country: {0}", Nation);
            Console.WriteLine("Growth field: {0}", GrowthField);
            Console.WriteLine("Age: {0} day(-s)", Age);
        }

    }

    public sealed class Rose : Flower
    {
        private string name;
        
        public string Name
        {
            get { return name; }
            set => name = value;
        }
        
        private string nation;

        public override string Nation 
        {
            get { return nation; }
            set => nation = value;
        }
        
        private string growthField;

        public override string GrowthField
        {
            get { return growthField; }
            set => growthField = "warm and wet places";
        }

        private int age;

        public override int Age
        {
            get { return age; }
            set => age = value;
        }

        private string color;

        public string Color
        {
            get { return color; }
            set => color = value;
        }

        public Rose(string name_, string _nation, int _age, string _color)
        {
            Name = name_;
            Nation = _nation;
            GrowthField = "";
            Age = _age;
            Color = _color;
        }
        

        public new void Info()
        {
            Console.WriteLine("Country: {0}", Nation);
            Console.WriteLine("Growth field: {0}", GrowthField);
            Console.WriteLine("Age: {0} day(-s)", Age);
            Console.WriteLine("Color: {0}", Color);
        }

        public override void GetSeeds(int count)
        {
            Console.WriteLine("You get {0} seeds of rose (Nation: {1}, Color: {2})", count, Nation, Color);
        }

        public override void PrintData()
        {
            Console.WriteLine("Name of the flower: {0}", Name);
            Console.WriteLine("Country: {0}", Nation);
            Console.WriteLine("Growth field: {0}", GrowthField);
            Console.WriteLine("Age: {0} day(-s)", Age);
            Console.WriteLine("Color: {0}", Color);
        }



    }

    public class Chamomile : Flower
    {
        public Chamomile(string name_, string nation_, int age_, int count_)
        {
            Name = name_;
            Age = age_;
            GrowthField = "";
            Nation = nation_;
            Count = count_;
        }
        
        private string name;
        
        public string Name
        {
            get { return name; }
            set => name = value;
        }

        private int age;

        public override int Age
        {
            get { return age; }
            set => age = value;
        }

        private string nation;

        public override string Nation
        {
            get { return nation; }
            set => nation = value;
        }

        private string growthField;

        public override string GrowthField
        {
            get { return growthField; }
            set => growthField = "field";
        }

        private int count;

        public int Count
        {
            get { return count; }
            set => count = value;
        }

        public new void Info()
        {
            Console.WriteLine("Country: {0}", Nation);
            Console.WriteLine("Growth field: {0}", GrowthField);
            Console.WriteLine("Age: {0} day(-s)", Age);
            Console.WriteLine("Count: {0}", Count);
        }

        public override void GetSeeds(int count)
        {
            if (count > Count)
            {
                Console.WriteLine("There are no this count of seeds.");
            }
            else Console.WriteLine("You get {0} seeds of rose (Nation: {1})", count, Nation);
        }

        public string Seeds(int count)
        {
            if (count > Count)
            {
                return "There are no this count of seeds.";
            }
            return null;
        }

        public override void PrintData()
        {
            Console.WriteLine("Name of the flower: {0}", Name);
            Console.WriteLine("Country: {0}", Nation);
            Console.WriteLine("Growth field: {0}", GrowthField);
            Console.WriteLine("Age: {0} day(-s)", Age);
            Console.WriteLine("Count: {0}", Count);
        }
    }

}
