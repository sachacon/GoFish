#include "deck.h"
#include "card.h"
using namespace std;

Deck::Deck(){
    myIndex = 0;
    int i = 0, j = 0, s = 0;
    for(j = 0; j < 4; j++){
        s = j;
	Card::Suit suit = static_cast<Card::Suit>(s);        	
        for(i = 1; i < 14; i++){
	    Card c(i,suit);
	    myCards[myIndex] = c;
	    myIndex++;
        }
   }
   myIndex = 0;
}

void Deck::shuffle(){

}

Card Deck::dealCard(){

}

int Deck::size() const {
    return (SIZE - myIndex);
}


