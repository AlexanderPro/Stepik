#include <iostream>
using namespace std;

void reverseNumberArray()
{
	int a;
	cin >> a;
	if (a != 0)
	{
		reverseNumberArray();
		cout << a << " ";
	}
	else
	{
		return;
	}
}

int main()
{
	reverseNumberArray();
	return 0;
}