/*
Последовательность Фибоначчи определяется так:

F(0) = 0, F(1) = 1, …, F(n) = F(n−1) + F(n−2).

По данному числу N определите N-е число Фибоначчи F(N).

Формат входных данных
Вводится натуральное число N.

Формат выходных данных
Выведите ответ на задачу.

Sample Input:
6

Sample Output:
8
*/

#include <iostream>
using namespace std;

int main()
{
	int n, e1, e2, r;
	r = 0;
	e1 = 0;
	e2 = 0;
	cin >> n;
	for (size_t i = 0; i <= n; i++)
	{
		if (i == 0)
		{
			r = 0;
			e1 = r;
		}
		else
		if (i == 1)
		{
			r = 1;
			e2 = r;
		}
		else
		{
			r = e1 + e2;
			e1 = e2;
			e2 = r;
		}
	}
	cout << r;
	return 0;
}