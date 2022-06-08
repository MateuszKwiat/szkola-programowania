#include <iostream>
#include <algorithm>
#include <vector>

const int NUM = 10;

template <typename T>
int reduce(T ar[], int n);

int main()
{
	long ar[NUM] = { 10, 20, 12, 10, 15, 20, 50, 21, 50, 32 };
	std::string str_ar[NUM] = { "art", "river", "support", "weather",
		"support", "base", "drop", "art", "support", "hand" };

	std::cout << reduce<long>(ar, NUM) << std::endl;
	
	for (auto x : ar)
		std::cout << x << std::endl;

	std::cout << std::endl << reduce<std::string>(str_ar, NUM) << std::endl;
	for (auto x : str_ar)
		std::cout << x << std::endl;
}

template <typename T>
int reduce(T ar[], int n)
{
	std::vector<T> temp_ar(ar, ar + n);

	std::sort(temp_ar.begin(), temp_ar.end());
	auto last = std::unique(temp_ar.begin(), temp_ar.end());
	temp_ar.erase(last, temp_ar.end());
	std::copy(temp_ar.begin(), temp_ar.end(), ar);

	std::fill(ar + temp_ar.size(), ar + n, '\0');

	return temp_ar.size();
}