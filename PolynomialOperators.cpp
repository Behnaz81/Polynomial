#include<string>
#include"PolynomialOperators.h"
#include"Polynomial.h"
#include"Term.h"
#include"TermOperators.h"
using namespace std;

/*******************Istream Overload*************************/

/*This function overloads operator >> to get a Polynomial object.
* It gets an istream object and a Polynomial object and returns an istream
* object. In this function we get a string and by that change the Term
* object.
*/
istream& operator>>(istream& in, Polynomial &polynomialEntered)
{
	string entery;  //Getting a string
	in >> entery;

	while (entery != "")  //a loop which continues until the string is null
	{
		Term term;
		string substr;
		int posPositive = entery.find('+');  //Finding + in the string
		int posNegetive = entery.find('-');  ////Finding - in the string

		//if both positive and negative existed

		//if postive was before negative 
		if (posPositive < posNegetive && posPositive != -1)
		{
			substr = entery.substr(0, posPositive);
			entery = entery.substr(posPositive + 1);
		}
		//if negative was before positive
		else if (posPositive > posNegetive && posNegetive != -1)
		{
			//if the negative was the first character in the string
			if (posNegetive == 0)
			{
				int posNegetive2 = (entery.substr(posNegetive + 1)).find('-'); //Finding the second negative
				//if there was a second negative
				if (posNegetive2 != -1)
				{
					//checking which is closer? 
					//positive
					if (posNegetive2 < posPositive)
					{
						substr = entery.substr(0, posNegetive2 + 1);
						entery = entery.substr(posNegetive2 + 1);
					}
					//or the second negative
					else if (posNegetive2 > posPositive)
					{
						substr = entery.substr(0, posPositive);
						entery = entery.substr(posPositive + 1);
					}
				}
				else
				{
					substr = entery.substr(0, posPositive);//-18x^2-2x
					entery = entery.substr(posPositive + 1);
				}
			}
			//if there was no second negative
			else
			{
				substr = entery.substr(0, posNegetive);
				entery = entery.substr(posNegetive);
			}
		}

		//if there was no positive and only negative
		else if (posPositive == -1 && posNegetive != -1)
		{
			//finding the second negative
			int posNegative2 = (entery.substr(posNegetive + 1)).find('-');
			//checking if the second negative exists
			if (posNegative2 != -1)
			{
				substr = entery.substr(0, posNegative2 + 1);
				entery = entery.substr(posNegative2 + 1);
			}
			//if the negative was the first character and there was no other negative
			else if (posNegetive == 0)
			{
				substr = entery;
				entery = "";
			}
			//if the first sentence was positive
			else
			{
				substr = entery.substr(0, posNegetive);
				entery = entery.substr(posNegetive);
			}
		}

		//if there was no negative and only positive
		else if (posNegetive == -1 && posPositive != -1)
		{
			substr = entery.substr(0, posPositive);
			entery = entery.substr(posPositive + 1);
		}

		//if there was no positive or negative
		else if (posNegetive == -1 && posPositive == -1)
		{
			substr = entery;
			entery = "";
		}

		//.........finding coefiicient......//

		//finding x in the sub string
		int found = substr.find('x');

		//if there was an x
		if (found != -1)
		{
			//and it wasn't the first character
			if (found != 0)
			{
				//if the first character was - and the second was x : -x
				if (substr[0] == '-' && found == 1)
				{
					term.setCoerfficient(-1);
				}
				//if the first character was - but the second one wasn't x: -4x
				else
				{
					term.setCoerfficient(stod((substr.substr(0, found)).c_str()));
				}
			}

			//if x was the first character :  x
			else
			{
				term.setCoerfficient(1);
			}

			//......finding the powes.....//

			//finding ^
			int _Pos = substr.find('^');

			//if there was a ^ : x^2
			if (_Pos != -1)
			{
				term.setPower(atoi((substr.substr(_Pos + 1)).c_str()));
			}
			//if there was no ^ : x
			else
			{
				term.setPower(1);
			}
		}

		//if there was no x : 4
		else
		{
			term.setCoerfficient(stof(substr));
			term.setPower(0);
		}

		//adding the new term to the vector
		polynomialEntered.poly.push_back(term);
	}

	//finding terms with the ame power and calculating the sum of them
	for (int i = 0; i < polynomialEntered.poly.size(); i++)
	{
		for (int j = i + 1; j < polynomialEntered.poly.size(); j++)
		{
			if (polynomialEntered.poly.at(i).getPower() == polynomialEntered.poly.at(j).getPower())
			{
				polynomialEntered.poly.at(i) += polynomialEntered.poly.at(j);
				polynomialEntered.poly.erase(polynomialEntered.poly.begin() + j);
				if (polynomialEntered.poly.size() != 1)
				{
					j--;
				}
			}
		}
	}

	//sorting terms by their powers
	sortTerms(polynomialEntered.poly);

	return in;
}


