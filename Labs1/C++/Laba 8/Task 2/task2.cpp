#include<iostream>
#include<vector>
#include<string>
#include<fstream>

std::ifstream fin("input.txt");
std::ofstream fout("output.txt");

struct SalaryData
{
	std::string name;
	int number;
	int hours;
	int tariff;
	double salary;
};

SalaryData* StructAdd(SalaryData* Data, int numberofdata)
{
	if (numberofdata == 0)
	{
		Data = new SalaryData[numberofdata + 1];
	}
	else
	{
		SalaryData* TemplateData = new SalaryData[numberofdata + 1];

		for (int i = 0; i < numberofdata; i++)
		{
			TemplateData[i] = Data[i];
		}
		delete[] Data;
		Data = TemplateData;
	}
	return Data;
}

void EnterData(SalaryData* Data, int numberofdata)
{
	std::getline(fin, Data[numberofdata].name);	
	fin >> Data[numberofdata].number;
	fin >> Data[numberofdata].hours;
	fin >> Data[numberofdata].tariff;
}

void EnterDataConsole(SalaryData* Data, int numberofdata)
{
	std::cin.ignore();
	std::cout << "\n\nEnter name: ";
	std::getline(std::cin, Data[numberofdata].name);
	std::cout << "\nEnter the personal number: ";
	std::cin >> Data[numberofdata].number;
	std::cout << "\nEnter the number of working hours: ";
	std::cin >> Data[numberofdata].hours;
	std::cout << "\nEnter the tariff: ";
	std::cin >> Data[numberofdata].tariff;
}

void ShowStruct(SalaryData* Data, int numberofdata)
{
	system("cls");
	for (int i = 0; i < numberofdata; i++)
	{
		std::cout << "#" << i + 1 << std::endl << "Name: " << Data[i].name << std::endl << "Personal number: " << Data[i].number << std::endl;
		std::cout << "Number of hours: " << Data[i].hours << std::endl << "Tariff (per hour): " << Data[i].tariff << std::endl << "General salary: " << Data[i].salary << std::endl;
		std::cout << std::endl << "================================================================================" << std::endl;
	}
}


SalaryData* AddElement(SalaryData* Data, int numberofdata)
{
	Data = StructAdd(Data, numberofdata);
	EnterDataConsole(Data, numberofdata);
	return Data;
}

