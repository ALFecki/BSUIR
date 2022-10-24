using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _153503_Skvortsov_Lab5.Domain.Classes {
    public class Building {
        public string Address { get; set; }
        public int NumberOfAppartments { get; set; }
        public HeatingSystem heatingSystem { get; set; }

        public void Print() {
            Console.WriteLine("\n--------------------------------------------");
            Console.WriteLine($"Address: {Address}");
            Console.WriteLine($"Appartments count: {NumberOfAppartments}");
            Console.WriteLine("Heating system:");
            Console.WriteLine($"Description: {heatingSystem.Description}");
            Console.WriteLine($"Working: {heatingSystem.IsEnabled}");
            Console.WriteLine($"Temperature: {heatingSystem.Temperature}");
        }
        
    }
}
