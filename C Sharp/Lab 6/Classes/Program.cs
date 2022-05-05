using Classes;


namespace Classes
{
    public class Program
    {
        public static void Main(string[] args)
        {
            Flower rose = new Rose("Rose", "Holland", 2, "Red");
            rose.Info();
            Console.WriteLine("");
            rose.PrintData();
            Console.WriteLine("");
            rose.GetSeeds(25);
            Console.WriteLine("");



            Flower chamomile = new Chamomile("Chamomile", "Russia", 3, 43);
            chamomile.Info();
            Console.WriteLine("");
            chamomile.PrintData();
            Console.WriteLine("");
            chamomile.GetSeeds(65);
            Console.WriteLine("");
            chamomile.GetSeeds(23);
        }
    }
}