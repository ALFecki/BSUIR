#include<iostream>
#include<vector>

using namespace std;
int main() {
	cout << "Program will find the number of local minimums of your matrix.\n";
	int i = 0, k = 0, M, N, n = 0;
	bool t = true;
	
	while (t)
	{

		cout << "\nEnter the number of lines: ";
		cin >> N;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "\nIncorrect input. Try again.\n";
			continue;
		}
		else
		{
			if (N < 0)
			{
				std::cout << "\nIncorrect input. Try again.\n";
				continue;
			}
			else
			{
				break;
			}
		}
	}
	while (t)
	{

	
		cout << "\nEnter the number of columns: ";
		cin >> M;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "\nIncorrect input. Try again.\n";
			continue;
		}
		else
		{
			if (M < 0)
			{
				std::cout << "\nIncorrect input. Try again.\n\n";
				continue;
			}
			else
			{
				break;
			}
		}
		cout << endl;
	}
	cout << endl;
	int** a = new int* [N];
	for (i = 0; i < N; i++)
	{
		a[i] = new int[M];
	}
	i = 0;
	while (i <= N - 1 && k <= M - 1)
	{
		while (t)
		{
			std::cout << "Enter a[" << i + 1 << "][" << k + 1 << "] ";
			std::cin >> a[i][k];
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(32767, '\n');
				std::cout << "\nIncorrect input. Try again.\n\n";
				continue;
			}
			else
			{
				break;
			}
		}
		if (k == M - 1)
		{
			k = -1;
			i++;
		}
		if (k == M - 1 && i == N - 1)
		{
			break;
		}
		k++;
	}
	i = 0;
	k = 0;
	std::cout << "\n\nYour matrix:\n\n";
	while (i <= N - 1 && k <= M - 1)
	{
		if (k == M - 1)
		{
			std::cout << "\t" << a[i][k] << std::endl;
			k = -1;
			i++;

		}
		else
		{
			std::cout << "\t" << a[i][k];
		}
		if (k == M - 1 && i == N - 1)
		{
			break;
		}
		k++;
	}
	i = 0;
	for ( ; i < N ; i++)
	{
		for ( k = 0; k < M; k++)
		{
			if (k - 1 < 0 && i - 1 < 0 && a[i][k] < a[i][k + 1] && a[i][k] < a[i + 1][k]) // проверка верхнего левого угла
			{
				 
				n++;
			}
			else
			{
				if (i - 1 < 0 && k + 1 <= M - 1 && k - 1 >= 0 && a[i][k] < a[i][k + 1] && a[i][k] < a[i + 1][k] && a[i][k] < a[i][k - 1]) // проверка врхней строки
				{
					
					n++;
				}
				else
				{
					if (k + 1 > M - 1 && i - 1 < 0 && a[i][k] < a[i][k - 1] && a[i][k] < a[i + 1][k]) // проверка правого верхнего угла
					{

						
						n++;
					}
					else
					{

						if (k + 1 > M - 1 && i - 1 >= 0 && i + 1 <= N - 1 && a[i][k] < a[i][k - 1] && a[i][k] < a[i + 1][k] && a[i][k] < a[i - 1][k]) // проверка правого столбца
						{
							
							n++;
						}
						else
						{
							
							if (k + 1 > M - 1 && i + 1 > N - 1 && a[i][k] < a[i][k - 1] && a[i][k] < a[i - 1][k]) // проверка правого нижнего угла
							{
								
								n++;
							}
							else
							{
								if (i + 1 > N - 1 && k - 1 >= 0 && k + 1 <= N -1 && a[i][k] < a[i][k - 1] && a[i][k] < a[i][k + 1] && a[i][k] < a[i - 1][k]) // проверка нижней строки
								{
									
									n++;
								}
								else
								{
									if (k -1 < 0 && i + 1 > N -1 && a[i][k] < a[i][k + 1] && a[i][k] < a[i - 1][k]) // проверка левого нижнего угла
									{
										
										n++;
									}
									else
									{
										if (k - 1 < 0 && i - 1 >= 0 && i + 1 <= M - 1 && a[i][k] < a[i + 1][k] && a[i][k] < a[i][k + 1] && a[i][k] < a[i - 1][k]) //проверка левого столбца
										{
											
											n++;
										}
										else
										{
											if (a[i][k] < a[i][k - 1] && a[i][k] < a[i][k + 1] && a[i][k] < a[i - 1][k] && a[i][k] < a[i + 1][k])
											{
												
												n++;
											}
											
										}
									}
								}
							}
							

						}



					}
				}
			}
			
		}
	}
	cout << "\nThe number of local minimums is " << n << endl;
}