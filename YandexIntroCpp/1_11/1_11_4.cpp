/*
Во входной строке записана последовательность чисел через пробел. Для каждого числа выведите слово YES (в отдельной строке), если это число ранее встречалось в последовательности или NO, если не встречалось.

Входные данные
Вводится число N - количество элементов списка, а затем N чисел.

Выходные данные
Выведите ответ на задачу.

Sample Input:
6
1 2 3 2 3 4

Sample Output:
NO
NO
NO
YES
YES
NO
*/

#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int main()
{
	int n, a;
	set<int> s;
	vector<string> v;
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		cin >> a;
		if (s.find(a) == s.end())
		{
			v.push_back("NO");
		}
		else
		{
			v.push_back("YES");
		}
		s.insert(a);
	}

	for (auto el : v)
	{
		cout << el << endl;
	}

	return 0;
}