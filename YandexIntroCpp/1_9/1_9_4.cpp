/*
Даны четыре действительных числа: x1, y1, x2, y2. Напишите функцию distance(x1, y1, x2, y2), вычисляющую расстояние между точкой (x1. y1) и (x2, y2). Считайте четыре действительных числа и выведите результат работы этой функции.

Формат входных данных
Вводятся четыре действительных числа.

Формат выходных данных
Выведите ответ на задачу.

Sample Input:
0
0
1
1

Sample Output:
1.41421
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

int main()
{
	double x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	cout << distance(x1, y1, x2, y2);
	return 0;
}