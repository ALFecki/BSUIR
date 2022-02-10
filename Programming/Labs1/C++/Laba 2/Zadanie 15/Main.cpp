#include<iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	double K, D;
	int K1;
	cout << "Введите количество грибов: ";
	cin >> K;
	D = K - floor(K);
	if (D > 0)
	{
		cout << "Мы нашли " << K << " гриба в лесу.";
	}
	else
	{
		//K1 = K;
		if ((int)K % 100 >= 5 && (int)K % 100 <= 20)
		{
			cout << "Мы нашли " << K << " грибов в лесу.";
		}
		else
		{
			
			if ((int)K % 10 == 1)
			{
				cout << "Мы нашли " << K << " гриб в лесу.";
			}
			else
			{
				if ((int)K % 10 > 0 && (int)K % 10 < 5)
				{
					cout << "Мы нашли " << K << " гриба в лесу.";
				}
				else
				{
					if ((int)K % 10 >=5 && (int)K % 10 <=9 || (int)K % 10 ==0)
					{
						cout << "Мы нашли " << K << " грибов в лесу.";
					}
				}
			}
		}
	}
}