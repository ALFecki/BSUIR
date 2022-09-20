namespace _153503_Skvortsov_Lab1.Interfaces {
    public interface ICustomCollection<T> {
        public T this[int index] { get; set; }
        public int Count { get; }
        public void Reset();
        public void Next();
        public T Current();
        public void Add(T item);
        public void Remove(T item);
        public T RemoveCurrent();



    }
}
