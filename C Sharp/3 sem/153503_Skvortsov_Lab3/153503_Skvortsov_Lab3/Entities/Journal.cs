namespace _153503_Skvortsov_Lab3.Entities {
    internal class Journal {

        private List<string> _journal;

        public Journal() {
            _journal = new List<string>();
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
