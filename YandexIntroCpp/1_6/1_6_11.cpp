/*
Даны действительные коэффициенты a, b, c, при этом a ≠ 0 . Решите квадратное уравнение ax2 + bx + c = 0 и выведите все его корни.

Формат входных данных
Вводятся три действительных числа.

Формат выходных данных
Если уравнение имеет два корня, выведите два корня в порядке возрастания, если один корень — выведите одно число, если нет корней — не выводите ничего.

Sample Input:
1
-1
-2

Sample Output:
-1 2
*/

#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
	double a, b, c, d, x1, x2;
	cin >> a >> b >> c;
	cout << setprecision(12);
	d = b*b - 4 * a*c;
	if (d == 0)
	{
		x1 = -b / (2.0 * a);
		cout << x1;
	}
	else if (d > 0)
	{
		x1 = (-b + sqrt(d)) / (2.0 * a);
		x2 = (-b - sqrt(d)) / (2.0 * a);
		if (x1 <= x2)
		{
			cout << x1 << " " << x2;
		}
		else
		{
			cout << x2 << " " << x1;
		}

	}
	return 0;
}