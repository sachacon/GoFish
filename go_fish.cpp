#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <vector> 
#include "card.h"
#include "deck.h"
#include "player.h"
using namespace std;

// deal_cards() - deals seven cards to each of the two players from the deck
// pre-conditions - deck has been shuffled, valid players, players have empty hands, deck is full
// post-conditions - deck has 14 less cards, each player has 7 cards in hand
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

// check_winner() - checks if the game has been won or tied
// pre-conditions - given player instances by reference, valid players
// post-conditions - returns true if game should end by way of majority books or tie, false otherwise
bool check_winner(Player &p1, Player &p2){
    // check if a player has a won (i.e. majority of 26 available books)
    bool win = false;
    cout << "p1.getBookSize() == " << p1.getBookSize() << endl
	 << "p2.getBookSize() == " << p2.getBookSize() << endl;
    if(p1.getBookSize() > 13 || p2.getBookSize() > 13){
	win = true;
    }
    // if the game ends in a tie than return end game bool as well
    if( (p1.getBookSize() == p2.getBookSize()) && p1.getBookSize() == 13){
	win = true;  
    }
    return win; 
}

// print_end_state() - prints who won, player's hands, sizes, and books
// pre-conditions: A player has won or a tie, given two player instances by references, valid players
// post-conditions: prints out to console game state
void print_end_state(Player &p1, Player &p2){
    // Print the winner's name and book size
    // Already checked that one of the two won (i.e. one has a book size >13)
    cout << endl << "--------------------------------------------" << endl;
    if((p1.getBookSize() == p2.getBookSize()) && p1.getBookSize() == 13){
	cout << endl << "Tie Game ... No Winner" << endl;
    }
    else if(p1.getBookSize() > 13){
	cout << endl << p1.getName() << " wins with " << p1.getBookSize() << " books" << endl;
    }else{
	cout << endl << p2.getName() << " wins with " << p2.getBookSize() << " books" << endl; 
    }
  
    // Show player 1's book and hand 
    cout << endl << p1.getName() << "'s hand: " << "size - " << p1.getHandSize()
	 << endl << p1.showHand() << endl;
    cout << p1.getName() << "'s book: " << "size - " << p1.getBookSize()
	 << endl << p1.showBooks() << endl;

    // Show player 2's book and hand 
    cout << endl << p2.getName() << "'s hand: " << "size - " << p2.getHandSize()
	 << endl << p2.showHand() << endl;
    cout << p2.getName() << "'s book: " << "size - " << p2.getBookSize()
	 << endl << p2.showBooks() << endl;
}

// book_cards() - books two given cards onto a player's book and removes
//		- the two cards from the the player's hand, outputs book rank
// pre-conditions: player's book and hand are not empty, checkHandForBook() true
// post-conditions: player's book bigger by two element's, removed one element from hand
void book_cards(Player &p, Card &book1, Card &book2){
    Card removed;
    p.bookCards(book1, book2);
    removed = p.removeCardFromHand(book1);
    removed = p.removeCardFromHand(book2);
    cout << p.getName() << " books a " << book1.rankString(book1.getRank()) << endl;
}

