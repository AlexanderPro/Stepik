/*
Даны пять действительных чисел: x, y, xc, yc, r. Проверьте, принадлежит ли точка (x, y) кругу с центром (xc, yc) и радиусом r. Если точка принадлежит кругу, выведите слово YES, иначе выведите слово NO.
Решение должно содержать функцию IsPointInCircle(x, y, xc, yc, r), возвращающую True, если точка принадлежит кругу и False, если не принадлежит. Основная программа должна считать координаты точки, вызвать функцию IsPointInCircle и в зависимости от возвращенного значения вывести на экран необходимое сообщение.
Функция IsPointInCircle не должна содержать инструкцию if.

Формат входных данных
Вводятся пять действительных чисел.

Формат выходных данных
Выведите ответ на задачу.

Sample Input 1:
0.5
0.5
0
0
1

Sample Output 1:
YES

Sample Input 2:
0.5
0.5
1
1
0.1

Sample Output 2:
NO
*/

#include <iostream>
#include <math.h>
using namespace std;

double distance(double x1, double y1, double x2, double y2)
{
	double x = fabs(x1 - x2);
	double y = fabs(y1 - y2);
	double d = sqrt(x*x + y*y);
	return d;
}

bool IsPointInCircle(double x, double y, double xc, double yc, double r)
{
	double d = distance(x, y, xc, yc);
	bool result = d <= r;
	return result;
}

int main()
{
	double x, y, xc, yc, r;
	cin >> x >> y >> xc >> yc >> r;
	cout << (IsPointInCircle(x, y, xc, yc, r) ? "YES" : "NO");
	return 0;
}