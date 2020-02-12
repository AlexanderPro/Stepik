#include <iostream>
using namespace std;

int ** createArray(unsigned a, unsigned b)
{
	int ** m = new int *[a];
	for (unsigned i = 0; i != a; ++i)
		m[i] = new int[b];
	return m;
}

int ** transpose(const int * const * m, unsigned rows, unsigned cols)
{
	int ** t = createArray(cols, rows);
	for (unsigned i = 0; i< rows; i++)
	for (unsigned j = 0; j< cols; j++)
		t[j][i] = m[i][j];
	return t;
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
	outArray(m, rows, cols);
	cout << endl;
	int** t = transpose(m, rows, cols);
	outArray(t, rows, cols);
	return 0;
}