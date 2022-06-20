#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <iterator>
#include "empoyee.h"

inline void eatline() { while (std::cin.get() != '\n') continue; }

enum classkind { Employee, Manager, Fink, HighFink };

const char* file = "employees.txt";

int main()
{
	int classtype;
	char ch;
	int i = 0;
	std::vector<abstr_emp*> emp_arr;
	std::ifstream fin;
	fin.open(file, std::ios_base::in);

	// SHOW CURRENT LIST OF EMPLOYEES
	if (fin.is_open())
	{
		std::cout << "Current file content:\n";
		while ((fin >> classtype))
		{
			switch (classtype)
			{
			case Employee:
				emp_arr.push_back(new employee());
				emp_arr[i++]->FileSetAll(fin);
				break;
			case Manager:
				emp_arr.push_back(new manager());
				emp_arr[i++]->FileSetAll(fin);
				break;
			case Fink:
				emp_arr.push_back(new fink());
				emp_arr[i++]->FileSetAll(fin);
				break;
			case HighFink:
				emp_arr.push_back(new highfink());
				emp_arr[i++]->FileSetAll(fin);
				break;
			default:
				break;
			}
		}
		fin.close();
		for (auto x : emp_arr)
		{
			x->ShowAll();
			std::cout << std::endl;
		}
	}

	std::ofstream fout(file, std::ios_base::out | std::ios_base::app);
	if (!fout.is_open())
	{
		std::cerr << "Can't open file: " << file << ".\n";
		exit(EXIT_FAILURE);
	}

	// ADD NEW EMPLOYEES
	std::cout << "";
	while ()
	{

	}

	fout.close();

	// SHOW UPDATED LIST OF EMPLOYEES
	fin.clear();
	fin.open(file, std::ios_base::in);
	if (fin.is_open())
	{
		std::cout << "New file content:\n";
		while ()
		{

		}
		fin.close();
	}
}