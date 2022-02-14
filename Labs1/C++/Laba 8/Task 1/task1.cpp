#include<iostream>
#include<string>
#include<vector>


using namespace std;

struct Abiturients
{
	string name;
	string adress;
	vector<int> mathematic;
	vector<int> physics;
	vector<int> russian;
};


Abiturients* StructAdd(Abiturients* Data, int numberofdata)
{
	if (numberofdata == 0)
	{
		Data = new Abiturients[numberofdata + 1];
	}
	else
	{
		Abiturients* TemplateData = new Abiturients[numberofdata + 1];

		for (int i = 0; i < numberofdata; i++)
		{
			TemplateData[i] = Data[i];
		}
		
		delete[] Data;
		Data = TemplateData;
	}
	return Data;
}

bool EnterData(Abiturients* Data, int numberofdata, string keyword = "")
{
	bool check = true;
	//rewind(stdin);
	cin.ignore();
	cout << "\nEnter the name of student: ";
	getline(cin, Data[numberofdata].name);
	//scanf_s("%[^\t\n]s", Data->name);
	cout << "\nEnter the adress: ";
	getline(cin, Data[numberofdata].adress);
	//scanf_s("%[^\t\n]s", Data->adress);
	cout << "\nEnter the Mathematic marks (enter -1 to stop entering): ";
	int marks = 0;
	while (true)
	{
		cin >> marks;
		if (cin.fail() || marks < -1 || marks > 10)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "\nIncorrect input. Try again.\n";
			continue;
		}
		//scanf_s("%d", &marks);
		if (marks == -1)
			break;
		Data[numberofdata].mathematic.push_back(marks);
		//rewind(stdin);
	}
	cout << "\nEnter the Physic marks (enter -1 to stop entering): ";
	marks = 0;
	while (true)
	{
		cin >> marks;
		if (cin.fail() || marks < -1 || marks > 10)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "\nIncorrect input. Try again.\n";
			continue;
		}
		//scanf_s("%d", &marks);
		if (marks == -1)
			break;
		Data[numberofdata].physics.push_back(marks);
		//rewind(stdin);
	}
	cout << "\nEnter the Russian marks (enter -1 to stop entering): ";
	marks = 0;
	while (true)
	{
		cin >> marks;
		if (cin.fail() || marks < -1 || marks > 10)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "\nIncorrect input. Try again.\n";
			continue;
		}
		//scanf_s("%d", &marks);
		if (marks == -1)
			break;
		Data[numberofdata].russian.push_back(marks);
		//rewind(stdin);
	}
	if (Data[numberofdata].name == keyword || Data[numberofdata].adress == keyword)
	{
		check = false;
	}
	return check;
}


void ShowStruct(Abiturients* Data, int numberofdata)
{
	system("cls");
	for (int i = 0; i < numberofdata; i++)
	{
		cout << "#" << i + 1 << endl << "Name: " << Data[i].name << endl << "Adress: " << Data[i].adress << endl;
		cout << "Mathematic: ";
		for (int j = 0; j < Data[i].mathematic.size(); j++)
		{
			cout << Data[i].mathematic[j] << " ";
		}

		cout << endl;
		cout << "Physics: ";
		for (int j = 0; j < Data[i].physics.size(); j++)
		{
			cout << Data[i].physics[j] << " ";
		}

		cout << endl;
		cout << "Russian: ";
		for (int j = 0; j < Data[i].russian.size(); j++)
		{
			cout << Data[i].russian[j] << " ";
		}


		cout << endl << endl << "==================================================================================" << endl << endl;
	}
}

Abiturients* AddElement(Abiturients* Data, int numberofdata)
{
	Data = StructAdd(Data, numberofdata);
	EnterData(Data, numberofdata);
	return Data;
}

void quick_sort(Abiturients* Data, int first, int last)
{
	int f = first, l = last;
	Abiturients* Template = new Abiturients[1];
	string middle = Data[(f + l) / 2].name;
	Abiturients temp;
	do
	{
		while (Data[f].name[0] > middle[0]) f++;
		while (Data[l].name[0] < middle[0]) l--;
		if (f <= l)
		{
			temp = Data[f];
			Data[f] = Data[l];
			Data[l] = temp;
			f++; l--;
		}
	} while (f < l);
	if (first < l) quick_sort(Data, first, l);
	if (f < last) quick_sort(Data, f, last);
}

