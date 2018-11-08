#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include "player.h" 
#include "card.h"
#include "deck.h"
using namespace std;

// no input constructor
Player::Player(){
    myHand_Index = 0;
    myName = "";
}

void Player::addCard(Card c){
    myHand.push_back(c);       
}

void Player::bookCards(Card c1, Card c2){
    myBook.push_back(c1);
    myBook.push_back(c2);
}

bool Player::checkHandForBook(Card &c1, Card &c2){
    bool book_in_hand = false;
    bool found_pair = false;
    vector<Card>::iterator iter;
    vector<Card>::iterator iter2;
    // check if any two different indexes have the same card in myHand vector
    // double while loop with extra bool variable  
    iter = myHand.begin();
    iter2 = myHand.begin();
    while(iter != myHand.end() && !found_pair){
	Card pair1 = *iter;
	while(iter2 != myHand.end() && !found_pair){
	    if( (iter - myHand.begin()) != (iter2 - myHand.begin()) ){
		Card pair2 = *iter2;
		if(pair1.getRank() == pair2.getRank()){
		    c1 = *iter;
		    c2 = *iter2;
		    found_pair = true;
		    book_in_hand = true;
		}
	    } 		
	    iter2++;
	}
	iter++;
	iter2 = myHand.begin();
    } 
    return book_in_hand;
}

bool Player::rankInHand(Card c) const {
    // loop through hand and compare with input card with iterators
    bool same_rank = false;
    vector<Card>::const_iterator iter;
    for(iter = myHand.begin(); iter != myHand.end(); iter++){
	Card in_hand = *iter;
	if(in_hand.getRank() == c.getRank()){
	    same_rank = true;
	}
    }
    return same_rank;
}

Card Player::chooseCardFromHand() const {
    // rotate hand to return a different card each time, strategy
    vector<Card>::const_iterator iter;
    iter = myHand.begin();
    for(int i = 0; i < myHand_Index;i++){
        iter++;
    }
    Card c = *iter;    
    myHand_Index = (myHand_Index+1) % myHand.size(); 
  
    return c;
}

bool Player::cardInHand(Card c) const {
    // loop through hand and find card if in hand with iterators  
    bool found_card = false;
    vector<Card>::const_iterator iter;
    Card c_hand;
    for(iter = myHand.begin(); iter != myHand.end(); iter++){
	c_hand = *iter;
	if(c_hand == c){
	    found_card = true;
	}	
    }
    return found_card;
}

Card Player::removeCardFromHand(Card c) {
    // remove card from hand with .erase make new card with exact qualities
    Card c_hand;
    int index = 0;
    vector<Card>::iterator iter;
    iter = myHand.begin();
    while(iter != myHand.end()){
        c_hand = *iter;
        if(c.getRank() ==  c_hand.getRank()){
	    int new_rank = c_hand.getRank();
	    int s = 0;
	    string old_suit = c_hand.toString();
	    old_suit.erase(0,1);
	    if(old_suit == "s"){
		s = 0;
	    }
	    else if(old_suit == "h"){
		s = 1;
	    } 
 	    else if(old_suit == "d"){
		s = 2;
	    }else{
		s = 3;
 	    }
	    Card::Suit new_suit = static_cast<Card::Suit>(s);
	    Card remove(new_rank, new_suit);
	    myHand.erase(myHand.begin()+index);
	    return remove;
 	}
	iter++;
	index++;
    }
    return c; 
}

string Player::showHand() const {
    // return hand as a string loop through, string concatenation
    string hand;
    if(myHand.size() == 0){
	 hand = "EMPTY";
    }
    else{
        vector<Card>::const_iterator iter;
        Card c;
        for(iter = myHand.begin(); iter != myHand.end(); iter++){
            c = *iter;
	    hand += c.toString() + " ";
        }
    }
    return hand; 
}

string Player::showBooks() const {
    // return book as a string loop through with iterators, sring concatenation
    vector<Card>::const_iterator iter;
    string book;
    Card c;
    for(iter = myBook.begin(); iter != myBook.end(); iter++){
	c = *iter;
	book += c.toString() + " ";
    }
    return book;
}

int Player::getHandSize() const {
    return myHand.size();
}

int Player::getBookSize() const {
    // each book is two cards , so num of cards divided by two
    return (myBook.size() / 2);
}

	/*
bool Player::checkHandForPair(Card &c1, Card &c2){
        
}
	*/

bool Player::sameRankInHand(Card c) const {
    bool same_rank = false;
    Card hand;
    vector<Card>::const_iterator iter;
    for(iter = myHand.begin(); iter != myHand.end(); iter++){
	hand = *iter;
	if(hand.getRank() == c.getRank()){
	    same_rank = true;
	}	
    }
    return same_rank;
}





