#include <iostream>
#include <string>

bool is_palindrome(const std::string& s);

int main()
{
	std::string temp;

	std::cout << "input word <q, to quit>:\n";
	while (std::cin >> temp && temp != "q")
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
	std::string temp = s;
	std::reverse(temp.begin(), temp.end());
	
	return temp == s ? true : false;
}