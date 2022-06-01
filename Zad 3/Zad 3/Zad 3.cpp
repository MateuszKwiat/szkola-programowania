#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <vector>
#include <fstream>

int main()
{
	std::srand(std::time(0));
	std::vector<std::string> wordlist;
	std::ifstream file_inp;
	std::string temp;
	char play;

	file_inp.open("words.txt");
	std::cout << "Would you like to play? <y/n>\n";
	std::cin >> play;
	play = tolower(play);
	while (play == 'y' && file_inp.is_open())
	{
		while (!file_inp.eof())
		{
			file_inp >> temp;
			wordlist.push_back(temp);
		}

		std::string target = wordlist[std::rand() % wordlist.size()];
		int length = target.length();
		std::string attempt(length, '-');
		std::string badchars;
		int guesses = 6;
		std::cout << "Guess the word. it has " << length
			<< " letters.\n"
			<< "You have " << guesses << " guesses.\n";
		std::cout << "Your word: " << attempt << std::endl;
		while (guesses > 0 && attempt != target)
		{
			char letter;
			std::cout << "Guess the letter: ";
			std::cin >> letter;
			if (badchars.find(letter) != std::string::npos || attempt.find(letter) != std::string::npos)
			{
				std::cout << "You already used this letter.\n";
				continue;
			}
			int loc = target.find(letter);
			if (loc == std::string::npos)
			{
				std::cout << "Wrong!\n";
				--guesses;
				badchars += letter;
			}
			else
			{
				std::cout << "Correct!\n";
				attempt[loc] = letter;
				loc = target.find(letter, loc + 1);
				while (loc != std::string::npos)
				{
					attempt[loc] = letter;
					loc = target.find(letter, loc + 1);
				}
			}
			std::cout << "Your word: " << attempt << std::endl;
			if (attempt != target)
			{
				if (badchars.length() > 0)
					std::cout << "Wrong letters: " << badchars << std::endl;
				std::cout << "You have " << guesses << " more guesses.\n";
			}
		}
		if (guesses > 0)
			std::cout << "You did it!\n";
		else
			std::cout << "The correct word is " << target << ".\n";

		std::cout << "Would you like to try again? <y/n>\n";
		std::cin >> play;
		play = tolower(play);
	}
}