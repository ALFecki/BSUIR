using Task_2;


Console.Write("Enter z: ");
int z = Convert.ToInt32(Console.ReadLine());

Services func = new Services();

func.GetResult(z);
Console.WriteLine($"\nResult is {func.result}");
Console.WriteLine($"\nNumber of branch is {func.num_of_branch}");
