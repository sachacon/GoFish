#include "deck.h"
#include "card.h"
using namespace std;

Deck::Deck(){
   myIndex = 0;
}

void Deck::shuffle(){

}

Card Deck::dealCard(){

}

int Deck::size() const {
    return (SIZE - myIndex);
}


