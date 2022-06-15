#include "Polynomial.h"
#include"TermOperators.h"
#include"PolynomialOperators.h"

/**********************Constructors**********************/
Polynomial::Polynomial(vector<Term> sentences)
{
	//checking for terms with the same power in the vector
	for (int i = 0; i < sentences.size(); i++)
	{
		for (int j = i + 1; j < sentences.size(); j++)
		{
			if (sentences.at(i).getPower() == sentences.at(j).getPower())
			{
				if (sentences.at(i).getCoefficient() + sentences.at(j).getCoefficient() != 0)
				{
					sentences.at(i) += sentences.at(j);
				}
				else
				{
					sentences.at(i) = Term(0, 0);
				}
				sentences.erase(sentences.begin() + j);
				if (sentences.size() != 1)
				{
					j--;
				}
			}
		}
		poly.push_back(sentences.at(i));
	}

	//sorting terms by their power
	sortTerms(poly);
}

/*This constructor transforms a Term object to a Polynomial.
*/
Polynomial::Polynomial(Term termEntered)
{
	poly.push_back(termEntered);
}

/*This constructor transforms a float number to a Polynomial.
* We know a float number is a Term with power 0.
*/
Polynomial::Polynomial(float numberEntered)
{
	poly.push_back(numberEntered);
}


/*******************Assignment Operators****************/

/*This method overloads operator += to let us use two Polynomial
* objects with operand += and save the sum of them in the first
* object.
*/
Polynomial& Polynomial::operator+=(Polynomial polyEntered)
{
	*this = *this + polyEntered;
	return *this;
}

/*This method overloads operator -= to let us use two Polynomial
* objects with operand -= and save the sub of them in the first
* object.
*/
Polynomial& Polynomial::operator-=(Polynomial polyEntered)
{
	*this = *this - polyEntered;
	return *this;
}

/*This method overloads operator *= to let us use two Polynomial
* objects with operator *= and save the multiply of them in the first
* object.
*/
Polynomial& Polynomial::operator*=(Polynomial polyEntered)
{
	*this = *this * polyEntered;
	return *this;
}

/* This method overloads assignment operator(=) which assigns a Polynomial
* object to another one.
*/
Polynomial& Polynomial::operator=(Polynomial polyEntered)
{
	poly = polyEntered.poly;
	return *this;
}


/******************Derivative Operator*****************/

/* This method overloads operator ~ which calculates derivative
* of the Polynomial.
*/
Polynomial Polynomial::operator~()
{
	vector<Term> terms;
	//calculating derivated term for each term in the vector
	for (int i = 0; i < poly.size(); i++)
	{
		Term tempTerm = ~poly.at(i);
		if (tempTerm.getCoefficient() != 0)
		{
			terms.push_back(tempTerm);
		}
	}
	return Polynomial(terms);
}


/*************Increment - Decrement operators*****************/

/*This method reduces a Polynomial object with one unit.
*/
Polynomial& Polynomial::operator++()
{
	*this += 1;
	return *this;
}

/*This method reduces a Polynomial object with one unit.
* and it returns the first version without reduction.
*/
Polynomial Polynomial::operator++(int x)
{
	Polynomial outputPoly = *this;
	*this += 1;
	return outputPoly;
}

/*This method adds one to a Polynomial with object.
*/
Polynomial& Polynomial::operator--()
{
	*this -= 1;
	return *this;
}

/*This method adds one to a Polynomial. and it returns
* the first version without addition.
*/
Polynomial Polynomial::operator--(int x)
{
	Polynomial outputPoly = *this;
	*this -= 1;
	return outputPoly;
}


/*****************Return A Term Of The Polynomial*****************/

/*This method returns the indxth Term of the vector.
* It returns a copy.
*/
Term Polynomial::operator[](int indx) const
{
	return poly.at(indx);
}

/*This method returns the indxth Term of the vector.
* It returns a refrence.
*/
Term& Polynomial::operator[](int indx)
{
	return poly.at(indx);
}


/*********************Amount Calculation**********************/

/*This method overloads operator () which gets a float number and
* calculates the amount of the term in case x = amount.
*/
float Polynomial::operator()(float x)
{
	float output = 0;
	//calculating each term amount if x was the entered number
	for (int i = 0; i < poly.size(); i++)
	{
		output += poly.at(i)(x);
	}
	return output;
}


/*******************Number Of Sentences*****************/

/*This method returns the number of Terms stored in the vector.
*/
int Polynomial::numberOfSentences()
{
	return poly.size();
}

/*********************Daraje Polynomia*******************/

/*This method returns the largest power of the Terms stored in the vector.
*/
int Polynomial::daraje()
{
	//degree of the polynomial is the largest power in the polynomial
	return poly.at(0).getPower();
}