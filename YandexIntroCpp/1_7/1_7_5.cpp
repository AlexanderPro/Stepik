/*
������� ���������� ������������� ��������� � ������ �������.

������ ������� ������
� ������ ������ �������� ���������� ��������� � �������. �� ������ ������ �������� �������� �������.

������ �������� ������
�������� ����� �� ������.

Sample Input:
5
1 -2 3 -4 5

Sample Output:
3
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, r = 0;
	double a;
	vector<int> v;

	cin >> n;
	while (n--)
	{
		cin >> a;
		v.push_back(a);
	}

	for (size_t i = 0; i < v.size(); i++)
	{
		if (v[i]> 0) r++;
	}

	cout << r;
	return 0;
}