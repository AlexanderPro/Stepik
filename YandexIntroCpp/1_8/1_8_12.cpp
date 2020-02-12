/*
По данным числам n и m заполните двумерный массив размером n×m числами от 1 до n×m “змейкой”, как показано в примере.

Формат входных данных
Вводятся два числа n и m, каждое из которых не превышает 30.

Формат выходных данных
Выведите полученный массив, отводя на вывод каждого элемента ровно 4 символа.

Sample Input:
3 5

Sample Output:
1   2   3   4   5
10   9   8   7   6
11  12  13  14  15
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int n, m, k = 0;
	int a[100][100];

	cin >> n >> m;

	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			a[i][j] = (++k);
		}
	}

	for (size_t i = 0; i < n; i++)
	{
		if (i % 2 == 0)
		{
			for (size_t j = 0; j < m; j++)
			{
				cout << setw(4) << a[i][j];
			}
		}
		else
		{
			for (size_t j = m; j > 0; j--)
			{
				cout << setw(4) << a[i][j - 1];
			}
		}
		cout << endl;
	}

	return 0;
}