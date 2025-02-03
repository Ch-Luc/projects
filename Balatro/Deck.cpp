#include <vector>
#include "Card.hpp"
#include <cstdlib>                                                   
#include <ctime>
#include "Deck.hpp"                                             
using namespace std;

const vector<string>& CardUtils::getValues() {
    static const vector<string> allValues = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "1"};
    return allValues;
}

const vector<string>& CardUtils::getSuits() {
    static const vector<string> allSuits = {"Spades", "Hearts", "Diamonds", "Clubs"};
    return allSuits;
}

vector<Card> standardDeck() {
    const vector<string>& allValues = CardUtils::getValues();
    const vector<string>& allSuits = CardUtils::getSuits();
    vector<Card> deck;
    for (const string& suit : allSuits) {
        for (const string& value : allValues) {
            deck.emplace_back(value, suit);
        }
    }
    return deck;
}

vector<Card> abandonnedDeck() {
    vector<string> allValues = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "1"};
    const vector<string>& allSuits = CardUtils::getSuits();
    vector<Card> deck;
    for (const string& suit : allSuits) {
        for (const string& value : allValues) {
            deck.emplace_back(value, suit);
        }
    }
    return deck;
}

vector<Card> checkeredDeck() {
    const vector<string>& allValues = CardUtils::getValues();
    vector<string> allSuits = {"Spades", "Hearts"};
    vector<Card> deck;
    for(int i=0; i<2; i++){
        for (const string& suit : allSuits) {
            for (const string& value : allValues) {
            deck.emplace_back(value, suit);
            }
        }
    }
    return deck;
}

vector<Card> erraticDeck() {
    srand(time(0));
    int tempVal(0);
    int tempSuit(0);
    const vector<string>& allValues = CardUtils::getValues();
    const vector<string>& allSuits = CardUtils::getSuits();
    vector<Card> deck;
    for (int i=0; i<=52; i++){
        tempVal = rand() % 13;
        tempSuit = rand() % 4;
        deck.emplace_back(allValues[tempVal], allSuits[tempSuit]);
    }
    return deck;
}