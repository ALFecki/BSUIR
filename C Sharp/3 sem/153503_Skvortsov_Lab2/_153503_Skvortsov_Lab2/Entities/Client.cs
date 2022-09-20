using _153503_Skvortsov_Lab1.Collections;

namespace _153503_Skvortsov_Lab1.Entities {
    public class Client {
        private string name;
        private int callsNumber;
        private DoublyLinked<double> callMinutes;
        private Tariff tariff;


        public Client(string name, Tariff tariff) {
            this.name = name;
            this.tariff = tariff;
            this.callMinutes = new DoublyLinked<double>();
        }
        public Client(string name, int callsNumber, double[] callMinutes, Tariff tariff) {
            this.name = name;
            this.callsNumber = callsNumber;
            this.callMinutes = new DoublyLinked<double>(callMinutes);
            this.tariff = tariff;
        }

        public void RegisterCall(double minutes) {
            callsNumber++;
            Console.WriteLine("minutes " + minutes.ToString());
            callMinutes.Add(minutes);
        }

        public void PrintMinutes() {
            callMinutes.Print();
        }

        public double NeddedMoney() {
            double sum = 0;
            for (int i = 0; i < callsNumber; i++) {
                sum += callMinutes[i] * tariff.Cost;
            }
            return sum;
        }

        public string Name { get { return this.name; } }
        public int CallsNumber { get { return this.callsNumber; } }

    }
}
