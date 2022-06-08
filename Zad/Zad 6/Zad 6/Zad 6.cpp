#include <iostream>
#include <cstdlib>
#include <ctime>
#include <queue>
#include "customer.h"

const int MIN_PER_HR = 60;

bool new_customer(double x);

int main()
{
	std::srand(std::time(0));

	std::cout << "How long the queue can get: ";
	int qs;
	std::cin >> qs;
	std::queue<Customer> line;

	std::cout << "Simulation time (hours): ";
	int hours;
	std::cin >> hours;
	long cycletime = MIN_PER_HR * hours;

	std::cout << "Average amount of clients per hour: ";
	double perhour;
	std::cin >> perhour;
	double min_per_cust;
	min_per_cust = MIN_PER_HR / perhour;

	Customer temp;
	long turnawways = 0;
	long customers = 0;
	long served = 0;
	long sum_line = 0;
	int wait_time = 0;
	long line_wait = 0;

	for (int cycle = 0; cycle < cycletime; cycle++)
	{
		if (new_customer(min_per_cust))
		{
			if (line.size() >= qs)
				turnawways++;
			else
			{
				customers++;
				temp.set(cycle);
				line.push(temp);
			}
		}
		if (wait_time <= 0 && !line.empty())
		{
			temp = line.front();
			line.pop();
			wait_time = temp.ptime();
			line_wait += cycle - temp.when();
			served++;
		}
		if (wait_time > 0)
			wait_time--;
		sum_line += line.size();
	}
	
	if (customers > 0)
	{
		std::cout << "       Amount of customers: " << customers << std::endl;
		std::cout << "Amount of served customers: " << served << std::endl;
		std::cout << "       Amount of turnaways: " << turnawways << std::endl;
		std::cout << "      Average queue length: ";
		std::cout.precision(2);
		std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
		std::cout.setf(std::ios_base::showpoint);
		std::cout << (double)sum_line / cycletime << std::endl;
		std::cout << "      Average waiting time: "
			<< (double)line_wait / served << "minutes\n";
	}
	else
		std::cout << "No clients\n";
}

bool new_customer(double x)
{
	return (std::rand() * x / RAND_MAX < 1);
}