#include<iostream>
#include<vector>

using namespace std;

int main() {

	vector<int> a;
	int i, S = 0, N;
	cout << "\nProgram will be able to count the number of Misha's sockets.";
	while (true)
	{
		cout << "\n\nEnter the number of extensions that Misha bought: ";
		cin >> N;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "\nIncorrect input. Try again.";
			continue;
		}
		else if (N < 0)
		{
			cout << "\nIncorrect input. Try again.";
			continue;
		}
		else break;
	}
	a.resize(N);
	cout << "\nEnter the number of sockets in each extension, please\n\n"; 
	for (i = 0; i < N; i++)
	{
		while (true)
		{
			cout << "Enter a[" << i << "]";
			cin >> a[i];
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(32767, '\n');
				cout << "\nIncorrect input. Try again.";
				continue;
			}
			else if (a[i] <= 0)
			{
				cout << "\nIncorrect input. Try again.";
				continue;
			}
			else break;
		}
	}
	for ( i = 0; i < N; i++)
	{
		S += a[i];
	}
	cout << "\nThe number of sockets is " << S - (N - 1) << endl;

}
