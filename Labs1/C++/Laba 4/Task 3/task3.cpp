#include<iostream>
#include<cstdlib>
#include<cmath>
#include<ctime>
using namespace std;
int main()
{
	setlocale(LC_ALL, "RU");
	srand(time(NULL));
	float a, b;
	int  x, R1, y, n, k, v, i = 0, x0, y0;
	cout << "Введите радиус" << endl;
	cin >> R1;
	cout << "Введите количество дротиков\t";
	cin >> n;
	x0 = R1;
	y0 = -R1;
	while (n > 0)
	{
		
		x = (1 + rand() % R1);
		y = (1 + rand() % R1);
		cout << x << endl;
		cout << y << endl;
		a = pow(x - x0, 2);
		b = pow(y - y0, 2);
		if ((a + b) <= (pow(R1, 2)) && (a + b != 0))
		{
			i = i + 1;
		}
		else
			if (a + b == 0)
			{
				cout << " Попадание в яблочко " << endl;
			}
		n--;
	}
	cout << "Вы набрали " << i << " баллов\t";
}
