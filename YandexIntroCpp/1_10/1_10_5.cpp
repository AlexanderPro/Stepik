/*
�������� ���� ������, �������� ��� �������. �� ����, ���� ���� ������� �������� ����� - �������� �� ��������� � ��������. �������, �� ���������� ��������� ������, ����� �������� ��� ���������.

������� ������
�������� ����������� ������.

�������� ������
�������� ����� �� ������.

Sample Input:
b

Sample Output:
B
*/

#include <iostream>
#include <ctype.h>
using namespace std;

int main()
{
	char ch;
	cin >> ch;
	cout << ((ch >= 'a' && ch <= 'z') ? (char)toupper(ch) : (ch >= 'A' && ch <= 'Z') ? (char)tolower(ch) : ch);
	return 0;
}