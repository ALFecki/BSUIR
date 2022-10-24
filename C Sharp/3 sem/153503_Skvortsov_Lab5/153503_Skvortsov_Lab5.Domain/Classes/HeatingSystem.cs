namespace _153503_Skvortsov_Lab5.Domain.Classes {
    public class HeatingSystem {

        public string Description { get; set; }
        public bool IsEnabled { get; set; }
        public int Temperature { get; set; }
        
        public HeatingSystem() { }

        public HeatingSystem(string description, bool isEnabled, int temperature) {
            this.Description = description;
            this.IsEnabled = isEnabled;
            this.Temperature = temperature;
        }


    }
}