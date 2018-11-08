#include <cstdlib>
#include <ctime>
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
    srand(time(0));
}

void Deck::shuffle(){
    // shuffles deck
    int i = 0;
    int deck_size = size();
    long card1, card2;
    for(i = 0; i < 200; i++){
	card1 = rand() % deck_size;
	card2 = rand() % deck_size;
	Card temp = myCards[card1];
	myCards[card1] = myCards[card2];
        myCards[card2] = temp;	
    }   
}

Card Deck::dealCard(){
    if(myIndex == SIZE){
	Card empty_deck;
	return empty_deck;
	
    }
    Card card_dealt = myCards[myIndex];
    myIndex++;
    return card_dealt;
}

int Deck::size() const {
    return (SIZE - myIndex);
}


