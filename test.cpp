//
//  test.cpp
//  
//
//  Created by ALex on 7/26/24.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;


// card class
class Card{

    string suit;
    string card;
    int value;

public:

    Card(string s, string c, int v){
            // initialize card
        // suit
        // card
        suit = s;
        card = c;
        value = v;
        cout << "Card Created; value: " << value << " suit: " << suit << " card: " << card << endl;

    };

        // static game

    // get value of card (input game)
    void get_value(){
        cout << "Card Value: " << value << endl;
    };

};


// deck class
class Deck{

    // initialize variables
    // static, does not change and is defined outside of Main
    static string GAME;


    // vector of cards
    vector<Card> deck;


    public:
    // initialize deck of cards
    Deck(){
        cout << "Constructor called" << endl;

        // create a deck of cards

        // creating deck variables
        string allSuits[] = {"Hearts", "Spades", "Diamonds", "Clubs"};

        string allCards[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10",
            "Jack", "Queen", "King", "Ace"};

        // temp variables
        int value;
        string suit;
        string card;

        // calc length of arrays
        int numSuits = sizeof(allSuits) / sizeof(allSuits[0]);
        int numCards = sizeof(allCards) / sizeof(allCards[0]);

        // loop through suits
        for(int i =0; i<numSuits; i++){
            
            // loop through variables
            for(int j=0; j<numCards; j++){

                // get value of card
                if (j < 9){
                    value = j+1;
                }else{
                    value = 10;
                }

                suit = allSuits[i];
                card = allCards[j];
                deck.push_back(Card(suit, card, value));
            }
        };

    };

    // sets game variable
    void set_game(string g){
        GAME = g;
        cout << "Game is set to: " << Deck::GAME << endl;
    };

    // gets game variable
    void get_game(){
        cout << "The game is: " << Deck::GAME << endl;
    }

    // draw a card
    void draw_a_card(){
        // get card value
        cout << "Drew a card from the current deck" << endl;

        // get last value in vector
        deck.back().get_value();

        // remove last variable
        deck.pop_back();
        
    };

};


// Define the static member variable outside the class
// how does this work?
string Deck::GAME = "";

int main() {
    cout << "Hello World!" << endl;

    Deck deck = Deck();
    deck.set_game("blackjack");
    deck.get_game();

    deck.draw_a_card();

    Card card = Card("hearts","Queen",10);

    card.get_value();


    return 0;
}