/***********************Ostream Overload**********************/

/*This function overloads the operator << to print the Polynomial object.
* It gets an ostream object and a Polynomial object and returns an ostream object.
* In this function we try to print the Polynomial object like what we write it in
* daily life. For example avoid writing 1 as the power or coefficient.
*/
ostream& operator<<(ostream& out, Polynomial polynomialEntered)
{
	for (int i = 0; i < polynomialEntered.getPolyVect().size(); i++)
	{
		if (polynomialEntered.getPolyVect().at(i).getCoefficient() != 0)
		{
			//printing + if it's not the first sentence or negative
			if (i > 0 && polynomialEntered.getPolyVect().at(i).getCoefficient() > 0) 
			{
				out << "+";
			}
			if (polynomialEntered.getPolyVect().at(i).getCoefficient() != -1 || polynomialEntered.getPolyVect().at(i).getPower() != 0)
			{
				out << polynomialEntered.getPolyVect().at(i);
			}
			else if (polynomialEntered.getPolyVect().at(i).getPower() == 0)
			{
				out << -1;
			}
		}
		else if (polynomialEntered.getPolyVect().size() == 1)
		{
			out << polynomialEntered.getPolyVect().at(0);
		}
	}
	return out;
}


/*******************Arithmetic Operators Overload*******************/

/*This method overloads operator + to let us use two Polynomial
* objects with operator + and return the sum of them.
*/
Polynomial operator+(const Polynomial& poly1, const Polynomial& poly2)
{
	vector<Term> sumTerms;

	//adding the terms of the first polynomial to the vector
	for (int i = 0; i < poly1.getPolyVect().size(); i++)
	{
		if (poly1.getPolyVect().at(i).getCoefficient() != 0)
		{
			sumTerms.push_back(poly1.getPolyVect().at(i));
		}
	}

	//adding the terms of the second polynomial to the vector
	for (int j = 0; j < poly2.getPolyVect().size(); j++)
	{
		if (poly2.getPolyVect().at(j).getCoefficient() != 0)
		{
			sumTerms.push_back(poly2.getPolyVect().at(j));
		}
	}

	//returning the new polynomial
	return Polynomial(sumTerms);
}

/*This method overloads operator - to let us use two Polynomial
* objects with operator - and return the sub of them.
*/
Polynomial operator-(const Polynomial& poly1, const Polynomial& poly2)
{
	vector<Term> subTerms;

	//adding the terms of the first polynomial to the vector
	for (int i = 0; i < poly1.getPolyVect().size(); i++)
	{
		subTerms.push_back(poly1.getPolyVect().at(i));
	}

	//adding the negative of terms of the second polynomial to the vector
	for (int j = 0; j < poly2.getPolyVect().size(); j++)
	{
		subTerms.push_back(-(poly2.getPolyVect().at(j)));
	}

	//returning the new Polynomial
	return Polynomial(subTerms);
}

