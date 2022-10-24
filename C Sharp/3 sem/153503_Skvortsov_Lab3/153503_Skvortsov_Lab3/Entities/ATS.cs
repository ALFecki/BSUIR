namespace _153503_Skvortsov_Lab3.Entities {
    public class ATS {
        private List<Client> clients;
        private Dictionary<string, Tariff> tariffes;
        public delegate void ATSHandler(string message);
        public event ATSHandler Notify;
        Journal journal = new Journal();

        

        public ATS() {
            clients = new List<Client>();
            tariffes = new Dictionary<string, Tariff>();
            Notify += AddMessage;
        }

        public ATS(List<Client> clients, Dictionary<string, Tariff> tariffes) {
            this.clients = clients;
            this.tariffes = tariffes;
            Notify += AddMessage;
        }

        public void RegisterTariff(Tariff tariff) {
            Notify?.Invoke($"Registered tariff: {tariff.Name}");
            tariffes.Add(tariff.Name, tariff);
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
            return clients.Select(c => c).FirstOrDefault(c => c.Name == name);
        }

        public Tariff? FindTariff(string name) {
            return tariffes.Select(t => t.Value).Where(t => t.Name == name).FirstOrDefault();
        }

        public List<Tariff> TariffesByCost() {
            return tariffes.Values.OrderBy(tariff => tariff.Cost).ToList();
        }

        public double AllCallsCost() {
            return clients.Sum(client => client.CallsCost());
        }

        public void PrintClientTariffes(string name) {
            Client? client = FindClient(name);
            if (client != null) {
                foreach (var tariff in client.GruopTariffesBySum()) {
                    Console.WriteLine($"Tariff: {tariff.Item1.Name}, sum: {tariff.Item2}");
                }
            }
            else {
                Console.WriteLine("Client not found");
            }

        }

        public double ClientCallsCost(string name) {
            Client? client = FindClient(name);
            if (client != null) {
                return client.CallsCost();
            }
            else {
                Console.WriteLine("Client not found");
                return 0;
            }
        }

        public string MaxClientCost() {
            return clients.Select(c => c).OrderByDescending(c => c.CallsCost()).FirstOrDefault().Name;
        }

        int ClientsCount(double sum) {
            return clients.Aggregate(0, (count, client) => count + (client.CallsCost() > sum ? 1 : 0));
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
