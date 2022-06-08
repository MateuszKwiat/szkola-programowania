#include <iostream>
#include <string>
#include <cctype>

bool is_palindrome(const std::string& s);

int main()
{
	std::string temp;

	std::cout << "input word <q, to quit>:\n";
	while (std::getline(std::cin, temp) && temp != "q")
	{
		if (is_palindrome(temp))
			std::cout << '\t' << temp << " - palindrome\n";
		else
			std::cout << '\t' << temp << " - not a palindrome\n";

		std::cout << "input word <q, to quit>:\n";
	}
}

bool is_palindrome(const std::string& s)
{
	std::string temp;
	std::string reverse_temp;

	for (auto i = s.begin(); i != s.end(); i++)
		if (isalnum(*i))
			temp.push_back(tolower(*i));

	reverse_temp = temp;
	std::reverse(reverse_temp.begin(), reverse_temp.end());

	return temp == reverse_temp ? true : false;
}