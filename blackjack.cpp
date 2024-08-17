//  test.cpp
//  Created by ALex on 7/26/24.

#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

#include <algorithm> // for shuffle
#include <random> // random number generator

// enum suit
enum Suit {
    Hearts,
    Diamonds,
    Clubs,
    Spades
};

// enum rank
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

// enum variable suit mapping to string
static map<Suit, std::string> suitToString = {
            {Suit::Hearts, "Hearts"},
            {Suit::Diamonds, "Diamonds"},
            {Suit::Clubs, "Clubs"},
            {Suit::Spades, "Spades"}
        };

// enum variable rank mapping to string
static map<Rank, std::string> rankToString = {
            {Rank::Two, "Two"},
            {Rank::Three, "Three"},
            {Rank::Four, "Four"},
            {Rank::Five, "Five"},
            {Rank::Six, "Six"},
            {Rank::Seven, "Seven"},
            {Rank::Eight, "Eight"},
            {Rank::Nine, "Nine"},
            {Rank::Ten, "Ten"},
            {Rank::Jack, "Jack"},
            {Rank::Queen, "Queen"},
            {Rank::King, "King"},
            {Rank::Ace, "Ace"}
        };

// map for values to work on enumerated variables
static const std::map<Rank, int> blackjackValues = {
        {Rank::Two, 2},
        {Rank::Three, 3},
        {Rank::Four, 4},
        {Rank::Five, 5},
        {Rank::Six, 6},
        {Rank::Seven, 7},
        {Rank::Eight, 8},
        {Rank::Nine, 9},
        {Rank::Ten, 10},
        {Rank::Jack, 10},
        {Rank::Queen, 10},
        {Rank::King, 10},
        {Rank::Ace, 11} // Treating Ace as 11 for simplicity, in real game can be 1
};

// card class
class Card{

    // declaring variable
    Suit enumSuit;
    Rank enumRank;

public:
    // Pass by Value: by defualt all data is copied when passed into any function all C++ (no reference)
    // Pass by Reference: passing in a pointer not a primitive - use & infront of variable name
    // const in front of string - cannot be changed by reference 

    Card(Suit s, Rank r): enumSuit(s), enumRank(r){
        // initialize a card with suit and rank

        cout << "Enum Card Created; " << "\t suit: " << suitToString[enumSuit] << "\t rank: " << rankToString[enumRank] << "\t value: " << blackjackValues[enumRank] << endl;

    };

    // get the card rank
    string get_suit(){
        cout << "Card Suit: " << suitToString[enumSuit] << endl;
        return suitToString[enumSuit];
    };

    // get the card rank
    string get_rank(){
        cout << "Card Rank: " << rankToString[enumRank] << endl;
        return rankToString[enumRank];
    };


    // TODO: allow for input of game name to get correct map - later
    // TODO: use initializer list (look up) - what do i use this for??

    // get value of card
    int get_value(){
        // use map to get value

        // .at() checks if the index is in the map, by default if it is not, it will add it
        // TODO: do the same for other maps
        cout << "Card Value: " << blackjackValues.at(enumRank) << endl;

        return blackjackValues[enumRank];
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
    vector<Card> deck;

    public:
    // initialize deck of cards
    Deck(){
        cout << "Constructor called" << endl;

        // create a deck of cards

        // loop through enum variables and use them instead of Strings
        // TODO: use the keys in the map defined above instead of an array
        Suit allSuitsEnum[] = {Hearts, Spades, Diamonds, Clubs};
        Rank allRanksEnum[] = {Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace};

        // calc length of arrays
        // TODO: use the size of the map to get both 
        int numSuits = sizeof(allSuitsEnum) / sizeof(allSuitsEnum[0]);
        int numCards = sizeof(allRanksEnum) / sizeof(allRanksEnum[0]);

        // loop through suits
        // ++ infront of i to make it quicker
        // TODO: can use python style loop through loop - range based for on map object
        for(int i =0; i<numSuits; ++i){
            
            // loop through variables
            for(int j=0; j<numCards; ++j){
                // memory is allocated
                // pushback - copies the object to vector (2 copies)
                // emplace - creates object directly in vector
                
                // TODO: fix deck creation after fixing above
                deck.emplace_back(Card(allSuitsEnum[i], allRanksEnum[j]));
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

    // use random number generator to shuffle
    void shuffle_deck(){
        random_device rd; // device
        mt19937 g(rd()); // algorithm to shuffle
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

        // remove last card
        deck.pop_back();
        
    };

};

// TODO: make a fuction to run a blackjack game, maybe look into Player class (to hold Deck)
// TODO: make deck class empty on intialization and create function to populat and shuffle it
// TODO: make a add_card_to_deck() function


// Define the static member variable outside the class
string Deck::GAME = "";

int main() {
    cout << "Hello World!" << endl;

    // testing Deck
    Deck deck = Deck();

    cout << "\n"; 

    deck.set_game("blackjack");
    deck.get_game();

    cout << "\n"; 

    // draw card
    deck.draw_a_card();
    deck.shuffle_deck();
    cout << "Card After shuffled deck: " << endl;
    deck.draw_a_card();

    cout << "\n"; 

    // testing card
    Card card = Card(Hearts,Queen);
    int cardValTest = card.get_value();
    string cardSuitTest = card.get_suit();
    string cardRankTest = card.get_rank();

    cout << "\n"; 

    // testing enum Suits
    Suit allSuitsEnum[] = {Hearts, Spades, Diamonds, Clubs};
    Suit enumSuit = allSuitsEnum[0];
    string testSuit = suitToString[enumSuit];
    cout << "Converting Enum Suit to String:  " << testSuit << endl;

    cout << "\n"; 

    // testing enum rank
    Rank allRanksEnum[] = {Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace};
    Rank enumRank = allRanksEnum[2];
    string testRank = rankToString[enumRank];
    cout << "Converting Enum Rank to String:  " << testRank << endl;

    cout << "\n"; 

    // testing enum Card
    Card enumCard = Card(enumSuit, enumRank);

    // testing value map

    return 0;
}