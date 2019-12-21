#include<iostream>
#include "RATIONAL.h"           //Including RATIONAL.h file for class declaration
#include<string>

using namespace std;
using std::string;
using std::to_string;


//Rational constructor which accepts two arguments n and d. Then it assigns them to 
//numerator and denominator inside the class. 
Rational::Rational(int n, int d)
{	
	numerator = n;
	denominator = d;
    reduce();        // To make sure that numerator and deonimnator are always saved in reduced form
}


//Reduce function which has n and d arguments. This function reduces the numerator and denominator.

void Rational::reduce()
{

	//Calling to gcd function to find greatest common divisor
	int d = (gcd(numerator, denominator));
	numerator /= d;
	denominator /= d;

}

// Function to find greatest common divisor which is called by reduce function. It accepts two varaibles. Then returns their value to reduce function
//Also, this function uses Euclid method to find greatest common divisor
int Rational::gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a%b);
}



// Overloading == operator. Returns true if this rational has the same numeric value as rhs
bool Rational::operator ==(const Rational& rhs) const{
	return numerator == rhs.numerator && denominator == rhs.denominator;
}

// Overloading <= operator. Returns true if this rational has the same or less than numeric value as rhs
bool Rational::operator <=(const Rational& rhs) const{
	return numerator * rhs.denominator <= rhs.numerator*denominator;
}

// Overloading >= operator. Returns true if this rational has the same or greater than numeric value as rhs
bool Rational::operator >=(const Rational& rhs)const {
	return numerator * rhs.denominator >= rhs.numerator*denominator;
}

// Overloading < operator. Returns true if this rational is smaller than the rhs value
bool Rational::operator <(const Rational& rhs) const{
	return numerator * rhs.denominator < rhs.numerator*denominator;
}

// Overloading > operator. Returns true if this rational is greater than the rhs value
bool Rational::operator >(const Rational& rhs) const{
	return numerator * rhs.denominator > rhs.numerator*denominator;
}

// Overloading != operator. Returns true if this rational does not have the same numeric value as rhs
bool Rational::operator !=(const Rational& rhs) const {
	return !(numerator == rhs.numerator && denominator == rhs.denominator);
}


// Overloading * operator. It multipies numerator and denominator with values of the rational rhs class.
//Then it returns Rational class with newly changed numerator and denominator as argument.
Rational Rational::operator * (const Rational& rhs) const{
	
	int denom = denominator * rhs.denominator;
	int num = numerator * rhs.numerator;
	return Rational(num, denom);
}

// Overloading / operator. It divides numerator and denominator with values of the rational rhs class
//Then it returns Rational class with newly changed numerator and denominator as argument.
Rational Rational::operator / (const Rational& rhs) const{

	int denom = denominator * rhs.numerator;
	int num = numerator * rhs.denominator;
	return Rational(num, denom);
}

// Overloading + operator. It adds numerator and denominator with values of the rational rhs class
//Then it returns Rational class with newly changed numerator and denominator as argument.
Rational Rational::operator + (const Rational& rhs) const{

	int num = numerator * rhs.denominator + rhs.numerator*denominator;
	int denom = denominator * rhs.denominator;

	return Rational(num, denom);
}


// Overloading - operator. It subtracts numerator and denominator with values of the rational rhs class
//Then it returns Rational class with newly changed numerator and denominator as argument.
Rational Rational::operator - (const Rational& rhs) const {

	int num = numerator * rhs.denominator - rhs.numerator*denominator;
	int denom = denominator * rhs.denominator;

	return Rational(num, denom);
}

// This function converts numerator and denimnator to string class and assings them to new string object.
// After that it returns that new string object.
string Rational::toString() {
	string object;
	object = to_string(numerator) + "/" + to_string(denominator);
	return object;
}

//Overloading << operator with ostream member function. Then returning stream itself
ostream &operator <<(ostream &stream, Rational & object)
{
	stream << object.toString();
	return stream;
}

//Overloading >> operator with istream member function
istream &operator >>(istream &stream, Rational & object)
{
	stream >> object.numerator;
	stream.ignore();
	stream >> object.denominator;
	object.reduce();
	return stream;

}