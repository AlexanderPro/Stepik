#include <iostream>
using namespace std;

void shiftArrayToLeft(int* m, unsigned size)
{
	if (size <= 1) return;
	int currentElement = 0;
	int previousElement = m[size - 1];
	for (int i = size - 2; i >= 0; i--)
	{
		currentElement = m[i];
		m[i] = previousElement;
		previousElement = currentElement;
	}
	m[size - 1] = currentElement;
}

void rotate(int a[], unsigned size, int shift)
{
	for (; shift > 0; shift--)
	{
		shiftArrayToLeft(a, size);
	}
}

int main()
{
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	rotate(a, 10, 1);
	return 0;
}