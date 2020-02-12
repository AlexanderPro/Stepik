/*
Дан многочлен P(x)=anxn + an−1xn−1+ … + a1x + a0 и число x. Вычислите значение этого многочлена, воспользовавшись схемой Горнера:

P(x)=(…(((anx + an−1)x + an−2)x + an−3) … )x+ a0

Формат входных данных
Сначала программе подается на вход целое неотрицательное число n ≤ 20, затем действительное число x, затем следует n+1 вещественное число — коэффициенты многочлена от старшего к младшему.

Формат выходных данных
Программа должна вывести значение многочлена.

Sample Input 1:
1
0.000
1.000
1.000

Sample Output 1:
1

Sample Input 2:
2
0.500
1.000
1.000
1.000

Sample Output 2:
1.75
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
	int n;
	double a, x, r = 0;
	vector<double> v;
	cin >> n >> x;
	n++;
	while (n--)
	{
		cin >> a;
		if (a == 0) break;
		v.push_back(a);
	}

	for (int i = 0; i < v.size(); i++)
	{
		if (i == 0)
		{
			r = v[i];
		}

		if (i < v.size() - 1)
		{
			r = r * x + v[i + 1];
		}
	}

	cout << setprecision(12);
	cout << r;
	return 0;
}