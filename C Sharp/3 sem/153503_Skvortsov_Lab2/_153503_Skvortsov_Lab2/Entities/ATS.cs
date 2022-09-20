using _153503_Skvortsov_Lab1.Collections;

namespace _153503_Skvortsov_Lab1.Entities {
    public class ATS {
        public DoublyLinked<Client> clients;
        public DoublyLinked<Tariff> tariffes;

        public ATS(DoublyLinked<Client> clients, DoublyLinked<Tariff> tariffes) {
            this.clients = clients;
            this.tariffes = tariffes;
        }
        public double Cost() {
            double sum = 0;
            clients.Reset();
            for (int i = 0; i < clients.Count; i++) {
                sum+=clients.Current().NeddedMoney();
                clients.Next();
            }
            return sum;
        }
    }
}
