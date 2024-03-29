﻿using _153503_Skvortsov_Lab6.Interfaces;
using System.Text.Json;

namespace Services {
    public class FileService<T> : IFileService<T> where T : class {
        public IEnumerable<T>? ReadFile(string fileName) {
            return JsonSerializer.Deserialize<IEnumerable<T>>(File.ReadAllText(fileName));
        }

        public void SaveData(IEnumerable<T> data, string fileName) {
            File.WriteAllText(fileName, JsonSerializer.Serialize(data));
        }
    }

}