#include<iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	double K, D;
	int K1;
	cout << "������� ���������� ������: ";
	cin >> K;
	D = K - floor(K);
	if (D > 0)
	{
		cout << "�� ����� " << K << " ����� � ����.";
	}
	else
	{
		//K1 = K;
		if ((int)K % 100 >= 5 && (int)K % 100 <= 20)
		{
			cout << "�� ����� " << K << " ������ � ����.";
		}
		else
		{
			
			if ((int)K % 10 == 1)
			{
				cout << "�� ����� " << K << " ���� � ����.";
			}
			else
			{
				if ((int)K % 10 > 0 && (int)K % 10 < 5)
				{
					cout << "�� ����� " << K << " ����� � ����.";
				}
				else
				{
					if ((int)K % 10 >=5 && (int)K % 10 <=9 || (int)K % 10 ==0)
					{
						cout << "�� ����� " << K << " ������ � ����.";
					}
				}
			}
		}
	}
}