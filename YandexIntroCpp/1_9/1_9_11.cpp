/*
���� ����������� ����� n > 1. ���������, �������� �� ��� �������. ��������� ������ ������� ����� YES, ���� ����� ������� � NO, ���� ����� ���������.
������� �������� � ���� ������� IsPrime(n), ������� ���������� True ��� ������� ����� � False ��� ��������� �����. ���������� �������� � ��������� ������ ���� ��������������� ����� �� n.

������ ������� ������
�������� ����������� �����.

������ �������� ������
�������� ����� �� ������.

Sample Input 1:
2

Sample Output 1:
YES

Sample Input 2:
4

Sample Output 2:
NO
*/

#include <iostream>
#include <math.h>
using namespace std;

bool IsPrime(int n)
{
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0) return false;
	}
	return true;
}

int main()
{
	int n;
	cin >> n;
	cout << (IsPrime(n) ? "YES" : "NO");
	return 0;
}