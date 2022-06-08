#include <iostream>
#include <set>
#include <string>
#include <algorithm>

int main()
{
	std::set<std::string> bolek_list;
	std::set<std::string> lolek_list;
	std::set<std::string> merge_list;
	std::string temp;

	std::cout << "would you like to fill Bolek's and Lolek's lists <y/n>:\n";
	while (std::cin >> temp && temp != "n")
	{
		std::cout << "Bolek's friends (n, to end the list):\n";
		while (std::cin >> temp && temp != "n")
			bolek_list.insert(temp);

		std::cout << "Lolek's friends (n, to end the list):\n";
		while (std::cin >> temp && temp != "n")
			lolek_list.insert(temp);

		std::merge(bolek_list.begin(), bolek_list.end(), lolek_list.begin(), lolek_list.end(),
			std::insert_iterator<std::set<std::string>>(merge_list, merge_list.begin()));
		
		std::cout << "Merged list:\n";
		for (auto x : merge_list)
			std::cout << '\t' << x << std::endl;

		bolek_list.clear();
		lolek_list.clear();
		merge_list.clear();

		std::cout << "Would you like to try again <y/n>:\n";
	}
}