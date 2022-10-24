using System;
using _153503_Skvortsov_Lab5.Domain.Classes;
using _153503_Skvortsov_Lab5.Domain.Interfaces;
using System.Xml.Linq;
using System.Xml.Serialization;
using System.Text.Json;

namespace SerializerNS {
    public class Serializer : ISerializer<Building> {

        public Serializer() {
            
        }

        public void SerializeByLINQ(IEnumerable<Building> buildings, string fileName) {
            XDocument doc = new XDocument();
            XElement root = new XElement("Buildings");
            foreach (var building in buildings) {
                XElement buildingElement = new XElement("Building");
                buildingElement.Add(new XElement("Address", building.Address));
                buildingElement.Add(new XElement("NumberOfAppartments", building.NumberOfAppartments));
                buildingElement.Add(new XElement("Description", building.heatingSystem.Description));
                buildingElement.Add(new XElement("IsEnabled", building.heatingSystem.IsEnabled));
                buildingElement.Add(new XElement("Temperature", building.heatingSystem.Temperature));
                root.Add(buildingElement);
            }
            doc.Add(root);
            doc.Save(fileName);

        }
        public void SerializeXML(IEnumerable<Building> buildings, string fileName) {
            XmlSerializer serializer = new XmlSerializer(typeof(List<Building>));
            using (var stream = new FileStream(fileName, FileMode.Create)) {
                serializer.Serialize(stream, buildings);
            }
        }

        public void SerializeJSON(IEnumerable<Building> buildings, string fileName) {
            File.WriteAllText(fileName, JsonSerializer.Serialize(buildings));
        }



        public IEnumerable<Building>? DeSerializeByLINQ(string fileName) {
            XDocument doc = XDocument.Load(fileName);
            XElement? root = doc.Element("Buildings");
            List<Building> buildings = new();
            foreach (var buildingElement in root.Elements("Building")) {
                Building building = new Building();
                building.Address = buildingElement.Element("Address").Value;
                building.NumberOfAppartments = int.Parse(buildingElement.Element("NumberOfAppartments").Value);
                building.heatingSystem = new HeatingSystem(
                    buildingElement.Element("Description").Value,
                    bool.Parse(buildingElement.Element("IsEnabled").Value),
                    int.Parse(buildingElement.Element("Temperature").Value)
                    );
                buildings.Add(building);
            }
            return buildings;
        }

        public IEnumerable<Building>? DeSerializeXML(string fileName) {
            XmlSerializer serializer = new XmlSerializer(typeof(List<Building>));
            using (var stream = new FileStream(fileName, FileMode.Open)) {
                return (List<Building>)serializer.Deserialize(stream);
            }
        }

        public IEnumerable<Building>? DeSerializeJSON(string fileName) {
            return JsonSerializer.Deserialize<List<Building>>(File.ReadAllText(fileName));
        }

    }
}