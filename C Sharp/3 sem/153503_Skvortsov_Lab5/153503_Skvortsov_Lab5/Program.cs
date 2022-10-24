
using _153503_Skvortsov_Lab5.Domain.Classes;
using SerializerNS;

namespace _153503_Skvortsov_Lab5 {
    class Program {
        static void Main(string[] args) {
            var buildings = new List<Building> {
                new Building {
                    Address = "Lenina 1",
                    NumberOfAppartments = 10,
                    heatingSystem = new HeatingSystem {
                        Description = "Central",
                        IsEnabled = true,
                        Temperature = 20
                    }
                },
                new Building {
                    Address = "Lenina 2",
                    NumberOfAppartments = 10,
                    heatingSystem = new HeatingSystem {
                        Description = "Central",
                        IsEnabled = true,
                        Temperature = 20
                    }
                },
                new Building {
                    Address = "Lenina 3",
                    NumberOfAppartments = 10,
                    heatingSystem = new HeatingSystem {
                        Description = "Central",
                        IsEnabled = true,
                        Temperature = 20
                    }
                }
            };
            var serializer = new Serializer();
            serializer.SerializeByLINQ(buildings, "buildings.xml");
            serializer.SerializeXML(buildings, "buildings_1.xml");
            serializer.SerializeJSON(buildings, "buildings_2.json");
            var buildings2 = serializer.DeSerializeByLINQ("buildings.xml");
            var buildings3 = serializer.DeSerializeXML("buildings_1.xml");
            var buildings4 = serializer.DeSerializeJSON("buildings_2.json");
            foreach (var building in buildings2) {
                building.Print();
            }
            Console.WriteLine("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
            foreach (var building in buildings3) {
                building.Print();
            }
            Console.WriteLine("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
            foreach (var building in buildings4) {
                building.Print();
            }

        }
    }
}