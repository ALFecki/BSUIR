using _153503_Skvortsov_Lab2.Collections;

namespace _153503_Skvortsov_Lab2.Entities {
    internal class Journal {

        private DoublyLinked<string> _journal;

        public Journal() {
            _journal = new DoublyLinked<string>();
        }

        public void Add(string message) {
            _journal.Add(message);
        }

        public void Print() {           
            foreach (var item in _journal) {
                Console.WriteLine(item);
            }
        }

    }
}
