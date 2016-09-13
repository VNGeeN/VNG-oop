// Var№4(VNG).cpp: определяет точку входа для консольного приложения.

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

struct StudentData
{
    string surnameOfStudent;
	string department;
	string group;
	stringstream point;
};

//opening the file check
ifstream OpenFile()
{
	ifstream fin("studentsPoint.txt");
	if (!fin.is_open())
	{
		cout << "File is not open\n";
	}
	return fin;
}

//Delete ' ' in str and write its in str1
void transformation(string &str, string &str1)
{
	for (int i = 0; i != str.length(); i++)
	{
		if (str[i] != ' ')
		{
			str1 += str[i];
		}
		if ((str[i] != ' ') && (str[i + 1] == ' '))
		{
			str1 += str[i + 1];
		}
	}
}

//
void distribution(string &str1, StudentData &inputData)
{
	int j = 0;
	for (int i = 0; i != str1.length(); i++)
	{
		if (str1[i] != ' ')
		{
			if (j == 0)
			{
				inputData.surnameOfStudent += str1[i];
			}
			else
			{
				if (j == 1)
				{
					inputData.department += str1[i];
				}
				else
				{
					if (j == 2)
					{
						inputData.group += str1[i];
					}
					else
					{
						if (j == 3)
						{
							inputData.point << str1[i];
						}
					}
				}
			}
		}
		else
		{
			j++;
		}
	}
}

//int main()
void main()
{
	setlocale(LC_ALL, "rus");
	char ch = ' ';
	int i = 0;
	string str;
	string strTransform;
	int j = 0;
	StudentData inputData1;
	ifstream fin = OpenFile();
	while (!EOF(fin))
	{
		getline(fin, str);
		transformation(str, strTransform);
		distribution(strTransform, inputData1);
		
	}
	/*inputData1.point >> i;
	cout << inputData1.surnameOfStudent << "\n";
	cout << inputData1.department << "\n";
	cout << inputData1.group << "\n";
	cout << i << "\n";
	//cout << inputData1.point << "\n";
	//cout << inputData1.surnameOfStudent << "\n";*/
	fin.close();
}




/*istringstream *ist = new istringstream(str);
for (string word; *ist >> word; str1 = str1 + word + " ");
cout << str1;
delete ist;*/