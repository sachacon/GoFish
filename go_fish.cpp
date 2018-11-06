#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <vector> 
#include "card.h"
#include "deck.h"
#include "player.h"
using namespace std;


void deal_cards(Player &p1, Player &p2, Deck &d){
    Card c1;
    Card c2;
    for(int i = 0; i < 7; i++){
	c1 = d.dealCard();
        c2 = d.dealCard();
	p1.addCard(c1);
	p2.addCard(c2);
    }	
}

bool check_winner(){
    return true;
}

void print_end_state(){

}

bool draw_or_book(){
    return true;
}

int main(){
 
    bool winner = false;
    string current_player, next_player, temp;
      
 
    // Construct two players and a deck
    Player p1("Joe");
    Player p2("Jane");
    Deck d;

    // Shuffle and deal 7 card to each player
    d.shuffle();
    deal_cards(p1, p2, d);
    cout << "# of cards in Joe's hand - " << p1.getHandSize() << endl << p1.showHand() << endl   
         << "# of cards in Jane's hand - " << p2.getHandSize() << endl << p2.showHand() << endl
	 << "# of cards left in deck - " << d.size() << endl << endl;
    cout << "Players ready , deck shuffled, cards dealt, " 
	 << p1.getName() << " goes first ... " << endl;

    // Start and play the game until there's a winner
    current_player = p1.getName();
    next_player = p2.getName();
    while(!winner){
        cout << current_player << " asks - Do you have a " << endl;
	cout << next_player << "says - " << endl;
	
 	if(draw_or_book){
	    cout << current_player << " draws ";
	}else{
	    cout << current_player << "books the ";
	}	
	 
 	// change who's asks next
 	temp = current_player;
	current_player = next_player;
	next_player = temp;  
 
	// check if a player has enough books to win
	if(check_winner){
	    winner = true;
 	}
    }

    // Find and print who won, show each player's hands and books
    print_end_state();







 
	/*
    Card c;
    Card cc;
    cout << c << endl;
    
    int s = 0;
    Card::Suit suit = static_cast<Card::Suit>(s);
    int rank = 13;
    Card c1(rank, suit);
    cout << c1 << endl; 

    cout << "c.toString() = " << c.toString() << endl;
    if(c.sameSuitAs(c1)){
	cout << "c is the same suit as c1" << endl;
    }else{
	cout << "c is not the same suit as c1" << endl;
    }
    cout << "c.getRank() = " << c.getRank() << endl;
    cout << "c.suitString(suit) = " << c.suitString(suit) << endl;
    cout << "c.rankString(rank) = " << c.rankString(rank) << endl;

    if(c == c1){
  	cout << "c == c1 " << endl;
    }
    if(c != c1){
	cout << "c != c1" << endl;
    }
    if(c == cc){
	cout << "c == cc" << endl;
    }  
	*/
    return(0);
}


