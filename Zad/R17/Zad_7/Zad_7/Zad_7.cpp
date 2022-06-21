#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include "a.h"

int main()
{
	std::vector<std::string> vostr;
	std::string temp;

	std::cout << "Type a string (eof to exit):\n";
	while (std::getline(std::cin, temp) && temp[0] != '\0')
		vostr.push_back(temp);
	std::cout << "You input data:\n";
	std::for_each(vostr.begin(), vostr.end(), ShowStr);
	
	std::ofstream fout("strings.dat", std::ios_base::out | std::ios_base::binary);
	std::for_each(vostr.begin(), vostr.end(), Store(fout));
	fout.close();
	
	std::vector<std::string> vistr;
	std::ifstream fin("strings.dat", std::ios_base::in | std::ios_base::binary);
	if (!fin.is_open())
	{
		std::cerr << "Missing file\n";
		exit(EXIT_FAILURE);
	}
	GetStrs(fin, vistr);
	std::cout << "\nData from file:\n";
	std::for_each(vistr.begin(), vistr.end(), ShowStr);
}