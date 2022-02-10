#include<iostream>
#include<vector>

using namespace std;
int main() {
	cout << "Program will replace all elements for maximum of their upper and left \"neighbors\".\n";
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
	float** a = new float* [N];
	for (i = 0; i < N; i++)
	{
		a[i] = new float[M];
	}
	float** b = new float* [N];
	for (i = 0; i < N; i++)
	{
		b[i] = new float[M];
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
	std::cout << "\n\nYour matrix:\n\n";
	for (i = 0; i < N; i++)
	{
		for (k = 0; k < M; k++)
		{
			cout << "\t" << a[i][k];
		}
		cout << endl;
	}
	for (i = 0; i < N; i++)
	{
		for (k = 0; k < M; k++)
		{
			if (k - 1 < 0 && i - 1 < 0) // проверка верхнего левого угла
			{
				b[i][k] = a[i][k];
			}
			else
			{
				if (k + 1 > M - 1  && i - 1 < 0) // проверка правого верхнего угла
				{
					if (a[i][k - 1] > a[i][k])
					{
						b[i][k] = a[i][k - 1];
					}
					else
					{
						b[i][k] = a[i][k];
					}

				}
				else
				{

					if (i - 1 < 0) // проверка верхней строки
					{

						if (a[i][k - 1] > a[i][k])
						{
							b[i][k] = a[i][k - 1];
						}
						else
						{
							b[i][k] = a[i][k];
						}
					}
					else
					{
						if (k - 1 < 0 && i + 1 > N - 1) // проверка левого нижнего угла
						{
							if (a[i - 1][k] > a[i][k])
							{
								b[i][k] = a[i - 1][k];
							}
							else
							{
								b[i][k] = a[i][k];
							}
							 
						}
						else
						{


							if (k - 1 < 0) // проверка левого столбца
							{
								if (a[i - 1][k] > a[i][k])
								{
									b[i][k] = a[i - 1][k];
								}
								else
								{
									b[i][k] = a[i][k];
								}

							}
							else
							{
								if (a[i][k - 1] > a[i][k] && a[i][k - 1] > a[i - 1][k])
								{
									b[i][k] = a[i][k - 1];
								}
								else
								{
									if (a[i - 1][k] > a[i][k] && a[i - 1][k] > a[i][k - 1])
									{
										b[i][k] = a[i - 1][k];
									}
									else
									{
										b[i][k] = a[i][k];
										continue;
									}
								}



							}
						}



					}
				}
			}

		}
	}

	cout << "\n\nNew matrix:\n\n";
	for (i = 0; i < N; i++)
	{
		for (k = 0; k < M; k++)
		{
			cout << "\t" << b[i][k];
		}
		cout << endl;
	}


}