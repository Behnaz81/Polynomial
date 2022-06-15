/*********************************************
** File   :  FileFunctions.h
** Project:  HW3, Spring 2022
** Author :  Behnaz Mohamad Hasani Zade
** Date:  :  6/2/2022

** E-mail :  18behnaz@gmail.com
**
** This file contains prototypes of the file functions.
***********************************************/

#pragma once
#include<iostream>
#include<fstream>
#include"Polynomial.h"
using namespace std;

//Writing in Files
void writeInFileTxt(string fileName, Polynomial p);
void writeInFileBinary(string fileName, Polynomial p);

//Reading from Files
Polynomial readFileTxt(string fileName);
Polynomial readFileBinary(string fileName);
