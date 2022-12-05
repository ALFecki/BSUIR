using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Text.Json;

namespace _153503_Skvortsov_Lab8.services {
    public class StreamService<T> {

        public object locker = new object();


        public void ProgressBar(int progress, int total) {
            int percent = (int)(((double)progress / (double)total) * 100);
            Console.Write("\r{0}% complete", percent);
        }

        public StreamService() {
            Console.WriteLine($"Starting StreamService with thread {Thread.CurrentThread.ManagedThreadId}");

        }

        public void LogMessage(string message) {
            Console.WriteLine(message);
        }

        public async Task WriteToStreamAsync(Stream stream, IEnumerable<T> data) {
            var progress = new ProgressBar();
            await Task.Run(() => {
                lock (locker) {
                    LogMessage($"Writing to stream is started with thread {Thread.CurrentThread.ManagedThreadId}");

                    stream.Seek(0, SeekOrigin.Begin);
                    var writer = new StreamWriter(stream);
                    foreach (var item in data) {
                        writer.WriteLine(JsonSerializer.Serialize(item));
                        progress.Report(data.ToList().IndexOf(item) + 1, data.Count(), 25);
                        /*Thread.Sleep(100);*/

                    }
                    writer.Flush();
                }
            });
            LogMessage($"Stream writing finished successful");
        }

        public async Task CopyFromStreamAsync(Stream stream, string filename) {
            var progressBar = new ProgressBar();
            await Task.Run(() => {
                lock (locker) {
                    LogMessage($"Copying to file is started with thread {Thread.CurrentThread.ManagedThreadId}");
                    stream.Seek(0, SeekOrigin.Begin);
                    var reader = new StreamReader(stream);

                    var writer = new StreamWriter(filename);
                    while (!reader.EndOfStream) {
                        var line = reader.ReadLine();
                        progressBar.Report(Convert.ToInt32(reader.BaseStream.Position), Convert.ToInt32(reader.BaseStream.Length), 26);
                        writer.WriteLine(line);
                    }
                    /*reader.Close();*/
                    writer.Flush();
                    writer.Close();
                }

            });
            LogMessage($"File copying finished successful");
        }

        public async Task<int> GetStatisticAsync(string filename, Func<T, bool> filter) {
            int count = 0;
            await Task.Run(() => {
                LogMessage($"Get stats is started with thread {Thread.CurrentThread.ManagedThreadId}");
                var reader = new StreamReader(filename);
                while (!reader.EndOfStream) {
                    var line = reader.ReadLine();
                    var item = JsonSerializer.Deserialize<T>(line);
                    if (filter(item)) {
                        count++;
                    }
                }

            });
            return count;
        }
    };
}
