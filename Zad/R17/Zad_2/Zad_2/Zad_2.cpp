#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::string file;
	std::ofstream fout;
	char ch;

	std::cout << "File name: ";
	std::cin >> file;
	fout.open(file.c_str(), std::ios_base::out | std::ios_base::app);

	if (!fout.is_open())
	{
		std::cout << "Can't open file " << file << std::endl;
		exit(EXIT_FAILURE);
	}

	else
	{
		std::cin.get();
		ch = std::cin.get();
		while (!std::cin.eof())
		{
			fout << ch;
			ch = std::cin.get();
		}

		fout.close();
	}
}