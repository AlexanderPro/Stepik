/*
��� ������, ������������� �� ���������� ��������� � ���. ����������, ������� � ��� ��������� ���������.

������ ������� ������
� ������ ������ �������� ���������� ��������� � �������. �� ������ ������ �������� �������� �������.

������ �������� ������
�������� ����� �� ������.

Sample Input:
6
1 2 2 3 3 3

Sample Output:
3
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	long a, r = 0;
	vector<long> v;

	cin >> n;
	while (n--)
	{
		cin >> a;
		v.push_back(a);
	}

	for (size_t i = 0; i < v.size(); i++)
	{
		if (i == 0) r++;
		if ((i < v.size() - 1) && (v[i] != v[i + 1])) r++;
	}

	cout << r;
	return 0;
}