/*
Выведите все исходные точки в порядке возрастания их расстояний от начала координат.

Входные данные
Программа получает на вход набор точек на плоскости. Сначала задано количество точек n, затем идет последовательность из n строк, каждая из которых содержит два числа: координаты точки. Величина n не превосходит 100, все исходные координаты – целые числа, не превосходящие 103.

Выходные данные
Необходимо вывести все исходные точки в порядке возрастания их расстояний от начала координат.

Sample Input:
2
1 2
2 3

Sample Output:
1 2
2 3
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Point
{
	Point(int x, int y, double d) : x(x), y(y), d(d)
	{}

	int x;
	int y;
	double d;
};

bool compare(Point p1, Point p2)
{
	return p1.d < p2.d;
}

int main()
{
	int n, x, y;
	double d;
	vector<Point> v;

	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		cin >> x;
		cin >> y;
		d = sqrt(x*x + y*y);
		Point p(x, y, d);
		v.push_back(p);
	}

	sort(v.begin(), v.end(), compare);
	for (auto p : v)
	{
		cout << p.x << " " << p.y << endl;
	}
	return 0;
}