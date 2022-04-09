#include <iostream>
#include <string>
#include <vector>


int main()
{
	long long N;
	int number_of_solutions;
	std::cin >> number_of_solutions;
	std::vector<long long> array_of_counters;
	for (int i = 0; i < number_of_solutions; i++)
	{
		std::cin >> N;
		int counter = 0;
		bool is_fib = false, is_fib_1 = true;

		std::vector<int> fib_nums;
		fib_nums.push_back(1);
		fib_nums.push_back(2);
		int t1 = 1, t2 = 2, temp = 3;
		while (temp <= N)
		{
			fib_nums.push_back(temp);
			t1 = t2;
			t2 = temp;
			temp = t1 + t2;

		}
		for (long long i = 0; i <= N; i++)
		{
			std::string temp = std::to_string(i);
			if (temp[0] == '1')
			{
				i *= 3;
				continue;
			}
			bool is_fib_2 = false;
			for (int y = 0; y < temp.size(); y++)
			{
				if (temp[y] == '1' || temp[y] == '2' || temp[y] == '3' || temp[y] == '5' || temp[y] == '8')
				{
					is_fib_2 = true;
					break;
				}
			}
			if (is_fib_2)
			{
				continue;
			}
			is_fib_1 = true;
			for (int j = 0; j < fib_nums.size() && is_fib_1; j++)
			{
				if (i == fib_nums[j])
				{
					is_fib = false;
					break;
				}
				std::string temp_fib = std::to_string(fib_nums[j]);
				std::string temp = std::to_string(i);
				for (int k = 0, l = 0; k < temp.size(); k++)
				{
					//is_fib = false;
					//if ((l != 0 && l == temp_fib.size() - 1) || l == 1 && l == temp_fib.size()) // 0 1 2 3 5 8 13 21 34 55 89 144 233 377
					//{
					//	is_fib_1 = false;
					//	break;
					//}
					if (temp[k] == temp_fib[l])
					{
						l++;
						if ((l != 0 && l == temp_fib.size() - 1) || l == 1 && l == temp_fib.size())
						{
							is_fib = false;
							is_fib_1 = false;
							break;
						}
					}
					is_fib = true;
				}
				
			}
			if (is_fib)
			{
				counter++;
				is_fib = false;
			}
		}
		array_of_counters.push_back( counter);
	}
	for (int i = 0; i < array_of_counters.size(); i++)
	{
		std::cout << array_of_counters[i] << std::endl;
	}
	return 0;



}