/*This method overloads operator * to let us use two Polynomial
* objects with operator * and return the multiply of them.
*/
Polynomial operator*(const Polynomial& poly1, const Polynomial& poly2)
{
	vector<Term> terms;

	//every term multiplies with all other sentences from the other polynomial
	for (int i = 0; i < poly1.getPolyVect().size(); i++)
	{
		for (int j = 0; j < poly2.getPolyVect().size(); j++)
		{
			terms.push_back(poly1.getPolyVect().at(i)*poly2.getPolyVect().at(j));
		}
	}

	//returning the new polynomial
	return Polynomial(terms);
}


/************************Comparison Operators Overload**********************/

/* This method overloads comparison operator <. It gets two Polynomial objects and
* returns a boolean which shows if the right objects is smaller than the
* left one.
*/
bool operator<(const Polynomial& poly1, const Polynomial& poly2)
{
	//comparing every term
	for (int i = 0; i < poly1.getPolyVect().size(); i++)
	{
		if (poly1.getPolyVect().at(i) < poly2.getPolyVect().at(i))
		{
			return true;
		}
		else if (poly1.getPolyVect().at(i) > poly2.getPolyVect().at(i))
		{
			return false;
		}
	}
	return false;
}

/* This method overloads comparison operator <=. It gets a Polynomial object and
* returns a boolean which shows if the right objects is smaller or equal to the
* left one.
*/
bool operator<=(const Polynomial& poly1, const Polynomial& poly2)
{
	//comparing every term
	for (int i = 0; i < poly1.getPolyVect().size(); i++)
	{
		if (poly1.getPolyVect().at(i) > poly2.getPolyVect().at(i))
		{
			return false;
		}
		else if (poly1.getPolyVect().at(i) < poly2.getPolyVect().at(i))
		{
			return true;
		}
	}
	return true;
}

/* This method overloads comparison operator >. It gets two Polynomial objects and
* returns a boolean which shows if the right objects is larger than the
* left one.
*/
bool operator>(const Polynomial& poly1, const Polynomial& poly2)
{
	//comparing every term
	for (int i = 0; i < poly1.getPolyVect().size(); i++)
	{
		if (poly1.getPolyVect().at(i) > poly2.getPolyVect().at(i))
		{
			return true;
		}
		else if (poly1.getPolyVect().at(i) < poly2.getPolyVect().at(i))
		{
			return false;
		}
	}
	return false;
}

/* This method overloads comparison operator >=. It gets two Polynomial objects and
* returns a boolean which shows if the right objects is larger or equal to the
* left one.
*/
bool operator>=(const Polynomial& poly1, const Polynomial& poly2)
{
	//comparing every term
	for (int i = 0; i < poly1.getPolyVect().size(); i++)
	{
		if (poly1.getPolyVect().at(i) > poly2.getPolyVect().at(i))
		{
			return true;
		}
		else if (poly1.getPolyVect().at(i) < poly2.getPolyVect().at(i))
		{
			return false;
		}
	}
	return true;
}

/* This method overloads comparison operator ==. It gets two Polynomial objects and
* returns a boolean which shows if the two objects are equal.
*/
bool operator==(const Polynomial& poly1, const Polynomial& poly2)
{
	//comparing every term
	for (int i = 0; i < poly1.getPolyVect().size(); i++)
	{
		//if one term wasn't equal
		if (poly1.getPolyVect().at(i) != poly2.getPolyVect().at(i))
		{
			return false;
		}
	}
	//if all were equal
	return true;
}

/*This method overloads comparison !=. It gets two Polynomial objects and
* returns a boolean which shows if the objects aren't
* equal.
*/
bool operator!=(const Polynomial& poly1, const Polynomial& poly2)
{
	//comparing every term
	for (int i = 0; i < poly1.getPolyVect().size(); i++)
	{
		//if one term wasn't equal
		if (poly1.getPolyVect().at(i) != poly2.getPolyVect().at(i))
		{
			return true;
		}
	}
	//if all terms were equal
	return false;
}