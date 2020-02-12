/*
������� � ������ ������ ����� ������� ����� � �������� ���.

������� ������
�������� ���� ������. ����� � ��� �������� ����� ��������.

�������� ������
�������� ����� ������� �����. ���� ����� ���� ���������, �� �������� �����, ������� ����������� ������.

Sample Input:
Everyone of us has all we need

Sample Output:
Everyone
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s = "", r = " ";
	int counter = 0;
	int max = -1;
	getline(cin, s);
	int length = s.length();

	for (int i = 0; i < length; i++)
	{
		if (s[i] != ' ') counter++;
		if (s[i] == ' ' || i == length - 1) {
			if (counter > max) {
				max = counter;
				r = (i == length - 1) ? s.substr(i + 1 - max, max) : s.substr(i - max, max);
			}
			counter = 0;
		}
	}
	cout << r;
	return 0;
}