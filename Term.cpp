/*********************************************
** File   :  Term.cpp
** Project:  T3, Spring 2022
** Author :  Behnaz Mohamad Hasani Zade
** Date:  :  5/26/2022

** E-mail :  18behnaz@gmail.com
**
** This file contains implements of all Term class methods.
***********************************************/

#include "Term.h"
#include"TermOperators.h"

/**********************Constructors**********************/
Term::Term(float coe, int pow) :coefficient(coe), power(pow) {}

Term::Term(float num) : coefficient(num), power(0) {}


/*******************Assignment Operators****************/

/*This method overloads operator += to let us use two Term
* objects with operand += and save the sum of them in the first
* object.
*/
Term& Term::operator+=(Term termEnterd)
{
	try
	{
		*this = *this + termEnterd;
	}
	//catching errors
	catch (const invalid_argument& ex)
	{
		cout << "Powers aren't equal\n";
	}
	return *this;
}

/*This method overloads operator -= to let us use two Term
* objects with operand -= and save the sub of them in the first
* object.
*/
Term& Term::operator-=(Term termEnterd)
{
	try
	{
		*this = *this - termEnterd;
	}
	//catching errors
	catch (const invalid_argument& ex)
	{
		cout << "Powers aren't equal\n";
	}
	return *this;
}

/*This method overloads operator *= to let us use two Term
* objects with operator *= and save the multiply of them in the first
* object.
*/
Term& Term::operator*=(Term termEntered)
{
	*this = *this * termEntered;
	return *this;
}

/*This method overloads operator /= to let us use two Term
* objects with operator /= and save the division of them in the first
* object.
*/
Term& Term::operator/=(Term termEntered)
{
	*this = *this / termEntered;
	return *this;
}

/* This method overloads assignment operator(=) which assigns a Term
* object to another one.
*/
Term& Term::operator=(Term termEntered)
{
	coefficient = termEntered.coefficient;
	power = termEntered.power;
	return *this;
}


/******************Derivative Operator*****************/

/* This method overloads operator ~ which calculates derivative
* of the term.
*/
Term Term::operator~()
{
	if (power != 0)
	{
		return Term(coefficient*power, power - 1);
	}
	else
	{
		return Term(0, 0);
	}
}


/*********************Amount Calculation**********************/

/*This method overloads operator () which gets a float number and
* calculates the amount of the term in case x = amount.
*/
float Term::operator()(float amount)
{
	float ans = 1;
	//claculating x^power
	for (int i = 0; i < power; i++)
	{
		ans *= amount;
	}
	//calculating coefficient*(x^power)
	ans *= coefficient;

	return ans;
}


/*************Increment - Decrement operators*****************/

/*This method reduces a Term object with power 0 with one unit.
*/
Term& Term::operator--()
{
	*this -= 1;
	return *this;
}

/*This method reduces a Term object with the power 0 with one unit.
* and it returns the first version without reduction.
*/
Term Term::operator--(int x)
{
	Term output = *this;
	*this -= 1;
	return output;
}

/*This method adds one to a Term with the power 0;
*/
Term& Term::operator++()
{
	*this += 1;
	return *this;
}

/*This method adds one to a Term with the power 0. and it returns
* the first version without addition.
*/
Term Term::operator++(int x)
{
	Term output = *this;
	*this += 1;
	return output;
}


/**************Symmertry Operator************/

/*This method makes multyplies the Term by -1
*/
Term& Term::operator-()
{
	coefficient = -coefficient;
	return *this;
}
