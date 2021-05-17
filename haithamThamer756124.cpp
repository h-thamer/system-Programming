#include <iostream>
using namespace std;
 
struct Card
{
  string cardName;
  string suit;
  int cardValue;
};
 
void getCard(Card &theCard){
  switch(theCard.cardValue){
    case 1:
      theCard.cardName = "Ace";
      break;
    case 2:
      theCard.cardName = "Two";
      break;
    case 3:
      theCard.cardName = "Three";
      break;
    case 4:
      theCard.cardName = "Four";
      break;
    case 5:
      theCard.cardName = "Five";
      break;
    case 6:
      theCard.cardName = "Six";
      break;
    case 7:
      theCard.cardName = "Sevin";
      break;
   case 8:
      theCard.cardName = "Eight";
      break;
   case 9:
      theCard.cardName = "Nine";
      break;
   case 10:
      theCard.cardName = "Ten";
      break;
   case 11:
      theCard.cardName = "Jack";
      break;
   case 12:
      theCard.cardName = "Queen";
      break;
   case 13:
      theCard.cardName = "King";
      break;
 
  }
};
 
void getSuit(Card &theCard){
  int temp= 1 + (rand() % 4);
  switch(temp){
    case 1:
      theCard.suit = "Hearts";
      break;
    case 2:
      theCard.suit = "Clubs";
      break;
    case 3:
      theCard.suit = "Spades";
      break;
    case 4:
      theCard.suit = "Diamonds";
      break;
  }
 
};
void printInto()
  {
   cout<<" ██████╗ ██╗   ██╗███████╗███████╗███████╗     █████╗      ██████╗ █████╗ ██████╗ ██████╗\n";     
   cout<<"██╔════╝ ██║   ██║██╔════╝██╔════╝██╔════╝    ██╔══██╗    ██╔════╝██╔══██╗██╔══██╗██╔══██╗\n";    
   cout<<"██║  ███╗██║   ██║█████╗  ███████╗███████╗    ███████║    ██║     ███████║██████╔╝██║  ██║\n";   
   cout<<"██║   ██║██║   ██║██╔══╝  ╚════██║╚════██║    ██╔══██║    ██║     ██╔══██║██╔══██╗██║  ██║\n";    
   cout<<"╚██████╔╝╚██████╔╝███████╗███████║███████║    ██║  ██║    ╚██████╗██║  ██║██║  ██║██████╔╝\n";    
   cout<<" ╚═════╝  ╚═════╝ ╚══════╝╚══════╝╚══════╝    ╚═╝  ╚═╝     ╚═════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═════╝\n\n\n";
 };
int main() {
  int score = 0;
  string cardGuess;
  Card *cardPack;
  cardPack = new Card[52];
  printInto();
  const char *cardNu[13] = { "Ace" , "Two" , "Three" , "Four", "Five" , "Six" , "Sevin" , "Eight" , "Nine" , "Ten" , "Jack" , "Queen" , "King" };
  const char *cardNa[4] = { "Hearts" , "Clubs" , "Spades" , "Diamonds" };
  
  for (int index = 0; index < 52; index++) 
  {
    cardPack[index].cardValue = 1 + (rand() % 13);
  }
  
  for (int index = 0; index < 52; index++) 
   {
    getCard(cardPack[index]);
  }
  
  for (int index = 0; index < 52; index++) 
  {
    getSuit(cardPack[index]);
  }
 
  cout << "Here are the cards \n\n\n"; 
  for (int i = 0; i < 4 ; i++)
  {
	for (int j = 0; j < 13 ; j++)
	 { 
	    cout << cardNu[j]<< " of " << cardNa[i]<<"\n";
	}
}
	
  for (int index = 0; index < 52; index++) 
   {
    cout << "\n\nGuess the name of the cards \n";
    getline(cin, cardGuess);
 
    if (cardGuess == cardPack[index].cardName){
      cout << "\nCorrect \n";
      score++;
    }
    else{
      cout << "\n Wrong Guess \n";
    }
    cout <<  "\nThe card was the ";
    cout << cardPack[index].cardName;
    cout << " of " << cardPack[index].suit;
    cout << " | value: " << cardPack[index].cardValue;
    cout << "\n";
    cout << " Your score is " << score << "\n";
  }
  return 0;
} 