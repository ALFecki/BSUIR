class Number
{
    public bool Menu()
    {
        Console.WriteLine("====== MENU ======");
        Console.WriteLine("1 - Enter new number");
        Console.WriteLine("2 - Exit\n");
        Console.Write("Choose your variant: ");
        int sw = int.Parse(Console.ReadLine());

        switch (sw)
        {
            case 1:
                Console.Write("Enter the number: ");
                int number = Convert.ToInt32(Console.ReadLine());
                if (isEven(number)) Console.WriteLine("\nNumber is even\n");
                else Console.WriteLine("\nNumber isn't even\n");
                return true;
            case 2:
                return false;
            default:
                Console.WriteLine("\n\nIncorrect input! Try again");
                return false;
        }

    }
    public bool isEven(int c)
    {
        return c % 2 == 0;
    }
}

