/*
�������� ��� ������ �������� �������.

������ ������� ������
� ������ ������ �������� ���������� ��������� � �������. �� ������ ������ �������� �������� �������.

������ �������� ������
�������� ����� �� ������. �������� ��������� � ��� �� �������, � ������� ��� ������ � �������.

Sample Input:
7
1 2 2 3 3 3 4

Sample Output:
2 2 4
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
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
		if (v[i] % 2 == 0)
		{
			cout << v[i] << " ";
		}
	}

	return 0;
}