void quick_sort(SalaryData* Data, int first, int last)
{
	int f = first, l = last;
	SalaryData* Template = new SalaryData[1];
	int middle = Data[(f + l) / 2].number;
	SalaryData temp;
	do
	{
		while (Data[f].number < middle) f++;
		while (Data[l].number > middle) l--;
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

void EditElement(SalaryData* Data, int numberofelement, std::string typeofdata)
{
	if (typeofdata == "Name")
	{
		Data[numberofelement - 1].name.clear();
		std::cout << "\nEnter new data: ";
		std::getline(std::cin, Data[numberofelement - 1].name);
	}
	else if (typeofdata == "PersNum")
	{
		std::cout << "\nEnter new data: ";
		std::cin >> Data[numberofelement - 1].number;
	}
	else if (typeofdata == "Hours")
	{
		std::cout << "\nEnter new data: ";
		std::cin >> Data[numberofelement - 1].hours;
	}
	else if (typeofdata == "Tariff")
	{
		std::cout << "\nEnter new data: ";
		std::cin >> Data[numberofelement - 1].tariff;
	}
}


SalaryData* DeleteElement(SalaryData* Data, int arrlength, int numberofelement)
{
	SalaryData* TemplateData = new SalaryData[arrlength - 1];
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
	SalaryData* Data = 0;
	std::cout << "\nProgram will make an array of the structures.\n";
	std::cout << "\nEnter the number of members: ";
	int arrlength; 
	std::cin >> arrlength;
	int temp = 0;
	while (temp < arrlength)
	{
		if (fin.eof())
		{
			std::cout << "\nYou need to enter more information.\n";
			break;
		}
		Data = StructAdd(Data, temp);
		EnterData(Data, temp);
		temp++;
	}
	while (temp < arrlength)
	{
		Data = StructAdd(Data, temp);
		EnterDataConsole(Data, temp);
		temp++;
	}
	for (int i = 0; i < arrlength; i++)
	{
		if (Data[i].hours > 144)
		{
			Data[i].salary = 0.88 * Data[i].hours * Data[i].tariff * 2;
		}
		else
		{
			Data[i].salary = 0.88 * Data[i].hours * Data[i].tariff;
		}
	}
	std::cout << "\nPrint struct? (YES or NO)\n";
	std::string show;
	std::cin.ignore();
	std::getline(std::cin, show);
	if (show == "YES")
	{
		ShowStruct(Data, arrlength);
	}
	bool t = true;
	while (t)
	{
		std::cout << "\nWhat you want to do next?\n";
		std::cout << "\n1 - Add structure.\n";
		std::cout << "2 - Print structure.\n";
		std::cout << "3 - Sort the structure.\n";
		std::cout << "4 - Delete or change element.\n";
		std::cout << "5 - Save data and stop the program.\n";
		int decision;
		while (true)
		{
			std::cout << "\nChoose your variant: ";
			std::cin >> decision;
			if (std::cin.fail() || decision < 1 || decision > 5)
			{
				std::cin.clear();
				std::cin.ignore(32767, '\n');
				std::cout << "\nIncorrect input. Try again.\n";
				continue;
			}
			else break;
		}
		switch (decision)
		{
		case 1:
		{
			Data = AddElement(Data, arrlength);
			if (Data[arrlength].hours > 144)
			{
				Data[arrlength].salary = 0.88 * Data[arrlength].hours * Data[arrlength].tariff * 2;
			}
			else
			{
				Data[arrlength].salary = 0.88 * Data[arrlength].hours * Data[arrlength].tariff;
			}
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
			quick_sort(Data, 0, arrlength - 1);
			break;
		}
		case 4:
		{
			std::cout << "\nEdit or Delete?\n";
			std::cin.ignore();
			std::string answer;
			std::getline(std::cin, answer);
			if (answer == "Edit")
			{
				int numberofelement;
				while (true)
				{
					std::cout << "\nEnter the number of element: ";
					std::cin >> numberofelement;
					if (numberofelement > arrlength - 1 || std::cin.fail())
					{
						std::cin.clear();
						std::cin.ignore(32767, '\n');
						std::cout << "\nIncorrect input. Try again.\n";
						continue;
					}
					else break;
				}
				std::cin.ignore();
				std::string typeofdata;
				while (true)
				{
					std::cout << "\nEnter type of data (Name, PersNum, Hours, Tariff): ";
					std::getline(std::cin, typeofdata);
					if (typeofdata != "Name" && typeofdata != "PersNum" && typeofdata != "Hours" && typeofdata != "Tariff")
					{
						std::cout << "\nIncorrect input. Try again.\n";
						continue;
					}
					else break;
				}
				EditElement(Data, numberofelement, typeofdata);
				if (Data[numberofelement].hours > 144)
				{
					Data[numberofelement].salary = 0.88 * Data[numberofelement].hours * Data[numberofelement].tariff * 2;
				}
				else
				{
					Data[numberofelement].salary = 0.88 * Data[numberofelement].hours * Data[numberofelement].tariff;
				}
				break;
			}
			else if (answer == "Delete")
			{
				int numberofelement;
				while (true)
				{
					std::cout << "\nEnter the number of element: ";
					std::cin >> numberofelement;
					if (numberofelement > arrlength || numberofelement < 1 || std::cin.fail())
					{
						std::cin.clear();
						std::cin.ignore(32767, '\n');
						std::cout << "\nIncorrect input. Try again.\n";
						continue;
					}
					else break;
				}
				Data = DeleteElement(Data, arrlength, numberofelement);
				arrlength--;
				break;
			}
		}
		case 5:
		{
			system("cls");
			for (int i = 0; i < arrlength; i++)
			{
				fout << "#" << i + 1 << std::endl << "Name: " << Data[i].name << std::endl << "Personal number: " << Data[i].number << std::endl;
				fout << "Number of hours: " << Data[i].hours << std::endl << "Tariff (per hour): " << Data[i].tariff << std::endl << "General salary: " << Data[i].salary << std::endl;
				fout << std::endl << "================================================================================" << std::endl;
			}		
			t = false;
			break;
		}
		
		}
	
	
	}
}