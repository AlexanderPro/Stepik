/*
���� ����������� ����� N. �������� ����� YES, ���� ����� N �������� ������ �������� ������, ��� ����� NO � ��������� ������.

������ ������� ������
�������� ����������� �����.

������ �������� ������
�������� ����� �� ������.

Sample Input 1:
1

Sample Output 1:
YES

Sample Input 2:
2

Sample Output 2:
YES
*/

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int n, i, p;
	bool r = false;
	i = 0;
	p = 0;
	cin >> n;

	do
	{
		p = pow(2, i);
		r = p == n;
		i++;
	} while (p < n);

	cout << (r ? "YES" : "NO");

	return 0;
}