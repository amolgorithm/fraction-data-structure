#pragma once

#include <string>

/**
 * @brief Represents a fraction and allows operations between them.
 * @version 1.0.0
 * @author Amolgorithm
 */
class Fraction {
public:
	/**
	 * @brief Constructs a Fraction object given two 64-bit integers.
	 * @param numer, denom Numerator and Denominator of a Fraction object. (denom is optional, the default value is 1).
	 * @example:
	 *  ------ EXAMPLE 1 ------
	 *  Fraction myFrac{ 3, 5 }; // numer = 3, denom = 5
	 
	 *  ------ EXAMPLE 2 ------
	 *  Fraction myFrac2{ 3 }; // numer = 3, denom = 1 (denom is set to 1 by default)
	 */
	explicit Fraction(long long numer, long long denom = 1);

	/**
	 * @brief Constructs a Fraction object given a double.
	 * @param decimal The decimal form of a fraction.
	 * @example:
	 *  Fraction myFrac{ 0.875 }; // decimal = 0.875 (Initially, numerator = 875 and denominator = 1000, then simplified to 7/8 by default )
	 */
	explicit Fraction(double decimal);

	/**
	 * @brief Constructs a Fraction object given a double.
	 * @param decimal The decimal form of a fraction.
	 * @example:
	 *  ------ EXAMPLE 1 ------
	 *  Fraction myFrac{ "7/10" }; // fraction = "7/10" (numerator = 7 and denominator = 10)

	 *  ------ EXAMPLE 2 ------
	 *  Fraction myFrac{ "7//10/*" }; // ERROR! The given argument for the constructor is not a valid fraction or ratio!
	 */
	explicit Fraction(std::string fraction);

	/**
	 * @brief Returns the numerator of a Fraction object.
	 * @example:
	 *  ------------ EXAMPLE 1 ------------
	 *  Fraction myFrac{ 3, 5 };
	 *  std::cout << myFrac.getNumerator();
	 *  ------------------------------------
	 *  Output: 3
	 
	 *  ------------ EXAMPLE 2 ------------
	 *  Fraction myFrac{ 0.6 }; // 0.6 = 3/5
	 *  std::cout << myFrac.getNumerator();
	 *  ------------------------------------
	 *  Output: 3

	 *  ------------ EXAMPLE 3 ------------
	 *  Fraction myFrac{ "3/5" };
	 *  std::cout << myFrac.getNumerator();
	 *  ------------------------------------
	 *  Output: 3
	 */
	long long getNumerator() const;

	/**
	 * @brief Returns the denominator of a Fraction object.
	 * @example:
	 *  ------------ EXAMPLE 1 ------------
	 *  Fraction myFrac{ 3, 5 };
	 *  std::cout << myFrac.getDenominator();
	 *  ------------------------------------
	 *  Output: 5

	 *  ------------ EXAMPLE 2 ------------
	 *  Fraction myFrac{ 0.6 }; // 0.6 = 3/5
	 *  std::cout << myFrac.getDenominator();
	 *  ------------------------------------
	 *  Output: 5

	 *  ------------ EXAMPLE 3 ------------
	 *  Fraction myFrac{ "3/5" };
	 *  std::cout << myFrac.getDenominator();
	 *  ------------------------------------
	 *  Output: 5
	 */
	long long getDenominator() const;

	/**
	 * @brief Returns an array containing both the numerator and the denominator of a Fraction object.
	 * @example:
	 *  Fraction myFrac{ 3, 4 };
	 *  --------------------------
	 *  myFrac.getTerms() = { 3, 4 }
	 */
	long long * getTerms() const;

	/**
	 * @brief Returns the decimal form of a Fraction object.
	 * @example:
	 *  Fraction myFrac{ 5, 8 };
	 *  std::cout << myFrac.toDecimal();
	 *  --------------------------
	 *  Output: 0.625
	 */
	double toDecimal() const;

	/**
	 * @brief Returns the GCF of the numerator and denominator of a Fraction object.
	 * @param a, b
	 * @example:
	 *  Fraction myFrac{ 4, 8 };
	 *  std::cout << myFrac.getGCFOfTerms();
	 *  --------------------------
	 *  Output: 4
	 */
	long long getGCFOfTerms() const;

	/**
	 * @brief Simplifies the fraction represented by a Fraction object.
	 * @example:
	 *  Fraction myFrac{ 125, 625 };
	 *  myFrac.simplify();
	 *  std::cout << myFrac;
	 *  ----------------------
	 *  Output: 1/5
	 */
	void simplify();

	/**
	 * @brief Returns a Fraction object representing the simplified form of the fraction represented by the first Fraction object.
	 * @example:
	 *  Fraction myFrac{ 125, 625 };
	 *  Fraction yourFrac = myFrac.getSimplifiedFraction();
	 *  std::cout << yourFrac;
	 *  ----------------------
	 *  Output: 1/5
	 */
	Fraction getSimplifiedFraction() const;

	/**
	 * @brief Returns an array containing the numerator and denominator of the simplified form of the fraction represented by a Fraction object.
	 * Does not affect the Fraction object itself.
	 * @example:
	 *  Fraction myFrac{ 125, 625 };
	 *  auto myFracSimplifiedTerms = myFrac.getSimplifiedTerms();
	 *  std::cout << myFracSimplifiedTerms[0] << "/" << myFracSimplifiedTerms[1];
	 *  ----------------------
	 *  Output: 1/5
	 */
	long long * getSimplifiedTerms() const;

	/**
	 * @brief Returns a const char array (C-string) containing the numerator and denominator in the fractional format: numerator/denominator.
	 * @example:
	 * Fraction myFrac{ 7, 13 };
	 * std::cout << myFrac;
	 * -------------------------
	 * Output: 7/13
	 */
	operator const char*() const;

