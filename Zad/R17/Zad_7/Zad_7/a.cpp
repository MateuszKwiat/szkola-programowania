#include "a.h"

void ShowStr(const std::string& s) { std::cout << s << std::endl; }

std::ifstream& GetStrs(std::ifstream& fin, std::vector<std::string>& strvec)
{
	std::size_t siz;
	
	while (!fin.eof())
	{
		fin.read((char*)&siz, sizeof(std::size_t));
		char* temp = new char[siz + 1];
		fin.read(temp, siz);
		temp[siz] = '\0';
		std::string a = temp;
		strvec.push_back(temp);
	}

	return fin;
}

Store::Store(std::ofstream& f)
{
	fout = std::move(f);
}

void Store::operator()(const std::string& s)
{
	std::size_t temp = s.size();
	fout.write((char*)&temp, sizeof(std::size_t));
	fout.write(s.c_str(), temp);
}
