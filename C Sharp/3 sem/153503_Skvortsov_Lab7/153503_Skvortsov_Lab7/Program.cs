using _153503_Skvortsov_Lab7.src.services;


IntegralService integral1 = new IntegralService(ThreadPriority.Highest, 1);
IntegralService integral2 = new IntegralService(ThreadPriority.Lowest, 2);
Thread.Sleep(300);
IntegralService integral3 = new IntegralService(ThreadPriority.Normal, 3);
IntegralService integral4 = new IntegralService(ThreadPriority.Normal, 4);
IntegralService integral5 = new IntegralService(ThreadPriority.Normal, 5);


while (
    integral1.thread.IsAlive ||
    integral2.thread.IsAlive ||
    integral3.thread.IsAlive ||
    integral4.thread.IsAlive ||
    integral5.thread.IsAlive
    ) {
    Thread.Sleep(50);
    (int left, int right) = Console.GetCursorPosition();
    Console.SetCursorPosition(0, 25);
    integral1.ProgressBar();
    integral2.ProgressBar();
    integral3.ProgressBar();
    integral4.ProgressBar();
    integral5.ProgressBar();
    Console.SetCursorPosition(left, right);

}
