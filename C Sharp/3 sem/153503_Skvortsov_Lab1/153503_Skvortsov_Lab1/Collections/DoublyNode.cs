using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _153503_Skvortsov_Lab1.Collections {
    public class DoublyNode<T> {
        private T data;
        private DoublyNode<T> next;
        private DoublyNode<T> prev;

        public DoublyNode(T data) {
            this.data = data;
            next = null;
            prev = null;
        }

        public DoublyNode(T data, DoublyNode<T> next, DoublyNode<T> prev) {
            this.data = data;
            this.next = next;
            this.prev = prev;
        }

        public T Data { get { return this.data; } set { this.data = value; } }
        public DoublyNode<T> Next { get { return this.next; } set { this.next = value; } }
        public DoublyNode<T> Prev { get { return this.prev; } set { this.prev = value; } }

    }
}
