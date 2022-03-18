#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

void findANDreplace(char* str, char* resault);
void convert(float y, char* str);

int main()
{
	setlocale(LC_ALL, "RUS");
	float y, z;
	cout << "Введите y: ";
	cin >> y;
	cout << "Введите z: ";
	cin >> z;
	char res[50];
	convert(y, res);
	cout << res << endl;
	char* str1 = new char[250];
	char* str2 = new char[250];
	strcpy(str1, "Привет 5 4 3 Почему прикол!");
	findANDreplace(str1, str2);
	cout << str1 << endl;
	cout << str2 << endl;
	delete[]str1;
	delete[]str2;
}
void convert(float y, char* str)
{
	double x = sin(3 * y) + 16.5;
	sprintf(str, "%08.8f = sin(3* %08.8f)+16.5", x, y);
}

void findANDreplace(char* str_l, char* resault_l) {
	memset(resault_l, 0, sizeof(char) * 250);

	char str[250] = {};
	for (short i = 0; i < strlen(str_l); i++) {
		str[i] = str_l[i];
	}

	short is = 0;
	char str1[250];

	strncpy(str1, str, 250);
	char rep[] = " Неудовлетворительно ";
	char rep_2[] = "Ладно, тройка!";
	char str2[250] = {};
	char ssss[250] = {};
	char ssll[250] = {};
	int was_in = 0;
	int ignore;
	for (int i = 0; i < strlen(str1); i++) {
		if ((static_cast<int>(str1[i]) == 52) || (static_cast<int>(str1[i]) == 53)) {
			memset(str2, 0, sizeof(char) * 250);
			strncpy(str2, was_in + str1, i - was_in);
			was_in = i + 1;
			ignore = i;
		}
	}
	memset(str2, 0, sizeof(char) * 250);
	was_in = 0;

	for (int i = 0; i < strlen(str1); i++) {
		if ((static_cast<int>(str1[i]) == 52) || (static_cast<int>(str1[i]) == 53)) {
			memset(str2, 0, sizeof(char) * 250);
			strncpy(str2, was_in + str1, i - was_in);
			strcat(ssss, str2);
			strcat(ssll, str2);
			if (i == ignore) {
				strcat(ssll, rep_2);
			}
			else {
				strcat(ssll, rep);
			}
			was_in = i + 1;

		}
	}
	char sss[100] = {};
	if (was_in < strlen(str1)) {
		strncpy(sss, was_in + str1, strlen(str1) - was_in);
		strcat(ssll, sss);
	}

	for (int i = 0; i < strlen(ssll); i++)
	{
		resault_l[i] = ssll[i];
	}
}