	/**
	 * @brief Returns a Fraction object representing the sum of two or more fractions represented by Fraction objects.
	 * @param other
	 * @example:
	 *  Fraction f1{ 1, 8 }, f2{ 3, 4 };
	 *  std::cout << (f1 + f2);
	 *  ----------------------
	 *  Output: 7/8
	 */
	Fraction operator+(const Fraction& other) const;

	/**
	 * @brief Returns a Fraction object representing the difference of two or more fractions represented by Fraction objects.
	 * @param other
	 * @example:
	 *  Fraction f1{ 1, 8 }, f2{ 3, 4 };
	 *  std::cout << (f2 - f2);
	 *  ----------------------
	 *  Output: 5/8
	 */
	Fraction operator-(const Fraction& other) const;

	/**
	 * @brief Returns a Fraction object representing the product of two or more fractions represented by Fraction objects.
	 * @param other
	 * @example:
	 *  Fraction f1{ 1, 8 }, f2{ 3, 4 };
	 *  std::cout << (f1 * f2);
	 *  ----------------------
	 *  Output: 3/32
	 */
	Fraction operator*(const Fraction& other) const;

	/**
	 * @brief Returns a Fraction object representing the result after a division operation between two or more fractions represented by Fraction objects.
	 * @param other
	 * @example:
	 *  Fraction f1{ 1, 8 }, f2{ 3, 4 };
	 *  std::cout << (f1 / f2);
	 *  ----------------------
	 *  Output: 4/24
	 */
	Fraction operator/(const Fraction& other) const;

	/**
	 * @brief Returns a Fraction object representing the result after an exponential operation between some fractions represented by Fraction objects.
	 * @param other
	 * @example:
	 *  Fraction f1{ 1, 8 }, f2{ 3, 4 };
	 *  std::cout << (f1 ^ f2);
	 *  ----------------------
	 *  Output: 210224103/1000000000
	 */
	Fraction operator^(const Fraction& other) const;

	/**
	 * @brief Returns the Fraction object with the opposite sign.
	 * @example:
	 *  ------ EXAMPLE 1 ------
	 *  Fraction f1{ 1, 8 };
	 *  std::cout << -f1;
	 *  -----------------------
	 *  Output: -1/8

	 *  ------ EXAMPLE 2 ------
	 *  Fraction f1{ -1, 8 };
	 *  std::cout << -f1;
	 *  -----------------------
	 *  Output: 1/8
	 */
	Fraction operator-() const;

	/**
	 * @brief Increases value of numerator of a Fraction object by the denominator, resulting in increasing the value of the fraction by a whole.
	 * @example:
	 *  Fraction f1{ 1, 8 };
	 *  f1++;
	 *  std::cout << (f1);
	 *  ----------------------
	 *  Output: 9/8
	 */
	void operator++(int);

	/**
	 * @brief Increases value of numerator of a Fraction object by the denominator, resulting in decreasing the value of the fraction by a whole.
	 * @example:
	 *  Fraction f1{ 14, 8 };
	 *  f1--;
	 *  std::cout << (f1);
	 *  ----------------------
	 *  Output: 6/8
	 */
	void operator--(int);

	/**
	 * @brief Returns a boolean stating whether a Fraction object has a value greater than the value of another Fraction object.
	 * @param other
	 * @example:
	 *  Fraction f1{ 1, 8 }, f2{ 1, 10 };
	 *  std::cout << (f1 > f2);
	 *  ----------------------
	 *  Output: 1
	 */
	bool operator>(const Fraction& other) const;

	/**
	 * @brief Returns a boolean stating whether a Fraction object has a value lesser than the value of another Fraction object.
	 * @param other
	 * @example:
	 *  Fraction f1{ 1, 8 }, f2{ 1, 10 };
	 *  std::cout << (f1 < f2);
	 *  ----------------------
	 *  Output: 0
	 */
	bool operator<(const Fraction& other) const;

	/**
	 * @brief Returns a boolean stating whether a Fraction object has a value greater than or equal to the value of another Fraction object.
	 * @param other
	 * @example:
	 *  Fraction f1{ 1, 8 }, f2{ 1, 10 };
	 *  std::cout << (f1 >= f2);
	 *  ----------------------
	 *  Output: 1
	 */
	bool operator>=(const Fraction& other) const;

	/**
	 * @brief Returns a boolean stating whether a Fraction object has a value lesser than or equal to the value of another Fraction object.
	 * @param other
	 * @example:
	 *  Fraction f1{ 1, 8 }, f2{ 2, 16 };
	 *  std::cout << (f1 <= f2);
	 *  ----------------------
	 *  Output: 1
	 */
	bool operator<=(const Fraction& other) const;

	/**
	 * @brief Returns a boolean stating whether a Fraction object has a value equal to the value of another Fraction object.
	 * @param other
	 * @example:
	 *  Fraction f1{ 8, 80 }, f2{ 1, 10 };
	 *  std::cout << (f1 == f2);
	 *  ----------------------
	 *  Output: 1
	 */
	bool operator==(const Fraction& other) const;

	/**
	 * @brief Returns a boolean stating whether a Fraction object has a value not equal to the value of another Fraction object.
	 * @param other
	 * @example:
	 *  Fraction f1{ 8, 80 }, f2{ 1, 10 };
	 *  std::cout << (f1 != f2);
	 *  ----------------------
	 *  Output: 0
	 */
	bool operator!=(const Fraction& other) const;

private:
	long long numerator, denominator; // Two 64-bit integers bearing the numerator and denominator values of a Fraction object, respectively.

	/**
	 * @brief Returns the GCF of an alternate set of a and b, given as parameters.
	 * @param a, b
	 */
	long long getGCFOfAlternateSet(long long a, long long b) const;
};
