﻿/*
Последовательность Фибоначчи определяется так:

F(0) = 0, F(1) = 1, …, F(n) = F(n−1) + F(n−2).

Дано натуральное число A. Определите, каким по счету числом Фибоначчи оно является, то есть выведите такое число N, что F(N) = A. Если А не является числом Фибоначчи, выведите число -1.

Формат входных данных
Вводится натуральное число A > 1.

Формат выходных данных
Выведите ответ на задачу.

Sample Input:
8

Sample Output:
6
*/

#include <iostream>
using namespace std;

int main()
{
	int n, e1, e2, r, a, i = 0;
	r = 0;
	e1 = 0;
	e2 = 0;
	cin >> a;
	while (1)
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
		if (r == a)
		{
			break;
		}
		else if (r > a)
		{
			i = -1;
			break;
		}
		else
		{
			i++;
		}
	}
	cout << i;
	return 0;
}