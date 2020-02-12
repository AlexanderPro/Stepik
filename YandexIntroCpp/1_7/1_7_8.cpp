/*
Выведите значение наименьшего из всех положительных элементов в массиве. Известно, что в массиве есть хотя бы один положительный элемент.

Формат входных данных
В первой строке вводится количество элементов в массиве. Во второй строке вводятся элементы массива.

Формат выходных данных
Выведите ответ на задачу.

Sample Input:
5
5 -4 3 -2 1

Sample Output:
1
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	double a, m = 0;
	vector<int> v;

	cin >> n;
	while (n--)
	{
		cin >> a;
		v.push_back(a);
	}

	for (size_t i = 0; i < v.size(); i++)
	{
		if (v[i] > 0 && (v[i] < m || m == 0))
		{
			m = v[i];
		}
	}

	cout << m;
	return 0;
}