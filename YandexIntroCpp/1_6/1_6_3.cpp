/*
Дано положительное действительное число X. Выведите его дробную часть.

Формат входных данных
Вводятся положительное действительное число.

Формат выходных данных
Выведите ответ на задачу.

Sample Input:
17.9

Sample Output:
0.9
*/

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	double n;
	cin >> n;
	n = n - trunc(n);
	cout << n;
	return 0;
}