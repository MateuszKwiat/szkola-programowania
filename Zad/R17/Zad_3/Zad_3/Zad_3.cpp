#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::string file1;
	std::string file2;
	std::ofstream fout;
	std::ifstream fin;
	char ch;

	std::cout << "Source file: ";
	std::getline(std::cin, file1);
	std::cout << "Destination file: ";
	std::getline(std::cin, file2);

	fin.open(file1.c_str());
	fout.open(file2.c_str());

	if (!(fin.is_open() && fout.is_open()))
	{
		std::string temp = (fin.is_open()) ? file2 : file1;
		std::cout << "Missing file " << temp;
		exit(EXIT_FAILURE);
	}

	fin.get(ch);
	while (!fin.eof())
	{
		fout << ch;
		fin.get(ch);
	}
}