// card.cpp starts here....

// CONTAINS ::      Functions For Card Transcations


#include "card.h"
#include <iostream>

Card::Card()        // VBase Function for Card ID
{
	number = 0;
	suit = '\0';
	block = false;
}

Card::Card(int no, char s)      // Assign Function for Card ID
{
	number = no;
	suit = s;
	block = false;
}

int Card::getNumber()           // Function for getting Card Number
{
	return number;
}

char Card::getSuit()            // Function for returning Card Suit
{
	return suit;
}

bool Card::getBlock()           // Function for block Identification
{
	return block;
}

void Card::setNumber(int no)    // Function for Setting Values(Bets,card Nums)
{
	number = no;
}

void Card::setSuit(char c)      // Function for Setting Suit
{
	suit = c;
}

void Card::setBlock(bool b)     // Function for Block Selection
{
	block = b;
}

char Card::getPrintNumber()     // Function for Retruning Card numbers
{
	switch (number)
	{
	case 1: return 'A';
	case 10: return 'X';
	case 11: return 'J';
	case 12: return 'Q';
	case 13: return 'K';
	default:
		char * digits;
		int g = 10;  // Get the number of elements for the array
		int i;
		digits = (char*)malloc(g * sizeof(char));// Dynamically allocate memory using malloc() 
		   // Check if the memory has been successfully 
		   // allocated by malloc or not
		if (digits == NULL)
		{
			exit(0);
		}
		else {    // Get the elements of the array 
			for (i = 0; i < g; ++i)
			{
				digits[i] = i;
			}
		}
	}
}
void Card::printCardL1()        // Function For Printing Player Card
{
	switch (suit)
	{
	case 'C': std::cout << "| :(): |"; break;
	case 'H': std::cout << "| (\\/) |"; break;
	case 'D':
	case 'S': std::cout << "| :/\\: |"; break;
	default: std::cout << "|  //  |";
	}
}

void Card::printCardL2()        // Function for Printing Dealer card
{
	switch (suit)
	{
	case 'C': std::cout << "| ()() |"; break;
	case 'H':
	case 'D': std::cout << "| :\\/: |"; break;
	case 'S': std::cout << "| (__) |"; break;
	default: std::cout << "|  //  |";
	}
}

// Card.cpp ends here...
