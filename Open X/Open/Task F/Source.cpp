	#include <iostream>


	//-9223372036854775808 9223372036854775807
	int main()
	{
		long long a, b;
		std::cin >> a >> b;

		if ((a < b && a > 0) || (b < a && b > 0) || a == b || (a < 0 && b < 0) || (a > 0 && b > 0))
		{
			std::cout << a - b;
		}
		else if (a < 0 && b < 0 || a > 0 && b > 0)
		{
			std::cout << a - b;
		}
		else
		{
			std::cout << a + b;
		}
		return 0;
	}