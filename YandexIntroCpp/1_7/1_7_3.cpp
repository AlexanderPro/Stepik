/*
�������� ��� �������� ������� � ������� ��������� (�� ���� A[0], A[2], A[4], ...).

������ ������� ������
� ������ ������ �������� ���������� ��������� � �������. �� ������ ������ �������� �������� �������.

������ �������� ������
�������� ����� �� ������.

Sample Input:
5
1 2 3 4 5

Sample Output:
1 3 5
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
		if (i % 2 == 0)
		{
			cout << v[i] << " ";
		}
	}

	return 0;
}