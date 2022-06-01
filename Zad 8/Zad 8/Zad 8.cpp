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

	std::cout << "Bolek's friends (q, to end the list):\n";
	while (std::cin >> temp && temp != "q")
		bolek_list.insert(temp);

	std::cout << "Lolek's friends (q, to end the list):\n";
	while (std::cin >> temp && temp != "q")
		lolek_list.insert(temp);

	std::merge(bolek_list.begin(), bolek_list.end(), lolek_list.begin(), lolek_list.end(),
		std::insert_iterator<std::set<std::string>>(merge_list, merge_list.begin()));
	
	std::cout << "Merged list:\n";
	for (auto x : merge_list)
		std::cout << '\t' << x << std::endl;
}