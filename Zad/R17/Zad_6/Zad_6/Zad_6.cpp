#include <iostream>
#include "empoyee.h"

int main()
{
	employee em("Tadeusz", "Hubert", "Sprzedawca");
	std::cout << em << std::endl;
	em.ShowAll();

	manager ma("Amforiusz", "Smoczewski", "Malarz", 5);
	std::cout << ma << std::endl;
	ma.ShowAll();

	fink fi("Maurycy", "Olkuski", "Hydraulik", "Julian Bar");
	std::cout << fi << std::endl;
	fi.ShowAll();

	highfink hf(ma, "Jan Kudlaty");
	hf.ShowAll();
	std::cout << "Wcisnij dowolnt przycisk, aby przejsc do nastepnego etapu:\n";
	std::cin.get();
	highfink hf2;
	hf2.SetAll();

	std::cout << "Uzywa wskaznika abstr_emp*:\n";
	abstr_emp* tri[4] = { &em, &fi, &hf, &hf2 };
	for (int i = 0; i < 4; i++)
		tri[i]->ShowAll();

}