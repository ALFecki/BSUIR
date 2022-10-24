using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _153503_Skvortsov_Lab4.Entities {
    internal class People {

        private string name;
        private int appartament;
        private bool isMale;

        public People() {
            name = null;
            appartament = 0;
            isMale = false;
        }

        public People(string name, int appartament, bool isMale) {
            this.name = name;
            this.appartament = appartament;
            this.isMale = isMale;
        }

        public People(BinaryReader reader) {
            var data = reader.ReadString().Split(',');
            name = data[0];
            appartament = int.Parse(data[1]);
            isMale = bool.Parse(data[2]);
        }

        public string Name {
            get { return name; }
            set { name = value; }
        }

        public int Appartament {
            get { return appartament; }
            set { appartament = value; }
        }

        public bool IsMale {
            get { return isMale; }
            set { isMale = value; }
        }

        public override string ToString() {
            return $"{name},{appartament},{isMale}";
        }
    }
}
