/*
Переставьте соседние элементы массива (A[0] c A[1], A[2] c A[3] и т.д.). Если элементов нечетное число, то последний элемент остается на своем месте.

Формат входных данных
В первой строке вводится количество элементов в массиве. Во второй строке вводятся элементы массива.

Формат выходных данных
Выведите ответ на задачу.

Sample Input:
5
1 2 3 4 5

Sample Output:
2 1 4 3 5
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	long a, r = 0, t;
	vector<long> v;

	cin >> n;
	while (n--)
	{
		cin >> a;
		v.push_back(a);
	}

	for (size_t i = 0; i < v.size(); i++)
	{
		if ((i % 2 == 0) && (i < v.size() - 1))
		{
			t = v[i];
			v[i] = v[i + 1];
			v[i + 1] = t;
		}
	}

	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}

	return 0;
}