/*
���� ���� �������������� �����: x, y, xc, yc, r. ���������, ����������� �� ����� (x, y) ����� � ������� (xc, yc) � �������� r. ���� ����� ����������� �����, �������� ����� YES, ����� �������� ����� NO.
������� ������ ��������� ������� IsPointInCircle(x, y, xc, yc, r), ������������ True, ���� ����� ����������� ����� � False, ���� �� �����������. �������� ��������� ������ ������� ���������� �����, ������� ������� IsPointInCircle � � ����������� �� ������������� �������� ������� �� ����� ����������� ���������.
������� IsPointInCircle �� ������ ��������� ���������� if.

������ ������� ������
�������� ���� �������������� �����.

������ �������� ������
�������� ����� �� ������.

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