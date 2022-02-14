#include<iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	double V0,V, a,S, t,S1, S2;
	cout << "¬ведите скорость: ";
	cin >> V0;
	cout << "\n¬ведите ускорение: ";
	cin >> a; 
	cout << "\n¬ведите врем€: ";
	cin >> t;
	if (V0 > 0 && a<0)
	{
		V = V0 + a * t;
		S1 = (pow(V0, 2)) / (2 * a);
		S2 = pow(V, 2) / (2 * abs(a));
		S = abs(S1) + S2;
	}
	else if (V0<0 && a>0)
	{
		V = V0 + a * t;
		S1 = (pow(V0, 2)) / (2 * a);
		S2 = pow(V, 2) / (2 * abs(a));
		S = abs(S1) + S2;

	}
	{
		V = V0 + a * t;
		S = (pow(V, 2) - pow(V0, 2)) / (2 * a);
	}
	cout << "\nѕуть равен: " << S;
}