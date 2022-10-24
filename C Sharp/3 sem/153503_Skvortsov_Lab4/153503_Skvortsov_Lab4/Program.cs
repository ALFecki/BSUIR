using _153503_Skvortsov_Lab4.Utils;
using _153503_Skvortsov_Lab4.Entities;

namespace _153503_Skvortsov_Lab4 {
    class Program {
        static void Main(string[] args) {
            FileService<People> fileService = new FileService<People>();
            try {
                FileInfo fileToWrite = new FileInfo("PeopleFile.txt");
                if (fileToWrite.Exists) {
                    File.Delete("PeopleFile.txt");
                }
            }
            catch (Exception) {

                throw (new Exception("Error found file file"));
            }   

            List<People> people = new List<People>();
            people.Add(new People("Ivan", 20, true));
            people.Add(new People("Elena", 15, false));
            people.Add(new People("Pavel", 15, true));
            people.Add(new People("Anastasia", 78, false));
            people.Add(new People("Andrey", 141, true));
            people.Add(new People("Vladislav", 1, true));
            
            try {
                File.Create("People.txt").Close();
                fileService.SaveData(people.AsEnumerable(), "People.txt");
            }
            catch (Exception) {

                throw (new Exception("Error saving data"));
            }


            try {
                FileInfo fileToRead = new FileInfo("People.txt");
                if (fileToRead.Exists) {
                    File.Move("People.txt", "PeopleFile.txt");
                    Console.WriteLine("File renamed");
                    File.Delete("People.txt");
 
                }

            }
            catch (Exception) {

                throw(new Exception("Error renaming file"));
            }

            IEnumerable<People> newPeople;
            MyCustomComparer<People> comparer;
            List<People> sorted;
            
            try {
                newPeople = fileService.ReadFile("PeopleFile.txt");

            }
            catch (Exception) {

                throw(new Exception("Error reading file"));
            }

            comparer = new MyCustomComparer<People>();
            sorted = newPeople.OrderBy(x => x, comparer).ToList<People>();

            Console.WriteLine("Unsorted list:");
            foreach (var man in newPeople) {
                Console.WriteLine($"Name: {man.Name}\n Apartament: {man.Appartament}\n isMale: {man.IsMale}");
            }

            Console.WriteLine("\n****************************************************\n");

            Console.WriteLine("Sorted list:");
            foreach (var man in sorted) {
                Console.WriteLine($"Name: {man.Name}\n Apartament: {man.Appartament}\n isMale: {man.IsMale}");
            }

            sorted = newPeople.OrderBy(x => x.Appartament).ToList<People>();

            Console.WriteLine("\n****************************************************\n");

            Console.WriteLine("Sorted by appartament list:");
            foreach (var man in sorted) {
                Console.WriteLine($"Name: {man.Name}\n Apartament: {man.Appartament}\n isMale: {man.IsMale}");
            }

        }
    }
}
