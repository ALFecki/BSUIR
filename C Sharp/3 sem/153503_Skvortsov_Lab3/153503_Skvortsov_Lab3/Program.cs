using _153503_Skvortsov_Lab3.Entities;

namespace _153503_Skvortsov_Lab3 {
    class Program {
        static void Main(string[] args) {
            ATS ats = new ATS();
            ats.RegisterClient(new Client("Ivan"));
            ats.RegisterClient(new Client("Petr"));
            ats.RegisterClient(new Client("Sidor"));
            ats.RegisterTariff(new Tariff("Tariff1", 10));
            ats.RegisterTariff(new Tariff("Tariff2", 20));
            ats.RegisterTariff(new Tariff("Tariff3", 30));
            ats.RegisterCall("Ivan", 10, "Tariff1");
            ats.RegisterCall("Ivan", 20, "Tariff2");
            ats.RegisterCall("Ivan", 30, "Tariff3");
            ats.RegisterCall("Petr", 10, "Tariff1");
            ats.RegisterCall("Petr", 20, "Tariff2");
            ats.RegisterCall("Petr", 30, "Tariff3");
            ats.RegisterCall("Sidor", 10, "Tariff1");
            ats.RegisterCall("Sidor", 20, "Tariff2");
            ats.RegisterCall("Sidor", 30, "Tariff3");
            ats.RegisterCall("Ivan", 10, "Tariff1");
            ats.PrintClientTariffes("Ivan");
            ats.PrintClientTariffes("Petr");
            ats.PrintClientTariffes("Sidor");
            Console.WriteLine("Ivan call cost: " + ats.ClientCallsCost("Ivan"));
            Console.WriteLine("Petr call cost: " + ats.ClientCallsCost("Petr"));
            Console.WriteLine("Sidor call cost: " + ats.ClientCallsCost("Sidor"));
            Console.WriteLine("All calls cost: " + ats.AllCallsCost());
        }
    }
}
