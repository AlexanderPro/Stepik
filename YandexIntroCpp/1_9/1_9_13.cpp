/*
���� ������������������ �����, ������������� ������ 0. ������� ����� ���� ���� �����, �� ��������� ����.

������ ������� ������
�������� ������������������ ����� �����, �������������� ������ 0 (���� ����� 0 � ������������������ �� ������, � ������ ��� ������� �� ���������).

������ �������� ������
�������� ����� �� ������.

Sample Input:
1
7
9
0

Sample Output:
17
*/

#include <iostream>
#include <iomanip>
using namespace std;

double sum(double s)
{
	double a;
	cin >> a;
	if (a != 0)
	{
		s += a;
		return sum(s);
	}
	else
	{
		return s;
	}
}

int main()
{
	double s = 0;
	s = sum(s);
	cout << s;
	return 0;
}