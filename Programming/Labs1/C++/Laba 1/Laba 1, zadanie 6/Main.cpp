#include<iostream>

using namespace std;

int main() {
	int h1, min1, h2, min2,S1,S2,D,H,M;
	
	setlocale(LC_ALL, "Rus");
	cout << "Введите время начала работы ";
	cin >> h1 >> min1;
	cout << "Введите время окончания ";
	cin >> h2 >> min2;
	if (h1 >= h2)
	{
		S1 = h1 * 60 + min1;
		S2 = h2 * 60 + min2;
		H = (24 * 60 - S1 + S2) / 60;
		M = (24 * 60 - S1 + S2) % 60;
	}
	else
	{
		S1 = h1 * 60 + min1;
		S2 = h2 * 60 + min2;
		D = S2 - S1;
		H = D / 60;
		M = D % 60;
	}
	cout << "Затраченное время равно: " << H << " часа(-ов) " << M << " минут(-ы)" << endl;
}