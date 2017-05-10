#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"
#include "expression.hpp"
#include "interpreter.hpp"
#include "tokenize.hpp"


using namespace std;


TEST_CASE("Testing Subtraction", "interpreter.hpp")
{

	Interpreter inter;

	Expression bigger;
	Expression smaller;

	Expression negative;
	Expression positive;

	bigger.express.type = NumberType;
	bigger.express.Data.number_value = 1000;

	smaller.express.type = NumberType;
	smaller.express.Data.number_value = 2;

	negative.express.type = NumberType;
	negative.express.Data.number_value = -20;

	positive.express.type = NumberType;
	positive.express.Data.number_value = 30;

	REQUIRE(inter.subtract_expression(bigger.express.Data.number_value,
	 smaller.express.Data.number_value) == 998);

	REQUIRE(inter.subtract_expression(smaller.express.Data.number_value,
	 bigger.express.Data.number_value) == -998);

	REQUIRE(inter.subtract_expression(positive.express.Data.number_value,
	 negative.express.Data.number_value) == 50.0);

	REQUIRE(inter.subtract_expression(negative.express.Data.number_value,
	 positive.express.Data.number_value) == -50.0);


}

//add
TEST_CASE("Testing Addition", "interpreter.hpp")
{
	Interpreter inter;

	Expression bigger;
	Expression smaller;

	Expression negative;
	Expression positive;

	bigger.express.type = NumberType;
	bigger.express.Data.number_value = 1000;

	smaller.express.type = NumberType;
	smaller.express.Data.number_value = 2;

	negative.express.type = NumberType;
	negative.express.Data.number_value = -20;

	positive.express.type = NumberType;
	positive.express.Data.number_value = 30;


	REQUIRE(inter.addition(bigger.express.Data.number_value,
	 smaller.express.Data.number_value) == 1002);

	REQUIRE(inter.addition(smaller.express.Data.number_value,
	 bigger.express.Data.number_value) == 1002);

	REQUIRE(inter.addition(positive.express.Data.number_value,
	 negative.express.Data.number_value) == 10);

	REQUIRE(inter.addition(negative.express.Data.number_value,
	 negative.express.Data.number_value) == -40);

	REQUIRE(inter.addition(negative.express.Data.number_value,
	 positive.express.Data.number_value) == 10.0);

}

//mutliply
TEST_CASE("Testing multiplication", "interpreter.hpp")
{
	Interpreter inter;

	Expression bigger;
	Expression smaller;

	Expression negative;
	Expression positive;

	bigger.express.type = NumberType;
	bigger.express.Data.number_value = 10;

	smaller.express.type = NumberType;
	smaller.express.Data.number_value = 2;

	negative.express.type = NumberType;
	negative.express.Data.number_value = -2;

	positive.express.type = NumberType;
	positive.express.Data.number_value = 3;


	REQUIRE(inter.multiplication(bigger.express.Data.number_value,
	 smaller.express.Data.number_value) == 20);

	REQUIRE(inter.multiplication(smaller.express.Data.number_value,
	 bigger.express.Data.number_value) == 20);

	REQUIRE(inter.multiplication(positive.express.Data.number_value,
	 negative.express.Data.number_value) == -6);

	REQUIRE(inter.multiplication(negative.express.Data.number_value,
	 negative.express.Data.number_value) == 4.0);

	REQUIRE(inter.multiplication(negative.express.Data.number_value,
	 positive.express.Data.number_value) == -6);

}


//divide

TEST_CASE("Testing division", "interpreter.hpp")
{
	Interpreter inter;

	Expression bigger;
	Expression smaller;

	Expression negative;
	Expression positive;

	bigger.express.type = NumberType;
	bigger.express.Data.number_value = 10;

	smaller.express.type = NumberType;
	smaller.express.Data.number_value = 2;

	negative.express.type = NumberType;
	negative.express.Data.number_value = -2;

	positive.express.type = NumberType;
	positive.express.Data.number_value = 2;


	REQUIRE(inter.division(bigger.express.Data.number_value,
	 smaller.express.Data.number_value) == 5);

	REQUIRE(inter.division(smaller.express.Data.number_value,
	 bigger.express.Data.number_value) == 0.2);

	REQUIRE(inter.division(positive.express.Data.number_value,
	 negative.express.Data.number_value) == -1);

	REQUIRE(inter.division(negative.express.Data.number_value,
	 negative.express.Data.number_value) == 1);

	REQUIRE(inter.division(negative.express.Data.number_value,
	 positive.express.Data.number_value) == -1);

}


TEST_CASE("Testing the Interpreter's equality", "interpreter.hpp")
{
	Expression left;
	Expression right;
	Expression one_more;
	Interpreter inter;
	left.express.type = NumberType;
	left.express.Data.number_value = 55;
	right.express.type = NumberType;
	right.express.Data.number_value = 55;
	one_more.express.type = NumberType;
	one_more.express.Data.number_value = -10;

	REQUIRE(inter.equals(left.express.Data.number_value,
	 right.express.Data.number_value) == true);

}





