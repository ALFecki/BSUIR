#include<iostream>

using namespace std;

int main(){

	int a,b;
	setlocale(LC_ALL, "Rus");
	cout << "¬ведите числа: ";
	cin >> a >> b;
	b += a;
	cout << a << " " << b << endl;
	a = b - a;
	cout << a << " " << b << endl;
	b = b - a;
	cout << a << " " << b << endl;

		}