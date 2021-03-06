#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Patterns {
	string p; //паттерн
	int count; //число вхождений
};

int max(int *array, int n) {
	int imax = 0;
	for (int i = 1; i < n; i++) {
		if (array[i] > array[imax]) imax = i;
	}
	return array[imax];
}

int PatternCount(string s, string p) {
	int i, j, m, n;
	int count = 0;
	int l_s = s.length();//длина строки
	int l_p = p.length();//длина паттерна
	for (i = 0; i <= l_s - l_p; i++) {
		n = 0;
		for (j = i, m = 0; m < l_p; j++, m++) {
			if (p[m] == s[j]) n++;
		}
		if (n == l_p) count++;
	}
	return count;
}

void FrequentWords(string s, int k) {
	ofstream fout("output.txt");
	const int n = k;
	int l_s = s.length();
	string buff;
	struct Patterns *t = new struct Patterns[l_s - k + 1];
	int i, j, m;
	int *Count = new int[l_s - k + 1];
	for (i = 0; i <= l_s - k; i++) {
		j = i;
		for (m = 0; m < k; m++) {
			buff += s[j]; j++;
		}
		t[i].p = buff;
		t[i].count = Count[i] = PatternCount(s, buff);
		buff = "";

	}
	int max_Count = max(Count, l_s - k + 1);
	for (int g = 0; g <= l_s - k; g++) {
		if (t[g].count == max_Count) {
			int h;
			for (h = 0; (h < g) && (t[h].p != t[g].p); h++)
				;
			if (h == g) {
				fout << t[g].p << " ";
			}
		}
	}
	fout.close();

}

int main()
{
	ifstream fin("input.txt");

	string str;
	int k;


	if (!fin.is_open())
		cout << "Файл не может быть открыт!\n";
	else
	{
		fin >> str; // считали строку из файла

		fin >> k; // считали размер паттерна из файла

		FrequentWords(str, k);

	}

	return 0;
}

