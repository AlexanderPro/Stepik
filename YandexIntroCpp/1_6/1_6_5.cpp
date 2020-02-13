/*
Даны длины сторон треугольника. Вычислите площадь треугольника.

Формат входных данных
Вводятся три положительных числа.

Формат выходных данных
Выведите ответ на задачу.

Sample Input:
3
4
5

Sample Output:
6
*/

#include <iostream>
#include <math.h> 
using namespace std;

int main()
{
	double a, b, c, p, s;
	cin >> a >> b >> c;
	p = (a + b + c) / 2;
	s = sqrt(p*(p - a)*(p - b)*(p - c));
	cout << s;
	return 0;
}