/*
По данному числу N распечатайте все целые степени двойки, не превосходящие N, в порядке возрастания.

Формат входных данных
Вводится натуральное число.

Формат выходных данных
Выведите ответ на задачу.

Sample Input:
50

Sample Output:
1 2 4 8 16 32
*/

#include <iostream>
#include <math.h>
using namespace std;

int main() 
{
	int n, i;
	i = 0;
	cin >> n;

	while (pow(2, i) <= n)
	{
		cout << pow(2, i) << " ";
		i++;
	}

	return 0;
}