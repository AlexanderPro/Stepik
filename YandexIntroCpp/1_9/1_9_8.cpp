/*
Проверьте, принадлежит ли точка данной закрашенной области:
Если точка принадлежит области (область включает границы), выведите слово YES, иначе выведите слово NO.
Решение должно содержать функцию IsPointInArea(x, y), возвращающую True, если точка принадлежит области и False, если не принадлежит. Основная программа должна считать координаты точки, вызвать функцию IsPointInArea и в зависимости от возвращенного значения вывести на экран необходимое сообщение.
Функция IsPointInArea не должна содержать инструкцию if.

Формат входных данных
Вводятся два действительных числа.

Формат выходных данных
Выведите ответ на задачу.

Sample Input 1:
-4
-4

Sample Output 1:
NO

Sample Input 2:
-4
-3

Sample Output 2:
NO
*/

#include <iostream>
#include <cmath>

using namespace std;

bool IsPointInArea(double x, double y)
{
	double in_circle = 2 * 2 >= abs(x + 1) * abs(x + 1) + abs(y - 1) * abs(y - 1);
	double above_line1 = y >= 2 * x + 2;
	double above_line2 = y >= -x;
	double below_line1 = y <= 2 * x + 2;
	double below_line2 = y <= -x;
	double on_circle = 2 * 2 == abs(x + 1) * abs(x + 1) + abs(y - 1) * abs(y - 1);
	return in_circle && above_line1 && above_line2 || (on_circle || !in_circle) && below_line1 && below_line2;
}

int main()
{
	double  x, y;
	cin >> x >> y;
	cout << (IsPointInArea(x, y) ? "YES" : "NO");
	return 0;
}