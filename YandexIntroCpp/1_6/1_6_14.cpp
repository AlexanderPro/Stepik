/*
���� ������������ ����� a, b, c, d, e, f. ������ ������� �������� ���������

������ ������� ������
�������� ����� ����� - ������������ ��������� �������.

������ �������� ������
����� ��������� ������� �� ���� ������� ���� �������.

���� ������� �� ����� �������, �� ��������� ������ ������� ������������ ����� 0.
���� ������� ����� ���������� ����� �������, ������ �� ������� ����� ��� y=kx+n, �� ��������� ������ ������� ����� 1, � ����� �������� k � n.
���� ������� ����� ������������ ������� (x0, y0), �� ��������� ������ ������� ����� 2, � ����� �������� x0 � y0.
���� ������� ����� ���������� ����� ������� ���� x=x0, y � �����, �� ��������� ������ ������� ����� 3, � ����� �������� x0.
���� ������� ����� ���������� ����� ������� ���� y=y0, x � �����, �� ��������� ������ ������� ����� 4, � ����� �������� y0.
���� ����� ���� ����� (x, y)  �������� ��������, �� ��������� ������ ������� ����� 5.

Sample Input 1:
1
0
0
1
3
3

Sample Output 1:
2 3 3

Sample Input 2:
1
1
2
2
1
2

Sample Output 2:
1 -1 1

Sample Input 3:
0
2
0
4
1
2

Sample Output 3:
4 0.5

Sample Input 4:
2
3
4
6
1
2

Sample Output 4:
1 -0.666667 0.333333

Sample Input 5:
0
1
0
3
5
15

Sample Output 5:
4 5

Sample Input 6:
1
0
1
0
3
3

Sample Output 6:
3 3
*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
	double a, b, c, d, e, f, D, Dx, Dy, zero, x, y;
	cin >> a >> b >> c >> d >> e >> f;
	zero = 1.0e-7;
	D = a * d - c * b;
	Dx = e * d - f * b;
	Dy = a * f - c * e;
	if (!fabs(D) <= zero) // ���� �������
	{
		x = Dx / D;
		y = Dy / D;
		cout << 2 << " " << x << " " << y;
	}
	else
	{
		if (fabs(a) + fabs(b) + fabs(c) + fabs(d) <= zero)
		{
			if (fabs(e) + fabs(f) <= zero) // ����������� ��������� �������
			{
				cout << 5;
			}
			else // ������� ���
			{
				cout << 0;
			}
		}
		else if ((!fabs(Dx) <= zero) || (!fabs(Dy) <= zero)) // ��� �������
		{
			cout << 0;
		}
		else if (b == 0)
		{
			if (!fabs(a) <= zero) cout << 3 << " " << e / a; // y - ����� �����
			else if (fabs(d) <= zero) cout << 3 << " " << f / c; // y - ����� �����
			else if (fabs(c) <= zero) cout << 4 << " " << f / d; // x - ����� �����
			else cout << 1 << " " << -c / d << " " << f / d; // y = kx + b
		}
		else if (a == 0)
		{
			if (!fabs(b) <= zero) cout << 4 << " " << e / b; // x - ����� �����
			else if (fabs(d) <= zero) cout << 3 << " " << f / c; // y - ����� �����
			else if (fabs(c) <= zero) cout << 4 << " " << f / d; // x - ����� �����
			else cout << 1 << " " << -c / d << " " << f / d; // y = kx + b
		}
		else cout << 1 << " " << -a / b << " " << e / b; // y = kx + b
	}

	return 0;
}