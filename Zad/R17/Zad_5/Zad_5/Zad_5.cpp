#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>

int main()
{
	std::ifstream finb("bolek.dat");
	std::ifstream finl("lolek.dat");
	std::ofstream fout("bolilol.dat");
	std::set<std::string> bolek;
	std::set<std::string> lolek;
	std::set<std::string> bolek_and_lolek;
	std::string temp1;
	std::string temp2;

	if (finb.is_open() && finl.is_open() && fout.is_open())
	{
		while (!(finb.eof() && finl.eof()))
		{
			finb >> temp1;
			finl >> temp2;
			bolek.insert(temp1);
			lolek.insert(temp2);
		}

		std::cout << "Bolek's list:\n";
		for (auto x : bolek)
			std::cout << x << std::endl;

		std::cout << "\nLolek's list:\n";
		for (auto x : lolek)
			std::cout << x << std::endl;

		std::merge(bolek.begin(), bolek.end(), lolek.begin(), lolek.end(),
			std::insert_iterator<std::set<std::string>>(bolek_and_lolek, bolek_and_lolek.begin()));
		
		for (auto x : bolek_and_lolek)
			fout << x << std::endl;

		finb.close();
		finl.close();
		fout.close();
	}
	else
	{
		std::cout << "Missing file";
		exit(EXIT_FAILURE);
	}


}