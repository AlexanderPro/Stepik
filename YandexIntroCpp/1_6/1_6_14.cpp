/*
ƒаны вещественные числа a, b, c, d, e, f. –ешите систему линейных уравнений

‘ормат входных данных
¬вод€тс€ шесть чисел - коэффициенты уравнений системы.

‘ормат выходных данных
¬ывод программы зависит от вида решени€ этой системы.

≈сли система не имеет решений, то программа должна вывести единственное число 0.
≈сли система имеет бесконечно много решений, каждое из которых имеет вид y=kx+n, то программа должна вывести число 1, а затем значени€ k и n.
≈сли система имеет единственное решение (x0, y0), то программа должна вывести число 2, а затем значени€ x0 и y0.
≈сли система имеет бесконечно много решений вида x=x0, y Ч любое, то программа должна вывести число 3, а затем значение x0.
≈сли система имеет бесконечно много решений вида y=y0, x Ч любое, то программа должна вывести число 4, а затем значение y0.
≈сли люба€ пара чисел (x, y)  €вл€етс€ решением, то программа должна вывести число 5.

Sample Input 1:
1
0
0
1
3
3

Sample Output 1:
2 3 3

Sample Input 2:
1
1
2
2
1
2

Sample Output 2:
1 -1 1

Sample Input 3:
0
2
0
4
1
2

Sample Output 3:
4 0.5

Sample Input 4:
2
3
4
6
1
2

Sample Output 4:
1 -0.666667 0.333333

Sample Input 5:
0
1
0
3
5
15

Sample Output 5:
4 5

Sample Input 6:
1
0
1
0
3
3

Sample Output 6:
3 3
*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
	double a, b, c, d, e, f, D, Dx, Dy, zero, x, y;
	cin >> a >> b >> c >> d >> e >> f;
	zero = 1.0e-7;
	D = a * d - c * b;
	Dx = e * d - f * b;
	Dy = a * f - c * e;
	if (!fabs(D) <= zero) // ќдно решение
	{
		x = Dx / D;
		y = Dy / D;
		cout << 2 << " " << x << " " << y;
	}
	else
	{
		if (fabs(a) + fabs(b) + fabs(c) + fabs(d) <= zero)
		{
			if (fabs(e) + fabs(f) <= zero) // бесконечное множество решений
			{
				cout << 5;
			}
			else // решений нет
			{
				cout << 0;
			}
		}
		else if ((!fabs(Dx) <= zero) || (!fabs(Dy) <= zero)) // нет решений
		{
			cout << 0;
		}
		else if (b == 0)
		{
			if (!fabs(a) <= zero) cout << 3 << " " << e / a; // y - любое число
			else if (fabs(d) <= zero) cout << 3 << " " << f / c; // y - любое число
			else if (fabs(c) <= zero) cout << 4 << " " << f / d; // x - любое число
			else cout << 1 << " " << -c / d << " " << f / d; // y = kx + b
		}
		else if (a == 0)
		{
			if (!fabs(b) <= zero) cout << 4 << " " << e / b; // x - любое число
			else if (fabs(d) <= zero) cout << 3 << " " << f / c; // y - любое число
			else if (fabs(c) <= zero) cout << 4 << " " << f / d; // x - любое число
			else cout << 1 << " " << -c / d << " " << f / d; // y = kx + b
		}
		else cout << 1 << " " << -a / b << " " << e / b; // y = kx + b
	}

	return 0;
}