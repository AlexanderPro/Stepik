/*
�� ������ ������ ����������, �������� �� ��� ����������� (�� ����, �������� ��������� ��� �����-�������, ��� � ������-������).

������� ������
�� ���� �������� 1 ������ ��� ��������.

�������� ������
���������� ������� yes, ���� ������ �������� �����������, � no � ��������� ������.
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s = "";
	bool result = true;
	getline(cin, s);

	for (size_t i = 0; i < s.size() / 2; i++)
	{
		if (s[i] != s[s.size() - i - 1])
		{
			result = false;
			break;
		}
	}

	cout << (result ? "yes" : "no");
	return 0;
}