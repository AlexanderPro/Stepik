/*
Даны два списка чисел, которые могут содержать до 100000 чисел каждый. Посчитайте, сколько чисел содержится одновременно как в первом списке, так и во втором.

Входные данные
Вводится число N - количество элементов первого списка, а затем N чисел первого списка.
Затем вводится число M - количество элементов второго списка, а затем M чисел второго списка.

Выходные данные
Выведите ответ на задачу.

Sample Input:
3
1 3 2
3
4 3 2

Sample Output:
2
*/

#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int main()
{
	int n, a;
	set<int> s1;
	set<int> s2;

	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		cin >> a;
		s1.insert(a);
	}

	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		cin >> a;
		s2.insert(a);
	}

	a = 0;
	for (auto el : s1)
	{
		if (s2.find(el) != s2.end())
		{
			a++;
		}
	}

	cout << a;
	return 0;
}