#include <iostream>
#include <vector>
#include <cmath>

int main()
{
	int N, pasture, sheep, minutes = 0;
	std::vector<long long> K;
	long sum_of_pastures = 0, num_of_sheeps = 0;
	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		std::cin >> pasture;
		sum_of_pastures += pasture;
		std::cin >> sheep;
		num_of_sheeps += sheep * pasture;
		for (int j = 0; j < pasture; j++)
		{
			K.push_back(sheep);
		}
	}
	long count = num_of_sheeps / sum_of_pastures;
	if (K[0] > K[K.size() - 1])
	{


		for (int j = K.size() - 1; j >= 0; j--)
		{

			while (K[j] < count && K[0] != 1)
			{
				K[j - 1]--;
				K[j]++;
				minutes++;
			}
		}
	}
	else
	{
		for (int j = 0; j < K.size(); j++)
		{

			while (K[j] < count && K[K.size() - 1] != 0)
			{
				K[j + 1]--;
				K[j]++;
				minutes++;
			}
		}
	}
	std::cout << minutes % (static_cast<int>(pow(10, 9)) + 7);
}