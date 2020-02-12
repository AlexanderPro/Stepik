#include <iostream>
using namespace std;

int ** createArray(unsigned a, unsigned b)
{
	int ** m = new int *[a];
	for (unsigned i = 0; i != a; ++i)
		m[i] = new int[b];
	return m;
}

void swap_min(int * m[], unsigned rows, unsigned cols)
{
	int min = 2147483647;
	unsigned minRow = 0;
	for (unsigned i = 0; i < rows; i++)
	for (unsigned j = 0; j < cols; j++)
	{
		if (m[i][j] < min)
		{
			min = m[i][j];
			minRow = i;
		}
	}

	int* temp = m[0];
	m[0] = m[minRow];
	m[minRow] = temp;
}

void initArray(int ** m, unsigned a, unsigned b)
{
	int value = 1;
	for (unsigned i = 0; i < a; ++i)
	for (unsigned j = 0; j < b; ++j)
		m[i][j] = value++;
}

void outArray(int ** m, unsigned a, unsigned b)
{
	for (unsigned i = 0; i < a; ++i)
	{
		for (unsigned j = 0; j < b; ++j)
			cout << m[i][j] << " ";
		cout << endl;
	}
}

int main()
{
	int rows = 5;
	int cols = 5;
	int** m = createArray(rows, cols);
	initArray(m, rows, cols);
	m[rows - 1][cols - 1] = 0;
	outArray(m, rows, cols);
	cout << endl;
	swap_min(m, rows, cols);
	outArray(m, rows, cols);
	return 0;
}