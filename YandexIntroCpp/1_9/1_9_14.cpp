/*
Напишите функцию fib(n), которая по данному целому положительному n возвращает n-e число Фибоначчи. В этой задаче нельзя использовать циклы - используйте рекурсию.
Первое и второе числа Фибоначчи равны 1, а каждое следующее равно сумме двух предыдущих.

Формат входных данных
Вводится целое число.

Формат выходных данных
Выведите ответ на задачу.

Sample Input:
1

Sample Output:
1
*/

#include <iostream>
#include <iomanip>
using namespace std;

long fib(long n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;
	return fib(n - 1) + fib(n - 2);
}

int main()
{
	long n;
	cin >> n;
	cout << fib(n);
	return 0;
}