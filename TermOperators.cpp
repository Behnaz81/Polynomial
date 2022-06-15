/*********************************************
** File   :  TermOperators.cpp
** Project:  T3, Spring 2022
** Author :  Behnaz Mohamad Hasani Zade
** Date:  :  5/26/2022

** E-mail :  18behnaz@gmail.com
**
** This file contains implement of non-member functions of Term class which
** overload some of the operators.
***********************************************/

#include<iostream>
#include<string>
#include"TermOperators.h"
using namespace std;

/*******************Istream Overload*************************/

/*This function overloads operator >> to get a Term object.
* It gets an istream object and a Term object and returns an istream
* object. In this function we get a string and by that change the Term
* object.
*/
istream& operator>>(istream& termin, Term &termEntered)
{
	//getting a string
	string entery;
	termin >> entery;

	//checking for the x
	int found = entery.find('x');

	//if there was a x
	if (found != -1)
	{
		//if x wan's the first character
		if (found != 0)
		{
			if (entery[0] == '-')  //if the first character was - : -x
			{
				termEntered.coefficient = -1;
			}
			//if the first character isn't - : 4x
			else
			{
				termEntered.coefficient = stod((entery.substr(0, found)).c_str());
			}
		}
		//if the first character was x
		else
		{
			termEntered.coefficient = 1;
		}

		//checking for ^
		int _Pos = entery.find('^');

		//if there was a ^ : x^2
		if (_Pos != -1)
		{
			termEntered.power = atoi((entery.substr(_Pos + 1)).c_str());
		}
		//if there was no ^ : 3x
		else
		{
			termEntered.power = 1;
		}
	}
	//if there was no x: 44
	else
	{
		termEntered.coefficient = stof(entery);
		termEntered.power = 0;
	}
	return termin;
}

/***********************Ostream Overload**********************/

/*This function overloads the operator << to print the term object.
* It gets an ostream object and a Term object and returns an ostream object.
* In this function we try to print the Term object like what we write it in
* daily life. For example avoid writing 1 as the power or coefficient.
*/
ostream & operator<<(ostream& out, const Term  termEntered)
{
	if (termEntered.getCoefficient() == -1)
	{
		out << "-";
	}
	else if (termEntered.getCoefficient() != 1)
	{
		out << termEntered.getCoefficient();
	}
	else if (termEntered.getCoefficient() == 1 && termEntered.getPower() == 0)
	{
		out << 1;
	}
	if (termEntered.getCoefficient() != 0)
	{
		if (termEntered.getPower() != 0 && termEntered.getPower() != 1)
		{
			out << "x^" << termEntered.getPower();
		}
		else if (termEntered.getPower() == 1)
		{
			out << "x";
		}
	}
	
	return out;
}


/*******************Arithmetic Operators Overload*******************/

/*This method overloads operator + to let us use two Term
* objects with operator + and return the sum of them.
*/
Term operator+(const Term& term1, const Term& term2)
{
	//throwing exception in case the power of terms weren't equal
	if (term1.getPower() != term2.getPower())
	{
		throw invalid_argument("powers aren't equal\n");
	}

	//4x + 3x = (3 + 4 ) x
	return Term(term1.getCoefficient() + term2.getCoefficient(), term1.getPower());
}

/*This method overloads operator - to let us use two Term
* objects with operator - and return the sub of them.
*/
Term operator-(const Term& term1, const Term& term2)
{
	//throwing exception in case the power of terms weren't equal
	if (term1.getPower() != term2.getPower())
	{
		throw invalid_argument("powers aren't equal\n");
	}

	//4x^2 - 6x^2 = (4-6) x^2
	return Term(term1.getCoefficient() - term2.getCoefficient(), term1.getPower());
}

