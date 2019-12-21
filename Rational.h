
#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>
#include <string>

class Rational
{
private:
	int numerator;
	int denominator;
	void reduce();

public:
	// Consctructor accepting two integers first being numerator and then denominator
	Rational(int numerator=0, int denominator=1);

	//Default constructor if no values were passed. it initilaizes numerator to 0 , denominatro to 1
	//Rational() {
	//	numerator = 0;
	//	denominator = 1;
	//}
	
	//This function finds the greatest common divisor between two fractions.
	//It accepts two int numbers as an argument.
	int gcd(int a, int b);

	//Accessor function to get the value of the denominator
	int getDenom() const
	{
		return denominator;
	}

	//Accesor function to get the value of the numerator 
	int getNumerator() const
	{
		return numerator;
	}

	//This function converts numerator and denominator to string object then retruns that object
	std::string toString();

	// relational operators (==, <=, >=, !=, etc.) compare the numeric values represented by two Rational objects
	// e.g. == returns true if the numeric value of the left-hand-side is equal to that of the right-hand-side of the operator
	bool operator ==(const Rational&) const;
	bool operator <=(const Rational&) const;
	bool operator >=(const Rational&) const;
	bool operator <(const Rational&) const;
	bool operator >(const Rational&)const;
	bool operator !=(const Rational&)const;


	// Overloading arithmetic operators (+, *, /, -) to do arithmetic operations on the numeric values of the two Rational class objects.
	//e.g + returns newly created Rational class object which contains the sum of the numeric values of two Rational class objects.
	Rational operator +(const Rational&)const;
	Rational operator -(const Rational&) const;
	Rational operator *(const Rational&) const;
	Rational operator /(const Rational&) const;

	// Declares friend the string extraction operator to get the numeric values of the Rational class.
	friend std::istream &operator>>(std::istream &, Rational &);
};

// prints rational number e.g. as 3/5
std::ostream& operator<<(std::ostream&, Rational&);
// expects rational number in the form of 3/5
std::istream& operator>>(std::istream&, Rational&);

#endif

