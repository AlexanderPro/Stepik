#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	for (; n > 0; n--)
	{
		int a = 0;
		int p = 0;
		cin >> a;
		for (int i = 1; i <= a; i++)
		{
			if ((int)pow(2, i) <= a)
			{
				p = i;
			}
			else
			{
				break;
			}
		}
		cout << p << endl;
	}
	return 0;
}