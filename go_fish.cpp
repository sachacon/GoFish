#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <vector> 
#include "card.h"
#include "deck.h"
#include "player.h"
using namespace std;

int main(){
    Player p("Sergio");
    cout << "Player is called - " << p.getName() << endl;
    int i = 0;
    Deck d;
    cout << d.size() << endl;
    for(i = 0; i < 10; i++){
	Card cd = d.dealCard();
	cout << cd << endl;
    }
    d.shuffle();
    for(i = 0; i < 10; i++){
	Card cd = d.dealCard();
	cout << cd << endl;
    }  
    cout << d.size() << endl;  
 
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


