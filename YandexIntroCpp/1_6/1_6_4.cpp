/*
���� ������������� �������������� ����� X. �������� ��� ������ ����� ����� ���������� �����.

������ ������� ������
�������� ������������� �������������� �����.

������ �������� ������
�������� ����� �� ������.

Sample Input:
1.79

Sample Output:
7
*/

#include <iostream>
#include <math.h> 
using namespace std;

int main()
{
	double n;
	cin >> n;
	n *= 10;
	n = n - (n - trunc(n));
	n = (int)n % 10;
	cout << n;
	return 0;
}