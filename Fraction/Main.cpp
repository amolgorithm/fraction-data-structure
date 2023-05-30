#include <iostream>
#include "Fraction.h"


int main()
{
	Fraction f1{ 3, 4 }, f2{ 1, 2 }, f3{ 12, 16 };

	std::cout << "Fraction 1: " << f1 << std::endl;
	std::cout << "Decimal form of Fraction 1: " << f1.toDecimal() << std::endl << std::endl;
	std::cout << "Negative Fraction 1: " << -f1 << std::endl;
	std::cout << "Fraction 2: " << f2 << std::endl;
	std::cout << "Decimal form of Fraction 2: " << f2.toDecimal() << std::endl << std::endl;

	std::cout << "Fraction 1 + Fraction 2: " << (f1 + f2) << std::endl;
	std::cout << "Fraction 1 - Fraction 2: " << (f1 - f2) << std::endl;
	std::cout << "Fraction 1 * Fraction 2: " << (f1 * f2) << std::endl;
	std::cout << "Fraction 1 / Fraction 2: " << (f1 / f2) << std::endl;
	std::cout << "Fraction 1 to the power of Fraction 2: " << (f1 ^ f2) << " (" << (f1 ^ f2).toDecimal() << ")" << std::endl << std::endl;

	std::cout << "Fraction 1 is " << (f1 == f2 ? "" : "not ") << "equivalent to Fraction 2." << std::endl;
	std::cout << "Fraction 1 is " << (f1 == f3 ? "" : "not ") << "equivalent to Fraction 3." << std::endl;

	f1++;
	f2--;
	std::cout << "Fraction 1 + 1: " << f1 << std::endl;
	std::cout << "Fraction 2 - 1: " << f2 << std::endl;

	return 0;
}