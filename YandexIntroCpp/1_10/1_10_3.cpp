/*
�� ���������� ������� ����������, �������� �� �� ������.

������� ������
�������� ����������� ������.

�������� ������
�������� "yes", ���� ������ �������� ������ � "no" � ��������� ������. �������� ��������, ��� ����� ����� �������� ���������� �������.

Sample Input 1:
1

Sample Output 1:
yes

Sample Input 2:
a

Sample Output 2:
no
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	char ch;
	cin >> ch;
	cout << ((ch >= '0' && ch <= '9') ? "yes" : "no");
	return 0;
}