int main(){
 
    bool winner = false;
    int player = 1, s1 = 0, s2 = 0, rank1 = 1, rank2 = 1;   
    const int NUM_RANKS = 13;  
 
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
    Card card_to_ask;
    Card removed;
    Card book1;
    Card book2;
    Card went_fishing;
    bool pair_found = true; 
    while(!winner){

 	// execute turn 
 	pair_found = true; 
	if(player == 1){
	   
	    // book any cards if needed
	    while(pair_found){
		if(p1.checkHandForBook(book1, book2)){
		    book_cards(p1, book1, book2);
		}else{
		    pair_found = false;
		}	
	    }

 	    // if no cards in hand or in deck, ask a random card
	    if(p1.getHandSize() == 0 && d.size() == 0){
		rank1 = (rand() % NUM_RANKS) + 1;
		Card::Suit suit1 = static_cast<Card::Suit>(s1);
		Card rand_card1(rank1, suit1);
		card_to_ask = rand_card1;
		cout << "asking a random card " << "p1 has " << p1.getHandSize()
		     << ", p2 has " << p2.getHandSize() << endl;
 	    }
	    // if no cards in hand, draw a card and ask
	    else if(p1.getHandSize() == 0){
		card_to_ask = d.dealCard();
		cout << p1.getName() << " draws a " << card_to_ask.toString() << endl;
	    }else{
	        card_to_ask = p1.chooseCardFromHand();
	    }
	    cout << p1.getName() << " asks - Do you have a " << card_to_ask.rankString(card_to_ask.getRank()) << endl;
 	    // if other player has the card, get it and book it if able to
	    if(p2.rankInHand(card_to_ask)){
		cout << p2.getName() << " says - Yes. I have a " 
		     << card_to_ask.rankString(card_to_ask.getRank()) << endl;
	        removed = p2.removeCardFromHand(card_to_ask);
	        p1.addCard(removed);
		
		if(p1.checkHandForBook(book1, book2)){
		    book_cards(p1, book1, book2);
		}
	    // if other player does not have the card, go fishing, draw card
	    }else{
		cout << p2.getName() << " says - Go Fish " << endl;
		if(d.size() != 0){
		    went_fishing = d.dealCard();
		    p1.addCard(went_fishing);
		    cout << p1.getName() << " draws " << went_fishing.toString() << endl;
		}
	    }

        }else{
	    // player 2's turn
	    // if player has extra cards to book
	    while(pair_found){
		if(p2.checkHandForBook(book1, book2)){
		    book_cards(p2, book1, book2);
		}else{
		    pair_found = false;
		}
 	    }
		
	    // if player has no card in hand or in deck, ask a random card
	    if(p2.getHandSize() == 0 && d.size() == 0){
		rank2 = (rand() % NUM_RANKS) + 1;
		Card::Suit suit2 = static_cast<Card::Suit>(s2);
		Card rand_card2(rank2, suit2);
		card_to_ask = rand_card2;
		cout << " asking a random card " << "p1 has " << p1.getHandSize() 
		     << ", p2 has " << p2.getHandSize() << endl;
   	    }
	    // if player has no cards in hand, draw a card and ask it	
	    else if(p2.getHandSize() == 0){
		card_to_ask = d.dealCard();
		cout << p2.getName() << " draws a " << card_to_ask.toString() << endl;
 	    }
	    else{
	    card_to_ask = p2.chooseCardFromHand();
	    }
	    cout << p2.getName() << " asks - Do you have a " << card_to_ask.rankString(card_to_ask.getRank()) << endl;
	    // if other player has the card, get it and book it if able to
	    if(p1.rankInHand(card_to_ask)){
		cout << p1.getName() << " says - Yes. I have a " 
		     << card_to_ask.rankString(card_to_ask.getRank()) << endl;
		removed = p1.removeCardFromHand(card_to_ask);
		p2.addCard(removed);

		if(p2.checkHandForBook(book1, book2)){
		    book_cards(p2, book1, book2);
		}
	    // if other player doesn't have the card, go fishing, draw a card
	    }else{
		cout << p1.getName() << " says - Go Fish " << endl;
		if(d.size() != 0){
		    went_fishing = d.dealCard();
		    p2.addCard(went_fishing);
		    cout << p2.getName() << " draws " << went_fishing.toString() << endl;
		}
	    }

	}

 	// change which player's turn it is
 	if(player == 1){
	    player = 2;
        }else{
 	    player = 1;
	} 
 
	// check if a player has enough books to win
	if(check_winner(p1, p2) || (p1.getHandSize() == 0 && p2.getHandSize() == 0 && d.size() == 0) ){
	    winner = true;
 	}

    }
   
    // Find and print who won, show each player's hands and books
    print_end_state(p1, p2);
    cout << endl << "GAME OVER\n\n";

    return(0);
}


