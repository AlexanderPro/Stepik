/*
��� ������ �����. ����������, ������� � ��� ��� ���������, ������ ���� �����. ���������, ��� ����� ��� ��������, ������ ���� ����� �������� ���� ����, ������� ���������� ���������.

������ ������� ������
� ������ ������ �������� ���������� ��������� � �������. �� ������ ������ �������� �������� �������.

������ �������� ������
�������� ����� �� ������.

Sample Input 1:
5
1 2 3 2 3

Sample Output 1:
2

Sample Input 2:
5
1 1 1 1 1

Sample Output 2:
10
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	long a, r = 0, t, prev;
	vector<long> v;

	cin >> n;
	while (n--)
	{
		cin >> a;
		v.push_back(a);
	}

	for (size_t i = 0; i < v.size(); i++)
	{
		for (size_t j = i + 1; j < v.size(); j++)
		{
			if (v[i] == v[j]) r++;
		}
	}

	cout << r;

	return 0;
}