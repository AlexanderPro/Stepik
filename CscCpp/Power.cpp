#include <iostream>

int power(int x, unsigned p) 
{
	int answer = x;
	if (p == 0) return 1;
	for (int i = 2; i <= p; i++)
	{
		answer = answer * x;
	}
	return answer;
}

int main()
{
	std::cout << "power(5, 2) = " << power(5, 2) << std::endl;
	std::cout << "power(2, 10) = " << power(2, 10) << std::endl;
	return 0;
}