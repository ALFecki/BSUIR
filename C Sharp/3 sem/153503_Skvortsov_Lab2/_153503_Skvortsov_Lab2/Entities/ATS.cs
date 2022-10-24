using _153503_Skvortsov_Lab2.Collections;

namespace _153503_Skvortsov_Lab2.Entities {
    public class ATS {
        private DoublyLinked<Client> clients;
        private DoublyLinked<Tariff> tariffes;
        public delegate void ATSHandler(string message);
        public event ATSHandler Notify;
        Journal journal = new Journal();

        

        public ATS() {
            clients = new DoublyLinked<Client>();
            tariffes = new DoublyLinked<Tariff>();
            Notify += AddMessage;
        }

        public ATS(DoublyLinked<Client> clients, DoublyLinked<Tariff> tariffes) {
            this.clients = clients;
            this.tariffes = tariffes;
            Notify += AddMessage;
        }

        public void RegisterTariff(Tariff tariff) {
            Notify?.Invoke($"Registered tariff: {tariff.Name}");
            tariffes.Add(tariff);
        }

        public void RegisterClient(Client client) {
            Notify?.Invoke($"Registered client: {client.Name}");
            clients.Add(client);
        }

        public void RegisterCall(string name, double minutes, string tariffName) {
            Client? client = FindClient(name);
            Tariff? tariff = FindTariff(tariffName);
            if (client != null && tariff != null) {
                client.RegisterCall(minutes, tariff);
            }
            else {
                Console.WriteLine("Client or tariff not found");
            }
        }

        public Client? FindClient(string name) {
            clients.Reset();
            while (clients.Current() != null) {
                Client client = clients.Current();
                if (client.Name == name) {
                    return client;
                }
                clients.Next();
            }
            return null;
        }

        public Tariff? FindTariff(string name) {
            tariffes.Reset();
            while (tariffes.Current() != null) {
                Tariff tariff = tariffes.Current();
                if (tariff.Name == name) {
                    return tariff;
                }
                tariffes.Next();
            }
            return null;
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

        void AddMessage(string message) {
            journal.Add(message);
            /*Console.WriteLine(message);*/
        }

        public void PrintJournal() {
            journal.Print();
        }

    }
}
