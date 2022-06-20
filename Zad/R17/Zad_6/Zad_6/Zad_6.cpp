#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include "empoyee.h"

inline void eatline() { while (std::cin.get() != '\n') continue; }

enum classkind { Employee, Manager, Fink, HighFink };

const char* file = "employees.txt";

int main()
{
	int classtype;
	char ch;
	int i = 0;
	abstr_emp* temp;
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
	std::cout << "What type of employee would you like to add:\n"
		<< "0 - employee\t1 - manager\t2 - fink\n"
		<< "3 - high fink\t4 - exit\n";
	std::cin >> classtype;
	while (classtype != 4)
	{
		switch (classtype)
		{
		case Employee:
			temp = new employee();
			temp->SetAll();
			fout << 0 << std::endl;
			temp->FileOut(fout);
			break;
		case Manager:
			temp = new manager();
			temp->SetAll();
			fout << 1 << std::endl;
			temp->FileOut(fout);
			break;
		case Fink:
			temp = new fink();
			temp->SetAll();
			fout << 2 << std::endl;
			temp->FileOut(fout);
			break;
		case HighFink:
			temp = new highfink();
			temp->SetAll();
			fout << 3 << std::endl;
			temp->FileOut(fout);
			break;	
		}
		std::cout << "What type of employee would you like to add:\n"
			<< "0 - employee\t1 - manager\t2 - fink\n"
			<< "3 - high fink\t4 - exit\n";
		std::cin >> classtype;
	}
	fout.close();

	// SHOW UPDATED LIST OF EMPLOYEES
	emp_arr.clear();
	fin.clear();
	fin.open(file, std::ios_base::in);
	i = 0;

	if (fin.is_open())
	{
		std::cout << "New file content:\n";
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
}