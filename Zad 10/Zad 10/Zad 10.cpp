#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include <fstream>

struct Review
{
	std::string title;
	int rating;
	double price;
};

std::ifstream file_input;

bool operator<(const std::shared_ptr<Review>& r1, const std::shared_ptr<Review>& r2);
bool worseThan(const std::shared_ptr<Review>& r1, const std::shared_ptr<Review>& r2);
bool cheaperThan(const std::shared_ptr<Review>& r1, const std::shared_ptr<Review>& r2);
bool FillReview(Review& rr, char ch);
void ShowReview(const std::shared_ptr<Review>& rr);
void menu();

int main()
{
	std::vector<std::shared_ptr<Review>> books;
	Review temp;
	int choice;
	file_input.open("books.txt");

	std::cout << "Would you like to use file input? <y/n>\n";
	char ch;
	std::cin >> ch;

	while (FillReview(temp, ch))
		books.push_back(std::shared_ptr<Review>(new Review(temp)));
	std::vector<std::shared_ptr<Review>> auxiliary_books_vector(books);
	
	if (books.size() > 0)
	{
		std::cout << "You have reviewed " << books.size() << " books\n";
		menu();
		while (std::cin >> choice && choice != 0)
		{
			switch (choice)
			{
			case 1:
				std::cout << "Input order:\nrating\tbook\tprice\n";
				std::for_each(books.begin(), books.end(), ShowReview);
				break;
			case 2:
				std::sort(auxiliary_books_vector.begin(), auxiliary_books_vector.end());
				std::cout << "Sorted alphabetically:\nrating\tbook\tprice\n";
				std::for_each(auxiliary_books_vector.begin(), auxiliary_books_vector.end(), ShowReview);
				break;
			case 3:
				std::sort(auxiliary_books_vector.begin(), auxiliary_books_vector.end(), worseThan);
				std::cout << "Sorted by rating:\nrating\tbook\tprice\n";
				std::for_each(auxiliary_books_vector.begin(), auxiliary_books_vector.end(), ShowReview);
				break;
			case 4:
				std::sort(auxiliary_books_vector.rbegin(), auxiliary_books_vector.rend(), worseThan);
				std::cout << "Sorted by rating:\nrating\tbook\tprice\n";
				std::for_each(auxiliary_books_vector.begin(), auxiliary_books_vector.end(), ShowReview);
				break;
			case 5:
				std::sort(auxiliary_books_vector.begin(), auxiliary_books_vector.end(), cheaperThan);
				std::cout << "Sorted by price:\nrating\tbook\tprice\n";
				std::for_each(auxiliary_books_vector.begin(), auxiliary_books_vector.end(), ShowReview);
				break;
			case 6:
				std::sort(auxiliary_books_vector.rbegin(), auxiliary_books_vector.rend(), cheaperThan);
				std::cout << "Sorted by price:\nrating\tbook\tprice\n";
				std::for_each(auxiliary_books_vector.begin(), auxiliary_books_vector.end(), ShowReview);
			}
			menu();
		}
	}
	else
		std::cout << "No data.\n";
}

bool operator<(const std::shared_ptr<Review>& r1, const std::shared_ptr<Review>& r2)
{
	if (r1->title < r2->title)
		return true;
	else if (r1->title == r2->title && r1->rating < r2->rating)
		return true;
	else if (r1->title == r2->title && r1->rating == r2->rating && r1->price < r2->price)
		return true;
	else
		return false;
}

bool worseThan(const std::shared_ptr<Review>& r1, const std::shared_ptr<Review>& r2)
{
	if (r1->rating < r2->rating)
		return true;
	else
		return false;
}

bool cheaperThan(const std::shared_ptr<Review>& r1, const std::shared_ptr<Review>& r2)
{
	if (r1->price < r2->price)
		return true;
	else
		return false;
}

bool FillReview(Review& rr, char ch)
{
	if (ch == 'y')
	{
		if (file_input.eof())
			return false;

		file_input >> rr.title;
		file_input >> rr.rating;
		file_input >> rr.price;
		return true;
	}
	else
	{
		std::cout << "Type the title (e, to exit): ";
		std::getline(std::cin, rr.title);
		if (rr.title == "e")
			return false;
		std::cout << "Type your rating of the book: ";
		std::cin >> rr.rating;
		if (!std::cin)
			return false;
		std::cout << "Price of the book: ";
		std::cin >> rr.price;
		if (!std::cin)
			return false;
		while (std::cin.get() != '\n')
			continue;

		return true;
	}
}

void ShowReview(const std::shared_ptr<Review>& rr)
{
	std::cout << rr->rating << "\t" << rr->title << "\t" << rr->price << std::endl;
}

void menu()
{
	std::cout << "\n0 - to exit\n1 - input order\n2 - alphabetical order\n"
		<< "3 - sorted by rating (from the worst)\n4 - sorted by raring (from the best)\n"
		<< "5 - sorted by price (from the cheapest)\n6 - sorted by price (from the most expensive)\n> ";
}