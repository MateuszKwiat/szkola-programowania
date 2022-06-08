#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

std::vector<int> lotto(int fields, int choices);

int main()
{
	std::vector<int> winners;
	int fields;
	int choices;

	std::cout << "How many fields (0, to exit):\n";
	while (std::cin >> fields && fields != 0)
	{
		std::cout << "How many winning fields:\n";
		std::cin >> choices;

		winners = lotto(fields, choices);

		std::cout << "The wining numbers are:\n";
		for (auto i : winners)
			std::cout << '\t' << i << std::endl;
		
		std::cout << "How many fields (0, to exit):\n";
	}
}

std::vector<int> lotto(int fields, int choices)
{
	std::vector<int> temp(fields);
	int value = 1;

	for (auto i = temp.begin(); i != temp.end(); i++)
		*i = value++;
	std::random_shuffle(temp.begin(), temp.end());

	return std::vector<int>(temp.begin(), temp.begin() + choices);
}