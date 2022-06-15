#pragma once
/*********************************************
** File   :  Term.h
** Project:  HW3, Spring 2022
** Author :  Behnaz Mohamad Hasani Zade
** Date:  :  5/26/2022

** E-mail :  18behnaz@gmail.com
**
** This file defines the term class and implements of getters.
***********************************************/

#include<iostream>
using namespace std;

class Term
{
public:
	//Constructors
	Term(float coe, int pow);
	Term(float num);
	Term() {}

	//Getters
	float getCoefficient() const { return coefficient; }
	int getPower() const { return power; }

	//Setters
	void setCoerfficient(float coeEntered) { coefficient = coeEntered; }
	void setPower(int pEntered) { power = pEntered; }

	//Assignment Operators Overload
	Term& operator+=(Term termEnterd);
	Term& operator-=(Term termEntered);
	Term& operator*=(Term termEntered);
	Term& operator/=(Term termEntered);
	Term& operator=(Term termEntered);

	//An operator to calculate derivative of the Term
	Term operator~();

	//An operator to calculate the amount of Term for a certain number
	float operator()(float amount);

	//Increment / Decrement operators
	Term& operator++();      // ++Term
	Term operator++(int x);  // Term++
	Term& operator--();      // --Term
	Term operator--(int x);  // Term--

	//To make the symmertry of the term
	Term& operator-();

private:
	float coefficient;  //The coefficient of the Term object
	int power;          //The power of the Term object   

	//Friend Functions of the class
	friend istream& operator>>(istream& termin, Term& termEntered);    //Showing Term objects
};