double AverageMark(Abiturients* Data, int arrlength)
{
	vector<double> avgmark;
	for (int i = 0; i < arrlength; i++)
	{
		if (Data[i].adress == "Minsk")
		{
			double mathavg = 0, physavg = 0, rusavg = 0;
			for (int j = 0; j < Data[i].mathematic.size(); j++)
			{
				mathavg += Data[i].mathematic[j];
			}
			mathavg /= Data[i].mathematic.size();
			for (int j = 0; j < Data[i].physics.size(); j++)
			{
				physavg += Data[i].physics[j];
			}
			physavg /= Data[i].physics.size();
			for (int j = 0; j < Data[i].russian.size(); j++)
			{
				rusavg += Data[i].russian[j];
			}
			rusavg /= Data[i].russian.size();
			avgmark.push_back((mathavg + physavg + rusavg) / 3);
		}
	}
	double result = 0;
	for (int i = 0; i < avgmark.size(); i++)
	{
		result += avgmark[i];
	}
	return result / avgmark.size();
}


Abiturients* EditElement(Abiturients* Data, int numberofelement, string typeofdata)
{
	if (typeofdata == "Name")
	{
		Data[numberofelement - 1].name.clear();
		cout << "\nEnter new data: ";
		getline(cin, Data[numberofelement - 1].name);
	}
	else if (typeofdata == "Adress")
	{
		Data[numberofelement - 1].adress.clear();
		cout << "\nEnter new data: ";
		getline(cin, Data[numberofelement - 1].adress);
	}
	else if (typeofdata == "Math")
	{
		Data[numberofelement - 1].mathematic.clear();
		cout << "\nEnter new Mathematic marks (enter -1 to stop entering): ";
		int marks = 0;
		while (true)
		{
			cin >> marks;
			if (cin.fail() || marks < -1 || marks > 10)
			{
				cin.clear();
				cin.ignore(32767, '\n');
				cout << "\nIncorrect input. Try again.\n";
				continue;
			}
			if (marks == -1)
				break;
			Data[numberofelement].mathematic.push_back(marks);

		}
	}
	else if (typeofdata == "Phys")
	{
		Data[numberofelement - 1].physics.clear();
		cout << "\nEnter new Physics marks (enter -1 to stop entering): ";
		int marks = 0;
		while (true)
		{
			cin >> marks;
			if (cin.fail() || marks < -1 || marks > 10)
			{
				cin.clear();
				cin.ignore(32767, '\n');
				cout << "\nIncorrect input. Try again.\n";
				continue;
			}
			if (marks == -1)
				break;
			Data[numberofelement].physics.push_back(marks);

		}
	}
	else if (typeofdata == "Rus")
	{
		Data[numberofelement - 1].russian.clear();
		cout << "\nEnter new Russian marks (enter -1 to stop entering): ";
		int marks = 0;
		while (true)
		{
			cin >> marks;
			if (cin.fail() || marks < -1 || marks > 10)
			{
				cin.clear();
				cin.ignore(32767, '\n');
				cout << "\nIncorrect input. Try again.\n";
				continue;
			}
			if (marks == -1)
				break;
			Data[numberofelement].russian.push_back(marks);
		}
	}
	return Data;
}

Abiturients* DeleteElement(Abiturients* Data, int arrlength, int numberofelement)
{
	Abiturients* TemplateData = new Abiturients[arrlength - 1];
	for (int i = 0, j = 0; j < arrlength; i++, j++)
	{
		if (j == numberofelement - 1)
		{
			i--;
			continue;
		}
		TemplateData[i] = Data[j];
	}
	delete[] Data;
	Data = TemplateData;
	return Data;
}

