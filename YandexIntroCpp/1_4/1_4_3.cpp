/*
���� ��� ����� �����. �������� �������� ����������� �� ���. ���� ����� �����, �������� ����� �� ���.

������ ������� ������
�������� ��� �����.

������ �������� ������
�������� ����� �� ������.

Sample Input 1:
1
2

Sample Output 1:
2

Sample Input 2:
5
3

Sample Output 2:
5
*/

#include <iostream>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	if (a > b)
		cout << a;
	else
		cout << b;
	return 0;
}