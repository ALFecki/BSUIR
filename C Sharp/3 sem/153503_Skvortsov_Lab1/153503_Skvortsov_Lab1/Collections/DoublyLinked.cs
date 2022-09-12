using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using _153503_Skvortsov_Lab1.Interfaces;

namespace _153503_Skvortsov_Lab1.Collections {
    public class DoublyLinked<T> : ICustomCollection<T> {
        private DoublyNode<T> head;
        private DoublyNode<T> tail;
        private DoublyNode<T> current;
        private int count;

        public DoublyLinked() {
            head = null;
            tail = null;
            current = null;
            count = 0;

        }

        public DoublyLinked(T item) {
            head = new DoublyNode<T>(item);
            tail = head;
            current = head;
            count = 1;
        }

        public DoublyLinked(T[] items) {
            head = new DoublyNode<T>(items[0]);
            tail = head;
            current = head;
            count = 1;
            for (int i = 1; i < items.Length; i++) {
                Add(items[i]);
            }
        }

        public T this[int index] {
            get {
                if (index < 0 || index >= count)
                    throw new IndexOutOfRangeException();

                current = head;
                for (int i = 0; i < index; i++) {
                    current = current.Next;
                }
                return current.Data;
            }

            set {
                if (index < 0 || index >= count)
                    throw new IndexOutOfRangeException();
                current = head;

                for (int i = 0; i < index; i++) {
                    current = current.Next;
                }
                current.Data = value;
            }
        }

        public int Count { get { return this.count; } }

        public void Reset() {
            current = head;
        }

        public void Next() {
            if (current.Next != null)
                current = current.Next;
            else
                throw new IndexOutOfRangeException();
        }

        public T Current() {
            return current.Data;
        }

        public void Add(T item) {
            if (head == null) {
                head = new DoublyNode<T>(item);
                tail = head;
                current = head;
                count = 1;
            }
            else {
                DoublyNode<T> newNode = new DoublyNode<T>(item);
                tail.Next = newNode;
                newNode.Prev = tail;
                tail = newNode;
                count++;
            }
        }

        public void Remove(T item) {
            if (head == null)
                throw new IndexOutOfRangeException();
            current = head;
            for (int i = 0; i < count; i++) {
                if (current.Data.Equals(item)) {
                    if (current == head) {
                        head = current.Next;
                        current = head;
                    }
                    else if (current == tail) {
                        tail = current.Prev;
                        tail.Next = null;
                    }
                    else {
                        current.Prev.Next = current.Next;
                        current.Next.Prev = current.Prev;
                    }
                    count--;
                    return;
                }
                current = current.Next;
            }
        }

        public T RemoveCurrent() {
            if (head == null)
                throw new IndexOutOfRangeException();
            T res = current.Data;
            Remove(res);
            return res;
        }

        public void Print() {
            current = head;
            for (int i = 0; i < count; i++) {
                Console.WriteLine(current.Data.ToString());
                current = current.Next;
            }
        }
    }
    
}
