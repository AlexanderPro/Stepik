/*
Переведите символ в верхний регистр.

Входные данные
Вводится единственый символ.

Выходные данные
Если введеный символ является строчной буквой латинского алфавита, то выведите такую же заглавную букву. В противном случае выведите тот же символ, который был введен.

Sample Input:
b

Sample Output:
B
*/

#include <iostream>
#include <ctype.h>
using namespace std;

int main()
{
	char ch;
	cin >> ch;
	cout << ((ch >= 'a' && ch <= 'z') ? (char)toupper(ch) : ch);
	return 0;
}