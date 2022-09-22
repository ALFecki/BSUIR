using _153503_Skvortsov_Lab2.Collections;

namespace _153503_Skvortsov_Lab2.Entities {
    public class Client {
        private string name;
        private int callsNumber;
        private DoublyLinked<double> calls;


        public Client(string name) {
            this.name = name;
            this.calls = new DoublyLinked<double>();
        }
        public Client(string name, int callsNumber, double[] calls) {
            this.name = name;
            this.callsNumber = callsNumber;
            this.calls = new DoublyLinked<double>(calls);
        }

        public void RegisterCall(double minutes, Tariff tariff) {
            callsNumber++;
            calls.Add(minutes * tariff.Cost);
        }

        public void PrintMinutes() {
            calls.Print();
        }

        public double NeddedMoney() {
            double sum = 0;
            for (int i = 0; i < callsNumber; i++) {
                sum += calls[i];
            }
            return sum;
        }

        public string Name { get { return this.name; } }
        public int CallsNumber { get { return this.callsNumber; } }

    }
}
