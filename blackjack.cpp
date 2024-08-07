//
//  test.cpp
//  
//
//  Created by ALex on 7/26/24.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

#include <algorithm> // for shuffle
#include <random> // random number generator

// enumurated classes
enum Suit {
    Hearts,
    Diamonds,
    Clubs,
    Spades
};

enum Rank {
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace
};


// card class
class Card{

    // declaring variable
    string suit;
    string card;
    int value;

public:

    Card(string s, string c, int v): suit(s), card(c), value(v){
        // initialize card
        // suit
        // card -> change to rank
        
        suit = s;
        card = c;
        value = v;
        cout << "Card Created; value: " << value << " suit: " << suit << " card: " << card << endl;

    };

    // static game

    // get the card rank
    string get_suit(){
        cout << "Card Suit: " << suit << endl;
        return card;
    };

    // get the card rank
    string get_rank(){
        cout << "Card Rank: " << card << endl;
        return card;
    };


    // get value of card (input game)
    // TODO: create a map for values to work on enumerated variables
    int get_value(){

    map<Rank, int> blackjackValues;

    blackjackValues[Two] = 2;
    blackjackValues[Three] = 3;
    blackjackValues[Four] = 4;
    blackjackValues[Five] = 5;
    blackjackValues[Six] = 6;
    blackjackValues[Seven] = 7;
    blackjackValues[Eight] = 8;
    blackjackValues[Nine] = 9;
    blackjackValues[Ten] = 10;
    blackjackValues[Jack] = 10;
    blackjackValues[Queen] = 10;
    blackjackValues[King] = 10;
    blackjackValues[Ace] = 11; // Treating Ace as 11 for simplicity


        cout << "Card Value: " << value << endl;
        return value;
    };

};


// deck class
class Deck{

    // initialize variables
    // static, does not change and is defined outside of Main
    // re-implement, will only allow to have one game at a time
    static string GAME;

    // vector of cards
    // reserve 52 spaces in vector (not critical for this length)
    // TODO: how to specify a fixed length vector?
    vector<Card> deck;


    public:
    // initialize deck of cards
    Deck(){
        cout << "Constructor called" << endl;

        // create a deck of cards
        // TODO: Enumurate suit and card to reduce memory
        // creating deck variables
        string allSuits[] = {"Hearts", "Spades", "Diamonds", "Clubs"};

        string allCards[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10",
            "Jack", "Queen", "King", "Ace"};

        // TODO: loop through enum variables and use them instead of Strings

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
                // memory is allocated
                // pushback - copies the object to vector (2 copies)
                // emplace - creates object directly in vector
                deck.emplace_back(Card(suit, card, value));
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

    // TODO: use random number generator to shuffle
    // how does this work?
    void shuffle_deck(){
        random_device rd;
        mt19937 g(rd());
        shuffle(deck.begin(), deck.end(), g);
    }

    // draw a card
    void draw_a_card(){
        // get card value
        cout << "Drew a card from the current deck" << endl;

        // get last value in vector
        Card curCard = deck.back();

        // show the value
        curCard.get_value();
        curCard.get_rank();
        curCard.get_suit();

        // remove last variable
        deck.pop_back();
        
    };

};


// Define the static member variable outside the class
string Deck::GAME = "";

int main() {
    cout << "Hello World!" << endl;

    // testing Deck
    Deck deck = Deck();
    deck.set_game("blackjack");
    deck.get_game();

    // draw card
    deck.draw_a_card();
    deck.shuffle_deck();
    cout << "Card After shuffled deck: " << endl;
    deck.draw_a_card();

    // testing card
    Card card = Card("hearts","Queen",10);
    int cardValTest = card.get_value();
    cout << "returned card Value: " << cardValTest << endl;



    // testing enum
    enum allSuits{
        Hearts,
        Spades,
        Diamonds,
        Clubs
    };

    return 0;
}