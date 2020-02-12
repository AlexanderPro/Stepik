#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int a, b, c, d;
	double x1, x2;
	cin >> a >> b >> c;
	d = b*b - 4 * a*c;
	if (d < 0)
	{
		cout << "No real roots";
	}
	else if (d == 0)
	{
		x1 = -b / (2.0 * a);
		x2 = x1;
		cout << x1 << " " << x2;
	}
	else
	{
		x1 = (-b + sqrt(d)) / (2.0 * a);
		x2 = (-b - sqrt(d)) / (2.0 * a);
		cout << x1 << " " << x2;
	}
	return 0;
}