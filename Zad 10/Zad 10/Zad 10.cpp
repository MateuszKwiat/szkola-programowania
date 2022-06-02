#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Review
{
	std::string title;
	int rating;
	double price;
};

bool operator<(const Review& r1, const Review& r2);
bool worseThan(const Review& e1, const Review& r2);
bool FillReview(Review& rr);
void ShowReview(const Review& rr);

int main()
{
	std::vector<std::shared_ptr<Review>> books;
	std::shared_ptr<Review> temp;
	while (FillReview(temp))
		books.push_back(new(temp));
	if (books.size() > 0)
	{
		std::cout << "You have reviewed "
			<< books.size() << " books:\n"
			<< "rating\tbook\n";
		std::for_each(books.begin(), books.end(), ShowReview);

		std::sort(books.begin(), books.end());
		std::cout << "Sorted alphabetically:\nrating\tbook\n";
		std::for_each(books.begin(), books.end(), ShowReview);

		std::sort(books.begin(), books.end(), worseThan);
		std::cout << "Sorted by rating:\nrating\tbook\n";
		std::for_each(books.begin(), books.end(), ShowReview);

		std::random_shuffle(books.begin(), books.end());
		std::cout << "After random shuffle:\nrating\tbook\n";
		std::for_each(books.begin(), books.end(), ShowReview);
	}
	else
		std::cout << "No data.\n";
}

bool operator<(const Review& r1, const Review& r2)
{
	if (r1.title < r2.title)
		return true;
	else if (r1.title == r2.title && r1.rating < r2.rating)
		return true;
	else
		return false;
}

bool worseThan(const Review& r1, const Review& r2)
{
	if (r1.rating < r2.rating)
		return true;
	else
		return false;
}

bool FillReview(Review& rr)
{
	std::cout << "Type the title (e, to exit): ";
	std::getline(std::cin, rr.title);
	if (rr.title == "e")
		return false;
	std::cout << "Type your rating of the book: ";
	std::cin >> rr.rating;
	if (!std::cin)
		return false;
	while (std::cin.get() != '\n')
		continue;
	
	return true;
}

void ShowReview(const Review& rr)
{
	std::cout << rr.rating << "\t" << rr.title << std::endl;
}