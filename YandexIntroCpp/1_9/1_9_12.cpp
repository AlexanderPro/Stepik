/*
Возводить в степень можно гораздо быстрее, чем за n умножений! Для этого нужно воспользоваться следующими рекуррентными соотношениями:

an = (a2)n/2  при четном n,
an = a × an−1 при нечетном n.

Реализуйте алгоритм быстрого возведения в степень с помощью рекурсивной функции.

Формат входных данных
Вводятся действительное число a и целое неотрицательное число n.

Формат выходных данных
Выведите ответ на задачу.

Sample Input 1:
2.0
1

Sample Output 1:
2

Sample Input 2:
2
2

Sample Output 2:
4
*/

#include <iostream>
#include <iomanip>
using namespace std;

double powerp(double a, int n)
{
	if (n == 0) return 1;
	if (n % 2 == 0) return powerp(a * a, n / 2);
	return a * powerp(a, n - 1);
}

double power(double a, int n)
{
	int p = abs(n);
	double r = (n % 2 == 0) ? powerp(a*a, p / 2) : powerp(a, p);
	r = n >= 0 ? r : 1 / r;
	return r;
}

int main()
{
	double a;
	int n;
	cin >> a >> n;
	cout << power(a, n);
	return 0;
}