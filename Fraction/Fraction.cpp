#include <algorithm>
#include <cmath>
#include <stdexcept>
#include <string>
#include "Fraction.h"


Fraction::Fraction(long long numer, long long denom)
{
	if (denom == 0) throw std::invalid_argument("0 is an invalid argument for denominator!");
	numerator = numer;
	denominator = denom;
}

Fraction::Fraction(double decimal)
{
	numerator = static_cast<long long>(decimal * 1000000000);
	denominator = 1000000000;
	simplify();
}

Fraction::Fraction(std::string fraction)
{
	int terms[2] = { 0, 0 };
	short index = 0;
		
	for (char c : fraction)
	{
		if (!isdigit(c))
		{
			if (c == '/' || c == ':')
			{
				if (index < 1)
					index++;
				else
					throw std::invalid_argument("The given argument for the constructor is not a valid fraction or ratio!");
				continue;
			}
			else
			{
				throw std::invalid_argument("The given argument for the constructor is not a valid fraction or ratio!");
			}
		}
			
		terms[index] = (10 * terms[index]) + (c - '0');
	}

	numerator = terms[0];
	denominator = terms[1];
}

long long Fraction::getNumerator() const
{
	return numerator;
}

long long Fraction::getDenominator() const
{
	return denominator;
}

long long * Fraction::getTerms() const
{
	long long terms[2] = { numerator, denominator };
	return terms;
}

double Fraction::toDecimal() const
{
	return (static_cast<double>(numerator) / denominator);
}

long long Fraction::getGCFOfTerms() const
{
	if (numerator == 0)
		return denominator;
	return getGCFOfAlternateSet(denominator % numerator, numerator);
}

void Fraction::simplify()
{
	long long theGCF = getGCFOfTerms();
	numerator /= theGCF;
	denominator /= theGCF;
}

Fraction Fraction::getSimplifiedFraction() const
{
	long long theGCF = getGCFOfTerms();
	return Fraction{ numerator / theGCF, denominator / theGCF };
}

long long * Fraction::getSimplifiedTerms() const
{
	long long theGCF = getGCFOfTerms();
	long long simplifiedTerms[2] = { numerator / theGCF, denominator / theGCF };
	return simplifiedTerms;
}


Fraction::operator const char*() const
{
	static std::string fractionStr;
	fractionStr = std::to_string(numerator) + "/" + std::to_string(denominator);

	return fractionStr.c_str();
}
	
Fraction Fraction::operator+(const Fraction& other) const
{
	long long lcm = (denominator * other.denominator) / getGCFOfAlternateSet(denominator, other.denominator);
	return Fraction{ (numerator * (lcm / denominator)) + (other.numerator * (lcm / other.denominator)), lcm };
}

Fraction Fraction::operator-(const Fraction& other) const
{
	long long lcm = (denominator * other.denominator) / getGCFOfAlternateSet(denominator, other.denominator);
	return Fraction{ (numerator * (lcm / denominator)) - (other.numerator * (lcm / other.denominator)), lcm };
}

Fraction Fraction::operator*(const Fraction& other) const
{
	return Fraction{ numerator * other.numerator, denominator * other.denominator };
}

Fraction Fraction::operator/(const Fraction& other) const
{
	return Fraction{ numerator * other.denominator, denominator * other.numerator };
}

Fraction Fraction::operator^(const Fraction& other) const
{
	return Fraction{ pow(toDecimal(), other.toDecimal()) };
}

Fraction Fraction::operator-() const
{
	return Fraction{ -numerator, denominator };
}

void Fraction::operator++(int)
{
	numerator += denominator;
}

void Fraction::operator--(int)
{
	numerator -= denominator;
}

bool Fraction::operator>(const Fraction& other) const
{
	return toDecimal() > other.toDecimal();
}

bool Fraction::operator<(const Fraction& other) const
{
	return toDecimal() < other.toDecimal();
}

bool Fraction::operator>=(const Fraction& other) const
{
	return toDecimal() >= other.toDecimal();
}

bool Fraction::operator<=(const Fraction& other) const
{
	return toDecimal() <= other.toDecimal();
}

bool Fraction::operator==(const Fraction& other) const
{
	return toDecimal() == other.toDecimal();
}
	
bool Fraction::operator!=(const Fraction& other) const
{
	return toDecimal() != other.toDecimal();
}

long long Fraction::getGCFOfAlternateSet(long long a, long long b) const
{
	if (a == 0)
		return b;
	return getGCFOfAlternateSet(b % a, a);
}