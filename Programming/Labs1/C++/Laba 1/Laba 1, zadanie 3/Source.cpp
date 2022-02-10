#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	const double PI = 3.141592653589793;
	float x1, x2, x3, y1, y2, y3, a, b, c, S, r, R, P, p,C1, C2, S1,S2, h1, h2, h3, m1, m2, m3, l1, l2, l3, cos1, cos2, cos3,sin1, alpha,alpha1, betta,betta1, gamma, gamma1;
	setlocale(LC_ALL, "Rus");
	cout << "Введите параметры треугольника\n";
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	a = (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
	b = (sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2)));
	c = (sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2)));
	
		cout << "1) Стороны треугольника равны\n" << "AB: " << a << endl << "BC: " << b << endl << "AC: " << c << endl;
		P = a + b + c;
		p = P / 2;
		S = sqrt(p * (p - a) * (p - b) * (p - c));
		h1 = 2 * S / a;
		h2 = 2 * S / b;
		h3 = 2 * S / c;
		cout << "2) Высоты треугольника соответственно равны: " << h1 << " " << h2 << " " << h3 << endl;
		m1 = sqrt(2 * pow(b, 2) + 2 * pow(c, 2) - pow(a, 2)) / 2;
		m2 = sqrt(2 * pow(a, 2) + 2 * pow(c, 2) - pow(b, 2)) / 2;
		m3 = sqrt(2 * pow(b, 2) + 2 * pow(a, 2) - pow(c, 2)) / 2;
		cout << "3) Медианы треугольника соответсвенно равны: " << m1 << " " << m2 << " " << m3 << endl;
		R = a * b * c / (4 * S);
		sin1 = 2 * S / (a * b);
		/*sin2 = 2 * S / (b * c);
		sin3 = 2 * S / (a * c);
		alpha = asin(sin1);
		betta = asin(sin2);
		gamma = asin(sin3);
		alpha1 = alpha*180/PI;
		betta1 = betta * 180 / PI;
		gamma1 = gamma * 180 / PI; */
		cos1 = (pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2 * a * b);
		cos2 = (pow(a, 2) + pow(c, 2) - pow(b, 2)) / (2 * a * c);
		cos3 = (pow(c, 2) + pow(b, 2) - pow(a, 2)) / (2 * c * b);
		
		alpha = acos(cos1);
		betta = acos(cos2);
		gamma = acos(cos3);
		alpha1 = alpha * 180 / PI;
		betta1 = betta * 180 / PI;
		gamma1 = gamma * 180 / PI;
		r = S / p;
		l1 = 2 * sqrt(a * b * p*(p - c)) / (a + b);
		l2 = 2 * sqrt(b * c * p*(p - a)) / (b + c);
		l3 = 2 * sqrt(a * c * p*(p - b)) / (a + c);
		cout << "4) Биссектрисы треугольника равны " << l1 << " " << l2 << " " << l3 << endl;
		cout << "5) Радианные меры углов равны: " << alpha << " " << betta << " " << gamma << endl;
		cout << "Градусные меры углов равны: " << alpha1 << " " << betta1 << " " << gamma1 << endl;
		cout << "6)Радиус вписанной окружности равен: " << r << endl << "Радиус описанной окружности равен: " << R << endl;
		C1 = 2 * PI * R;
		C2 = 2 * PI * r;
		S1 = PI * pow(R, 2);
		S2 = PI * pow(r, 2);
		cout << "7) Длина описанной окружности равна: "  << C1 << endl << "Длина вписанной окружности: " << C2<< endl;
		cout << "Площадь описанной окружности равна: " << S1 << endl << "Площадь вписанной окружности: " << S2 << endl;
		S = (a * h1) / 2;
		S = (a * b * sin1) / 2;
		cout << "8) Площадь треугольника равна: " << S << endl << "Периметр треугольника равен: " << P;
		
		

	
		




}