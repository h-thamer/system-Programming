// Dealer.cpp sharts here..

/* Contains ::      Function for Dealers firstcard  */

#include "dealer.hpp"
#include <iostream>

void Dealer::printFirstCard()       // Prints first card revealed and second card hidden
{
    std::cout<<"\n";
    std::cout<<".------..------."<<"\n";
    std::cout<<"|"<<hand[0].getPrintNumber()<<".--. || .--. |"<<"\n";
    hand[0].printCardL1(); std::cout<<"|  //  |"<<"\n";
    hand[0].printCardL2(); std::cout<<"|  //  |"<<"\n";
    std::cout<<"| '--'"<<hand[0].getPrintNumber()<<"|| '--' |"<<"\n";
    std::cout<<"`------'`------'"<<"\n";
}

// Dealer.cpp ends here