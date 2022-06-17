#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::ifstream fin1("so1.txt");
	std::ifstream fin2("so2.txt");
	std::ofstream fout("dest.txt");
	std::string temp1;
	std::string temp2;

	if (fin1.is_open() && fin2.is_open() && fout.is_open())
	{
		while (!(fin1.eof() && fin2.eof()))
		{
			if (fin1.eof())
				temp1 = "\0";
			else if (fin2.eof())
				temp2 = "\0";

			std::getline(fin1, temp1);
			std::getline(fin2, temp2);
			fout << temp1 + ' ' + temp2 << std::endl;
		}

		fin1.close();
		fin2.close();
		fout.close();
	}
	else
	{
		std::cout << "Missing file";
		exit(EXIT_FAILURE);
	}
	
}