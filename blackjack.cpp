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
static std::map<Rank, int> blackjackValues = {
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

        // cout << "Enum Card Created; " << "\t suit: " << suitToString[enumSuit] << "\t rank: " << rankToString[enumRank] << "\t value: " << blackjackValues[enumRank] << endl;

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
    // intializes an empty deck of cards
    Deck(){
        // cout << "Constructor called" << endl;

        // create a deck of cards


    };

    // use random number generator to shuffle
    void shuffle_deck(){
        random_device rd; // device
        mt19937 g(rd()); // algorithm to shuffle
        shuffle(deck.begin(), deck.end(), g);
    }

    // fills the deck
    void fill_deck(){
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

        shuffle_deck();
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
    Card draw_a_card(){
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
        
        return curCard;
    };

    // adds a card to the deck
    void add_a_card(Card card){
        deck.emplace_back(card);
    }

    // gets total score from deck
    int get_score(){
        int score = 0;
        for(Card curCard : deck){
            // show the value
            score += curCard.get_value();
        };

        return score;
    };

    // prints deck
    void print_deck(){
        for(Card curCard : deck){
            // show the value
            cout << "\n  Card:" << endl;
            curCard.get_value();
            curCard.get_rank();
            curCard.get_suit();
        };
        int score = get_score();
        cout << "\nScore: " << score << endl;
    };



};

// returns true if score is 21
bool win_blackjack_game(Deck deck){
    int score = deck.get_score();
    if(score == 21){
        return true;
    }else{
        return false;
    };
};

// returns true if score is over 21
bool over_21(Deck deck){
    int score = deck.get_score();
    if(score > 21){
        return true;
    }else{
        return false;
    };
};

bool draw_card_choice(){
    char userInput;
    do {
            cout << "Please enter 'y' or 'n': ";
            cin >> userInput;
        
            // Convert to lowercase to accept both 'Y' and 'y'
            userInput = tolower(userInput);

            // Check if the input is valid
            if (userInput != 'y' && userInput != 'n') {
                cout << "Invalid input. ";
        }
    } while (userInput != 'y' && userInput != 'n');

    if(userInput == 'y'){
        return true;
    }else{
        return false;
    }
}


// TODO: make a fuction to run a blackjack game, maybe look into Player class (to hold Deck)
// TODO: make deck class empty on intialization and create function to populat and shuffle it
// TODO: make a add_card_to_deck() function

// TODO:
// create a status for player 0 active or out - if score over 21 or done drawing
// while (status for each player){for player in each one to make sure their status is good}

// Define the static member variable outside the class
string Deck::GAME = "";

int main() {
    /*
    // Testing Functionalities
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
    */

    cout << "\n Playing a game of blackjack: \n";

    // create dealer and populate
    Deck dealer = Deck();
    dealer.fill_deck();
    dealer.print_deck();

    // create players 
    Deck player1 = Deck();
    Deck player2 = Deck();

    // each player draws two cards
    player1.add_a_card(dealer.draw_a_card());
    player2.add_a_card(dealer.draw_a_card());
    player1.add_a_card(dealer.draw_a_card());
    player2.add_a_card(dealer.draw_a_card());

    // show each deck
    cout << "\n Player 1 Deck: \n";
    player1.print_deck();
    cout << "\n Player 2 Deck: \n";
    player2.print_deck();

    // holds all players
    vector<Deck> players = {player1, player2};

    // status for players
    bool player1Win = false;
    bool player1Bust = false;

    bool player2Win = false;
    bool player2Bust = false;

    bool endGame = false;

    // bool draw1;
    // bool draw2;

    // playing the game
    while(!endGame){

        // give player 1 option to draw card
        cout << "Player 1: Draw a card?" << endl;
        bool draw1 = draw_card_choice();

        if(draw1){
            player1.add_a_card(dealer.draw_a_card());
        }

        // give player 2 option to draw card
        cout << "Player 2: Draw a card?" << endl;
        bool draw2 = draw_card_choice();

        if(draw2){
            player2.add_a_card(dealer.draw_a_card());
        }

        // check if player won
        // check if player is over 21

        player1Win = win_blackjack_game(player1);
        if(player1Win){
            cout << "Player 1 Won!" << endl;
            endGame = true;
        }

        player1Bust = over_21(player1);
        if(player1Bust){
            cout << "Player 1 Bust!" << endl;
            endGame = true;
        }

        player2Win = win_blackjack_game(player2);
        if(player2Win){
            cout << "Player 2 Won!" << endl;
            endGame = true;
        }

        player2Bust = over_21(player2);        
        if(player2Bust){
            cout << "Player 2 Bust!" << endl;
            endGame = true;
        }

    };
    

    return 0;
}