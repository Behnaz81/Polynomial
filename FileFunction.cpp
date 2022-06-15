/*********************************************
** File   :  FileFunction.cpp
** Project:  HW3, Spring 2022
** Author :  Behnaz Mohamad Hasani Zade
** Date:  :  6/2/2022

** E-mail :  18behnaz@gmail.com
**
** This file contains functions for writing or reading from file.
***********************************************/

#include"FileFunctions.h"
#include"PolynomialOperators.h"

/*This functions gets a string as the file name 
* and a polynomial object to write it in the text file. 
*/
void writeInFileTxt(string fileName, Polynomial p)
{
	ofstream inFile(fileName);
	inFile << p.getPolyVect();
	inFile.close();
}

/*This functions gets a string as the file name
* and a polynomial object to write it in the binary file.
*/
void writeInFileBinary(string fileName, Polynomial p)
{
	ofstream inFile(fileName, ios::binary);
	inFile << p.getPolyVect();
	inFile.close();
}

/*This functions gets a string as the file name
* to read from a text file. It returns a polynomial object.
*/
Polynomial readFileTxt(string fileName)
{
	Polynomial polyOutput;
	ifstream outFile(fileName);
	outFile >> polyOutput;
	outFile.close();
	return polyOutput;
}

/*This functions gets a string as the file name
* to read from a binary file. It returns a polynomial object.
*/
Polynomial readFileBinary(string fileName)
{
	Polynomial polyOutput;
	ifstream outFile(fileName, ios::binary);
	outFile >> polyOutput;
	outFile.close();
	return polyOutput;
}