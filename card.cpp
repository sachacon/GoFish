// implementation of card class
#include <iostream>
#include <sstream>
#include <string>
#include "card.h"
using namespace std;

// default constructor to ace of spades
Card::Card(){
    myRank = 1;
    mySuit = spades;
}

// overloaded constructor
Card::Card(int rank, Suit s){
    myRank = rank;
    mySuit = s; 
}

// add together rank string and suit string
string Card::toString() const {
    string card = rankString(myRank) + suitString(mySuit); 
    return card; 	    
}

// see if two cards are the same suit throughs string comparisons
bool Card::sameSuitAs(const Card& c) const {
    bool equal_suit = false;
    string c_suit = c.toString();
    c_suit.erase(0,1);

    if(suitString(mySuit) == c_suit){
	equal_suit = true;
    }
    return equal_suit;
}

int Card::getRank() const {
    return myRank;
}

// change suits to strings 
string Card::suitString(Suit s) const {
    string suit;
    if(s == spades){
	suit = 's';
    }
    else if(s == hearts){
	suit = 'h';
    }
    else if(s == diamonds){
	suit = 'd';
    }
    else{
	suit = 'c';
    }
    return suit;   
}

// change rank to strings
string Card::rankString(int r) const {
    string rank;
    if(r == 1){
	rank = 'A';
    }
    else if(r == 11){
	rank = 'J';
    }
    else if(r == 12){
	rank = 'Q';
    }
    else if(r == 13){
	rank = 'K';
    }
    else{
	stringstream out;
	out << r;
	rank = out.str();
    }
    return rank;
}

bool Card::operator ==(const Card& rhs) const {
    bool equality = false; 
    if(toString() == rhs.toString()){
	equality = true;
    }
    return equality;
}

bool Card::operator !=(const Card& rhs) const { 
    bool equality = false;
    if(toString() != rhs.toString()){
	equality = true;
    }
    return equality;
}

ostream& operator << (ostream& out, const Card &c){
    out << c.toString();
    return out;
}


