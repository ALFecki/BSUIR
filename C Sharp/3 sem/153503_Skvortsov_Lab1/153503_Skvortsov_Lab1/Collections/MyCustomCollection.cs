using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using _153503_Skvortsov_Lab1.Interfaces;

namespace _153503_Skvortsov_Lab1.Collections
{
    public class MyCustomCollection<T> : ICustomCollection<T>
    {
        private T[]? collection;
        private int currentPosition;
        private int elementsCount;

        public MyCustomCollection() {
            collection = new T[5];
            currentPosition = -1;
            elementsCount = 0;
        }

        public MyCustomCollection(int length) {
            collection = new T[length];
            currentPosition = -1;
            elementsCount = 0;
        }

        public MyCustomCollection(T[] item) {
            collection = new T[item.Length];
            collection = item;
            currentPosition = 0;
            elementsCount = collection.Length;
        }
        public T this[int index] {
            get {
                if (index < 0 || index >= collection.Length) {
                    throw new IndexOutOfRangeException();
                } else {
                    return collection[index];
                }
            }
            set {
                if (index < 0 || index >= collection.Length) {
                    throw new IndexOutOfRangeException();
                }
                else {
                    collection[index] = value;
                    elementsCount++;
                }
            }
        }

        public int Count {
            get {
                return elementsCount;
            }
        }

        public void Reset() {
            currentPosition = -1;
        }

        public void Next() {
            if (currentPosition < collection.Length - 1)
                currentPosition++;
        }
        public T Current() {
            if (currentPosition < 0 || currentPosition >= collection.Length)
                throw new IndexOutOfRangeException();
            return collection[currentPosition];
        }
        public void Add(T item) {
            if (elementsCount + 1 > collection.Length) {
                T[] newCollection = new T[collection.Length + 5];
                for (int i = 0; i < elementsCount; i++) {
                    newCollection[i] = collection[i];
                }
                collection = newCollection;
            }
            collection[elementsCount] = item;
            elementsCount++;
        }

        public int Find(T item) {
            for (int i = 0; i < collection.Length; i++)
            {
                if (collection[i].Equals(item))
                {
                    return i;
                }
            }
            return -1;
        }
        public void Remove(T item) {
            int index = Find(item);
            if (index == -1)
                throw new ArgumentException();
            T[] newCollection = new T[collection.Length - 1];
            for (int i = 0; i < elementsCount; i++) {
                if (i == index)
                    continue;
                newCollection[i] = collection[i];
            }
            collection = newCollection;
            elementsCount--;
        }

        public void Remove(int index) {
            if (index < 0 || index >= collection.Length) {
                throw new IndexOutOfRangeException();
            }
            Remove(collection[index]);
        }
        public T RemoveCurrent() {

            if (currentPosition < 0 || currentPosition >= collection.Length)
                throw new IndexOutOfRangeException();
            T element = collection[currentPosition];
            Remove(element);
            return element;
        }

        public void Print() {
            foreach (var item in collection) {
                Console.WriteLine(item.ToString() + ' ');
            }
        }
        
    }
}



/*        using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using _153503_Skvortsov_Lab1.Interfaces;

namespace _153503_Skvortsov_Lab1.Collections
    {
        public class MyCustomCollection<T> : ICustomCollection<T>
        {
            private T[] collection;
            private int currentPosition;

            public MyCustomCollection()
            {
                collection = new T[0];
                currentPosition = -1;
            }

            public T this[int index]
            {
                get
                {
                    if (index < 0 || index >= collection.Length)
                        throw new IndexOutOfRangeException();
                    return collection[index];
                }
                set
                {
                    if (index < 0 || index >= collection.Length)
                        throw new IndexOutOfRangeException();
                    collection[index] = value;
                }
            }

            public int Count
            {
                get { return collection.Length; }
            }

            public void Reset()
            {
                currentPosition = -1;
            }

            public void Next()
            {
                if (currentPosition < collection.Length - 1)
                    currentPosition++;
            }

            public T Current()
            {
                if (currentPosition < 0 || currentPosition >= collection.Length)
                    throw new IndexOutOfRangeException();
                return collection[currentPosition];
            }

            public void Add(T item)
            {
                T[] newCollection = new T[collection.Length + 1];
                for (int i = 0; i < collection.Length; i++)
                    newCollection[i] = collection[i];
                newCollection[collection.Length] = item;
                collection = newCollection;
            }

            public void Remove(T item)
            {
                int index = -1;
                for (int i = 0; i < collection.Length; i++)
                    if (collection[i].Equals(item))
                    {
                        index = i;
                        break;
                    }
                if (index == -1)
                    throw new ArgumentException();
                T[] newCollection = new T[collection.Length - 1];
                for (int i = 0; i < index; i++)
                    newCollection[i] = collection[i];
                for (int i = index + 1; i < collection.Length; i++)
                    newCollection[i - 1] = collection[i];
                collection = newCollection;
            }

            public T RemoveCurrent()
            {
                if (currentPosition < 0 || currentPosition >= collection.Length)
                    throw new IndexOutOfRangeException();
                T item = collection[currentPosition];
                T[] newCollection = new T[collection.Length - 1];
                {

                }
            }*/
