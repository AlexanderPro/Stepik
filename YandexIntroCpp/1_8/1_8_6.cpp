/*
Дан двумерный массив и два числа: i и j. Поменяйте в массиве столбцы с номерами i и j

Формат входных данных
Программа получает на вход размеры массива n и m, не превосходящие 100, затем элементы массива, затем числа i и j.

Формат выходных данных
Выведите результат.

Sample Input:
3 4
11 12 13 14
21 22 23 24
31 32 33 34
0 1

Sample Output:
12 11 13 14
22 21 23 24
32 31 33 34
*/

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int n, m, c1, c2, t;
	int a[100][100];

	cin >> n >> m;

	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}

	cin >> c1 >> c2;

	for (size_t i = 0; i < n; i++)
	{
		t = a[i][c1];
		a[i][c1] = a[i][c2];
		a[i][c2] = t;
	}

	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}