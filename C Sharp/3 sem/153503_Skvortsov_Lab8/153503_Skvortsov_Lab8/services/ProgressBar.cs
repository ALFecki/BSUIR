using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _153503_Skvortsov_Lab8.services {
    public class ProgressBar : IProgress<int> {
        public void Report(int value) {
            (int left, int right) = Console.GetCursorPosition();
            Console.SetCursorPosition(0, 25);
            Console.WriteLine($"Thread {Thread.CurrentThread.ManagedThreadId}: {value}%");
            Console.SetCursorPosition(left, right);
        }

        public void Report(int value, int total, int cursorPosition) {
            (int left, int right) = Console.GetCursorPosition();
            Console.SetCursorPosition(0, cursorPosition);
            Console.WriteLine($"Thread {Thread.CurrentThread.ManagedThreadId}: {value}/{total}");
            Console.SetCursorPosition(left, right);
            Thread.Sleep(50);
        }
    }
}