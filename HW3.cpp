/*********************************************
** File   :  HW3.cpp
** Project:  HW3, Spring 2022
** Author :  Behnaz Mohamad Hasani Zade
** Date:  :  5/26/2022

** E-mail :  18behnaz@gmail.com
**
** This file contains the main function.
***********************************************/

#include <iostream>
#include<vector>
#include<string>
#include"Term.h"
#include"TermOperators.h"
#include"PolynomialOperators.h"
#include"Polynomial.h"
#include"FileFunctions.h"
using namespace std;

int main()
{
	Term t(3, 0);
	cout<<++t;
	char mchoice;  //your choice in the main menu             
	int pChoce;    //your choice in the Polynomial menu

	bool mcontinueOrNot = true;   //A boolean for the first loop which shows the main menu
	bool pcontinueOrNot = true;   //A boolean for the second loop which shows the Polynomial menu

	Polynomial currentPoly(0);   //Assigning amount to current Polynomial
	while (mcontinueOrNot)       //The main menu will be shown while the boolean is true
	{
		//Displaying main menu
		cout << "Main Menu\n"
			<< "1 - New Polynomial\n"
			<< "2 - Load from text file\n"
			<< "3 - Load from binary file\n"
			<< "4 - Quit\n";
		
		//getting user's choice from the menu
		cin >> mchoice;

		switch (mchoice)
		{
		case '1':
		{
			//1. New Polynomial
			while (pcontinueOrNot)
			{
				//Displaying Polynomial Menu
				cout << "Polynomial Menu\n"
					<< "Current Polynomial = " << currentPoly << endl
					<< "1 - Add\n"
					<< "2 - Subtract\n"
					<< "3 - Multiply\n"
					<< "4 - Derivative\n"
					<< "5 - Find Degree\n"
					<< "6 - Find Value for specific x\n"
					<< "7 - Compare\n"
					<< "8 - Save to a text file\n"
					<< "9 - Save to a binary file\n"
					<< "10 - Back to Main Menu\n";

				//getting user's choice
				cin >> pChoce;

				if (pChoce == 1)
				{
					//1. Add
					Polynomial pAdd; 
					cin >> pAdd;   
					currentPoly += pAdd;
				}
				else if (pChoce == 2)
				{
					//2. Subtract
					Polynomial pSub;
					cin >> pSub;
					currentPoly -= pSub;
				}
				else if (pChoce == 3)
				{
					//3. Multiply
					Polynomial pMult;
					cin >> pMult;
					currentPoly *= pMult;
				}
				else if (pChoce == 4)
				{
					//4. Derivative
					currentPoly = ~currentPoly;
				}
				else if (pChoce == 5)
				{
					//5. Find Degree
					cout << currentPoly.daraje() << endl;
				}
				else if (pChoce == 6)
				{
					//6. Find Value for specific x
					int amount;
					cin >> amount;
					cout << currentPoly(amount) << endl;
				}
				else if (pChoce == 7)
				{
					//7. Compare
					Polynomial otherPoly;
					cin >> otherPoly;
					cout << "Comparing " << currentPoly << " with " << otherPoly << endl;

					//current polynomial > new polynomial
					cout << currentPoly << ">" << otherPoly << ":";
					if (currentPoly > otherPoly)
					{
						cout << "True\n";
					}
					else
					{
						cout << "False\n";
					}

					//current polynomial >= new polynomial
					cout << currentPoly << ">=" << otherPoly << ":";
					if (currentPoly >= otherPoly)
					{
						cout << "True\n";
					}
					else
					{
						cout << "False\n";
					}

					//current polynomial < new polynomial
					cout << currentPoly << "<" << otherPoly << ":";
					if (currentPoly < otherPoly)
					{
						cout << "True\n";
					}
					else
					{
						cout << "False\n";
					}

					//current polynomial <= new polynomial
					cout << currentPoly << "<=" << otherPoly << ":";
					if (currentPoly <= otherPoly)
					{
						cout << "True\n";
					}
					else
					{
						cout << "False\n";
					}

					//current polynomial == new polynomial
					cout << currentPoly << "==" << otherPoly << ":";
					if (currentPoly == otherPoly)
					{
						cout << "True\n";
					}
					else
					{
						cout << "False\n";
					}

					//current polynomial != new polynomial
					cout << currentPoly << "!=" << otherPoly << ":";
					if (currentPoly != otherPoly)
					{
						cout << "True\n";
					}
					else
					{
						cout << "False\n";
					}
				}
				else if (pChoce == 8)
				{
				    //8. Save to a text file
					string fileName;
					cout << "File Name: ";
					cin >> fileName;
					writeInFileTxt(fileName, currentPoly);
				}
				else if (pChoce == 9)
				{
				    //9. Save to a binary file
					string fileName;
					cout << "File Name: ";
					cin >> fileName;
					writeInFileBinary(fileName, currentPoly);
				}
				else if (pChoce == 10)
				{
					//10. Back to Main Menu
					pcontinueOrNot = false;
				}
			}
			break;
		}

		//2. Load from text file
		case '2':
		{	string fileName;
			cout << "File Name: ";
			cin >> fileName;
			currentPoly = readFileTxt(fileName);
			break;
		}
		
		//3. Load from binary file
		case '3':
		{	
			string fileName;
			cout << "File Name: ";
			cin >> fileName;
			currentPoly = readFileBinary(fileName);
			break;
		}

		//4. Quit
		case '4':
			mcontinueOrNot = false;
			break;

		default:
			break;
		}
	}

	system("pause");
}
