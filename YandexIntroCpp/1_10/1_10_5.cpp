/*
Вводится один символ, измените его регистр. То есть, если была введена строчная буква - сделайте ее заглавной и наоборот. Символы, не являющиеся латинской буквой, нужно выводить без изменений.

Входные данные
Вводится единственый символ.

Выходные данные
Выведите ответ на задачу.

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
	cout << ((ch >= 'a' && ch <= 'z') ? (char)toupper(ch) : (ch >= 'A' && ch <= 'Z') ? (char)tolower(ch) : ch);
	return 0;
}