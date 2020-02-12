/*
���� ������ �������������� �����: x1, y1, x2, y2. �������� ������� distance(x1, y1, x2, y2), ����������� ���������� ����� ������ (x1. y1) � (x2, y2). �������� ������ �������������� ����� � �������� ��������� ������ ���� �������.

������ ������� ������
�������� ������ �������������� �����.

������ �������� ������
�������� ����� �� ������.

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