/*********************************************
** File   :  TermOperators.h
** Project:  HW3, Spring 2022
** Author :  Behnaz Mohamad Hasani Zade
** Date:  :  5/26/2022

** E-mail :  18behnaz@gmail.com
**
** This file defines non-member functions of term class which overload
** some of the operators.
***********************************************/

#pragma once
#include<iostream>
#include<vector>
#include"Term.h"
using namespace std;
class Term;

//istream ostream operator overloaded
istream& operator>>(istream& in, Term& termEntered);
ostream& operator<<(ostream& out, const Term termEntered);

//Arithmetic Operators Overload
Term operator+(const Term& term1, const Term& term2);
Term operator-(const Term& term1, const Term& term2);
Term operator*(const Term& term1, const Term& term2);
Term operator/(const Term& term1, const Term& term2);

//Comparison Operators Overload
bool operator<(const Term& term1, const Term& term2);
bool operator<=(const Term& term1, const Term& term2);
bool operator>(const Term& term1, const Term& term2);
bool operator>=(const Term& term1, const Term& term2);
bool operator==(const Term& term1, const Term& term2);
bool operator!=(const Term& term1, const Term& term2);

//To order a vector of Terms by their power
void sortTerms(vector<Term> &terms);