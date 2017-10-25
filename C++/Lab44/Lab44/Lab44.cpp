#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
	int n;
	long int ve = 0;
	int ni = 0;
	int max = 0;
	int k = 1;
	cout << "Size matrix: ";
	cin >> n;
	int **arr = new int*[n];
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		arr[i] = new int[n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = rand() % 4;
			cout << arr[i][j] << " ";
			if (arr[i][j] > 0)
				k *= arr[i][j];
			else
				k = 0;
		}
		cout << "         Proizvedenie el. >0: " << k << endl;
		k = 1;
		cout << endl;
	}
	for (int z = 1;z < n; z++) //цикл дл€ нахождени€ максимальной суммы диагоналей
	{
		for (int i = 0; i < n-z; i++) //верхн€€ часть
		{
			for (int j = 0; j < n; j++)
			{
				if (i == j)
					ve += arr[i][j + z];
			}
		}
		for (int i =z ; i < n; i++) // нижн€€ часть
		{
			for (int j = 0; j < n; j++)
			{
				if (i == j)
					ni += arr[i][j - z];
			}
		}
		if (max < ve)
			max = ve;
		ve = 0;
		if (max < ni)
			max = ni;
		ni = 0;
	}
	cout << "Max sum diagonaley: " << max << endl;
	return 0;
}

