/*
Даны вещественные числа a, b, c, d, e, f. Известно, что система линейных уравнений
имеет ровно одно решение. Выведите два числа x и y, являющиеся решением этой системы.

Формат входных данных
Вводятся шесть чисел - коэффициенты уравнений системы.

Формат выходных данных
Выведите ответ на задачу.

Sample Input:
1
0
0
1
3
3

Sample Output:
3 3
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double a, b, c, d, e, f, x, y;
	cin >> a >> b >> c >> d >> e >> f;
	x = (e*d - f*b) / (a*d - b*c);
	y = (a*f - c*e) / (a*d - b*c);
	cout << setprecision(12);
	cout << x << " " << y;
	return 0;
}