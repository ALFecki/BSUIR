using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _153503_Skvortsov_Lab8.entities {
    public class Patient {
        public int Id { get; set; }
        public string Name { get; set; }
        public string Ill { get; set; }

        public string ToString() {
            return $"{Id} {Name} {Ill}";
        }
    }
}
