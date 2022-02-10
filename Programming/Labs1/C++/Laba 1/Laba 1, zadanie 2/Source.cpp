//Лаба 1 задание 2, вариант 1

#include<iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");
	float x,S, D, A, b;
	cout << "Введите числа: ";
	cin >> x >> D;
	b = x + D;
	A = (D * x) / b;
	S = (pow(A, 2) + b * cos(x)) / (pow(D, 3) + (A + D - b));
	cout << "Ответ: " << S;


}