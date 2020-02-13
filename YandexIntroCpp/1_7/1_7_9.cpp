/*
Выведите значение наименьшего нечетного элемента списка, а если в списке нет нечетных элементов - выведите число 0.

Формат входных данных
В первой строке вводится количество элементов в массиве. Во второй строке вводятся элементы массива.

Формат выходных данных
Выведите ответ на задачу.

Sample Input 1:
5
0 1 2 3 4

Sample Output 1:
1

Sample Input 2:
5
2 4 6 8 10

Sample Output 2:
0
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	long a, m = 0;
	vector<int> v;

	cin >> n;
	while (n--)
	{
		cin >> a;
		v.push_back(a);
	}

	for (size_t i = 0; i < v.size(); i++)
	{
		if (v[i] % 2 != 0 && (v[i] < m || m == 0))
		{
			m = v[i];
		}
	}

	cout << m;
	return 0;
}