//human.cpp starts here....

// Contains ::          Functions For Player Interaction

#include "human.hpp"
#include <iostream>

Human::Human()      // Default Constructor
{
	sum = 0;
}

int Human::getSum()     //  Function for sum to check end of game
{
	switchAce();
	return sum;
}

void Human::switchAce()     // Function for Switching Ace between 1 and 11
{
	if (sum > 21)
	{
		for (int i = 0; i < hand.size(); i++)
		{
			if (hand[i].getNumber() == 1 && !(hand[i].getBlock()))
			{
				hand[i].setBlock(true);
				sum -= 10;
				return;
			}
		}
	}
}


void Human::addCard(Card c)     // / Function for adding card to player
{
	hand.push_back(c);
	if (c.getNumber() > 10) {
		c.setNumber(10);
	}
	else if (c.getNumber() == 1) {
		c.setNumber(11);
	}
	sum += c.getNumber();
}

void Human::clearCards()        // Function for clearing Player cards
{
	hand.clear();
	sum = 0;
}


void Human::printCards()        // Function for Printing Players Cards
{
	std::cout << "\n";
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < hand.size(); j++)
		{
			switch (i)
			{
			case 0: std::cout << ".------."; break;
			case 1: std::cout << "|" << hand[j].getPrintNumber() << ".--. |"; break;
			case 2: hand[j].printCardL1(); break;
			case 3: hand[j].printCardL2(); break;
			case 4: std::cout << "| '--'" << hand[j].getPrintNumber() << "|"; break;
			case 5: std::cout << "`------'";
			}
		}
		std::cout << "\n";
	}
}

// human.cpp ends here.......