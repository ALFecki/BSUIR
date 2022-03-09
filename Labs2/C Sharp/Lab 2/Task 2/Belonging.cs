//variant 4


class Belonging
{
    public bool Menu()
    {
        Console.WriteLine("====== MENU ======");
        Console.WriteLine("1 - Enter new coordinates");
        Console.WriteLine("2 - Exit\n");
        Console.Write("Choose your variant: ");
        int sw = int.Parse(Console.ReadLine());

        switch (sw)
        {
            case 1:
                Console.Write("Enter coordinate x: ");
                int x = Convert.ToInt32(Console.ReadLine());
                Console.Write("Enter coordinate y: ");
                int y = Convert.ToInt32(Console.ReadLine());
                isInArea(x, y);
                return true;
            case 2:
                return false;
            default:
                Console.WriteLine("\n\nIncorrect input! Try again");
                return false;
        }
    }


    public void isInArea(int x, int y)
    {
        if (y < 0)
        {
            Console.WriteLine("\nNO\n");
            return;
        }
        else if ((Math.Pow(x, 2) + Math.Pow(y, 2) == 25) || (Math.Pow(x, 2) + Math.Pow(y, 2) == 100) || y == 0)
        {
            Console.WriteLine("\nON THE BOARD\n");
            return;
        }
        else if (Math.Pow(x, 2) + Math.Pow(y, 2) > 25 && Math.Pow(x, 2) + Math.Pow(y, 2) < 100)
        {
            Console.WriteLine("\nYES\n");
            return;
        }
        else
        {
            Console.WriteLine("\nNO\n");
            return;
        }
    }
}

