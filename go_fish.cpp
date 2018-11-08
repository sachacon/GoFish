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
    // Deal seven card at the beginning to each of the 2 players
    Card c1;
    Card c2;
    for(int i = 0; i < 7; i++){
	c1 = d.dealCard();
        c2 = d.dealCard();
	p1.addCard(c1);
	p2.addCard(c2);
    }	
}

bool check_winner(Player &p1, Player &p2){
    cout << endl << " checking if there's a winner " << endl;
    // check if a player has a won (i.e. majority of 26 available books)
    bool win = false;
    if(p1.getBookSize() > 13 || p2.getBookSize() > 13){
	bool win = true;
    }
    return win; 
}

void print_end_state(Player &p1, Player &p2){
    // Print the winner's name and book size
    // Already checked that one of the two won (i.e. one has a book size >13)
    if(p1.getBookSize() > 13){
	cout << p1.getName() << " wins with " << p1.getBookSize() << " books" << endl;
    }else{
	cout << p2.getName() << " wins with " << p2.getBookSize() << " books" << endl; 
    }
  
    // Show player 1's book and hand 
    cout << p1.getName() << "'s hand: " << "size - " << p1.getHandSize()
	 << endl << p1.showHand() << endl;
    cout << p1.getName() << "'s book: " << "size - " << p1.getBookSize()
	 << endl << p2.showBooks() << endl;

    // Show player 2's book and hand 
    cout << p2.getName() << "'s hand: " << "size - " << p2.getHandSize()
	 << endl << p2.showHand() << endl;
    cout << p2.getName() << "'s book: " << "size - " << p2.getBookSize()
	 << endl << p2.showBooks() << endl;
}

int main(){
 
    bool winner = false;
    int player = 1;     
 
    // Construct two players and a deck
    cout << endl << "Starting game ... " << endl;
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
    while(!winner){

 	// execute turn 
 	Card card_to_ask;
        Card removed;
	Card book1;
	Card book2;
	Card went_fishing;   
	cout << "it's player " << player << "'s turn " << endl;    
	if(player == 1){

	    card_to_ask = p1.chooseCardFromHand();
	    cout << "p1 chose a card to ask" << endl;
	    cout << p1.getName() << " asks - Do you have a " << card_to_ask.toString() << endl;
	    if(p2.rankInHand(card_to_ask)){
		cout << p2.getName() << " says - Yes. I have a " << card_to_ask.getRank() << endl;
	        removed = p2.removeCardFromHand(card_to_ask);
	        p1.addCard(removed);
		if(p1.checkHandForBook(book1, book2)){
		    p1.bookCards(book1, book2);
		    cout << p1.getName() << " books a " << book1.getRank() << endl;
		}
	    }else{
		cout << p2.getName() << " says - Go Fish " << endl;
		went_fishing = d.dealCard();
		p1.addCard(went_fishing);
		cout << p1.getName() << " draws " << went_fishing.toString() << endl;
	    }

        }else{

	    card_to_ask = p2.chooseCardFromHand();
	    cout << "p2 chose a card to ask" << endl;
	    cout << p2.getName() << " asks - Do you have a " << card_to_ask.toString() << endl;
	    if(p1.rankInHand(card_to_ask)){
		cout << p1.getName() << " says - Yes. I have a " << card_to_ask.getRank() << endl;
		removed = p1.removeCardFromHand(card_to_ask);
		p2.addCard(removed);
		if(p2.checkHandForBook(book1, book2)){
		    p2.bookCards(book1, book2);
		    cout << p2.getName() << " books a " << book1.getRank() << endl;
		}
	    }else{
		cout << p1.getName() << " says - Go Fish " << endl;
		went_fishing = d.dealCard();
		p2.addCard(went_fishing);
		cout << p2.getName() << " draws " << went_fishing.toString() << endl;
	    }

	}	
	
 	// change which player's turn it is
 	if(player == 1){
	    player = 2;
        }else{
 	    player = 1;
	} 
 
	// check if a player has enough books to win
	if(check_winner(p1, p2)){
	    winner = true;
 	}

    }
   
    // Find and print who won, show each player's hands and books
    print_end_state(p1, p2);
    cout << endl << "GAME OVER\n\n";

    return(0);
}


