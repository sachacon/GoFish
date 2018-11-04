#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include "player.h" 
#include "card.h"
using namespace std;

Player::Player(){
    myName = "";
}

void Player::addCard(Card c){
    myHand.push_back(c);       
}

void Player::bookCards(Card c1, Card c2){

}

bool Player::checkHandForBook(Card &c1, Card &c2){

}

bool Player::rankInHand(Card c) const {
    bool same_rank = false;
    vector<Card>::iterator iter;
    for(iter = myHand.begin(); iter != myHand.end(); iter++){
	Card in_hand = *iter;
	if(in_hand == c){
	    same_rank = true;
	}
    }
    return same_rank;
}

Card Player::chooseCardFromHand() const {

}

bool Player::cardInHand(Card c) const {

}

Card Player::removeCardFromHand(Card c) {

}

string Player::showHand() const {
   vector<Card>::iterator iter;
   for(iter = myHand.begin(); iter != myHand.end(); iter++){
	Card c = *iter;
   }
   string hand = c.toString();
   return hand; 
}

string Player::showBooks() const {

}

int Player::getHandSize() const {
    return myHand.size();
}

int Player::getBookSize() const {
    return myBook.size();
}

bool Player::checkHandForPair(Card &c1, Card &c2){

}

bool Player::sameRankInHand(Card c) const {

}





