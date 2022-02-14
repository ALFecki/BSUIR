#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    string strings;
    vector<string> text;
    int NumberOfStrings;
    cout << "Program will make the text using the \"new\" rules of English language." << endl;
    while (true)
    {
        cout << "Enter the number of strings of your text: ";
        cin >> NumberOfStrings;
        if (cin.fail() || NumberOfStrings < 0)
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "\nIncorrect input. Try again.\n";
            continue;
        }
        else break;
    }
    cout << "Enter your text:\n";
    cin.ignore();
    while ((text.size() < NumberOfStrings) && (getline(cin, strings)))
    {
        text.push_back(strings);
    }

    for (int i = 0; i < text.size(); i++)
    {
        strings = text[i];
        for (int j = 0; j < strings.size(); j++)
        {
            if ((int)strings[j] == 67 || (int)strings[j] == 99) // проверка буквы С
            {
                if ((int)strings[j] == 67)
                {
                    if ((int)strings[j + 1] == 101 || (int)strings[j + 1] == 105 || (int)strings[j + 1] == 121)
                    {
                        strings.replace(j, 1, "S");
                    }
                    else
                    {
                        strings.replace(j, 1, "K");
                    }
                }
                else if ((int)strings[j] == 99)
                {
                    if ((int)strings[j + 1] == 101 || (int)strings[j + 1] == 105 || (int)strings[j + 1] == 121)
                    {
                        strings.replace(j, 1, "s");
                    }
                    else
                    {
                        strings.replace(j, 1, "k");
                    }
                }
            }
            else if ((int)strings[j] == 81 || (int)strings[j] == 113) // проверка на Q
            {
                if ((int)strings[j] == 81)
                {
                    if ((int)strings[j + 1] == 117) strings.replace(j, 2, "Kv");
                    else strings.replace(j, 1, "K");
                }
                else if ((int)strings[j + 1] == 117)
                {
                    strings.replace(j, 2, "kv");
                }
                else strings.replace(j, 1, "k");
            }
            else if ((int)strings[j] == 88 || (int)strings[j] == 120) // проверка буквы Х
            {
                if ((int)strings[j] == 88)
                {
                    strings.replace(j, 1, "K");
                    strings.insert(j + 1, 1, 's');
                }
                else
                {
                    strings.replace(j, 1, "k");
                    strings.insert(j + 1, 1, 's');
                }
            }
            else if ((int)strings[j] == 87 || (int)strings[j] == 119) // проверка на W
            {
                if ((int)strings[j] == 87) strings.replace(j, 1, "V");
                else strings.replace(j, 1, "v");
            }
            else if ((int)strings[j] == 80 || (int)strings[j] == 112) // проверка сочетания ph
            {
                if ((int)strings[j] == 80 && (int)strings[j + 1] == 104)
                {
                    strings.replace(j, 1, "F");
                    strings.erase(j + 1, 1);
                }
                else if ((int)strings[j] == 112 && (int)strings[j + 1] == 104)
                {
                    strings.replace(j, 1, "f");
                    strings.erase(j + 1, 1);
                }
            }
            else if ((int)strings[j] == 89 && (int)strings[j + 1] == 111 && (int)strings[j + 2] == 117) // проверка на You
            {
                strings.replace(j, 1, "U");
                strings.erase(j + 1, 2);
            }
            else if ((int)strings[j] == 121 && (int)strings[j + 1] == 111 && (int)strings[j + 2] == 117)
            {
                strings.replace(j, 1, "u");
                strings.erase(j + 1, 2);
            }
            else if ((int)strings[j] == 111 && (int)strings[j + 1] == 111) // проверка на оо
            {
                strings.replace(j, 1, "u");
                strings.erase(j + 1, 1);
            }
            else if ((int)strings[j] == 101 && (int)strings[j + 1] == 101) // проверка на ее
            {
                strings.replace(j, 1, "i");
                strings.erase(j + 1, 1);
            }
            else if ((int)strings[j] == 84 && (int)strings[j + 1] == 104) // проверка на Th
            {
                strings.replace(j, 1, "Z");
                strings.erase(j + 1, 1);
            }
            else if ((int)strings[j] == 116 && (int)strings[j + 1] == 104)
            {
                strings.replace(j, 1, "z");
                strings.erase(j + 1, 1);
            }
        }
        text[i] = strings;
    }
    char vowels[6] = { 'e', 'a', 'y','i', 'o' };
    for (int i = 0; i < text.size(); i++)
    {
        strings = text[i];
        for (int j = 0; j < strings.size(); j++)
        {
            for (int k = 0; k < 6; k++)
            {
                if (strings[j] != vowels[i] && strings[j + 1] == strings[j])
                {
                    strings.erase(j + 1, 1);
                }
            }
        }
        text[i] = strings;
    }
    cout << "\nText with \"new rules\" is\n\n";
    
    for (int i = 0; i < text.size(); i++)
    {
        cout << text[i] << endl;
    }
    
}