
namespace _153503_Skvortsov_Lab3.Entities {
    public class Client {
        private string name;
        private int callsNumber;
        private List<Tariff> tariffs;
        private List<(Tariff, double)> calls_list;

        public Client(string name) {
            this.name = name;
            this.tariffs = new List<Tariff>();
            this.calls_list = new List<(Tariff, double)>();
        }

        public void RegisterCall(double minutes, Tariff tariff) {
            callsNumber++;
            calls_list.Add((tariff, minutes));
            tariffs.Add(tariff);
        }

        public double CallsCost() {
            double cost = 0;
            calls_list.Sum(x => cost += (x.Item1.Cost * x.Item2));
            return cost;
        }

        public IEnumerable<(Tariff, double)> GruopTariffesBySum() {
            return calls_list.GroupBy(x => x.Item1)
                .Select(x => (x.Key, x.Sum(y => y.Item2 * y.Item1.Cost)));
        }

        public List<(Tariff, double)> TariffesSum() {
            var result = new List<(Tariff, double)>();
            foreach (var tariff in tariffs) {
                var sum = calls_list.Where(x => x.Item1 == tariff).Sum(x => x.Item2);
                result.Add((tariff, sum));
            }
            return result.GroupBy(x => x.Item2).Select(x => x.First()).ToList();
        }

        public string Name { get { return this.name; } }
        public int CallsNumber { get { return this.callsNumber; } }

    }
}
