using System.Collections;

namespace _153503_Skvortsov_Lab2.Interfaces {
    public interface ICustomCollection<T> : IEnumerator<T>, IEnumerable {
        public T this[int index] { get; set; }
        public int Count { get; }
        public void Reset();
        public void Next();
        public T Current();
        public void Add(T item);
        public void Remove(T item);
        public T RemoveCurrent();
        /*public IEnumerable<T>? GetEnumerator();*/
        object IEnumerator.Current => this.Current();
        T IEnumerator<T>.Current => this.Current();
        bool IEnumerator.MoveNext() {
            this.Next();
            return this.Current() != null;
        }
        public void Dispose();
    }
}
