
#include<iostream>
#include "RATIONAL.h"
#include <string>
#include <iomanip>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::setw;

int main()
{
	//Declaring two Rational objects
	Rational num1, num2;

	//Menu to the user
	cout << "***************************************************************************************************" << endl;
	cout << "Hello! This program accepts two fractions and does some arithmetics on them. Are you ready?             *" << endl;
	cout << "***************************************************************************************************" << endl;

	cout << endl;


	//Getting first fraction from the user as a Rational class object
	cout << "Please enter first fraction in the form 5/2 (for example): ";
	cin >> num1;

	//Checking if denominator entered by user is 0. If it is take in the denominator again
	while (num1.getDenom() == 0)
	{
		cout << "Sorry, dividing by zero is undefined. Enter the fraction again: ";
		cin >> num1;
	}

	//Getting the second fraction from the user as a Rational class object
	cout << "\nPlease enter second fraction in the form 3/4 (for example): ";
	cin >> num2;

	//Checking if denominator entered by user is 0. If it is take in the denominator again
	while (num2.getDenom() == 0)
	{
		cout << "Sorry, dividing by zero is undefined. Please enter the fraction again: ";
		cin >> num2;
	}

	//Printing out the results after the fractions one get reduced
	{
		//If numerator of the fraction is zero, just print out the numerator only
		if (num1.getNumerator() == 0)
		{
			cout << "\nFirst fraction in reduced form is: " << num1.getNumerator() << endl;
		}

		//If denominator is 1, just print out the numerator only
		else if (num1.getDenom() == 1)
		{
			cout << "\nFirst fraction in reduced form is: " << num1.getNumerator() << endl;
		}
		//Otherwise print out both numerator and denominator as an object
		else
            cout << "\nFirst fraction in reduced from is: " << num1 <<endl;
	}

	//Printing out the results after the fractions two get reduced
	{
		if (num2.getNumerator() == 0)
		{
			cout << "Second fraction in reduced from is: " << num2.getNumerator() << endl;
		}

		else if (num2.getDenom() == 1)
		{
			cout << "Second fraction in reduced from is: " << num2.getNumerator() << endl;
		}
		else
			cout << "Second fraction in reduced from is: " << num2 << endl;
	}
	
	//*********************************************************************************

	//Calling sum member function and adding two Rational class obejcts num1 and num2(fractions user entered)
	//with the help of overloading + operator.
	Rational sum(num1 + num2);
	{
		if (sum.getNumerator() == 0)
		{
			cout << "\nAddition of the two fraction is:  " << sum.getNumerator() << endl;
		}

		else if (sum.getDenom() == 1)
		{
			cout << "\nAddition of the two fraction is:  " << sum.getNumerator() << endl;
		}
		else
			cout << "\nAddition of the two fraction is: " << sum << endl;
	}

	//Calling product member function and adding two Rational class obejcts with the help of overloading + operator 
	//by passing num1 and num2(fractions user entered) as an argument
	
	Rational product(num1 * num2);
	{
		if (product.getNumerator() == 0)
		{
			cout << "Product of the two fraction is:  " << product.getNumerator() << endl;
		}

		else if (product.getDenom() == 1)
		{
			cout << "Product of the two fraction is:  " << product.getNumerator() << endl;
		}
		else
			cout << "Product of the two fraction is: " << product << endl;
	}
	
	//Calling division member function and adding two Rational class obejcts with the help of overloading + operator 
	//by passing num1 and num2(fractions user entered) as an argument
	Rational division(num1 / num2);
	{
		if (division.getNumerator() == 0)
		{
			cout << "Division of the two fraction is:  " << division.getNumerator() << endl;
		}

		else if (division.getDenom() == 1)
		{
			cout << "Division of the two fraction is:  " << division.getNumerator() << endl;
		}
		else
			cout << "Division of the two fraction is: " << division << endl;
	}
	
	//Calling subtraction member function and adding two Rational class obejcts with the help of overloading + operator 
	//by passing num1 and num2(fractions user entered) as an argument
	Rational subtraction(num1 - num2);
	{
		if (subtraction.getNumerator() == 0)
		{
			cout << "Subtraction of the two fraction is:  " << subtraction.getNumerator() << endl;
		}

		else if (subtraction.getDenom() == 1)
		{
			cout << "Subtraction of the two fraction is:  " << subtraction.getNumerator() << endl;
		}
		else
			cout << "Subtraction of the two fraction is: " << subtraction << endl;
	}
	
	//******************************************************************************************************
	// Using if statement to check if one fraction is greater or smaller or equal to another fraction.
	// We pass num1 and num2, user entered fractions as an argument then by overloading < operator
	// we can check relational operations
	if (num1 < num2)
	{
		cout << "\nFirst Fraction is smaller than second fraction." << endl;

	}

	//Checking > overloaded operator to make sure if num1 object is greater than num2.
	else if (num1 > num2)
	{
		cout << "\nFirst Fraction is greater than second fraction." << endl;

	}
	//Checking = overloaded operator to make sure if num1 object is equal to num2.
	else if (num1 == num2)
	{
		cout << "\nFirst Fraction is equal to second fraction." << endl;

	}

	system("pause");

	return 0;
}
