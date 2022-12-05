using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;

namespace _153503_Skvortsov_Lab7.src.services {
    public class IntegralService {

        delegate void CalculationDelegate();
        event CalculationDelegate CalculationEvent;

        public static Semaphore semaphore = new Semaphore(2, 2);

        public Thread thread;
        
        public int Progress { get; set; }
        public double Result { get; set; }
        public int ThreadNumber { get; set; }

        public IntegralService(ThreadPriority priority = ThreadPriority.Normal, int number = 0) {
            CalculationEvent += ProgressBar;
            Result = 0;
            Progress = 0;
            thread = new Thread(Calculation);
            thread.Priority = priority;
            ThreadNumber = number;
            thread.Start();
        }

        public void Calculation() {

            Console.WriteLine("Thread {0} waiting for start", ThreadNumber);
            semaphore.WaitOne();
            Stopwatch timer = new Stopwatch();
            timer.Start();
            Console.WriteLine("Thread {0} started", ThreadNumber);

            double delta = 0.0000001;
            Progress = 0;
            Result = 0;

            for (double i = 0; i < 1; i += delta) {
                
                Result += Math.Sin(i) * delta;
                Progress = (int)(i / 1.0 * 100);
                int buf = 0;
                for (int j = 0; j < 100; j++) {
                    buf = j * (j + 1);
                }
            
            }

            
            Console.WriteLine("Thread {0} finished in {1} ms", ThreadNumber, timer.ElapsedMilliseconds);
            Progress = 100;
            timer.Stop();
            Console.WriteLine("Result = {0}", Result);
            semaphore.Release();
        }


        
        public void ProgressBar() {
            int partsNumber = Progress;
            string bar = "[";
            
            for (int i = 0; i < 100; i++) {
                
                if (i < partsNumber) {
                    bar += "=";
                }
                else if (i == partsNumber) {
                    bar += ">";
                }
                else {
                    bar += " ";
                }                
            }
            bar += "]";
            Console.WriteLine("Thread {0}:{1} {2}%", ThreadNumber, bar, partsNumber);

        }
    }
}
