

bool Menu()
{
    Console.WriteLine("====== MENU ======");
    Console.WriteLine("1 - Enter new number");
    Console.WriteLine("2 - Exit");
    char sw = Convert.ToChar(Console.Read());

    switch (sw)
    {
        case '1':

            Console.WriteLine("Enter the number: ");
            int number = Convert.ToInt32(Console.ReadLine());
            if (isEven(number)) Console.WriteLine("Number is even");
            else Console.WriteLine("Number isn't even");
            break;
        case '2':
            return false;
        default:
            Console.WriteLine("Incorrect input! Try again");
            return false;
    }

}


bool isEven(int c)
{
    if(c % 2 == 0) return true;
    else return false;
}


