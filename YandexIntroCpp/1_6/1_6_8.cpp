/*
���������� ������� �������� ���� ��������� ������������������, ������������� ������ 0.

������ ������� ������
�������� ������������������ ����� �����, �������������� ������ 0 (���� ����� 0 � ������������������ �� ������, � ������ ��� ������� �� ���������).

������ �������� ������
�������� ����� �� ������.

Sample Input:
1
7
9
0

Sample Output:
5.66666666667
*/

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
	int n;
	double r = 0;
	vector<int> v;
	while (1)
	{
		cin >> n;
		if (n == 0) break;
		v.push_back(n);
	}

	for (size_t i = 0; i < v.size(); i++)
	{
		r += v[i];
	}

	r = r / v.size();

	cout << setprecision(12);
	cout << r;
	return 0;
}