#pragma once
#include <string>
#include <fstream>
#include <vector>
#include <iostream>

void ShowStr(const std::string& s);

std::ifstream& GetStrs(std::ifstream& fin, std::vector<std::string>& strvec);

class Store
{
private:
	std::ofstream fout;
public:
	Store(std::ofstream& f);
	void operator()(const std::string& s);

};