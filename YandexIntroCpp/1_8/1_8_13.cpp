/*
По данным числам n и m заполните двумерный массив размером n×m числами от 1 до n×m “диагоналями”, как показано в примере.

Формат входных данных
Вводятся два числа n и m, не превышающие 100.

Формат выходных данных
Выведите полученный массив, отводя на вывод каждого элемента ровно 4 символа.

Sample Input:
3 5

Sample Output:
1   2   4   7  10
3   5   8  11  13
6   9  12  14  15
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int n, m, x, k = 0;
	int a[100][100];
	cin >> n >> m;

	for (int x = 0; x < n + m - 1; x++)
	{
		for (int j = x, i = 0; j > -1; j--, i++)
		{
			if (i < n && j < m)
			{
				a[i][j] = ++k;
			}
		}
	}

	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			cout << setw(4) << a[i][j];
		}
		cout << endl;
	}

	return 0;
}