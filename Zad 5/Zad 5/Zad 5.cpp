#include <iostream>
#include <algorithm>
#include <vector>

const int NUM = 10;

int reduce(long ar[], int n);

int main()
{
	long ar[NUM] = { 10, 20, 12, 10, 15, 20, 50, 21, 50, 32 };

	std::cout << reduce(ar, NUM) << std::endl;

	for (auto x : ar)
		std::cout << x << std::endl;
}

int reduce(long ar[], int n)
{
	std::vector<long> temp_ar(ar, ar + n);

	std::sort(temp_ar.begin(), temp_ar.end());
	auto last = std::unique(temp_ar.begin(), temp_ar.end());
	temp_ar.erase(last, temp_ar.end());
	std::copy(temp_ar.begin(), temp_ar.end(), ar);

	std::fill(ar + temp_ar.size(), ar + n, '\0');

	return temp_ar.size();
}