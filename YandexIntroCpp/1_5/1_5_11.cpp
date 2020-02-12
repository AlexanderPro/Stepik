/*
������������������ ������� �� ����������� ����� � ����������� ������ 0. ���������� �������� ������� �� �������� �������� � ���� ������������������, �� ���� ��������, ������� ����� ����������, ���� �� ������������������ ������� ���������� �������.

������ ������� ������
�������� ������������������ ����� �����, �������������� ������ 0 (���� ����� 0 � ������������������ �� ������, � ������ ��� ������� �� ���������).

������ �������� ������
�������� ����� �� ������.

Sample Input 1:
4
4
2
3
0

Sample Output 1:
4

Sample Input 2:
2
1
0

Sample Output 2:
1
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(int i, int j) { return (i>j); }

int main()
{
	int n, m1, m2;
	std::vector<int> v;

	while (1)
	{
		cin >> n;
		if (n == 0) break;
		v.push_back(n);
	}

	std::sort(v.begin(), v.end(), compare);
	cout << v[1];
	return 0;
}