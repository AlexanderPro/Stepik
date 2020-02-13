/*
Выведите фамилии и имена учащихся в порядке убывания их среднего балла.

Входные данные
Заданы сначала количество учащихся n, затем n строк, каждая из которых содержит фамилию, имя и три числа (оценки по трем предметам: математике, физике, информатике). Данные в строке разделены одним пробелом. Оценки принимают значение от 1 до 5.

Выходные данные
Необходимо вывести пары фамилия-имя по одной на строке, разделяя фамилию и имя одним пробелом. Выводить оценки не нужно. Если несколько учащихся имеют одинаковые средние баллы, то их нужно выводить в порядке, заданном во входных данных.

Sample Input:
3
Markov Valeriy 5 5 5
Sergey Petrov 1 1 1
Petrov Petr 3 3 3

Sample Output:
Markov Valeriy
Petrov Petr
Sergey Petrov
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> splitText(string s, string delimiter)
{
	vector<int> result;
	int n;
	if (s.find_first_of(delimiter, 0) == -1)
	{
		n = atoi(s.c_str());
		result.push_back(n);
	}
	else
	{
		int first = 0, second = 0;
		first = delimiter.size();
		first = -first;
		do
		{
			second = s.find_first_of(delimiter, first + delimiter.size());
			if (second == -1)
			{
				n = atoi(s.substr(first + delimiter.size()).c_str());
				result.push_back(n);
			}
			else
			{
				n = atoi(s.substr(first + delimiter.size(), second - first - delimiter.size()).c_str());
				result.push_back(n);
			}
			first = second;
		} while (second != -1);
	}
	return result;
}

bool compare(pair<string, double> p1, pair<string, double> p2)
{
	return p1.second > p2.second;
}

int main()
{
	int n, sum = 0, secondSpace = 0;
	string s, name, markSecuence;
	double d;
	vector<pair<string, double>> v;
	vector<int> marks;

	cin >> n;
	getline(cin, s);
	for (size_t i = 0; i < n; i++)
	{
		getline(cin, s);
		secondSpace = s.find_first_of(" ", s.find_first_of(" ", 0) + 1);
		marks = splitText(s.substr(secondSpace + 1), " ");
		sum = 0;
		for (size_t j = 0; j < marks.size(); j++)
		{
			sum += marks[j];
		}
		d = (double)sum / marks.size();
		v.push_back(pair<string, double>(s.substr(0, secondSpace), d));
	}

	stable_sort(v.begin(), v.end(), compare);
	for (auto p : v)
	{
		cout << p.first << endl;
	}
	return 0;
}