/*This method overloads operator * to let us use two Term
* objects with operator * and return the multiply of them.
*/
Term operator*(const Term& term1, const Term& term2)
{
	//3x^2 * 4x^3 = (3*4) x^(2+3)
	return Term(term1.getCoefficient()*term2.getCoefficient(), term1.getPower() + term2.getPower());
}

/*This method overloads operator / to let us use two Term
* objects with operator / and return the division of them.
*/
Term operator/(const Term& term1, const Term& term2)
{
	//4x^5 / 6x^3 = (4/6) x^(5-3)
	return Term(term1.getCoefficient() / term2.getCoefficient(), term1.getPower() - term2.getPower());
}


/************************Comparison Operators Overload**********************/

/* This method overloads comparison operator <. It gets two Term objects and
* returns a boolean which shows if the right objects is smaller than the
* left one.
*/
bool operator<(const Term& term1, const Term& term2)
{
	//checking power
	//if power weren't equal
	if (term1.getPower() < term2.getPower())
	{
		return true;
	}
	else if (term1.getPower() > term2.getPower())
	{
		return false;
	}

	//if power were equal
	//checking coefficient
	else
	{
		if (term1.getCoefficient() < term2.getCoefficient())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

/* This method overloads comparison operator <=. It gets a Term object and
* returns a boolean which shows if the right objects is smaller or equal to the
* left one.
*/
bool operator<=(const Term& term1, const Term& term2)
{
	//checking powe
	//if power weren't equal
	if (term1.getPower() < term2.getPower())
	{
		return true;
	}

	else if (term1.getPower() > term2.getPower())
	{
		return false;
	}

	//if power were equal
	//checking coefficient
	else
	{
		if (term1.getCoefficient() <= term2.getCoefficient())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

/* This method overloads comparison operator >. It gets two Term objects and
* returns a boolean which shows if the right objects is larger than the
* left one.
*/
bool operator>(const Term& term1, const Term& term2)
{
	//checking the power
	//if power weren't equal
	if (term1.getPower() > term2.getPower())
	{
		return true;
	}
	else if (term1.getPower() < term2.getPower())
	{
		return false;
	}

	//if power were equal
	//checking coefficient
	else
	{
		if (term1.getCoefficient() > term2.getCoefficient())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

/* This method overloads comparison operator >=. It gets two Term objects and
* returns a boolean which shows if the right objects is larger or equal to the
* left one.
*/
bool operator>=(const Term& term1, const Term& term2)
{
	//checking the power
	//if power weren't equal
	if (term1.getPower() > term2.getPower())
	{
		return true;
	}
	else if (term1.getPower() < term2.getPower())
	{
		return false;
	}

	//if power were equal
	//checking coefficient
	else
	{
		if (term1.getCoefficient() >= term2.getCoefficient())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

/* This method overloads comparison operator ==. It gets two Term objects and
* returns a boolean which shows if the two objects are equal.
*/
bool operator==(const Term& term1, const Term& term2)
{
	//checking if the coefficient and power both are equal
	return ((term1.getPower() == term2.getPower()) && (term2.getCoefficient() == term2.getCoefficient()));
}

/*This method overloads comparison !=. It gets two Term objects and 
* returns a boolean which shows if the objects aren't
* equal.
*/
bool operator!=(const Term& term1, const Term& term2)
{
	//checking if one of the coefficient or the power aren't equal
	return ((term1.getPower() != term2.getPower()) || (term2.getCoefficient() != term2.getCoefficient()));
}


/******************Sort Function************/

/* This function sorts a vector of terms by their power.
*/
void sortTerms(vector<Term> &terms)
{
	//sorting terms by their power 
	//using bubble sort
	for (int i = 0; i < terms.size(); i++)
	{
		for (int j = 0; j < terms.size() - i - 1; j++)
		{
			if (terms.at(j).getPower() < terms.at(j + 1).getPower())
			{
				Term temp = terms.at(j);
				terms.at(j) = terms.at(j + 1);
				terms.at(j + 1) = temp;
			}
		}
	}
}