#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <list>
#include <algorithm>

double seconds(const clock_t& start, const clock_t& end);

int main()
{
	srand(time(0));
	std::vector<int> vi0(10000000);
	clock_t start;
	clock_t end;
	
	for (auto& x : vi0)
		x = rand();
	
	std::vector<int> vi(vi0);
	std::list<int> li(vi0.begin(), vi0.end());

	// STL SORT FOR VECTOR
	start = clock();
	std::sort(vi.begin(), vi.end());
	end = clock();
	std::cout << "STL sort on vector time: " << seconds(start, end) << " seconds\n";

	// DEDICATED LIST'S SORT METHOD
	start = clock();
	li.sort();
	end = clock();
	std::cout << "List sort time: " << seconds(start, end) << " seconds\n";

	// COPYING LIST TO VECOTR AND BACK TO LIST TO USE STL SORT
	std::copy(vi0.begin(), vi0.end(), li.begin());
	start = clock();
	std::copy(li.begin(), li.end(), vi.begin());
	std::sort(vi.begin(), vi.end());
	std::copy(vi.begin(), vi.end(), li.begin());
	end = clock();
	std::cout << "Copying list to vector and back to list for STl sort time: "
		<< seconds(start, end) << " seconds\n";
}

double seconds(const clock_t& start, const clock_t& end)
{
	return (double)(end - start) / CLOCKS_PER_SEC;
}