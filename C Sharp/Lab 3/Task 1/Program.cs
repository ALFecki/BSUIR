using Task_1;

int num = 0;
while (true)
{
    Console.Write("Enter your number: ");
    num = Convert.ToInt32(Console.ReadLine());
    if (num > 999 || num < 100)
    {
        Console.Write("\nIncorrect input. Try again.\n");
    }
    else break;
}

Numbers numbers = new Numbers(num);
int new_number = numbers.Switch_numbers();
Console.WriteLine($"New number is {new_number}");