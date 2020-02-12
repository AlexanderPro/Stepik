/*
� ������� �������� ��������� ����� ������� �������. ��������, ��� ���� ���� ����� ����� ������ �� ������, ���� ��� ���� �� �� ��� ������� ������. � ������� ������ ����������. ��������� ����������, ����� ���������� ���������� ��� ����� ������ ���������� ��� �������� ���, ����� �� ���� ������ �� ��� ������������.

������� ������
������� �������� ������ ���� ���������� (����� �������� ������� �� ������ �� ������), ����� ���������� ��� ����� � �������� � ������ ������ ����. ������ � ����������� �����, �� ������������� 100, ���������� ��� ����� � �������� �� ����������� 1000.

�������� ������
�������� ������������ ����� � ������������ ���������� ��� �����.

Sample Input:
26
5
30 35 40 41 42

Sample Output:
3
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int size, n, a, counter = 0, previousValue = -1;
	string s, name, markSecuence;
	double d;
	vector<int> sizes;

	cin >> size >> n;
	for (size_t i = 0; i < n; i++)
	{
		cin >> a;
		sizes.push_back(a);
	}

	sort(sizes.begin(), sizes.end());
	for (size_t i = 0; i < n; i++)
	{
		if (sizes[i] < size) continue;
		if (sizes[i] >= size && previousValue == -1)
		{
			counter++;
			previousValue = sizes[i];
		}
		else if ((sizes[i] - previousValue) >= 3)
		{
			counter++;
			previousValue = sizes[i];
		}
	}

	cout << counter;
	return 0;
}