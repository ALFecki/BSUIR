#include<iostream>

using namespace std;

void main() {

	setlocale(LC_ALL, "ru");
	double x, a, b, c,g,v;
	cout << "������� �����: ";
	cin >> x;
	
	v = x * x;
	a = 69 * v + 8;
	b = x * (23 * v + 32);
	c = a + b;
	g = a - b;

	cout << "�������� ������� ��������� �����: " << c << endl << "�������� ������� ��������� �����: " << g;
}