TEST_CASE("Testing Negation Function", "interpreter.hpp")
{
	Expression express;
	Interpreter inter;
	express.express.type = NumberType;
	express.express.Data.number_value = 50;

	Expression express_negative;
	express_negative.express.type = NumberType;
	express_negative.express.Data.number_value = -40;

	REQUIRE(inter.negation(express.express.Data.number_value) ==  -50);
	REQUIRE(inter.negation(express) ==  -50);

	REQUIRE(inter.negation(express_negative.express.Data.number_value) ==  40);
	REQUIRE(inter.negation(express_negative) ==  40);



}

TEST_CASE("Testing Less Than and Greater Than functions", "interpreter.hpp")
{
	Expression express_one;
	Expression express_two;
	Expression express_less_equal_one;
	Interpreter inter;

	express_one.express.type = NumberType;
	express_one.express.Data.number_value = 100;

	express_two.express.type = NumberType;
	express_two.express.Data.number_value = 200.1;

	express_less_equal_one.express.type = NumberType;
	express_less_equal_one.express.Data.number_value = 100;


	REQUIRE(inter.less_than(express_one, express_two) == true);

	REQUIRE(inter.less_than(express_two, express_one) == false);

	REQUIRE(inter.less_than_or_equal(express_one, express_two) == true);

	REQUIRE(inter.less_than_or_equal(express_two, express_one) == false);

	REQUIRE(inter.less_than_or_equal(express_two, express_two) == true);

	REQUIRE(inter.greater_than(express_two, express_one) == true);

	REQUIRE(inter.greater_than(express_one, express_two) == false);

	REQUIRE(inter.greater_than_or_equal(express_less_equal_one, express_less_equal_one) == true);

	REQUIRE(inter.greater_than_or_equal(express_one, express_less_equal_one) == true);

	REQUIRE(inter.greater_than_or_equal(express_two, express_one) == true);


}


TEST_CASE("SymbolType testing through Constructor", "expression.hpp")
{
	string value = "blahblahblah";
	Interpreter inter;
	Expression *express = new Expression(value);
	REQUIRE(express->express.type == SymbolType);
	REQUIRE(express->express.Data.string_value == value);
}

TEST_CASE("NoneType testing through Constructor", "expression.hpp")
{
	Interpreter inter;
	Expression *express = new Expression();
	REQUIRE(express->express.type == NoneType);
}

TEST_CASE("BooleanType testing through Constructor", "expression.hpp")
{
	bool value = true;
	Interpreter inter;
	Expression express = new Expression(value);
	REQUIRE(express.express.type == BooleanType);
	REQUIRE(inter.equals(express, express));
	REQUIRE(express.express.Data.boolean_value == true);

	bool value_two = false;
	Expression express2 = new Expression(value_two);
	REQUIRE(express2.express.type == BooleanType);
	REQUIRE(inter.equals(express2, express2));
	REQUIRE(express2.express.Data.boolean_value == true);
}


TEST_CASE("Tesing NumberType methods and constructors (and expression_factory)", "expression.hpp")
{

	string value = "42";
	Interpreter inter;
	Expression express = inter.expression_factory(value);
	REQUIRE(express.express.type == NumberType);
	REQUIRE(express.express.Data.number_value == 42);

	double value_two = 1050.0;
    Expression express_two(value_two);
	REQUIRE(express_two.express.type ==  NumberType);
    REQUIRE(express_two.express.Data.number_value == 1050.0);

	double value_three = -28;
    Expression express_three(value_three);
	REQUIRE(express_three.express.type ==  NumberType);
    REQUIRE(express_three.express.Data.number_value == -28);

	REQUIRE(inter.negation(express_two) == -1050.0);

}


TEST_CASE("Testing Logical Not and Negation", "interpreter.hpp")
{
	bool value = true;
	Expression express(value);
	Interpreter inter;
    REQUIRE(express.express.Data.boolean_value == true);
    Expression express_not = inter.logical_not(express);
	REQUIRE(express_not.express.Data.boolean_value == false);
    REQUIRE(express_not.express.Data.boolean_value == 0);
    REQUIRE(express.express.type == BooleanType);
    REQUIRE(express_not.express.type == BooleanType);

	bool value_two = false;
    Expression express_two(value_two);
    Expression express_not2 = inter.logical_not(express_two);
	REQUIRE(express_not2 == true);

}

TEST_CASE("testing overall", "interpreter.hpp")
{

    Interpreter inter;
    Environment env;
    vector<string> recursive_vector;
    string hello_world = "(begin (define a 50))";
    string hello_people = "(define b 200)";
    string addition("(+ 1 2 3 4 5)");
    string yup = "True";
    string nope = "False";

    istringstream stream(addition);
    istringstream stream_two(hello_people);
    istringstream stream_three(hello_world);

    inter.parse(stream);
    inter.eval();

    inter.parse(stream_two);
    inter.eval();

    inter.parse(stream_three);
    inter.eval();

    inter.drawVectorGetter();
    inter.equals(Expression(4.), Expression(4.));
    inter.is_bool(yup);
    inter.is_bool(nope);

    Expression exp = new Expression(2.);
    Expression exp_new = new Expression(true);
    string hello = "hello";
    env.add_element_to_map(hello, &exp);
    bool inMap = env.is_present_in_map(hello);
    env.update_map_with_value(hello, &exp_new);
    env.print_map();
    env.clearMap();

    REQUIRE(inMap == true);



}
