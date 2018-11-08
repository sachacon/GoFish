#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include "player.h" 
#include "card.h"
using namespace std;

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

    // double while loop with extra bool variable  
    iter = myHand.begin();
    iter2 = myHand.begin();
    while(iter != myHand.end() && !found_pair){
	Card pair1 = *iter;
	while(iter2 != myHand.end() && !found_pair){
	    if( (iter - myHand.begin()) == (iter2 - myHand.begin()) ){
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
    vector<Card>::const_iterator iter;
    iter = myHand.begin();
    Card c = *iter;    
    myHand_Index = (myHand_Index + 1) % myHand.size();
    return c;
}

bool Player::cardInHand(Card c) const {
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
    bool found_card = false;
    Card c_hand;
    int index = 0;
    vector<Card>::iterator iter;
    iter = myHand.begin();
    while(iter != myHand.end() && !found_card){
        c_hand = *iter;
        if(c.getRank() ==  c_hand.getRank()){
	    myHand.erase(myHand.begin()+index);
	    bool found_card =true;
 	}
	iter++;
	index++;
    }
    return c_hand; 
}

string Player::showHand() const {
   vector<Card>::const_iterator iter;
   string hand;
   Card c;
   for(iter = myHand.begin(); iter != myHand.end(); iter++){
	c = *iter;
	hand += c.toString() + " ";
   }
   return hand; 
}

string Player::showBooks() const {
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





