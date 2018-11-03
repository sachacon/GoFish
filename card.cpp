// implementation of card class
#include <iostream>
#include <string>
#include "card.h"
using namespace std;

Card::Card(){
    myRank = 1;
    mySuit = spades;
}

Card::Card(int rank, Suit s){
    myRank = rank;
    mySuit = s; 
}

string Card::toString() const {
    
}

bool Card::sameSuitAs(const Card& c) const {
    if( ){
	return true;
    }else{
	return false;
    }
}

int Card::getRank() const {
    return myRank;
}

string Card::suitString(Suit s) const {
    
}

string Card::rankString(int r) const {

}

bool Card::operator ==(const Card& rhs) const {

}

bool Card::operator !=(const Card& rhs) const { 

}

ostream& operator << (ostream& out, const Card& c){
    out << toString();
    return out;
}


