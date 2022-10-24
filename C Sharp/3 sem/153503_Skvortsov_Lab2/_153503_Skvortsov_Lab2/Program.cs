using _153503_Skvortsov_Lab2.Entities;


class Program {
    delegate void RegisterCallDelegate(double minutes, Tariff tariff);
    static event RegisterCallDelegate? RegisterCallEvent;
    static Journal journal;

    static void RegisterCall(double minutes, Tariff tariff) {
        string message = "Registering call, minutes: " + minutes.ToString() + ", tariff: " + tariff.Name;
        /*Console.WriteLine(message);*/
        journal.Add(message);

    }


    static void Main(string[] args) {
        RegisterCallEvent += RegisterCall;
        ATS ats = new ATS();
        journal = new Journal();

        ats.Notify+= journal.Add;// .AddMessage;

        ats.RegisterTariff(new Tariff("Standart", 1));
        ats.RegisterTariff(new Tariff("Premium", 2));
        ats.RegisterTariff(new Tariff("VIP", 3));

        ats.RegisterClient(new Client("Ivan"));
        ats.RegisterClient(new Client("Petr"));
        ats.RegisterClient(new Client("Sidor"));

        ats.RegisterCall("Ivan", 10, "Standart");
        RegisterCallEvent?.Invoke(10, new Tariff("Standart", 1));
        ats.RegisterCall("Ivan", 20, "Standart");
        RegisterCallEvent?.Invoke(20, new Tariff("Standart", 1));
        ats.RegisterCall("Petr", 30, "Premium");
        RegisterCallEvent?.Invoke(30, new Tariff("Premium", 2));

        Console.WriteLine("Program journal: ");
        journal.Print();

        Console.WriteLine("ATS journal: ");
        ats.PrintJournal();
    }
}
