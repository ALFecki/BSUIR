using _153503_Skvortsov_Lab8.entities;
using _153503_Skvortsov_Lab8.services;

class Program {
    static async Task Main(string[] args) {
        var patients = new List<Patient>();
        string[] ills = { "Flu", "Cancer", "AIDS", "Covid-19" };
        Random random = new Random();
        for (int i = 1; i <= 100; i++) {
            patients.Add(new Patient() {
                Id = i,
                Name = $"Patient {i}",
                Ill = ills[random.Next(0, ills.Length)]
            });
        }
        var streamService = new StreamService<Patient>();
        var memoryStream = new MemoryStream();
        var task1 = streamService.WriteToStreamAsync(memoryStream, patients);
        Thread.Sleep(200);
        var task2 = streamService.CopyFromStreamAsync(memoryStream, "patients.txt");

        Task.WaitAll(task1, task2);

        var count = await streamService.GetStatisticAsync("patients.txt", x => x.Ill.Equals("Flu"));
        Console.WriteLine($"Count of patients with flu is {Convert.ToInt32(count)}");

    }
}