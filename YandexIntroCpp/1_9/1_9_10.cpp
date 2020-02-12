/*
���� ����������� ����� n > 1. �������� ��� ���������� ��������, �������� �� 1.
������� �������� � ���� ������� MinDivisor(n). ���������� �������� � ��������� ������ ���� ��������������� ����� �� n.
��������. ���� � ����� n ��� ��������, �������� n , �� ����� n � ������� � ������� ����� ���� ����� n.

������ ������� ������
�������� ����������� �����.

������ �������� ������
�������� ����� �� ������.

Sample Input 1:
4

Sample Output 1:
2

Sample Input 2:
5

Sample Output 2:
5
*/

#include <iostream>
#include <math.h>
using namespace std;

int MinDivisor(int n)
{
	for (int i = 2; i <= n && i <= sqrt(n); i++)
	{
		if (n % i == 0) return i;
	}
	return n;
}

int main()
{
	int n;
	cin >> n;
	cout << MinDivisor(n);
	return 0;
}