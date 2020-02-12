/*
��� ������ ����� �����, ������� ����� ��������� �� 100000 �����. ����������, ������� � ��� ����������� ��������� �����.

������� ������
�������� ����� N - ���������� ��������� ������, � ����� N �����.

�������� ������
�������� ����� �� ������.

Sample Input:
5
1 2 3 2 1

Sample Output:
3
*/

#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{
	int n, a;
	set<int> s;
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		cin >> a;
		s.insert(a);
	}
	cout << s.size();
	return 0;
}