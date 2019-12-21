
#include "catch.hpp"
#include "RATIONAL.h"

#include <sstream>
#include <cstring>
#include <string>


TEST_CASE("Testing relational operations") {

	SECTION("testing < operator")
	{
		Rational number1(8, 6);
		Rational number2(14, 7);
		Rational number3(6, 2);
		
		REQUIRE((number1 < number3)==true);
		REQUIRE((number2 < number3) == true);
		REQUIRE((number2 < number1) == false);
		
	}

	SECTION("testing <= operator")
	{
		Rational number1(8, 6);
		Rational number2(4, 3);
		Rational number3(8, 3);

		REQUIRE((number1 <= number2) == true);
		REQUIRE((number2 < number3) == true);
		REQUIRE((number3 < number1) == false);
	}

	SECTION("testing > operator")
	{
		Rational number1(15, 5);
		Rational number2(5, 1);
		Rational number3(9, 2);

		REQUIRE((number2 > number1) == true);
		REQUIRE((number2 > number3) == true);
		REQUIRE((number3 > number2) == false);
		
	}
	SECTION("testing >= operator")
	{
		Rational number1(12, 4);
		Rational number2(9, 3);
		Rational number3(10, 2);

		REQUIRE((number2 >= number1) == true);
		REQUIRE((number3 >= number2) == true);
		REQUIRE((number2 >= number3) == false);
	}
	SECTION("testing != operator")
	{
		Rational number1(8, 6);
		Rational number2(14, 7);
		Rational number3(6, 2);
		Rational number4(12, 4);

		REQUIRE((number2 != number1) == true);
		REQUIRE((number3 != number2) == true);
		REQUIRE((number3 != number4) == false);
	}
	
	
}


TEST_CASE("Testing arithmetic operations")
{

SECTION("testing + operation")
	{
		Rational number1(2, 5);
		Rational number2(1, 5);
		Rational number3(3, 5);

		REQUIRE(((number1+number2)==number3)==true);
		
		Rational number4(2, 5);
		Rational number5(4, 7);
		Rational number6(34, 35);
		REQUIRE(((number4 + number5) == number6)==true);

		Rational number7(3, 5);
		Rational number8(4, 5);
		Rational number9(35, 23);
		REQUIRE(((number7 + number8) == number9) == false);
	}
	SECTION("testing - operation")
	{
		Rational number1(3, 6);
		Rational number2(4, 8);
		Rational number3;

		REQUIRE(((number1 - number2) == number3) == true);


		Rational number4(3, 4);
		Rational number5(8, 5);
		Rational number6(-17, 20);

		REQUIRE(((number4 - number5) == number6) == true);

		Rational number7(7, 4);
		Rational number8(8, 5);
		Rational number9(3, 20);

		REQUIRE(((number7 - number8) == number8) == false);
	}
	SECTION("testing * operation")
	{
		Rational number1(35, 5);
		Rational number2(15, 10);
		Rational number3(21, 2);

		REQUIRE(((number1 * number2) == number3) == true);

		Rational number4(-5, 9);
		Rational number5(18, 5);
		Rational number6(-2, 1);

		REQUIRE(((number4 * number5) == number6) == true);

		Rational number7(35, 5);
		Rational number8(15, 10);
		Rational number9(25, 2);

		REQUIRE(((number8 * number7) == number9) == false);

	}

	SECTION("testing / operation")
	{
		Rational number1(18, 12);
		Rational number2(9, 3);
		Rational number3(1, 2);

		REQUIRE(((number1 / number2) == number3) == true);

		Rational number4(27, 48);
		Rational number5(9, 12);
		Rational number6(3, 4);

		REQUIRE(((number4 / number5) == number6) == true);

		Rational number7(18, 12);
		Rational number8(9, 3);
		Rational number9(7, 2);

		REQUIRE(((number7 / number8) == number9) == false);
	}

}

TEST_CASE("Testing other operations") {

	SECTION("Testing to_string function")
	{
		Rational number(3, 4);

		REQUIRE(((number.toString()) == "3/4") == true);

		Rational number2(15, 9);

		REQUIRE(((number2.toString()) == "5/3") == true);

		Rational number3(15, 9);

		REQUIRE(((number2.toString()) == "7/3") == false);
	}

	SECTION("Testing << and >>") {

		std::ostringstream out;
		Rational r(3,5);
		out << r;
		REQUIRE(out.str() == "3/5");

		std::istringstream in("3/5");
		in >> r;
		REQUIRE((r.getNumerator()) == 3);
		REQUIRE((r.getDenom()) == 5);

		REQUIRE(std::to_string(r.getNumerator()) == "3");
		REQUIRE(std::to_string(r.getDenom()) == "5");

	}

}


