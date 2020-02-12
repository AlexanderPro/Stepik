/*
Дано число n, не превосходящее 10, и массив размером n × n. Проверьте, является ли этот массив симметричным относительно главной диагонали. Выведите слово “YES”, если массив симметричный, и слово “NO” в противном случае.

Sample Input:
3
0 1 2
1 2 3
2 3 4

Sample Output:
YES
*/

#include <iostream>
using namespace std;

int main()
{
	int n;
	int a[100][100];

	cin >> n;

	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}

	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			if (i != j)
			{
				if (a[i][j] != a[j][i])
				{
					cout << "NO";
					return 0;
				}
			}
		}
	}

	cout << "YES";
	return 0;
}