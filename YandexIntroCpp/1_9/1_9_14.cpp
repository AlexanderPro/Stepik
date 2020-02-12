/*
�������� ������� fib(n), ������� �� ������� ������ �������������� n ���������� n-e ����� ���������. � ���� ������ ������ ������������ ����� - ����������� ��������.
������ � ������ ����� ��������� ����� 1, � ������ ��������� ����� ����� ���� ����������.

������ ������� ������
�������� ����� �����.

������ �������� ������
�������� ����� �� ������.

Sample Input:
1

Sample Output:
1
*/

#include <iostream>
#include <iomanip>
using namespace std;

long fib(long n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;
	return fib(n - 1) + fib(n - 2);
}

int main()
{
	long n;
	cin >> n;
	cout << fib(n);
	return 0;
}