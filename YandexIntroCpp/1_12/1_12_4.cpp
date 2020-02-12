/*
В обувном магазине продается обувь разного размера. Известно, что одну пару обуви можно надеть на другую, если она хотя бы на три размера больше. В магазин пришел покупатель. Требуется определить, какое наибольшее количество пар обуви сможет предложить ему продавец так, чтобы он смог надеть их все одновременно.

Входные данные
Сначала вводится размер ноги покупателя (обувь меньшего размера он надеть не сможет), затем количество пар обуви в магазине и размер каждой пары. Размер — натуральное число, не превосходящее 100, количество пар обуви в магазине не превосходит 1000.

Выходные данные
Выведите единственное число — максимальное количество пар обуви.

Sample Input:
26
5
30 35 40 41 42

Sample Output:
3
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int size, n, a, counter = 0, previousValue = -1;
	string s, name, markSecuence;
	double d;
	vector<int> sizes;

	cin >> size >> n;
	for (size_t i = 0; i < n; i++)
	{
		cin >> a;
		sizes.push_back(a);
	}

	sort(sizes.begin(), sizes.end());
	for (size_t i = 0; i < n; i++)
	{
		if (sizes[i] < size) continue;
		if (sizes[i] >= size && previousValue == -1)
		{
			counter++;
			previousValue = sizes[i];
		}
		else if ((sizes[i] - previousValue) >= 3)
		{
			counter++;
			previousValue = sizes[i];
		}
	}

	cout << counter;
	return 0;
}