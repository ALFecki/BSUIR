#include<iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	double W, H, w, h, w1, h1, x1, y1, x2, y2, L = 0, l, l1,l2;
	cout << "Введите размеры комнаты\n" << "Ширина: ";
	cin >> W;
	cout << "Высота: ";
	cin >> H;
	cout << "Введите координаты нижнего угла\n" << "x: ";
	cin >> x1;
	cout << "y: ";
	cin >> y1;
	cout << "Введите координаты верхнего угла\n" << "x: ";
	cin >> x2;
	cout << "y: ";
	cin >> y2;
	cout << "Введите размеры второго стола \n" << "Ширина: ";
	cin >> w;
	cout << "Высота: ";
	cin >> h;
	w1 = x2 - x1;
	h1 = y2 - y1;
	l1 = w - x1;
	l2 = h - y1;
	if (w > W || h > H)
	{
		L = -1;
	}
	else
	{

		if (W == x2 && l2 > 0 && w1 <= 1)
		{
			L = l2;
		}
		else
		{
			if (H == y2 && l1 > 0 && h1 <= 1)
			{
				L = l1;
			}
			else
			{



				if (l1 * l2 == 0)
				{
					L = 0;
				}
				else
				{
					if (W - x2 >= l1 && l1 < l2)
					{
						L = l1;
					}
					else
					{
						if (H - y2 >= l2 && l2 < l1)
						{
							L = l2;
						}
						else
						{
							if (W - x2 < l1 && H - y2 < l2)
							{
								L = -1;
							}
						}

					}



				}
			}
		}
	}
	cout << endl << L;
	
	
	
	
	
	/*else
	{
		if (w1 + w > x2 && h1 + h <= y2)
		{
			l = w - x1;
		}
		else
		{
			if (w1 + w <= x2 && h1 + h >y2)
			{
				l = h - y1;
			}
			else
			{
				if (w1 + w > x2 && h1 + h > y2)
				{
					l = w - x1;
					l1 = h - y1;
					L = sqrt((pow(l, 2) + pow(l1, 2)));
					cout << L;
				}
				else
				{
					l = -1;
				}
			}
		
		}
	
	}
	cout << l;*/
}