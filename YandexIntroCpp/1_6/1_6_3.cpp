/*
���� ������������� �������������� ����� X. �������� ��� ������� �����.

������ ������� ������
�������� ������������� �������������� �����.

������ �������� ������
�������� ����� �� ������.

Sample Input:
17.9

Sample Output:
0.9
*/

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	double n;
	cin >> n;
	n = n - trunc(n);
	cout << n;
	return 0;
}