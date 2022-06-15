/*********************************************
** File   :  Polynomial.h
** Project:  HW3, Spring 2022
** Author :  Behnaz Mohamad Hasani Zade
** Date:  :  6/2/2022

** E-mail :  18behnaz@gmail.com
**
** This file defines the Polynomial class and implements of getters.
***********************************************/

#pragma once

#include<vector>
#include"Term.h"
using namespace std;
class Term;

class Polynomial
{
public:
	//Constructors
	Polynomial(vector<Term> sentences);
	Polynomial() {}
	Polynomial(Term termEntered);    //To transform a Term to a Polynomial
	Polynomial(float numberEntered); //To transform a float number to a Polynomial

	//Getter
	vector<Term> getPolyVect() const { return poly; }

	//Assignment Operators
	Polynomial& operator+=(Polynomial polyEntered);
	Polynomial& operator-=(Polynomial polyEntered);
	Polynomial& operator*=(Polynomial polyEntered);
	Polynomial& operator=(Polynomial polyEntered);

	//An operator to calculate derivative of the Polynomial
	Polynomial operator~();

	//Increment / Decrement operators
	Polynomial& operator++();      // ++Polynomial
	Polynomial operator++(int x);  // Polynomial++
	Polynomial& operator--();      // --Polynomial
	Polynomial operator--(int x);  // Polynomial--

	//To retun the indxth Term of the vector 
	Term operator[](int indx) const; //returns a copy
	Term& operator[](int indx);      //returns a refrence

	//An operator to calculate the amount of Polynomial for a certain number
	float operator()(float x);

	//Returns the number of the Polynomial sentences
	int numberOfSentences();

	//Returns the largest power of the Polynomial
	int daraje();

private:
	vector<Term> poly;  // To store the Terms

	//Friend Functions of the Polynomial class
	friend istream& operator>>(istream& in, Polynomial &polynomialEntered);  //To print a Polynomial
};

