/*
���� ������������ ����� a, b, c, d, e, f. ��������, ��� ������� �������� ���������
����� ����� ���� �������. �������� ��� ����� x � y, ���������� �������� ���� �������.

������ ������� ������
�������� ����� ����� - ������������ ��������� �������.

������ �������� ������
�������� ����� �� ������.

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