using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using _153503_Skvortsov_Lab4.Interfaces;
using _153503_Skvortsov_Lab4.Entities;

namespace _153503_Skvortsov_Lab4.Utils {
    internal class FileService<T> : IFileService<T> {
        public IEnumerable<T?> ReadFile(string fileName) {
            using(BinaryReader reader = new BinaryReader(new FileStream(fileName, FileMode.Open))) {
                while (reader.PeekChar() > -1) {
                    yield return (T?)Activator.CreateInstance(typeof(T), reader);
                }
            }
        }

        public void SaveData(IEnumerable<T> data, string fileName) {
            using (BinaryWriter writer = new BinaryWriter(new FileStream(fileName, FileMode.Create))) {
                foreach (var item in data) {
                    writer.Write(item.ToString());
                }
            }
        }
    }
}

