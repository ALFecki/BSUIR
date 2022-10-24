using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using _153503_Skvortsov_Lab5.Domain.Classes;

namespace _153503_Skvortsov_Lab5.Domain.Interfaces {
    public interface ISerializer<T> {
        IEnumerable<T>? DeSerializeByLINQ(string fileName);
        IEnumerable<T>? DeSerializeXML(string fileName);
        IEnumerable<T>? DeSerializeJSON(string fileName);
        
        void SerializeByLINQ(IEnumerable<T> buildings, string fileName);
        void SerializeXML(IEnumerable<T> buildings, string fileName);
        void SerializeJSON(IEnumerable<T> buildings, string fileName);


    }
}
