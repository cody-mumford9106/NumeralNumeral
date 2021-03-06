/** 
	Cody Mumford
	OCCC Fall 2018
	C++ 
	MumfordHomework1.cpp : Defines the entry point for the console application.
	
	Display a friendly greeting to the user.
	Prompt the user for a string (either a decimal number or a Roman number)
	Accept that string.
	Identify the type of number entered.
	If the value entered is 0 or O, state the number of values converted and exit the program.
	Test the string to ensure that it adheres to the required format.
	If the string does not adhere to the appropriate format, display a message explaining that the user should more carefully read the specifications and exit.
	Convert the input string to the desired output string by invoking a function.
	If the conversion fails, output an appropriate error message
	If the conversion succeeded, display the appropriately-formatted output.
	Display the prompt again.

	I 1
	V 5
	X 10
	L 50
	C 100
	D 500
	M 1000

	Upper limit 9999*

**/
#include "stdafx.h"
#include "string"
#include "iostream"


using namespace std;
void displayMenu();
bool   isValidDecimalNumber(string s);
string convertDecimalToRoman(string s);
bool   isValidRomanNumber(string s);
string convertRomanToDecimal(string s);



int main()
{
	int choice;
	
	do {
		// Displays a simple menu for the user to understand the options
		displayMenu();
		cin >> choice;
		if (choice == 1)
		{
			string integer;
			cout << "You selected the Decimal to Roman Numeral option. Please enter a decimal less than 9999 \n";
			cin >> integer;

			if (isValidDecimalNumber(integer) == true) {
				cout << "your number converted is: " << convertDecimalToRoman(integer) << endl << endl;
			}
			else
				cout << "You fool. You MUST enter a valid decimal. \n\n";
		}
		if (choice == 2)
		{
			string roman;
			cout << "You selected the Roman Numeral to Decimal option. Please enter a Roman Numeral less than 9999 \n";
			cin >> roman;
			if (isValidRomanNumber(roman) != true)
			{
				cout << "You fool. You MUST enter a valid roman numeral. \n\n";
			}
			else 
			{
				cout << "your number converted is: " << convertRomanToDecimal(roman) << endl << endl;
			}
		}
	} while(choice != 3);

	
}

void displayMenu()
{
	cout << "Please select from the menu. \n";
	cout << left << "1. " << "\t Decimal to Roman " << endl;
	cout << left << "2. " << "\t Roman to Decimal " << endl;
	cout << left << "3. " << "\t To close the program. :) " << endl;
}


bool isValidDecimalNumber(string integer)
{
	// function tests whether or not he decimal entered was valid eg 0-9 
	int length = integer.length();
	int i = 0;
	while (length > i) 
	{
		if (integer[i] >= '0' &&  integer[i] <= '9')
		{
			// rudimentary way of testing to see if the loop got through to the end.
			if (i == length)
			{
				return true;
			}
			i++;
		}
		else 
			return false;
	}
	return true;
}

string convertDecimalToRoman(string s)
{
	int decimal[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1}; //base values
	char symbol[] = { 'M','CM','D','CD','C','XC','L', 'XL','X', 'IX', 'V', 'IV','I' };  //roman symbols
	int i = 0;
	int num = stoi(s);

	string answer; 
	while ((num))
	{
		while (num/decimal[i])
		{
			answer += symbol[i];
			num -= decimal[i];
		}
		i++;
	}
	return answer;
}

// validates input for roman
bool isValidRomanNumber(string roman) 
{
	int length = roman.length();
	int index = 0;
	char symbol[] = { 'M','CM','D','CD','C','XC','L', 'XL','X', 'IX', 'V', 'IV','I' };  //roman symbols
	while (index < length) 
	{
		if (roman[index] == symbol[index] )
		{
			return true;
		}
		index++;
	}
	return false;
}
string convertRomanToDecimal(string roman) 
{
	int length = roman.length();
	int index = 0;
	int sum = 0;
	int previous = 0;
	string answer;
	while (index < length) {
		switch (roman[index])
		{
			case 'M':
				sum += 1000;
				if (previous < 1000) 
				{
					sum -= 2 * previous;
				}
				previous = 1000;
				break;
			case 'D':
				sum += 500;
				if (previous < 500)
				{
					sum -= 2 * previous;
				}
				previous = 500;
				break;
			case 'C':
				sum += 100;
				if (previous < 100)
				{
					sum -= 2 * previous;
				}
				previous = 100;
				break;
			case 'L':
				sum += 50;
				if (previous < 50)
				{
					sum -= 2 * previous;
				}
				previous = 50;
				break;
			case 'X':
				sum += 10;
				if (previous < 10)
				{
					sum -= 2 * previous;
				}
				previous = 10;
				break;
			case 'V':
				sum += 5;
				if (previous < 5)
				{
					sum -= 2 * previous;
				}
				previous = 5;
				break;
			case 'I':
				sum += 1;
				if (previous < 1)
				{
					sum -= 2 * previous;
				}
				previous = 1;
				break;
			default:
				cout << roman[index] << "not a roman numeral! \n\n" << endl;
		}
		index++;
		answer = to_string(sum);
	}
	return answer;
}

