/*
Даны два действительных числа x и y. Проверьте, принадлежит ли точка с координатами (x, y) заштрихованному квадрату (включая его границу). Если точка принадлежит квадрату, выведите слово YES, иначе выведите слово NO. На рисунке сетка проведена с шагом 1.
Решение должно содержать функцию IsPointInSquare(x, y), возвращающую True, если точка принадлежит квадрату и False, если не принадлежит. Основная программа должна считать координаты точки, вызвать функцию IsPointInSquare и в зависимости от возвращенного значения вывести на экран необходимое сообщение.

Функция IsPointInSquare не должна содержать инструкцию if.

Формат входных данных
Вводятся два действительных числа.

Формат выходных данных
Выведите ответ на задачу.

Sample Input 1:
0
0

Sample Output 1:
YES

Sample Input 2:
1
1

Sample Output 2:
NO
*/

#include <iostream>
#include <math.h>
using namespace std;

struct Point
{
	Point(){}
	Point(const double X, const double Y) : x(X), y(Y){}
	double X(){ return x; }
	double Y(){ return y; }

private:
	double x, y, z;
};

struct Triangle
{
	Triangle(const Point &p1, const Point &p2, const Point &p3)
	{
		vert[0] = p1;
		vert[1] = p2;
		vert[2] = p3;
	}

	bool Contains(Point p)
	{
		double pl1, pl2, pl3;
		pl1 = (vert[0].X() - p.X())*(vert[1].Y() - vert[0].Y()) - (vert[1].X() - vert[0].X())*(vert[0].Y() - p.Y());
		pl2 = (vert[1].X() - p.X())*(vert[2].Y() - vert[1].Y()) - (vert[2].X() - vert[1].X())*(vert[1].Y() - p.Y());
		pl3 = (vert[2].X() - p.X())*(vert[0].Y() - vert[2].Y()) - (vert[0].X() - vert[2].X())*(vert[2].Y() - p.Y());
		return ((pl1 >= 0 && pl2 >= 0 && pl3 >= 0) || (pl1 <= 0 && pl2 <= 0 && pl3 <= 0));
	}

private:
	Point vert[3];
};

bool IsPointInSquare(double x, double y)
{
	Point p(x, y);
	Triangle t1(Point(0, 0), Point(0, 1), Point(1, 0));
	Triangle t2(Point(0, 0), Point(0, -1), Point(1, 0));
	Triangle t3(Point(0, 0), Point(0, 1), Point(-1, 0));
	Triangle t4(Point(0, 0), Point(0, -1), Point(-1, 0));

	bool r = t1.Contains(p) || t2.Contains(p) || t3.Contains(p) || t4.Contains(p);
	return r;
}

int main()
{
	double x, y;
	cin >> x >> y;
	cout << (IsPointInSquare(x, y) ? "YES" : "NO");
	return 0;
}