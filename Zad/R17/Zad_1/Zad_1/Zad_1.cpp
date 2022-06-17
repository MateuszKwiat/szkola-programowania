#include <iostream>

int main()
{
	int sum = 0;
	
	while (std::cin.get() != '$')
		sum++;
	std::cin.putback('$');

	char ch2;
	std::cin.get(ch2);
	std::cout << sum << ' ' << ch2;

}