int main()
{
	cout << "Program will make a dynamic array of sructures with your data.\n";
	cout << "How you want to enter data ? \n";
	cout << "1 - If you want to add	specific number of members of structure.\n";
	cout << "2 - If you want to make a structure, while you enter some type of data.\n";
	cout << "3 - If you want to add something 1 to your structure.\n";
	int decision;
	int arrlength = 0;
	Abiturients* Data = 0;
	while (true)
	{
		cout << "\nChoose your variant: ";
		cin >> decision;
		if (cin.fail() || decision < 1 || decision > 3)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "\nIncorrect input. Try again.\n";
			continue;
		}
		else break;
		/*if ((scanf_s("%d", &decision)) != 1 || decision > 3 || decision < 1)
		{
			rewind(stdin);
			printf("\nIncorrect input. Try again.\n");
			continue;
		}
		else break;*/
	}
	switch (decision)
	{
	case 1:
	{
		cout << "\nEnter the number of members: ";
		int numberofdata;
		while (true) // checking
		{
			cin >> numberofdata;
			if (cin.fail() || numberofdata < 0)
			{
				cin.clear();
				cin.ignore(32767, '\n');
				cout << "\nIncorrect input. Try again.\n";
				continue;
			}
			else break;
			/*if ((scanf_s("%d", &numberofdata)) != 1)
			{
				rewind(stdin);
				printf("\nIncorrect input. Try again.\n");
				continue;
			}
			else break;*/
		}

		arrlength = numberofdata;
		numberofdata = 0;
		while (numberofdata < arrlength) // adding and setting
		{

			Data = StructAdd(Data, numberofdata);
			EnterData(Data, numberofdata);
			numberofdata++;
		}
		break;
	}
	case 2:
	{
		//cout << "Choose the type of data:\n";
		//cout << "\n1 - Name\n2 - Adress\n";
		int numberofdata = 0;
		cout << "\nEnter keyword: ";
		cin.ignore();
		string keyword;
		getline(cin, keyword);
		bool check = true;
		while (check)
		{
			Data = StructAdd(Data, numberofdata);
			check = EnterData(Data, numberofdata, keyword);
			numberofdata++;
		}
		arrlength = numberofdata;
		break;
	}
	case 3:
	{
		Data = AddElement(Data, 0);
		arrlength = 1;
		break;
	}
	default:
	{
		cout << "\nInvalid case.\n";
		break;
	}
	}
	cout << "\nPrint struct? (YES or NO)\n";
	string show;
	cin.ignore();
	getline(cin, show);
	if (show == "YES")
	{
		ShowStruct(Data, arrlength); // number of elements of structure array
	}
	bool t = true;
	while (t)
	{
		cout << "\nWhat you want to do next?\n";
		cout << "\n1 - Add structure.\n";
		cout << "2 - Print structure.\n";
		cout << "3 - Sort the structure.\n";
		cout << "4 - Average mark of abiturients from Minsk.\n";
		cout << "5 - Delete or change element.\n";
		cout << "6 - Stop the program.\n";
		while (true)
		{
			cout << "\nChoose your variant: ";
			cin >> decision;
			if (cin.fail() || decision < 1 || decision > 6)
			{
				cin.clear();
				cin.ignore(32767, '\n');
				cout << "\nIncorrect input. Try again.\n";
				continue;
			}
			else break;
		}
		switch (decision)
		{
		case 1:
		{
			AddElement(Data, arrlength);
			++arrlength;
			break;
		}
		case 2:
		{
			ShowStruct(Data, arrlength);
			break;
		}
		case 3:
		{
			/*int minlength = Data[0].name.length();
			for (int i = 0; i < arrlength; i++)
			{
				if (Data[i].name.length() < minlength)
				{
					minlength = Data[i].name.length();
				}
			}*/
			quick_sort(Data, 0, arrlength - 1);
			cout << "\nPrint struct? (YES or NO)\n";
			cin.ignore();
			getline(cin, show);
			if (show == "YES")
			{
				ShowStruct(Data, arrlength);
			}
			break;
		}
		case 4:
		{
			double avg = AverageMark(Data, arrlength);;
			cout << "\n\nAverage mark of abiturient from Minsk: " << avg << endl;
			break;
		}
		case 5:
		{
			while (true)
			{
				cout << "\nEdit or Delete?\n";
				cin.ignore();
				string answer;
				getline(cin, answer);
				if (answer == "Edit")
				{
					int numberofelement;
					while (true)
					{
						cout << "\nEnter the number of element: ";
						cin >> numberofelement;
						if (numberofelement > arrlength || cin.fail())
						{
							cin.clear();
							cin.ignore(32767, '\n');
							cout << "\nIncorrect input. Try again.\n";
							continue;
						}
						else break;
					}
					string typeofdata;
					while (true)
					{
						cin.ignore();
						cout << "\nEnter type of data (Name, Adress, Math, Phys, Rus): ";
						getline(cin, typeofdata);
						if (typeofdata != "Name" && typeofdata != "Adress" && typeofdata != "Math" && typeofdata != "Phys" && typeofdata != "Rus")
						{
							cout << "\nIncorrect input. Try again.\n";
							continue;
						}
						else break;
					}
					Data = EditElement(Data, numberofelement, typeofdata);
					break;
				}
				else if (answer == "Delete")
				{
					int numberofelement;
					while (true)
					{
						cout << "\nEnter the number of element: ";
						cin >> numberofelement;
						if (numberofelement > arrlength || numberofelement < 1 || cin.fail())
						{
							cin.clear();
							cin.ignore(32767, '\n');
							cout << "\nIncorrect input. Try again.\n";
							continue;
						}
						else break;
					}
					Data = DeleteElement(Data, arrlength, numberofelement);
					break;
				}
				else
				{
					cout << "\nIncorrect input. Try again.\n";
					continue;
				}
			}
			break;
		}
		case 6:
		{
			t = false;
			break;
		}
		}
	}
}