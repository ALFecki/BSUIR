using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _153503_Skvortsov_Lab4.Utils {
    internal class MyCustomComparer<T> : IComparer<T> {
        public int Compare(T? x, T? y) {
            if (x == null && y == null)
                return -1;
            if (x == null)
                return 0;
            if (y == null)
                return -1;
            return x.ToString().CompareTo(y.ToString());

        }
    }
}
