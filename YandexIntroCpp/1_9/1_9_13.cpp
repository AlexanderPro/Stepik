/*
Дана последовательность чисел, завершающаяся числом 0. Найдите сумму всех этих чисел, не используя цикл.

Формат входных данных
Вводится последовательность целых чисел, оканчивающаяся числом 0 (само число 0 в последовательность не входит, а служит как признак ее окончания).

Формат выходных данных
Выведите ответ на задачу.

Sample Input:
1
7
9
0

Sample Output:
17
*/

#include <iostream>
#include <iomanip>
using namespace std;

double sum(double s)
{
	double a;
	cin >> a;
	if (a != 0)
	{
		s += a;
		return sum(s);
	}
	else
	{
		return s;
	}
}

int main()
{
	double s = 0;
	s = sum(s);
	cout << s;
	return 0;
}