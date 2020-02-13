/*
Дан массив чисел. Выведите все элементы массива, которые больше предыдущего элемента .

Формат входных данных
В первой строке вводится количество элементов в массиве. Во второй строке вводятся элементы массива.

Формат выходных данных
Выведите ответ на задачу.

Sample Input:
5
1 5 2 4 3

Sample Output:
5 4
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, r = 0;
	double a;
	vector<int> v;

	cin >> n;
	while (n--)
	{
		cin >> a;
		v.push_back(a);
	}

	for (size_t i = 0; i < v.size(); i++)
	{
		if (i > 0 && v[i] > v[i - 1])
		{
			cout << v[i] << " ";
		}
	}

	return 0;
}