/*********************************************
** File   :  PolynomialOperators.h
** Project:  HW3, Spring 2022
** Author :  Behnaz Mohamad Hasani Zade
** Date:  :  6/2/2022

** E-mail :  18behnaz@gmail.com
**
** This file defines the non-member funtions of Polynomial class.
***********************************************/

#pragma once
#include<iostream>
#include"Polynomial.h"
#include"Term.h"

//istream ostream operator overloaded
istream& operator>>(istream& in, Polynomial &polynomialEntered);
ostream& operator<<(ostream& out, Polynomial polynomialEntered);

//Arithmetic Operators Overload
Polynomial operator+(const Polynomial& poly1, const Polynomial& poly2);
Polynomial operator-(const Polynomial& poly1, const Polynomial& poly2);
Polynomial operator*(const Polynomial& poly1, const Polynomial& poly2);

//Comparison Operators Overload
bool operator<(const Polynomial& poly1, const Polynomial& poly2);
bool operator<=(const Polynomial& poly1, const Polynomial& poly2);
bool operator>(const Polynomial& poly1, const Polynomial& poly2);
bool operator>=(const Polynomial& poly1, const Polynomial& poly2);
bool operator==(const Polynomial& poly1, const Polynomial& poly2);
bool operator!=(const Polynomial& poly1, const Polynomial& poly2);