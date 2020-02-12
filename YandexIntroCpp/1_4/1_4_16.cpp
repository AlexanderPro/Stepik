/*
Есть две коробки, первая размером A1×B1×C1, вторая размером A2×B2×C2. Определите, можно ли разместить одну из этих коробок внутри другой, при условии, что поворачивать коробки можно только на 90 градусов вокруг ребер.

Формат входных данных
Программа получает на вход числа A1, B1, C1, A2, B2, C2.

Формат выходных данных
Программа должна вывести одну из следующих строчек:
Boxes are equal, если коробки одинаковые,
The first box is smaller than the second one, если первая коробка может быть положена во вторую,
The first box is larger than the second one, если вторая коробка может быть положена в первую,
Boxes are incomparable, во всех остальных случаях.

Sample Input 1:
1
2
3
3
2
1

Sample Output 1:
Boxes are equal

Sample Input 2:
2
2
3
3
2
1

Sample Output 2:
The first box is larger than the second one
*/

#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
	int c;
	c = a;
	a = b;
	b = c;
}

void sort(int &a, int &b, int &c)
{
	if (a > b) swap(a, b);
	if (b > c) swap(b, c);
	if (a > b) swap(a, b);
}

int main()
{
	int a1, a2, b1, b2, c1, c2;
	cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;

	sort(a1, b1, c1);
	sort(a2, b2, c2);

	if ((a1 == a2) && (b1 == b2) && (c1 == c2)){
		cout << "Boxes are equal";
	}
	else if ((a1 <= a2) && (b1 <= b2) && (c1 <= c2)){
		cout << "The first box is smaller than the second one";
	}
	else if ((a1 >= a2) && (b1 >= b2) && (c1 >= c2)){
		cout << "The first box is larger than the second one";
	}
	else cout << "Boxes are incomparable";

	return 0;
}